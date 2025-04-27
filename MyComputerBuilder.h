#pragma once
#include "ComputerBuilder.h"
class WinComputerBuilder :
    public ComputerBuilder
{
public:

    virtual void buildCpu() {
        _computer.setCpu("aaa");
    }
    virtual void buildMemory() {
        _computer.setMemory("bbb");
    }
    virtual void buildStorage() {
        _computer.setStorage("ccc");
    }
    virtual Computer createComputer() {
        return _computer;
    }

private:
    Computer _computer;
};

class MacComputerBuilder :
    public ComputerBuilder
{
public:
    virtual void buildCpu() {
        _computer.setCpu("ddd");
    }
    virtual void buildMemory() {
        _computer.setMemory("eee");
    }
    virtual void buildStorage() {
        _computer.setStorage("fff");
    }
    virtual Computer createComputer() {
        return _computer;
    }

private:
    Computer _computer;
};

class MyComputerBuilder
{
public:
    MyComputerBuilder& buildCpu(const string& cpu) {
        _computer.setCpu(cpu);
        return *this;
    }
    MyComputerBuilder& buildMemory(const string& memory) {
        _computer.setMemory(memory);
        return *this;
    }
    MyComputerBuilder& buildStorage(const string& storage) {
        _computer.setStorage(storage);
        return *this;
    }
    Computer createComputer() {
        return _computer;
    }

private:
    Computer _computer;
};

