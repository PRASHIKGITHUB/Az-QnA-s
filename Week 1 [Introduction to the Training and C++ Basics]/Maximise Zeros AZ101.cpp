#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int a,long long int b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

pair<long long int,long long int> reducePair(long long a,long long b){
    long long commonGcd=gcd(a,b);
    return make_pair(a/commonGcd,b/commonGcd);
}

void solve(){
    int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long int b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    map<pair<int,int>,int> frequencyMap;
    int zero=0;

    for(int i=0;i<n;i++){
        if(a[i]==0 && b[i]==0){
            zero++;
        }
        else if(a[i]==0){
            continue;
        }
        else{
            frequencyMap[reducePair(a[i],b[i])]++;
        }
    }
    int temp=0;
    for(auto i:frequencyMap){
        temp=max(temp,i.second);
    }
    cout<<temp+zero<<endl;

}

int main() {
   int t;
   cin>>t;
   while(t--){
    solve();
   }
   return 0;
}