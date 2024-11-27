#include<bits/stdc++.h>
using namespace std;
//T
class Rectangle{
    public:
    Rectangle(int length,int width):length_(length),width_(width){ }

    int GetPerimeter(){
        return 2*(length_+ width_);
    }
    int GetArea(){
        return length_*width_;
    }
    private:
        int length_,width_;
};

//S-subtype  
class Square:public Rectangle{
    public:
    Square(int length):Rectangle(length,length){};
};

//code using T
pair<int,int> GetRectangleInformation(Rectangle& rectangle){
    return {rectangle.GetArea(),rectangle.GetPerimeter()};
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Rectangle rectangle(8,3);
    auto it=GetRectangleInformation(rectangle);
    cout<<it.first<<" "<<it.second<<endl;

    Square square(5);//derived class from rectangle
    it=GetRectangleInformation(square);
    cout<<it.first<<" "<<it.second<<endl;

    return 0;
}