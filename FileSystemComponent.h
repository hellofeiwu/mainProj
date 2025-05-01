#pragma once
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

class FileSystemComponent
{
public:
	virtual void show() = 0;
	virtual void add(shared_ptr<FileSystemComponent> component) = 0;
	virtual void remove(shared_ptr<FileSystemComponent> component) = 0;
};

class File :public FileSystemComponent {
private:
	string _name;
public:
	File(const string& name):_name(name) {}
	virtual void show() {
		cout << "name: " <<_name<< endl;
	}
	//virtual void add(shared_ptr<FileSystemComponent> component) {}
	//virtual void remove(shared_ptr<FileSystemComponent> component) {}
};

class Dir :public FileSystemComponent {
private:
	string _name;
	vector<shared_ptr<FileSystemComponent>> _children;
public:
	Dir(const string& name) :_name(name) {}
	virtual void show() {
		cout << "name: " << _name << endl;
		for (auto& c: _children) {
			c->show();
		}
	}
	virtual void add(shared_ptr<FileSystemComponent> component) {
		_children.push_back(component);
	}
	virtual void remove(shared_ptr<FileSystemComponent> component) {
		auto it = find(_children.begin(), _children.end(),component);
		if (it !=_children.end()) {
			_children.erase(it);
		}
	}
};

