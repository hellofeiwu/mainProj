// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <csetjmp>

using namespace std;

jmp_buf jumpBuffer;

void foo() {
    cout << "enter foo()" << endl;
    longjmp(jumpBuffer, 1);
    cout << "exit foo()" << endl; // ????
}

void foo2() {
    cout << "enter foo2()" << endl;
    throw 1;
    cout << "exit foo2()" << endl; // ????
}

int main()
{
    //if (setjmp(jumpBuffer)==0) {
    //    cout << "befor foo()" << endl;
    //    foo();
    //    cout << "after foo()" << endl; // ????
    //}
    //else {
    //    cout << "jumped back to setjmp" << endl;
    //}

    try {
        cout << "befor foo2()" << endl;
        foo2();
        cout << "after foo2()" << endl; // ????
    }
    catch(int e) {
        cout << "jumped back to setjmp with number: "<< e << endl;
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
