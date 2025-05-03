#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <functional>

using namespace std;

class Observer
{
public:
	virtual void update(const string& message) = 0;
};

class Subject {
public:
	virtual void notifyObservers(const string& message) = 0;
	virtual void registObservers(shared_ptr<Observer> observer) = 0;
	virtual void removeObservers(shared_ptr<Observer> observer) = 0;
};

class News :public Subject {
private:
	vector<shared_ptr<Observer>> _observers;
public:
	virtual void notifyObservers(const string& message) {
		for (auto& o:_observers) {
			o->update(message);
		}
	}
	virtual void registObservers(shared_ptr<Observer> observer) {
		_observers.push_back(observer);
	}
	virtual void removeObservers(shared_ptr<Observer> observer) {
		auto it = find(_observers.begin(),_observers.end(),observer);
		if (it != _observers.end()) {
			_observers.erase(it);
		}
	}
};

class Observer1 :public Observer {
public:
	virtual void update(const string& message) {
		cout << "observer1 got message: " << message << endl;
	}
};

class Observer2 :public Observer {
public:
	virtual void update(const string& message) {
		cout << "observer2 got message: " << message << endl;
	}
};

class Observer3 :public Observer {
public:
	virtual void update(const string& message) {
		cout << "observer3 got message: " << message << endl;
	}
};

class StlNews {
private:
	vector<function<void(const string&)>> _observers;
public:
	virtual void notifyObservers(const string& message) {
		for (auto& o:_observers) {
			o(message);
		}
	}
	virtual void registObservers(function<void (const string&)> observer) {
		_observers.push_back(observer);
	}
	virtual void removeObservers(function<void(const string&)> observer) {
		// ????????????????
		auto it = remove_if(_observers.begin(),_observers.end(),
			[observer](function<void (const string&)> other) {
				return observer.target_type() == other.target_type();
			});

		if (it != _observers.end()) {
			_observers.erase(it);
		}
	}
};

