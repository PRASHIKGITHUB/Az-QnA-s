#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
lli m = 1e9 + 7;

void solve() {
    int a, b;
    string s;
    map<int, int> mp;
    int i = 1;
    cin >> a >> b;

    int flag=0;
    if((a*b)<0){
        flag=1;
    }
    a=abs(a);
    b=abs(b);
    int remainder;
    if (a == 0) {
        cout << "0" << endl;
        return;
    }
    int temp;
    if (a % b == 0) {
        if(flag){
            cout <<"-"<<a / b << endl;
        }
        else{
            cout<<a/b<<endl;
        }
        
        return;
    } else {
        s += to_string(a / b);
        temp=s.length();
        s += '.';
        remainder = a % b;
        
        while (remainder != 0 && mp.find(remainder) == mp.end()) {
            mp[remainder] = i++;
            remainder *= 10;
            s += to_string(remainder / b);
            remainder = remainder % b;
        }
    }
    
    if (flag) {
        //number is negative
        if(remainder==0){
            cout << "-" << s << endl;
        }
        else{
            int stBraces=mp[remainder];
            int endBraces=i;
            cout<<"-";
            for(int pos=0;pos<s.length();pos++){
                
                if(pos-temp==stBraces){
                    cout<<"("<<s[pos];
                }
                else{
                    cout<<s[pos];
                }
            }
            cout<<')'<<endl;
        }
        
        
    } else {
        if(remainder==0){
            cout << s << endl;
        }
        else{
            int stBraces=mp[remainder];
            int endBraces=i;
            for(int pos=0;pos<s.length();pos++){
                
                if(pos-temp==stBraces){
                    cout<<"("<<s[pos];
                }
                else{
                    cout<<s[pos];
                }
            }
            cout<<')'<<endl;
        }
           
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}