#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
       vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size();

        stack<int> st;
        vector<int> res(n, 0);
        st.push(n-1);

        for(int i = n - 2; i >= 0; i--) 
        {
            while(!st.empty() && a[st.top()] <= a[i]) {
                st.pop();
            }

            if(st.empty()) {
                res[i] = 0;
            }
            else{
                res[i] = st.top() - i;
            }

            st.push(i);
        }

        return res;
       }
};

int main() {
    Solution obj;

    vector<int> a = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = obj.dailyTemperatures(a);
    cout << "Days to wait for a warmer temperature: ";

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    cout << endl;
    return 0;
}