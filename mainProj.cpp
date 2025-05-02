// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

using namespace std;

class Render {
public:
    virtual void renderShape() = 0;
};

class OpenGLRender :public Render {
public:
    virtual void renderShape() {
        cout << "open gl render shape" << endl;
    }
};

class DirXRender :public Render {
public:
    virtual void renderShape() {
        cout << "DirX render shape" << endl;
    }
};

class Shape {
protected:
    shared_ptr<Render> _render;
public:
    Shape(shared_ptr<Render> render):_render(render) {}
    virtual void draw() = 0;

};

class Circle :public Shape {
public:
    Circle(shared_ptr<Render> render):Shape(render) {
    }
    virtual void draw() {
        cout << "draw circle" << endl;
        _render->renderShape();
    }

};

class Square :public Shape {
public:
    Square(shared_ptr<Render> render) :Shape(render) {
    }
    virtual void draw() {
        cout << "draw square" << endl;
        _render->renderShape();
    }
};

class Triangle : public Shape {
public:
    Triangle(shared_ptr<Render> render) :Shape(render) {
    }
    virtual void draw() {
        cout << "draw triangle" << endl;
        _render->renderShape();
    }
};

int main()
{
    shared_ptr<Render> openGLRender = make_shared<OpenGLRender>();
    shared_ptr<Shape> circle = make_shared<Circle>(openGLRender);
    circle->draw();

    auto dirXRender = make_shared<DirXRender>();
    auto square = make_shared<Square>(dirXRender);
    auto triangle = make_shared<Triangle>(dirXRender);
    square->draw();
    triangle->draw();

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
