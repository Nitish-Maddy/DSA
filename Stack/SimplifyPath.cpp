#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

class Solution {
    public:
       string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string dir;

        while(getline(ss, dir, '/'))
        {
            if(dir == "" || dir == ".") {
                continue;
            }

            if(dir == "..") {
                if(!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(dir);
            }
        }

        string res = "";

        while(!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }

        if(res == "") {
            return "/";
        }

        return res;

     }
};

int main() {
    Solution sol;

    string path = "/home//user/../documents/";
    cout << sol.simplifyPath(path) << endl;

    return 0;
}