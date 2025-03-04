// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;

void getMemory1(char* p) {
    p = new char[100];
}

char* getMemory2() {
    char p[] = "hello";
    return p;
}

void getMemory3(char** p) {
    *p = new char[100];
}

void test1() {
    char* s = nullptr;
    getMemory1(s);
    strcpy_s(s,100,"hello");
    cout << s << endl;
}

void test2() {
    char* s = nullptr;
    s = getMemory2();
    cout << s << endl;
}

void test3() {
    char* s = nullptr;
    getMemory3(&s);
    strcpy_s(s, 100, "hello");
    cout << s << endl;
    delete s;
    s = nullptr;
}

void test4() {
    char* s = new char[100];
    strcpy_s(s,100,"hello");
    
    if (s!=nullptr) {
        strcat_s(s,100, "world");
        cout << s << endl;
    }

    delete s;
    s = nullptr;
}

int main()
{
    test3();

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
