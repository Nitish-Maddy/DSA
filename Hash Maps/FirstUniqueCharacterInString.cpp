#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
         int firstUniqChar(string s) {
            int n = s.size();
            unordered_map<char, int> f;
            int i;

            //Step1: Count the frequency of each character
            for(i = 0; i < n; i++){
                f[s[i]]++;
            }

            //Step2: find the first non-repeating character
            for( i = 0; i < n; i++) {
                if(f[s[i]] == 1) {
                    return i;
                }
            } 

            //Step3: no unique character exists
            return -1;
         }
};

int main() {
    Solution sol;

    string s = "loveleetcode";
    cout << sol.firstUniqChar(s) << endl;

    return 0;
}