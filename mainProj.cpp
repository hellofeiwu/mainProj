// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <string>
#include "Singleton.h"

using namespace std;

int main()
{
    Singleton* s1 = Singleton::getInstance(10);
    Singleton* s2 = Singleton::getInstance(20);
    cout << s1->getData() << endl;
    cout << s2->getData() << endl;

    Singleton11& s11 = Singleton11::getInstance(30);
    Singleton11& s12 = Singleton11::getInstance(40);
    cout << s11.getData() << endl;
    cout << s12.getData() << endl;

    SingletonH& sh1 = SingletonH::getInstance(50);
    SingletonH& sh2 = SingletonH::getInstance(60);
    cout << sh1.getData() << endl;
    cout << sh2.getData() << endl;
    cout << &sh1 << endl;
    cout << &sh2 << endl;

    cout << Singleton98::getInstance(70)->getData() << endl;
    cout << Singleton98::getInstance(80)->getData() << endl;

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
