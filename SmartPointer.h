#pragma once

template<typename T>
class SmartPointer
{
public:
	SmartPointer(T* p=nullptr):_p(p) {
	}
	~SmartPointer() {
		delete _p;
	}

	// stl auto pointer
	//SmartPointer(SmartPointer& other) {
	//	_p = other._p;
	//	other._p = nullptr;
	//}
	//SmartPointer& operator=(SmartPointer& other) {
	//	std::swap(_p, other._p);
	//	return *this;
	//}

	// stl unique pointer
	SmartPointer(SmartPointer&& other) {
		_p = other._p;
		other._p = nullptr;
	}
	SmartPointer& operator=(SmartPointer&& other) {
		std::swap(_p, other._p);
		return *this;
	}

	// *, ->, bool
	T& operator* () {
		return *_p;
	}

	T* operator-> () {
		return _p;
	}

	operator bool (){
		return _p;
	}
private:
	T* _p;
};

