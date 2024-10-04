#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
lli H;
vector<lli>pre;
class Solution {
public:

    int helper(lli ele,lli x){
        lli high=H-1;
        lli low=0;
        lli ans=-1;
        while(low<=high){
            lli mid=low+(high-low)/2;
            if(pre[mid]*ele<=x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    bool check(lli x,vector<int>& arr){//x is the maximum time
        lli temp=H;
        for(auto ele:arr){
            int cnt=helper(ele,x);//how many seconds can be reduced by ele if x is the maximum time
            if(cnt!=-1){
                temp-=(cnt+1);
            }
            
        }
        if(temp<=0){
            return 1;
        }
        return 0;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& arr) {
        H=mountainHeight;
        pre.resize(H);
        pre[0]=1;
        for(int i=1;i<H;i++){
            pre[i]=i+1+pre[i-1];
        }
        lli low=0;
        lli high=-1e9;
        for(auto ele:arr){
            high=max(high,1LL*ele);
        }
        high=high*H*(H+1)/2;
        cout<<high<<endl;

        lli ans=-1;
        while(low<=high){
            lli mid=(low+high)/2;
            if(check(mid,arr)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};