#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
    public:
      bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for(int i = 0; i < n; i++) 
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') 
            {
                st.push(s[i]);
            }
            else{
                if(st.empty()) {
                    return false;
                }

                if(s[i] == ')' && st.top() == '(') {
                    st.pop();
                }
                else if(s[i] == ']' && st.top() == '[') {
                    st.pop();
                }
                else if(s[i] == '}' && st.top() == '{') {
                    st.pop();
                }
                
                else {
                    return false;
                }
            }
        }
        return st.empty();
      }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter parentheses: ";
    cin >> s;

    if(obj.isValid(s)) {
        cout << "Valid Parentheses" << endl;
    }
    else {
        cout << "Invalid Parentheses" << endl;
    }

    return 0;
}