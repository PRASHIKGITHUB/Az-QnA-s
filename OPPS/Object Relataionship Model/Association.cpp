#include <bits/stdc++.h>
using namespace std;
class Person;
class Home
{
public:
    Home(string address) : address_(address)
    {
        cout<<"Home() constructed"<<endl;
    }
    ~Home(){cout<<"~Home() destroyed "<<address_<<endl;}

    string address_;
    vector<Person*>persons;
    void addPerson(Person* per){
        persons.emplace_back(per);
    }

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
    Person(string person_name) : heart_(person_name),person_name_(person_name)
    {
        cout << "Person()" <<person_name_<< endl;
    }
    ~Person()
    {
        cout << "~Person()" <<person_name_<<endl;
    }
   
    void addHome(Home* home){
        homes.emplace_back(home);
    }

private: 
    //member
    Heart heart_; //composition

    //member
    vector<Home*>homes;//association

    //member
    string person_name_;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Home* h1=new Home("nagpur");
    Home* h2=new Home("banglore");
    Home* h3=new Home("mumbai");
    Home* h4=new Home("Hyderabad");

    Person *p1=new Person("prashik");
    Person *p2=new Person("shruti");

    p1->addHome(h1);
    h1->addPerson(p1); 
    
    p1->addHome(h2);
    h2->addPerson(p2);

    p2->addHome(h3);
    h3->addPerson(p2); 

    p2->addHome(h4);
    h4->addPerson(p2);

    
    return 0;
}