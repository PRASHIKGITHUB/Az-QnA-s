#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDecodings(const string &s) {
    int n = s.length();
    if (n == 0 || s[0] == '0') return 0;

    // dp[i] will store the number of ways to decode the string up to the i-th character.
    vector<long long> dp(n + 1, 0);

    dp[0] = 1;  // Base case: an empty string has one way to decode (doing nothing)
    dp[1] = 1;  // Base case: one way to decode if the string doesn't start with '0'

    for (int i = 2; i <= n; i++) {
        // Check if single digit decoding is possible (i.e., '1' to '9')
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }

        // Check if two-digit decoding is possible (i.e., '10' to '26')
        int twoDigit = stoi(s.substr(i - 2, 2));
        // int t=stoi(s.substr(i-1,2))
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

int main() {
    string s;
    cin>>s;
    cout << numDecodings(s) << endl;
    return 0;
}
