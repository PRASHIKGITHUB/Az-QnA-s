#include <bits/stdc++.h>
using namespace std;
int n;
map<int,int>mp;
using lli = long long int;
vector<int>curr_sol;
void rec(int x){
    if(x==n){
        for(auto i:curr_sol){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    //choices
    for(auto ch:mp){
        if(ch.second!=0){
            curr_sol.push_back(ch.first);
            mp[ch.first]--;
            rec(x+1);
            mp[ch.first]++;
            curr_sol.pop_back();
        }
    }
    return;
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        mp[temp]++;
    }

    rec(0);
    return 0;
}