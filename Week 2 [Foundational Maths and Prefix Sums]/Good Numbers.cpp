#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    int arr[1000000+1]={0};
    int arr[1000000+2]={0};
    

    // Building suffix sum array
    for (int i = 1; i <=n; i++) {
        int l, r;
        cin >> l >> r;
        arr[l] = arr[l] + 1;
        if (r + 1 <= 1000000) {
            arr[r + 1]--;
        }
    }
    // for(int i=1;i<=1000000;i++){
    //     cout<<arr[i]<<" ";
    // }

    // Building prefix sum array
    for (int i = 2; i <= 1000000; i++) {
        arr[i] = arr[i - 1] + arr[i];
    }
    // cout<<"printing prefix"<<endl;
    // for (int i = 1; i <= 1000000; i++) {
    //     cout<<arr[i]<<" ";
    // }

    int count[1000001]={0};
    if(arr[1]>=k){
        count[1]=1;
    }
    for(int i=2;i<=1000000;i++){
        if(arr[i]>=k){
            count[i]=count[i-1]+1;
        }
        else{
            count[i]=count[i-1];
        }
    }
    // cout<<"printing count"<<endl;
    // for(int i=1;i<=1000000;i++){
    //     cout<<count[i]<<" ";
    // }
    cout<<endl;
    // q queries
    while (q--) {
        int L, R;
        cin >> L >> R;
        // int ans = 0;
        // for (int i = L; i <= R; i++) {
        //     if (arr[i] >= k) {
        //         ans += 1;m
        //     }
        // }
        // cout<<ans<<endl;
        if(L==1){
            cout<<count[R]<<endl;
        }
        else{
            cout<<count[R]-count[L-1]<<endl;
        }
        
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}