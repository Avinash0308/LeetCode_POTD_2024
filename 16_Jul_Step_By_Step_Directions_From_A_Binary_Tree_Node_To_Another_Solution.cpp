#include <bits/stdc++.h>
using namespace std;

/*
 Definition for a binary tree node.
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    void solve(TreeNode *root, int start, int dest, string &cur, string &ans, int &reverse, int &one, int &two, char last)
    {
        if (!root)
            return;
        if (root->val == start)
        {
            one = 1;
            if (two == 0)
            {
                cur.push_back('L');
                solve(root->left, start, dest, cur, ans, reverse, one, two, 'L');
                if (two)
                    return;
                cur.pop_back();
                cur.push_back('R');
                solve(root->right, start, dest, cur, ans, reverse, one, two, 'R');
                if (two)
                    return;
                cur.pop_back();
                cur.push_back('U');
                return;
            }
            else
            {
                ans = cur;
                return;
            }
        }
        else if (root->val != dest)
        {
            if (one || two)
            {
                if (one)
                    cur.push_back('L');
                else
                    cur.push_back('U');
                solve(root->left, start, dest, cur, ans, reverse, one, two, 'L');
                if (one && two)
                    return;
                cur.pop_back();
                if (one)
                    cur.push_back('R');
                else
                    cur.push_back('U');
                solve(root->right, start, dest, cur, ans, reverse, one, two, 'R');
                if (one && two)
                    return;
                cur.pop_back();
                return;
            }
            else
            {
                solve(root->left, start, dest, cur, ans, reverse, one, two, 'L');
                if (one && two)
                    return;
                if (one || two)
                {
                    if (one)
                        cur.push_back('R');
                    else
                        cur.push_back('U');
                    solve(root->right, start, dest, cur, ans, reverse, one, two, 'R');
                    if (one && two)
                        return;
                    cur.pop_back();
                    if (one)
                        cur.push_back('U');
                    else
                        cur.push_back(last);
                    return;
                }
                else
                {
                    solve(root->right, start, dest, cur, ans, reverse, one, two, 'R');
                    if (one && two)
                        return;
                    if (one || two)
                    {
                        if (one)
                            cur.push_back('U');
                        else
                            cur.push_back(last);
                        return;
                    }
                    else
                        return;
                }
            }
        }
        else
        {
            two = 1;
            if (one == 0)
            {
                reverse = 1;
                cur.push_back('U');
                solve(root->left, start, dest, cur, ans, reverse, one, two, 'L');
                if (one)
                    return;
                cur.pop_back();
                cur.push_back('U');
                solve(root->right, start, dest, cur, ans, reverse, one, two, 'R');
                if (one)
                    return;
                cur.pop_back();
                cur.push_back(last);
                return;
            }
            else
            {
                ans = cur;
                return;
            }
        }
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string ans = "", cur = "";
        int revers = 0, found_one = 0, found_two = 0;
        solve(root, startValue, destValue, cur, ans, revers, found_one, found_two, 'L');
        if (revers)
            reverse(ans.begin(), ans.end());
        return ans;
    }
};