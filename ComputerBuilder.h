#pragma once
#include <iostream>
#include <memory>

using namespace std;

class Computer {
public:
	void setCpu(const string& cpu) {
		_cpu = cpu;
	}
	void setMemory(const string& memory) {
		_memory = memory;
	}
	void setStorage(const string& storage) {
		_storage = storage;
	}
	void show() {
		cout << "cpu: " << _cpu << endl;
		cout << "memory: " << _memory << endl;
		cout << "storage: " << _storage << endl;
	}
private:
	string _cpu;
	string _memory;
	string _storage;
};

class ComputerBuilder
{
public:
	virtual void buildCpu() = 0;
	virtual void buildMemory() = 0;
	virtual void buildStorage() = 0;
	virtual Computer createComputer() = 0;
};

