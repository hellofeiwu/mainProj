// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ComputerBuilder.h"
#include "MyComputerBuilder.h"

using namespace std;

class Director {
public:
    Computer buildComputer(ComputerBuilder& builder) {
        builder.buildCpu();
        builder.buildMemory();
        builder.buildStorage();
        return builder.createComputer();
    }
};

int main()
{
    Director d;
    shared_ptr<WinComputerBuilder> winPcBuilder = make_shared<WinComputerBuilder>();
    Computer pc1 = d.buildComputer(*winPcBuilder);
    pc1.show();

    shared_ptr<MacComputerBuilder> macPcBuilder = make_shared<MacComputerBuilder>();
    Computer pc2 = d.buildComputer(*macPcBuilder);
    pc2.show();

    MyComputerBuilder myPcBuilder;
    Computer pc3 = myPcBuilder.buildCpu("ggg").buildMemory("hhh").buildStorage("iii").createComputer();
    pc3.show();

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
