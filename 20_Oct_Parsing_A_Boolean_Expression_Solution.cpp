#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve_not(int &ind, int n, string &e){
        ind++;
        int t = 0, f = 0;
        while(e[ind] != ')'){
            char c = e[ind];
            if(c == '!' || c == '|' || c == '&') (solve(e,ind))?t++:f++;
            else if(c == 't') t++;
            else if(c == 'f') f++;
            ind++;
        }
        if(t) return false;
        else return true;
    }
    bool solve_and(int &ind, int n, string &e){
        ind++;
        int t = 0, f = 0;
        while(e[ind] != ')'){
            char c = e[ind];
            if(c == '!' || c == '|' || c == '&') (solve(e,ind))?t++:f++;
            else if(c == 't') t++;
            else if(c == 'f') f++;
            ind++;
        }
        if(f) return false;
        else return true;
    }
    bool solve_or(int &ind, int n, string &e){
        ind++;
        int t = 0, f = 0;
        while(e[ind] != ')'){
            char c = e[ind];
            if(c == '!' || c == '|' || c == '&') (solve(e,ind))?t++:f++;
            else if(c == 't') t++;
            else if(c == 'f') f++;
            ind++;
        }
        if(t) return true;
        else return false;
    }
    bool solve(string &e, int &ind){
        int n = e.size();
        if(n == 0) return true;
        if(e[ind] == '!') return solve_not(++ind,n,e);
        if(e[ind] == '|') return solve_or(++ind,n,e);
        return solve_and(++ind,n,e);
    }
    bool parseBoolExpr(string e) {
        int ind = 0;
        return solve(e,ind);
    }
};

int main(){
    return 0;
}