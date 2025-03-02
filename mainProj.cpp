// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Rational.h"
#include "vector"
#include <algorithm>
#include <functional>

class ToUpper {
public:
    char operator()(char c)const {
        if (c>='a'&&c<='z') {
            return static_cast<char>(c - 'a' + 'A');
        }
        return c;
    }
};

int main()
{
    auto f1 = bind([](int i, int b)->int {
        return i + b;
    }, placeholders::_1, 6);

    cout << f1(5) << endl;

    ToUpper toU;
    cout << toU('n') << endl;
    cout << toU('N') << endl;

    char c1 = 'a';
    char c2 = 'b';

    auto equal = equal_to<char>{};

    cout << equal(c1, c2) << endl;

    string s1 = "helloworld";
    string s2 = "worl";
    auto res = search(s1.begin(), s1.end(), s2.begin(), s2.end(),
        bind(equal_to<char>{},
            bind(toU, placeholders::_1),
            bind(toU, placeholders::_2)));

    if (res != s1.end()) {
        cout << "is a substring" << endl;
    }
    else
    {
        cout << "not a substring" << endl;
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
