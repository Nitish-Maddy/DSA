#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
      int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char, int> f;

        //Count the frequency of each character
        for(int i = 0; i < n; i++) {
            f[s[i]]++;
        }

        bool odd = false;
        int res = 0;

        //Add frequencies that are even 
        for(auto i : f) {
            int val = i.second;

            if(val % 2 == 0) {
                res += val;
            } else {
               odd = true;
            }
        }

        // One character with odd frequency can occupy the center
        return res + 1;
      }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Longest palindrome length: "
         << sol.longestPalindrome(s) << endl;

    return 0;     
}