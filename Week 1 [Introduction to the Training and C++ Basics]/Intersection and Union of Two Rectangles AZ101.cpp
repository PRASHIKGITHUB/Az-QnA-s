#include<bits/stdc++.h>
using namespace std;

using lli=long long int;
void solve(){
    lli x1, y1, x2, y2;
    lli x3, y3, x4, y4;
    cin>>x1>>y1>> x2>> y2;
    cin>>x3>>y3>> x4>> y4;

    //area of a
    lli a1;
    a1=abs((x1-x2)*(y1-y2));
    //area of b
    lli a2=0;
    a2=abs((x3-x4)*(y3-y4));
    

    
    //intersection
    lli x5,y5,x6,y6;
    x5=max(x1,x3);
    y5=max(y1,y3);
    x6=min(x2,x4);
    y6=min(y2,y4);
    //area of intersection
    lli inter;
    if(x5<=x6 && y5<=y6){
        inter=abs((x6-x5)*(y6-y5));
    }
    else{
        inter=0;
    }

    //union
    lli uni=a1+a2-inter;

    cout<<inter<<" "<<uni<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}