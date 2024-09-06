#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr={1,2,3,6};
    int ans=0;
    int currSum=0;
    int k=6;

    
    unordered_map<int,int>mp;
    mp[0]=1;
    for(int i=0;i<4;i++){
        currSum+=arr[i];//subarry ending at ith index
        if(mp.find(currSum-k)!=mp.end()){
            ans+=mp[currSum-k];
        }
        mp[currSum]++;
    }
    cout<<ans<<endl;
    return 0;
}