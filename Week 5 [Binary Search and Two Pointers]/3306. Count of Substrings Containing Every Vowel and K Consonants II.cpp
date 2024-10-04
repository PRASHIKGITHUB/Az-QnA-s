#include <bits/stdc++.h>
using namespace std;
bool is_vovel(char ch)
{

    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
long long countOfSubstrings(string word, int k)
{
    long long ans = 0;
    int n = word.length();
    int head = -1;
    int tail = 0;
    map<char, int> vov;
    vector<int> next_consonant_index(n + 1, n);

    for (int i = n - 2; i >= 0; i--)//crete a vector to store the next consonant index
    {
        if (!is_vovel(word[i + 1]))
        { // a consonant
            next_consonant_index[i] = i + 1;
        }
        else
        {
            next_consonant_index[i] = next_consonant_index[i + 1];
        }
    }
    int vovel_types = 0, consonant_count = 0;
    while (tail < n)
    {
        while (head + 1 < n && (vovel_types < 5 || consonant_count < k))//
        {
            head++;
            if (is_vovel(word[head]))
            {
                vov[word[head]]++;
                if (vov[word[head]] == 1)
                {
                    vovel_types++;
                }
            }
            else
            {
                consonant_count++;
            }
        }
        if (consonant_count == k && vovel_types == 5)
        {
            // find the next consonant
            int temp = next_consonant_index[head];
            ans += (temp - head);//all substrings ending between head and temp are valid
        }
        cout << "tail " << tail << " head " << head << endl;//printing this was causing more time to be taken

        if (tail > head)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            if (is_vovel(word[tail]))
            {
                vov[word[tail]]--;
                if (vov[word[tail]] == 0)
                {
                    vovel_types--;
                }
            }
            else
            {
                consonant_count--;
            }
            tail++;
        }
    }
    return ans;
}

int main()
{
    string s;
    int k;
    cin >> s >> k;
    cout << countOfSubstrings(s, k) << endl;
    return 0;
}