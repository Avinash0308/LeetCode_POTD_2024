#include <bits/stdc++.h>
using namespace std;

class MyCalendar
{
    set<pair<int, int>> s;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        if (s.find({start, end - 1}) == s.end())
        {
            s.insert({start, end - 1});
            auto it = s.find({start, end - 1});
            if (it != s.begin())
            {
                it--;
                if ((*it).second >= start)
                {
                    s.erase({start, end - 1});
                    return false;
                }
                it++;
            }
            it++;
            if (it != s.end())
            {
                if ((*it).first < end)
                {
                    s.erase({start, end - 1});
                    return false;
                }
            }
            return true;
        }
        else
            return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main()
{
    return 0;
}