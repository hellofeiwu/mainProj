// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;

enum numberType
{
    INTEGER,
    MYRATIONAL,
    COMPLEX
};

class Number {
public:
    Number() {
        cout << "in Number()" << endl;
    }
    virtual ~Number() {
        cout << "in ~Number()" << endl;
    }
};

class Integer:public Number {
public:
    Integer() {
        cout << "in Integer()" << endl;
    }
    ~Integer() {
        cout << "in ~Integer()" << endl;
    }
};

class Myrational:public Number {
public:
    Myrational() {
        cout << "in Myrational()" << endl;
    }
    ~Myrational() {
        cout << "in ~Myrational()" << endl;
    }
};

class Complex:public Number {
public:
    Complex() {
        cout << "in Complex()" << endl;
    }
    ~Complex() {
        cout << "in ~Complex()" << endl;
    }
};

Number* createNumber(numberType numberType) {
    switch (numberType)
    {
    case INTEGER:
        return new Integer();
    case MYRATIONAL:
        return new Myrational();
    case COMPLEX:
        return new Complex();
    default:
        return new Number();
    }
}

class NumberWrapper {
public:
    NumberWrapper(Number* p) {
        cout << "in NumberWrapper()" << endl;
        _p = p;
    }
    ~NumberWrapper() {
        cout << "in ~NumberWrapper()" << endl;
        delete _p;
    }
    Number* getP() {
        return _p;
    }
private:
    Number* _p;
};

int main()
{
    try
    {
        NumberWrapper(createNumber(INTEGER));
        throw "some error";
    }
    catch (const char* s)
    {
        cout << s << endl;
    }

    //Number* p = new Integer();
    //delete p;
    
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
