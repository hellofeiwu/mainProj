#pragma once
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Plugin
{
public:
	virtual void execute() = 0;
	virtual ~Plugin() {}
};

class PluginsManager {
public:
	void addPlugin(shared_ptr<Plugin> plugin) {
		_plugins.push_back(plugin);
	}

	void executeAllPlugins() {
		for (auto& p:_plugins) {
			p->execute();
		}
	}

	void unloadAllPlugins() {
		_plugins.clear();
	}
private:
	vector<shared_ptr<Plugin>> _plugins;
};

