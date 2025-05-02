// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <map>

using namespace std;

class Font {
public:
    virtual void applyFont() = 0;
};

class FontA : public Font {
public:
    virtual void applyFont() {
        cout << "apply font A" << endl;
    }
};

class DefaultFont : public Font {
public:
    virtual void applyFont() {
        cout << "apply default font" << endl;
    }
};

class FontFactory {
private:
    map<char, shared_ptr<Font>> _fonts;
public:
    virtual shared_ptr<Font> getFont(char key) {
        if (key == 'a') {
            _fonts[key] = make_shared<FontA>();
        }
        else {
            _fonts[key] = make_shared<DefaultFont>();
        }
        return _fonts[key];
    }
};

int main()
{
    char text[] = "aaeeaaet";

    FontFactory factory;

    for (int i = 0; text[i]!='\0'; i++) {
        factory.getFont(text[i])->applyFont();
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
