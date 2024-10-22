#include<bits/stdc++.h>
using namespace std;
class Heart{
    public:
    Heart(string person_name):person_name_(person_name){
        cout<<"Heart() of person "<<person_name_<<endl;
    }
    ~Heart(){
        cout<<"~Heart() of person "<<person_name_<<endl;
    }
    void Beats(){}
    private:
    string person_name_;
};
class Person{
    public:
    Person(string person_name): heart_(person_name) {
        cout<<"Person()"<<endl;
    }
    ~Person(){
        cout<<"~Person()"<<endl;
    }
    private:
    Heart heart_;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Person p1("prashik");
    return 0;
}