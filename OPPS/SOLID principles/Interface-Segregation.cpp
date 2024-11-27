#include <bits/stdc++.h>
using namespace std;

class ShapeInterface
{ // interface class
public:
    virtual double GetArea() = 0; // pure virtual functions

    virtual double GetVolume() = 0;
};

//Client-1
class Square : public ShapeInterface
{
public:
    Square(int len) : len_(len) {}

    double GetArea() override
    {
        return len_ * len_;
    }
    double GetVolume() override{//client is forced to declare it here eventhough it does not have volume property(to solve this we create two interface classes for 2D(only GetArea would be there) and 3D shapes) and inherit those accordingly
        return 0;
    }
private:
    int len_;
};


//Client-2
class Sphere : public ShapeInterface
{
public:
    Sphere(int r) : radius_(r) {}
    double GetArea() override
    {
        return 4 * 3.14 * radius_ * radius_;
    }

    double GetVolume() override
    {
        return (4 * 3.14 * radius_ * radius_ * radius_) / 3;
    }

private:
    int radius_;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Sphere sphere(2);
    cout << sphere.GetArea() << " " << sphere.GetVolume() << endl;

    Square square(4);
    cout<<square.GetArea()<<" "<<square.GetVolume()<<endl;

    return 0;
}