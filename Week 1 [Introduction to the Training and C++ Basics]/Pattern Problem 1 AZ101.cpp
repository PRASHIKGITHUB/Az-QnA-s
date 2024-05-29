#include<bits/stdc++.h>
using namespace std;
void solve(){
	int x,y;
	cin>>x>>y;
	for(int i=0;i<3*x+1;i++){
		for(int j=0;j<3*y+1;j++){
			if(i%3==0 || j%3==0){
				cout<<"*";
			}
			else{
				cout<<".";
			}
		}
		cout<<endl;
	}
    
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