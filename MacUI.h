#pragma once
#include "UI.h"
#include <iostream>

using namespace std;
class MacButton :public Button
{
public:
	virtual void click() {
		cout << "MacButton:click()" << endl;
	}
	virtual void close() {
		cout << "MacButton:close()" << endl;
	}
};

class MacWindow :public Window
{
public:
	virtual void show() {
		cout << "MacWindow:show()" << endl;
	}
	virtual void close() {
		cout << "MacWindow:close()" << endl;
	}
};


class MacUIFactory :public UIFactory
{
public:
	virtual shared_ptr<Button> createButton() {
		return make_shared<MacButton>();
	}
	virtual shared_ptr<Window> createWindow() {
		return make_shared<MacWindow>();
	}
};
