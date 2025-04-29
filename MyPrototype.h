#pragma once
#include "Prototype.h"
class MyPrototype :
    public Prototype
{
public:
    MyPrototype(int id, const string& name):_id(id),_name(name) {}
    virtual shared_ptr<Prototype> clone() const {
        return make_shared<MyPrototype>(_id,_name);
    }

    virtual void showInfo() const {
        cout << "id: " << _id << ", name: " << _name << endl;
    }
private:
    int _id;
    string _name;
};

