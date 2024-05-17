#include <bits/stdc++.h>
using namespace std;
int n;
int previ = -1, prevj = -1;
int grid[3][3];
vector<pair<int, int>> prevPos;
bool check(int i, int j)
{
    if(!prevPos.empty()){
        int size=prevPos.size();
        previ=prevPos[size-1].first;
        prevj=prevPos[size-1].second;
    }
    else{
        return true;
    }

    if(abs(i-previ)==2  &&  abs(j-prevj)==2){//extream end of diagonal
        if(grid[1][1]==1){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(abs(i-previ)==2 && abs(j-prevj)==0){//vertical extream
        if(grid[1][j]==1){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(abs(i-previ)==0 && abs(j-prevj)==2){//horizontal extream
        if(grid[i][1]==1){
            return 1;
        }
        else{
            return 0;
        }
    }

    return 1;
}
int rec(int level)
{
    if (level == n)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == 1)
                continue;
            if (check(i, j))
            {
                grid[i][j] = 1;
                prevPos.push_back({i, j});
                ans += rec(level + 1);
                prevPos.pop_back();
                grid[i][j] = 0;
            }
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int ans;
    ans = rec(0);
    cout << ans << endl;
    return 0;
}