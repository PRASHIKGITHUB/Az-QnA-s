#include <bits/stdc++.h>
using namespace std;

class ShapeInterface
{
public:
    virtual void Draw() = 0;
};

class Square : public ShapeInterface
{
public:
    void Draw() override
    {
        cout << "CHOURAS" << endl;
    }
};

class Circle : public ShapeInterface
{
public:
    void Draw() override
    {
        cout << "GOLA" << endl;
    }
};

class Rectangle : public ShapeInterface
{
public:
    void Draw() override
    {
        cout << "rectangle" << endl;
    }
};

class Cube : public ShapeInterface
{
public:
    void Draw() override
    {
        cout << "cube" << endl;
    }
};

class Sphere : public ShapeInterface
{
public:
    void Draw() override
    {
        cout << "cube" << endl;
    }
};

class ShapeFactory
{
public:
    ShapeInterface *GetShape(string shape_name)
    {
        if (shape_name == "CIRCLE")
        {
            return new Circle();
        }
        else if (shape_name == "SQUARE")
        {
            return new Square();
        }
    }
};

class ShapeFactoryInterface
{
public:
    virtual ShapeInterface *GetShape(string shape_name) = 0;
};



class TwoDShapeFactory : public ShapeFactoryInterface
{
public:
    ShapeInterface *GetShape(string shape_name) override
    {
        if (shape_name == "circle")
        {
            return new Circle();
        }
        if (shape_name == "square")
        {
            return new Square();
        }
        if (shape_name == "rectangle")
        {
            return new Rectangle();
        }
        return NULL;
    }
};

class ThreeDShapeFactory : public ShapeFactoryInterface
{
public:
    ShapeInterface *GetShape(string shape_name) override
    {
        if(shape_name=="cube"){
            return new Cube();
        }
        if(shape_name=="sphere"){
            return new Sphere();
        }
        return NULL;
    }
};


void DisplayOnMonitor(ShapeFactoryInterface* shape_facory){

}

void DisplayOnVR(ShapeFactoryInterface* shape_facory){
    
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ShapeFactoryInterface* two_d_factory=new TwoDShapeFactory();
    ShapeFactoryInterface* three_d_factory=new ThreeDShapeFactory();
    ShapeInterface* temp = two_d_factory->GetShape("rectangle");
    temp->Draw();
    return 0;
}