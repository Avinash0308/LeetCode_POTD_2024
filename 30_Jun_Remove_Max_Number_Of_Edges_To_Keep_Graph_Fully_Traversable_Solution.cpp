#include <bits/stdc++.h>
using namespace std;

/* Brute Force
class Solution {
public:
    void dfs(int ind, int n, vector<vector<vector<int>>> &mp, int type, vector<int> &visit){
        visit[ind] = 1;
        for(int i = 1; i<=n; i++){
            if(visit[i] == 0 && (mp[ind][i][type] != 0  || mp[ind][i][3] != 0)){
                dfs(i,n,mp,type,visit);
            }
        }
    }
    bool solve(vector<vector<vector<int>>> &mp, int n){
        vector<int> visit1(n+1);
        vector<int> visit2(n+1);
        dfs(1,n,mp,1,visit1);
        int count = 0;
        for(int i = 1; i<=n; i++){
            if(visit1[i]) count++;
            else break;
        }
        if(count == n){
            dfs(1,n,mp,2,visit2);
            count = 0;
            for(int i = 1; i<=n; i++){
                if(visit2[i]) count++;
                else break;
            }
            if(count == n) return true;
            else return false;
        }
        else{
            return false;
        }
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> mp(n+1,vector<vector<int>>(n+1,vector<int>(4,0)));
        for(auto edge:edges){
            mp[edge[2]][edge[1]][edge[0]] = 1;
            mp[edge[1]][edge[2]][edge[0]] = 1;
        }
        if(!solve(mp,n)) return -1;
        sort(edges.begin(),edges.end());
        int count = 0;
        for(auto edge:edges){
            mp[edge[2]][edge[1]][edge[0]] = 0;
            mp[edge[1]][edge[2]][edge[0]] = 0;
            if(solve(mp,n)){
                count++;
            }
            else{
                mp[edge[2]][edge[1]][edge[0]] = 1;
                mp[edge[1]][edge[2]][edge[0]] = 1;
            }
        }
        return count;
    }
};*/

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        class UnionFind
        {
        public:
            vector<int> parent, size;
            int components;
            UnionFind(int n)
            {
                components = n;
                parent.resize(n + 1);
                size.resize(n + 1, 1);
                for (int i = 0; i <= n; ++i)
                {
                    parent[i] = i;
                }
            }

            int find(int x)
            {
                if (parent[x] != x)
                {
                    parent[x] = find(parent[x]);
                }
                return parent[x];
            }

            bool unite(int x, int y)
            {
                int rootX = find(x), rootY = find(y);
                if (rootX == rootY)
                    return false;
                if (size[rootX] < size[rootY])
                    swap(rootX, rootY);
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                components--;
                return true;
            }

            bool isConnected()
            {
                return components == 1;
            }
        };

        UnionFind alice(n), bob(n);
        int edgesRequired = 0;

        // Process type 3 edges first
        for (const auto &edge : edges)
        {
            if (edge[0] == 3)
            {
                if (alice.unite(edge[1], edge[2]) | bob.unite(edge[1], edge[2]))
                {
                    edgesRequired++;
                }
            }
        }

        // Process type 1 and type 2 edges
        for (const auto &edge : edges)
        {
            if (edge[0] == 1)
            {
                if (alice.unite(edge[1], edge[2]))
                {
                    edgesRequired++;
                }
            }
            else if (edge[0] == 2)
            {
                if (bob.unite(edge[1], edge[2]))
                {
                    edgesRequired++;
                }
            }
        }

        // Check if both are fully connected
        if (alice.isConnected() && bob.isConnected())
        {
            return edges.size() - edgesRequired;
        }

        return -1;
    }
};

int main()
{
    return 0;
}