#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int one = 0, zero = 0;
        for (auto s : students)
        {
            if (s % 2)
                one++;
            else
                zero++;
        }
        for (auto s : sandwiches)
        {
            if (s == 1 && one)
                one--;
            else if (s == 1)
                break;
            else if (s == 0 && zero)
                zero--;
            else
                break;
        }
        return one + zero;
    }
};

int main()
{
    return 0;
}