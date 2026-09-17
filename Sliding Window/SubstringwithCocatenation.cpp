#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
    vector<int> findSubstring(string s, vector<string>& words) {
     vector<int> ans;
     int n = s.size();
     int wordLen = words[0].size();
     int wordCount = words.size();

     //Store how many times each word is required
     unordered_map<string, int> need;

     // Count required words
      for(string word: words) {
        need[word]++;
      }

      for (int start = 0; start < wordLen; start++) {
        int low = start;
        int high = start;

        unordered_map<string, int> have;

        int count = 0;

        while (high + wordLen <= n) {

            //Take one word from s
            string word = s.substr(high, wordLen);

            high += wordLen;

            //  If this word is not present in words,
            // start a completely new window
            if (need.find(word) == need.end()) {

                have.clear();
                count = 0;
                low = high;

                continue;
            }

            //Add this word to current window
            have[word]++;
            count++;

            //Too many copies of this word
            while (have[word] > need[word]) {
                string leftWord = s.substr(low, wordLen);

                have[leftWord]--;
                low += wordLen;
                count--;
            }

            //All the required words found
            if (count == wordCount) {
                ans.push_back(low);
                    
                //Move window forward by one word
                //remove the first word
                string leftWord = s.substr(low, wordLen);

                have[leftWord]--;
                low += wordLen;
                count--;
            }
        }
      }
      return ans;
    }
};

int main () {
    Solution obj;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> ans = obj.findSubstring(s, words);

    for(int x : ans) {
        cout << x << " ";
    }
    return 0;
}