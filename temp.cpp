#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
        int size = nums.size();
        vector<int> prefix(size, 0);

        // Preprocess to fill the prefix array
        for (int i = 1; i < size; ++i) {
            prefix[i] = prefix[i - 1] + (nums[i] % 2 == nums[i - 1] % 2);
        }

        vector<bool> ans;
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            // Check if the subarray nums[l..r] is special
            if (l == r) {
                ans.push_back(true); // A single element subarray is always special
            } else {
                bool subarraySpecial = (prefix[r] - prefix[l]) == 0;
                ans.push_back(subarraySpecial);
            }
        }

        return ans;
    }
};
int main()

{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}