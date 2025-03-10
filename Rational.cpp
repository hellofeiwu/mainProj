#include "Rational.h"
 Rational Rational::operator+(const Rational& other){
	 return Rational(_den * other._num + other._den * _num, _den * other._den);
 }

 Rational& Rational::operator+=(const Rational& other) {
	 return *this = *this + other;
 }

 Rational Rational::operator-(const Rational& other) {
	 return Rational(_num * other._den - other._num * _den, _den * other._den);
 }
 Rational& Rational::operator-=(const Rational& other) {
	 return *this = *this - other;
 }

 Rational Rational::operator*(const Rational& other) {
	 return Rational(_num * other._num, _den * other._den);
 }
 Rational& Rational::operator*=(const Rational& other) {
	 return *this = *this * other;
 }

 Rational Rational::operator/(const Rational& other) {
	 return Rational(_num * other._den, _den * other._num);
 }
 Rational& Rational::operator/=(const Rational& other) {
	 return *this = *this / other;
 }

 bool Rational::operator==(const Rational& other) const {
	 return _num == other._num && _den == other._den;
 }
 bool Rational::operator!=(const Rational& other) const {
	 return !(*this == other);
 }