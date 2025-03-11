// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "SmartPointer.h"
#include "Rational.h"
using namespace std;

class MySharedClass {
public:
    MySharedClass(){
        cout << "in MySharedClass()" << endl;
    }
    ~MySharedClass() {
        cout << "in ~MySharedClass()" << endl;
    }
    void doSomething() {
        cout << "in doSomething()" << endl;
    }
};

class SharedB;
class SharedA {
public:
    shared_ptr<SharedB> _shpB;
    SharedA() {
        cout << "in SharedA()" << endl;
    }
    ~SharedA() {
        cout << "in ~SharedA()" << endl;
    }
};

class SharedB {
public:
    weak_ptr<SharedA> _shpA;
    SharedB() {
        cout << "in SharedB()" << endl;
    }
    ~SharedB() {
        cout << "in ~SharedB()" << endl;
    }
};

int main()
{
    //Rational* p = new Rational(3,4);
    //SmartPointer<Rational> sp(p);

    //if (sp) {
    //    cout << *sp << endl;
    //    cout << sp->getNum() << endl;
    //}

    //SmartPointer<Rational> sp2;
    ////SmartPointer<Rational> sp3(new Rational(5, 9));
    //sp2 = move(sp);

    // use shared pointer
    /*shared_ptr<MySharedClass> shp = make_shared<MySharedClass>();
    shared_ptr<MySharedClass> shp2(shp);
    shared_ptr<MySharedClass> shp3 = shp;

    shp->doSomething();
    shp2->doSomething();
    shp3->doSomething();*/
    
    // loop share
    shared_ptr<SharedA> shpA = make_shared<SharedA>();
    shared_ptr<SharedB> shpB = make_shared<SharedB>();
    shpA->_shpB = shpB;
    shpB->_shpA = shpA;
    auto p = shpB->_shpA.lock();
    cout<< p->_shpB << endl;

    shared_ptr<MySharedClass> shp = make_shared<MySharedClass>();
    weak_ptr<MySharedClass> wp = shp;
    shp->doSomething();

    if (auto p = wp.lock()) {
        p->doSomething();
    }
    else {
        cout << "wp.lock() faile" << endl;
    }

    shp.reset();
    if (auto p = wp.lock()) {
        p->doSomething();
    }
    else {
        cout << "wp.lock() faile" << endl;
    }

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
