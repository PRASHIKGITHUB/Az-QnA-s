#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    A(int a, int b, int c) : a_(a), b_(b), c_(c)//this is called as constructor initializer list
    {
        cout << "A constructor is called " << endl;
        cout<<a_<<" "<<b_<<" "<<c_<<endl;
        
    }

protected:
    int a_;
    int b_, c_;
};

class B : public A
{
public:
    B(int x, int y, int z, int a, int b, int c) : A(a, b, c), x_(x), y_(y), z_(z)//constructor initializer list can only assign values to it's own members
    {
        cout << "B constructor is called " << endl;
        cout<<x_<<" "<<y_<<" "<<z_<<endl;
        cout<<a_<<" "<<b_<<" "<<c_<<endl;//you can access this since they are protected and got inherited from class A
    }

private:
    int x_, y_, z_;
};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    B b(1,2,3,4,5,6);
    return 0;
}