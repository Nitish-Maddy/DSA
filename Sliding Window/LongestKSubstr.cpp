#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestKSubstr(string &s, int k) {
    int low = 0;  //Left side of the window
    int ans = -1;  //Maximum length found so far

    // int res = INT_MIN;   //this code its works but it's unnecessary. 
    // then
    // if (res == INT_MIN) return -1;

    unordered_map<char, int> freq;

    //high expands the window
    for (int high = 0; high < s.size(); high++) {

        // add the current character to the (window) or frequency map
        freq[s[high]]++;

        // if we have more than k distinct characters,
        // we need to shrink the window from the left
        while (freq.size() > k) {

            freq[s[low]]--;

            // if the frequency of the character at low becomes 0,
            // this character is no longer in the window, so we remove it from the map
            if (freq[s[low]] == 0) {
                freq.erase(s[low]);
            }
            low++;
        }

        // if we have exactly k distinct characters, update the answer
        // this is a valid window, so we check if its length is greater than the maximum found so far
        if (freq.size() == k) {
            int len = high - low + 1;
            ans = max(ans, len);
        }
    }
    return ans;
}
int main() {
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter the value of k: ";
    cin >> k;

    int answer = longestKSubstr(s, k);

    cout << "Longest substring with exactly "
         << k << " distinct characters = "
            << answer << endl;

            return 0;
}