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
    virtual void testV() {
        cout << "A22: testV()" << endl;
    }
    void test() { cout << "A22: test()" << endl; }
    static void testS() { cout << "A22: testS()" << endl; }
};

class B22 :public A22 {
public:
    B22() {}
    virtual ~B22() {}
    virtual void testV() { cout << "B22: testV" << endl; }
    void test() { cout << "B22: test()" << endl; }
    static void testS() { cout << "B22: testS()" << endl; }
};

class Base1 {
public:
    virtual void func1() {}
};

class Base2 {
    virtual void func2() {}
};

class Child :public Base1, Base2 {
public:
    virtual void func2() {}
    virtual void func3() {}
};

int main()
{
    //A22 a;
    //B22 b;
    //cout << sizeof(b) << endl;
    //a.testV();
    //a.test();
    //b.testV();
    //b.test();
    //A22::testS();

    //A22* arr[2];
    //arr[0] = &a;
    //arr[1] = &b;

    //arr[0]->testV(); // ?????vptr?????
    //arr[0]->test(); // ???????????????????????????????????????
    //arr[1]->testV(); // ?????vptr?????
    //arr[1]->test(); // ???????????????????????????????????????
    Child c;
    cout << sizeof(c) << endl;

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
