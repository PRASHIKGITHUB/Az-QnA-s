#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word2.length();
        int m = word1.length();
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[word2[i]]++;
        }
        lli ans = 0;
        int requiredWord = mp.size();
        int fullfilled = 0;
        int head = -1;
        int tail = 0;
        while (tail < m) {
            while (head + 1 < m && fullfilled != requiredWord) {
                head++;
                if (mp.count(word1[head])) {
                    mp[word1[head]]--;
                    if (mp[word1[head]] == 0) {
                        fullfilled++;
                    }
                }
            }
            if (fullfilled == requiredWord) {
                ans += (m - head);
            }

            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
                if (mp.count(word1[tail])) {
                    mp[word1[tail]]++;
                    if (mp[word1[tail]] == 1) {
                        fullfilled--;
                    }
                }
                tail++;
            }
        }
        return ans;
    }
};