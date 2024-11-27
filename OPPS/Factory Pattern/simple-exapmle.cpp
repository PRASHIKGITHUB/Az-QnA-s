#include<bits/stdc++.h>
using namespace std;

class ShapeInterface{
    public:
    virtual void Draw()=0;
};

class Square:public ShapeInterface{
    public:
    void Draw() override{
        cout<<"CHOURAS"<<endl;
    }
};

class Circle:public ShapeInterface{
    public:
    void Draw() override{
        cout<<"GOLA"<<endl;
    }
};

class ShapeFactory{
    public: 
    ShapeInterface* GetShape(string shape_name){
        if(shape_name=="CIRCLE"){
            return new Circle();
        }
        else if(shape_name=="SQUARE"){
            return new Square();
        }
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string shape_name;
    cin>>shape_name;
    // Circle *circle=new Circle();
    ShapeFactory factory;
    ShapeInterface *shape=factory.GetShape(shape_name);
    shape->Draw();
    delete shape;
    return 0;
}