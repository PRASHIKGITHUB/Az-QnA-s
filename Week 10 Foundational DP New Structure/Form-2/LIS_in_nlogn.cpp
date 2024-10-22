#include<bits/stdc++.h>
using namespace std;
int n;
int arr[101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>lis;
    vector<int>last_inserted_position_length;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(lis.empty() || lis.back()<arr[i]){
            lis.push_back(arr[i]);
            last_inserted_position_length.push_back(lis.size());
        }
        else{
            auto it=lower_bound(lis.begin(),lis.end(), arr[i]);
            *it=arr[i];
            last_inserted_position_length.push_back(it-lis.begin()+1);
        }
        for(auto i:lis){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    cout<<"last_inserted_position_length: "<<endl;
    for(auto i:last_inserted_position_length){
        cout<<i<<" ";
    }

    int len=lis.size();//max length of lis

    //this is for finding the LIS

    vector<int>final_lis;
    for(int i=n-1;i>=0;i--){
        if(last_inserted_position_length[i]==len){
            final_lis.push_back(arr[i]);
            len--;
        }
    }
    reverse(final_lis.begin(),final_lis.end());
    cout<<endl;
    for(auto i:final_lis){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"length: "<<lis.size()<<endl;
    return 0;
}