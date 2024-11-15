#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0, j = n - 1;
        while (i < n - 1 && arr[i] <= arr[i + 1])
            i++;
        while (j > 0 && arr[j - 1] <= arr[j])
            j--;
        if (i >= j)
            return 0;
        int rem = min(n - i - 1, j);
        for (int x = 0, y = j; x <= i && y < n;)
        {
            if (arr[x] <= arr[y])
            {
                rem = min(rem, y - x - 1);
                x++;
            }
            else
                y++;
        }
        return rem;
    }
};

int main()
{
    return 0;
}