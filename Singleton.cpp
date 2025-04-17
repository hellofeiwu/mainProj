#include "Singleton.h"

Singleton* Singleton::_instance = nullptr;
mutex Singleton::_mutex;

Singleton98* Singleton98::_instance = nullptr;
once_flag Singleton98::_flag;

SingletonH SingletonH::_instance;