#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
struct monotonic_dequeue{
    deque<int>dq;
    void insert(int x){
        while(!dq.empty() && dq.back()<x){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void remove(int x){
        if(dq.front()==x){
            dq.pop_front();
        }
    }
    int getMax(){
        return dq.front();
    }

};
void solve()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    monotonic_dequeue dq;
    for(int i=0;i<n;i++){
        dq.insert(arr[i]);
        if(i-k>=0){
            dq.remove(arr[i-k]);
        }
        if(i>=k-1){
            cout<<dq.getMax()<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}