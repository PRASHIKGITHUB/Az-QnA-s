#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    bool check(long long mid,vector<int>& start, long long d){
        long long last=start[0];
        for(int i=1;i<=n-1;i++){
            if(max(last+mid,1LL*start[i])<=start[i]+d){
                last=max(last+mid,1LL*start[i]);
            }
            else{
                return 0;
            }
        }
        return 1;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        n=start.size();
        sort(start.begin(),start.end());
        int low=0;
        long long high=start[n-1]+d-start[0];
        long long ans=-1;
        while(high>=low){
            long long mid=low+(high-low)/2;
            if(check(mid,start,d)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}