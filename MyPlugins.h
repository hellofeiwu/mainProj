#pragma once
#include "Plugin.h"
class MyPlugin1:public Plugin
{
public:
	virtual void execute() {
		cout << "my plugin1 executed" << endl;
	}
};

class MyPlugin2 :public Plugin
{
public:
	virtual void execute() {
		cout << "my plugin2 executed" << endl;
	}
};

