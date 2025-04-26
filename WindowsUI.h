#pragma once
#include "UI.h"
#include <iostream>

using namespace std;
class WindowsButton:public Button
{
public:
	virtual void click() {
		cout << "WindowsButton:click()" << endl;
	}
	virtual void close() {
		cout << "WindowsButton:close()" << endl;
	}
};

class WindowsWindow:public Window
{
public:
	virtual void show() {
		cout << "WindowsWindow:show()" << endl;
	}
	virtual void close() {
		cout << "WindowsWindow:close()" << endl;
	}
};


class WindowsUIFactory:public UIFactory
{
public:
	virtual shared_ptr<Button> createButton() {
		return make_shared<WindowsButton>();
	}
	virtual shared_ptr<Window> createWindow() {
		return make_shared<WindowsWindow>();
	}
};
