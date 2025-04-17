#pragma once
#include <mutex>
using namespace std;

class Singleton
{
public:
	static Singleton* getInstance(int i) {
		if (_instance == nullptr) {
			lock_guard<mutex> lock(mutex);
			if (_instance == nullptr) {
				_instance = new Singleton(i);
			}
		}
		
		return _instance;
	}
	int& getData() {
		return _i;
	}
private:
	Singleton(int& i):_i(i) {}
	~Singleton() {}
	static Singleton* _instance;
	static mutex _mutex;
	int _i;
};

class Singleton98
{
public:
	static Singleton98* getInstance(int i) {
		call_once(_flag, [&]() {
			_instance = new Singleton98(i);
			});
	
		return _instance;
	}
	int& getData() {
		return _i;
	}
private:
	Singleton98(int& i) :_i(i) {}
	~Singleton98() {}
	static Singleton98* _instance;
	int _i;
	static once_flag _flag;
};


class Singleton11
{
public:
	static Singleton11& getInstance(int i) {
		static Singleton11 instance(i);
		return instance;
	}
	int& getData() {
		return _i;
	}
private:
	Singleton11(int& i):_i(i) {}
	~Singleton11() {}
	int _i;
};


class SingletonH
{
public:
	static SingletonH& getInstance(int i) {
		if (_instance.getData()==0) {
			_instance.setData(i);
		}
		
		return _instance;
	}
	int& getData() {
		return _i;
	}
	void setData(int& i) {
		_i = i;
	}
private:
	SingletonH() {}
	~SingletonH() {}
	static SingletonH _instance;
	int _i;
};
