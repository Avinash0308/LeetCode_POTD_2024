#include <bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        while (i < n && j < m)
        {
            if (nums1[i] == nums2[j])
                return nums1[i];
            if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return -1;
    }
};
int main()
{

    return 0;
}