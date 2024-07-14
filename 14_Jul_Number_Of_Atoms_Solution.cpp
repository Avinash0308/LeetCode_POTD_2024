#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, int> solve(string &formula, int &ind)
    {
        unordered_map<string, int> mp;
        int n = formula.size();
        if (ind == n)
            return mp;
        while (ind < n && formula[ind] != ')')
        {
            if (formula[ind] >= 'A' && formula[ind] <= 'Z')
            {
                string cur;
                cur.push_back(formula[ind]);
                while (ind + 1 < n && formula[ind + 1] >= 'a' && formula[ind + 1] <= 'z')
                {
                    cur.push_back(formula[ind + 1]);
                    ind++;
                }
                int val = 0;
                while (ind + 1 < n && formula[ind + 1] >= '0' && formula[ind + 1] <= '9')
                {
                    val = val * 10 + formula[ind + 1] - '0';
                    ind++;
                }
                mp[cur] += max(val, 1);
                ind++;
            }
            else
            {
                ind++;
                unordered_map<string, int> sp = solve(formula, ind);
                for (auto i : sp)
                {
                    mp[i.first] += i.second;
                }
            }
        }
        if (ind == n)
            return mp;
        if (formula[ind] == ')')
        {
            int val = 0;
            while (ind + 1 < n && formula[ind + 1] >= '0' && formula[ind + 1] <= '9')
            {
                val = val * 10 + formula[ind + 1] - '0';
                ind++;
            }
            ind++;
            val = max(val, 1);
            for (auto i : mp)
            {
                mp[i.first] = i.second * val;
            }
        }
        return mp;
    }
    string countOfAtoms(string formula)
    {
        int ind = 0;
        unordered_map<string, int> mp = solve(formula, ind);
        vector<pair<string, int>> sp;
        for (auto i : mp)
        {
            sp.push_back({i.first, i.second});
        }
        sort(sp.begin(), sp.end());
        string ans;
        for (auto i : sp)
        {
            ans += i.first;
            if (i.second > 1)
            {
                ans += to_string(i.second);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}