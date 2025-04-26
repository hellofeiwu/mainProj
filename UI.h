#pragma once
#include <memory>

using namespace std;
class Button
{
public:
	virtual void click() = 0;
	virtual void close() = 0;
};

class Window
{
public:
	virtual void show() = 0;
	virtual void close() = 0;
};


class UIFactory
{
public:
	virtual shared_ptr<Button> createButton() = 0;
	virtual shared_ptr<Window> createWindow() = 0;
};
