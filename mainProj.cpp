// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Decorator.h"

int main()
{
    shared_ptr<Stream> myStream = make_shared<MyStream>();
    shared_ptr<Stream> decorator = make_shared<Decorator>(myStream);
    decorator->doSomething();

    shared_ptr<Stream> deco2 = make_shared<Decorator2>(decorator);
    deco2->doSomething();

    shared_ptr<Stream> deco3 = make_shared<Decorator3>(deco2);
    deco3->doSomething();

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
