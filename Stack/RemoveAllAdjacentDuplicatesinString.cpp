#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    public:
       string removeDuplicates(string s) {
        int n = s.size();
        stack<char> st;
        int i; 
        string res;

        for(i = 0; i < n; i++)
        {
            if(st.empty()) {
                st.push(s[i]);
                continue;
            }

            if(st.top() == s[i]) {
                st.pop();
                continue;
            }

            st.push(s[i]);
        }

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;

       }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    cout << "String after removing duplicates: "
         << obj.removeDuplicates(s) << endl;

    return 0;
}