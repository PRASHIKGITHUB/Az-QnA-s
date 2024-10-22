#include <bits/stdc++.h>
using namespace std;
class Home
{
public:
    Home(string address) : address_(address)
    {
    }
    ~Home(){cout<<"~Home() of address "<<address_<<endl;}

    string address_;

};

class Heart
{
public:
    Heart(string person_name) : person_name_(person_name)
    {
        cout << "Heart() of person " << person_name_ << endl;
    }
    ~Heart()
    {
        cout << "~Heart() of person " << person_name_ << endl;
    }
    void Beats() {}

private:
    string person_name_;
};
class Person
{
public:
    Person(string person_name,Home *home) : heart_(person_name),home_(home),person_name_(person_name)
    {
        cout << "Person()" <<person_name_<< endl;
    }
    ~Person()
    {
        cout << "~Person()" <<person_name_<<endl;
    }
    void GetAddress(){
        cout<<home_->address_<<endl;
    }

private:
    //member
    Heart heart_; //composition

    //member
    Home* home_; //Aggregation

    //member
    string person_name_;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Home* home=new Home("Nehru Hall");
    Person *p1=new Person("prashik",home);
    Person *p2=new Person("shruti",home);
    delete p1;
    p2->GetAddress();//it's still there 
    // delete home;
    p2->GetAddress();
    delete p2;
    return 0;
}