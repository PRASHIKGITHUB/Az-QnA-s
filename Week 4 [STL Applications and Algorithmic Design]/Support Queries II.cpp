#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
using pp=pair<lli,lli>;
lli m = 1e9 + 7;
int q,k;
struct top_k{
    lli sum=0;
    multiset<int>ms1;
    multiset<int>ms2;
    void add(int x){
        ms1.insert(x);
        sum+=x;
        if(ms1.size()>k){
            int small=*(ms1.begin());
            sum-=small;
            ms1.erase(ms1.begin());
            ms2.insert(small);
        }
    }
    void remove(int x){
        if(ms1.find(x)!=ms1.end()){
            ms1.erase(ms1.find(x));
            sum-=x;
            while(!ms2.empty() && ms1.size()<k){
                int highest=*(ms2.rbegin());
                ms2.erase(ms2.find(highest));
                sum+=highest;
                ms1.insert(highest);
            }
        }
        else if(ms2.find(x)!=ms2.end()){
            ms2.erase(ms2.find(x));
        }
    }
    lli sum_of_top_k(){
        return sum;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>q>>k;
    struct top_k data;
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            int ele;
            cin>>ele;
            data.add(ele);
        }
        else if(x==2){
            int ele;
            cin>>ele;
            data.remove(ele);
        }
        else{
            char c;
            cin>>c;
            cout<<data.sum_of_top_k()<<endl;
        }
    }
    return 0;
}