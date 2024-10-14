#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>arr;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>first_right_greater;
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() &&  arr[st.top()]<arr[i]){
            st.pop();
        }
        if(st.empty()){
            first_right_greater[i]=n;
        }
        else{
            first_right_greater[i]=st.top();
        }
        st.push(i);
    }
    return 0;
}