// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class A {};

class A0 {
public :
    A0() {}
    ~A0() {}
};

class A1 {
public:
    A1():_a(0) {}
    ~A1() {}
private:
    int _a;
};

class A11 {
public:
    A11() :_a(0),_b(0) {}
    ~A11() {}
private:
    int _a;
    int _b;
};

class A2 {
public:
    A2() {}
    virtual ~A2() {}
    void test() {}
    static void testS() {}
};

class A22 {
public:
    A22() {}
    virtual ~A22() {}
    virtual void testV() {}
    void test() {}
    static void testS() {}
};

int main()
{

    cout << sizeof(A) << endl;     // 1
    cout << sizeof(A0) << endl;    // 1
    cout << sizeof(A1) << endl;     // 4
    cout << sizeof(A11) << endl;    // 8
    cout << sizeof(A2) << endl;     // 4
    cout << sizeof(A22) << endl;    // 4

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
