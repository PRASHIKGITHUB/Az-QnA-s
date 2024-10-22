#include<bits/stdc++.h>
using namespace std;
bool is_cycle=false;
class Animal{
    public:
    virtual void sound(){
        cout<<"No sound "<<endl;
    }
    Animal(){
        cout<<"Animal"<<endl;
    }
    // virtual ~Animal(){//if you do not make this virtual, while deleting the cat_prt only the animal gets deleted rest will stay as it is creating memory leak
    //     cout<<"~Animal"<<endl;
    // }
    virtual ~Animal()=default;//both ways it is fine
};
class Cat:public Animal{
    public:
    void sound (){
        cout<<"Meow "<<endl;
    }
    Cat(){
        cout<<"Cat"<<endl;
    }
    ~Cat() override{//writing override is optional after making base class destructor as vitrual
        cout<<"~Cat"<<endl;
    }
};


class Dog:public Animal{
    public:
    void sound(){
        cout<<"Bark "<<endl;
    }
    Dog(){
        cout<<"Dog"<<endl;
    }
    ~Dog(){
        cout<<"~Dog"<<endl;
    }
};

class Kitten:public Cat{
    public:
    void sound(){
        cout<<"meowww"<<endl;
    }
    Kitten(){
        cout<<"Kitten"<<endl;
    }
    ~Kitten(){
        cout<<"~Kitten"<<endl;
    }
};

void PlaySound(Animal& animal){
    animal.sound();
}

void temp(Cat& dd){
    dd.sound();
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    // Cat cat;
    // PlaySound(cat);
    
    // Dog dog;
    // PlaySound(dog);

    // Kitten kit;
    // PlaySound(kit);
    
    // temp(kit);

    Kitten *cat_prt=new Kitten();
    Animal &animal_ref=*cat_prt;//here we are not creating new object, so the constructor wont be called
    Animal *animal_ptr=&animal_ref;

    // animal_ptr->sound();
    // animal_ref.sound();

    delete animal_ptr;//new delete are used in pairs

    // Cat temp;
    // Kitten kit;

    return 0;
}