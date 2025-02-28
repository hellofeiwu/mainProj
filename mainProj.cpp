// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Rational.h"
#include "vector"
#include <algorithm>

//class Compare {
//public:
//    bool operator()(double a, double b) const {
//        return a < b;
//    }
//};

class Point {
public:
    Point(double x, double y):_x(x),_y(y){}
    double _x;
    double _y;
};

int main()
{
    Point p0(0.0,0.0);
    Point p1(2.5,3.0);
    Point p2(12.5,3.5);
    double distance = 10.0;

    auto inFirstQ = [](const Point& p)->bool {
        return p._x >= 0 && p._y >= 0;
    };

    auto inCircle = [&p0,distance](const Point& p)->bool {
        double res = sqrt((p._x - p0._x) * (p._x - p0._x) + (p._y - p0._y) * (p._y - p0._y));
        return res <= distance;
    };
    
    auto inFirstQandCircle = [&](const Point& p)->bool {
        return inFirstQ(p) && inCircle(p);
    };

    cout << inFirstQandCircle(p1) << endl;
    cout << inFirstQandCircle(p2) << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
