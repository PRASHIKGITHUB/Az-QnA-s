#include<bits/stdc++.h>
using namespace std;
bool is_cycle=false;
class Animal{
    public:
    virtual void sound(){
        // cout<<"No sound "<<endl;
    }
};
class Cat:public Animal{
    public:
    void sound(){
        cout<<"Meow "<<endl;
    }
};
class Dog:public Animal{
    public:
    void sound(){
        cout<<"Bark "<<endl;
    }
};

void PlaySound(Animal& animal){
    animal.sound();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Cat cat;
    PlaySound(cat);
    
    Dog dog;
    PlaySound(dog);
    
    return 0;
}