#pragma once
// ???????
#include <iostream>
#include "TargetSensor.h"
using namespace std;
class Adaptee
{
public:
	void recognize() {
		cout <<"doing recognize" << endl;
	}
};

// ???????
class Adaptor1 :public TargetSensor, public Adaptee {
public:
	void getDataAndRecognize() {
		getData();
		recognize();
	}
};

// ????????
class Adaptor2 : public TargetSensor {
public:
	void getDataAndRecognize() {
		getData();
		_adaptee->recognize();
	}
private:
	shared_ptr<Adaptee> _adaptee;
};

