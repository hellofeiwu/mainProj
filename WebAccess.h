#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>
#include <functional>
using namespace std;

class WebAccess
{
public:
	virtual void connectTo(const string& website) = 0;
};

class MyWebAccess : public WebAccess {
public:
	virtual void connectTo(const string& website) {
		cout << "connected to: "<<website<<endl;
	}
};

class ProxyAccess : public WebAccess {
private:
	shared_ptr<WebAccess> _myWebAccess;
	static vector<string> _blockedSites;
	bool isBlocked(const string& website) {
		auto it = find(_blockedSites.begin(), _blockedSites.end(), website);
		if (it != _blockedSites.end()) {
			return true;
		}
		return false;
	}
public:
	ProxyAccess(shared_ptr<WebAccess> myWebAccess):_myWebAccess(myWebAccess) {}
	virtual void connectTo(const string& website) {
		if (isBlocked(website)) {
			throw runtime_error(website + " is blocked");
		}
		else
		{
			_myWebAccess->connectTo(website);
		}
	}
};

class DelayProxyAccess : public WebAccess {
private:
	shared_ptr<WebAccess> _myWebAccess = nullptr;
	static vector<string> _blockedSites;
	bool isBlocked(const string& website) {
		for (auto& i : _blockedSites) {
			if (website.find(i) != string::npos) {
				return true;
			}
		}
		return false;
	}
public:
	virtual void connectTo(const string& website) {
		if (isBlocked(website)) {
			throw runtime_error(website + " is blocked");
		}
		else if(_myWebAccess == nullptr)
		{
			_myWebAccess = make_shared<MyWebAccess>();
		}
		_myWebAccess->connectTo(website);
	}
};


// ???????proxy
class DynaProxyAccess :public WebAccess {
private:
	function<void(const string&)> _myFunc;
	static vector<string> _blockedSites;
	bool isBlocked(const string& website) {
	auto it = find(_blockedSites.begin(), _blockedSites.end(), website);
	if (it != _blockedSites.end()) {
		return true;
	}
	return false;
	}
public:
	DynaProxyAccess(function<void(const string&)> myFunc):_myFunc(myFunc) {}
	virtual void connectTo(const string& website) {
		if (isBlocked(website)) {
			throw runtime_error(website + " is blocked");
		}
		else
		{
			_myFunc(website);
		}
	}
};
