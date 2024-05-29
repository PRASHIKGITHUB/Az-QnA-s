#include<bits/stdc++.h>
using namespace std;
void solve(){
    int arr[6];
    for(int i=0;i<6;i++){
        cin>>arr[i];
    }
    int top=arr[0];
    int front=arr[1];
    int bottom=arr[5];
    int frontL=arr[3];
    int frontR=arr[2];
    int back=arr[4];
    string s;
    cin>>s;
    // cout<<s<<endl;
    for(int i=0;i<s.length();i++){
        char direction=s[i];
        if(direction=='N'){
            int temp=top;
            top=front;
            front=bottom;
            bottom=back;
            back=temp;
        }
        else if(direction=='S'){
            int temp=top;
            top=back;
            back=bottom;
            bottom=front;
            front=temp;
        }
        else if(direction=='E'){
            int temp=top;
            top=frontL;
            frontL=bottom;
            bottom=frontR;
            frontR=temp;
        }
        else{
            int temp=top;
            top=frontR;
            frontR=bottom;
            bottom=frontL;
            frontL=temp;
        }
    }
    cout<<top<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}