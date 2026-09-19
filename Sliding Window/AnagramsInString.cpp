#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (p.size() > s.size())
        return ans;
        
        vector<int> need(26,0);
        vector<int> have(26,0);

        // Frequency of character required from p
        for (char ch : p) {
            need[ch - 'a']++;
        }

        int low = 0;
        int high = 0;

        while (high < s.size()) {
            //Add s[high] to current window
            have[s[high] - 'a']++;

            //If window size become p.size()
            if (high - low + 1 == p.size()) {
                //Cirrent window is an anagram of p
                if (have == need) {
                    ans.push_back(low);
                }

                //Remove s[low] before moving the window
                have[s[low] - 'a']--;
                low++;
            }
            high++;
        }
        return ans;
    }
};

int main() {
    string s = "cbaebabacd";
    string p = "abc";

    Solution obj;

    vector<int> result = obj.findAnagrams(s, p);
    cout << "Anagram starting indices:  ";

    for (int index : result) {
        cout << index << "";
    }
    cout << endl;
    return 0;
}