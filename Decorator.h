#pragma once
#include <memory>
#include <iostream>
using namespace std;

// ?????
class Stream {
public:
	virtual void doSomething() = 0;
};

class MyStream:public Stream {
public:
	virtual void doSomething() {
		cout << "MyStream do something" << endl;
	}
};

// ???
class Decorator: public Stream
{
private:
	shared_ptr<Stream> _stream;
public:
	Decorator(shared_ptr<Stream> stream):_stream(stream) {
	}
	virtual void doSomething() {
		if (_stream != nullptr) {
			_stream->doSomething();
		}
	}
};

class Decorator2 :public Decorator {
public:
	Decorator2(shared_ptr<Stream> stream):Decorator(stream) {}
	virtual void doSomething() {
		cout << "decorator2 do somthing" << endl;
		Decorator::doSomething();
	}
};

class Decorator3 :public Decorator {
public:
	Decorator3(shared_ptr<Stream> stream) :Decorator(stream) {}
	virtual void doSomething() {
		cout << "decorator3 do somthing" << endl;
		Decorator::doSomething();
	}
};
