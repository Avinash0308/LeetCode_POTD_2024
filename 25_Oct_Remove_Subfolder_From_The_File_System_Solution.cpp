#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        unordered_map<string, int> mp;
        sort(folder.begin(), folder.end());
        vector<string> ans;
        for (auto i : folder)
        {
            string cur = "";
            bool pos = true;
            for (int j = 0; j < i.size(); j++)
            {
                cur += i[j];
                while (j + 1 < i.size() && i[j + 1] != '/')
                {
                    cur += i[j + 1];
                    j++;
                }
                if (mp.count(cur) != 0)
                {
                    pos = false;
                    break;
                }
            }
            if (pos)
            {
                mp[i] = 1;
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}