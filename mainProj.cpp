// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Observer.h"

int main()
{
    //shared_ptr<Subject> news = make_shared<News>();
    //shared_ptr<Observer> ob1 = make_shared<Observer1>();
    //shared_ptr<Observer> ob2 = make_shared<Observer2>();
    //shared_ptr<Observer> ob3 = make_shared<Observer3>();

    //news->registObservers(ob1);
    //news->registObservers(ob2);
    //news->registObservers(ob3);

    //news->notifyObservers("news1");

    //news->removeObservers(ob2);
    //news->notifyObservers("news2");

    shared_ptr<StlNews> stlNews = make_shared<StlNews>();
    shared_ptr<Observer> ob1 = make_shared<Observer1>();
    shared_ptr<Observer> ob2 = make_shared<Observer2>();
    shared_ptr<Observer> ob3 = make_shared<Observer3>();

    function<void(const string&)> ob1func = [&](const string& message) {ob1->update(message); };
    function<void(const string&)> ob2func = [&](const string& message) {ob2->update(message); };
    function<void(const string&)> ob3func = [&](const string& message) {ob3->update(message); };

    stlNews->registObservers(ob1func);
    stlNews->registObservers(ob2func);
    stlNews->registObservers(ob3func);

    stlNews->notifyObservers("stl news1");

    stlNews->removeObservers(ob2func);

    stlNews->notifyObservers("stl news2");

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
