#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
void solve(int n){
   int arr[n];
    stack<int>s;
   for(int i=0;i<n;i++){
       cin>>arr[i];
       while(!s.empty() && arr[s.top()]>=arr[i]){
           s.pop();
       }
       if(s.empty()){
           cout<<"0"<<endl;
       }
       else{
           cout<<s.top()+1<<endl;
       }
       s.push(i);
   }
}
int main(){
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        solve(n);
    }
    return 0;
}