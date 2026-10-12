#include <iostream>
#include <string>
using namespace std;

class Solution{
    public:
       string removeKdigits(string num, int k) {
        string st;
        int n = num.size();

        for(int i = 0; i < n; i++)
        {
          while(!st.empty() && k > 0 && st.back() > num[i]) {
            st.pop_back();
            k--;
          }

          st.push_back(num[i]);
        }

        while(!st.empty() && k > 0) {
            st.pop_back();
            k--;
        }

        int i = 0;
        while(i < st.size() && st[i] == '0') {
            i++;
        }

        string res = st.substr(i);

        if(res.empty()) {
            return 0;
        }

        return res;
    }
};

int main() {
    Solution sol;

    string num = "1432219";
    int k = 3;

    cout << sol.removeKdigits(num, k);

    return 0;
}