#pragma once
#include "Adaptee.h"
class WinSensor :
    public Adaptor1
{
    virtual void getData() {
        cout << "win sensor got data" << endl;
    }
};

class MacSensor : public Adaptor2 {
    virtual void getData() {
        cout << "mac sensor got data" << endl;
    }
};

