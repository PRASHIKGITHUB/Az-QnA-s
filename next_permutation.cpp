#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={1,2,3,4};
    do
    {
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    } while (next_permutation(v.begin(),v.end()));
    
    cout<<"ending"<<endl;
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}