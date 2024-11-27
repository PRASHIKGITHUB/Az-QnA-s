#include<bits/stdc++.h>
using namespace std;

class IndiaIncome{
    private:
    double avg_indian_income_;
    public:
    IndiaIncome(double avg_india_income):avg_indian_income_(avg_india_income){}

    double GetAverageIncomeTax(){
        return  avg_indian_income_/15;
    }

    void PrintAverageIncome(){
        cout<<avg_indian_income_<<endl;
    }
};


class UsIncome{
    private:
    double avg_US_income_;
    public:
    UsIncome(double avg_US_income):avg_US_income_(avg_US_income ){}

    double GetAverageIncomeTax(){
        return  avg_US_income_/15;
    }

    void PrintAverageIncome(){
        cout<<avg_US_income_<<endl;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}