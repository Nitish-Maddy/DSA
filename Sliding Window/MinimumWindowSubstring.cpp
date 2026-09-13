#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
     bool fun(vector<int> &have, vector<int> &need)
     {
        for (int i=0; i<256; i++)
        {
            if(have[i] < need[i])
            return false;
        }
        return true;
     }

     string minWindow(string s, string t)
     {
        int n = s.size();
        int m = t.size();

        vector<int> have(256, 0);
        vector<int> need(256, 0);

        if(n < m)
        return "";

        //Store the frequency of characters required from t
        for(int i=0; i<m; i++)
        {
            need[t[i]]++;
        } 

        int low = 0;
        int high = 0;

        int res = INT_MAX;
        int start = -1;

        for (high = 0; high < n; high++)
        {
            //Add current character to window
            have[s[high]]++;

            //while current window contains all required characters
            while(fun(have, need))
            {
                int len = high - low + 1;
                //Save the smallest valid window
                if(res > len)
                {
                    res = len;
                    start = low;
                }
                //Remove the left character and shrink window
                have[s[low]]--;
                low++;
            }
        }
        // No valid window found
        if(res == INT_MAX)
        return "";

        return s.substr(start,res);

     }
};

int main()
{
    Solution obj;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << obj.minWindow(s, t);

    return 0;
}