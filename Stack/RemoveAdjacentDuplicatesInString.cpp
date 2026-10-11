#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    public:
      string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> st;

        for(int i=0; i<n; i++) 
        {
            char c = s[i];

            if(st.empty()) {
                st.push({c, 1});
                continue;
            }

            if(st.top().first != c) {
                st.push({c, 1});
                continue;
            }

            if(st.top().second < k-1) {
                pair<char, int> p = st.top();
                st.pop();
                st.push({p.first, p.second + 1});
            }
            else{
                st.pop();
            }
        }

        string res = "";

        while(!st.empty()) {
            pair<char, int> p = st.top();
            st.pop();

            while(p.second--) {
                res.push_back(p.first);
            }
        }

        reverse(res.begin(), res.end());

        return res;
      }
};

int main() {
    Solution obj;

    string s = "deeedbbcccbdaa";
    int k = 3;

    cout << obj.removeDuplicates(s, k) << endl;
    return 0;
}