#pragma once
#include <iostream>
#include <memory>
using namespace std;
class Prototype
{
public:
	virtual shared_ptr<Prototype> clone() const = 0;
	virtual void showInfo() const = 0;
};

