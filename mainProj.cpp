// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "WebAccess.h"

void access(const string& website) {
    shared_ptr<WebAccess> myWebAccess = make_shared<MyWebAccess>();
    shared_ptr<WebAccess> proxyAccess = make_shared<ProxyAccess>(myWebAccess);

    try {
        proxyAccess->connectTo(website);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}

void dynaAccess(const string& website) {
    shared_ptr<WebAccess> dynaProxyAccess = make_shared<DynaProxyAccess>([](const string& website) {
        shared_ptr<WebAccess> myWebAccess = make_shared<MyWebAccess>();
        myWebAccess->connectTo(website);
        });
    try {
        dynaProxyAccess->connectTo(website);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}

void delayAccess(const string& website) {
    shared_ptr<WebAccess> delayProxyAccess = make_shared<DelayProxyAccess>();
    try {
        delayProxyAccess->connectTo(website);
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
}

int main()
{
    //access("google.com");
    //access("baidu.com");
    //access("qq.com");
    //access("taobao.com");

    //dynaAccess("google.com");
    //dynaAccess("baidu.com");
    //dynaAccess("qq.com");
    //dynaAccess("taobao.com");

    delayAccess("google.com");
    delayAccess("baidu.com");
    delayAccess("www.qq.com");
    delayAccess("http://taobao.com");

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
