#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the number of intervals that contain the query point q
vector<int> getIntervalsCount(const vector<pair<int, int>>& intervals, const vector<int>& queries) {
    int n = intervals.size();
    
    // Arrays to store the start and end points
    vector<int> open, close;
    
    // Fill open and close arrays
    for (auto interval : intervals) {
        open.push_back(interval.first);
        close.push_back(interval.second);
    }
    
    // Sort open and close arrays
    sort(open.begin(), open.end());
    sort(close.begin(), close.end());
    
    vector<int> result;
    
    // Process each query
    for (int q : queries) {
        // Find how many intervals start <= q
        int startCount = upper_bound(open.begin(), open.end(), q) - open.begin();
        
        // Find how many intervals end < q
        int endCount = lower_bound(close.begin(), close.end(), q) - close.begin();
        
        // The number of intervals that contain q is startCount - endCount
        result.push_back(startCount - endCount);
    }
    
    return result;
}

int main() {
    // Example input
    int n = 3; // Number of intervals
    vector<pair<int, int>> intervals = {{1, 5}, {3, 7}, {8, 10}}; // Intervals (L, R)
    vector<int> queries = {4, 6, 9}; // Queries
    
    // Get the result for each query
    vector<int> result = getIntervalsCount(intervals, queries);
    
    // Output the result
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;
    
    return 0;
}
