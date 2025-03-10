#pragma once
#include <iostream>

using namespace std;

class Rational
{
public:
	Rational(int num = 0, int den = 1) :_num(num), _den(den) {}
	Rational(const Rational& other):_num(other._num),_den(other._den) {}
	Rational(Rational&& other) {
		_num = other._num;
		_den = other._den;
		other._num = 0;
		other._den = 1;
	}

	Rational& operator=(const Rational& other) {
		if (this != &other) {
			_num = other._num;
			_den = other._den;
		}
		return *this;
	}
	Rational& operator=(Rational&& other) {
		if (this != &other) {
			_num = other._num;
			_den = other._den;
			other._num = 0;
			other._den = 1;
		}
		return *this;
	}

	virtual ~Rational() {}

	Rational operator+(const Rational& other);
	Rational& operator+=(const Rational& other);

	Rational operator-(const Rational& other);
	Rational& operator-=(const Rational& other);

	Rational operator*(const Rational& other);
	Rational& operator*=(const Rational& other);

	Rational operator/(const Rational& other);
	Rational& operator/=(const Rational& other);

	bool operator==(const Rational& other) const;
	bool operator!=(const Rational& other) const;

	friend ostream& operator<<(ostream& os, const Rational& r) {
		cout << r._num << "/" << r._den;
		return os;
	}

	int getNum() {
		return _num;
	}

	int getDen() {
		return _den;
	}

private:
	int _num;
	int _den;
};

