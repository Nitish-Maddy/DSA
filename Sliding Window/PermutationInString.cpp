#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        //If s1 is bigger than s2,
        //permutation of s1 can never fit inside s2.
        if(n > m) {
            return false;
        }

        //count1 = frequency of characters in s1
        //count2 = frequency of characters in current window of s2
        int count1[26] = {0};
        int count2[26] = {0};

        //Store frequency of every character of s1
        for (int i = 0; i < n; i++) {
            count1[s1[i] - 'a']++;
        }

        //low and high represent our sliding window
        int high = 0;
        int low = 0;

        //First create a window of size n
        while (high < n) {
          count2[s2[high] - 'a']++;
          high++;
        }

        //Now slide the window through s2
        while (high < m) {

            //compare count1 and count2
            bool same = true;

            for (int i = 0; i < 26; i++) {
                if (count1[i] != count2[i]) {
                    same = false;
                    break;
                }
            }

            //if frequencies are same,
            //current window is a permutation of s1.
            if(same) {
                return true;
            }

            //Remove the character at low
            count2[s2[low] - 'a']--;
            low++;

            //Add the new character at high
            count2[s2[high] - 'a']++;
            high++; 
        }

        //Check the final window
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    string s1 = "ab";
    string s2 = "eidbaooo";

    bool answer = obj.checkInclusion(s1, s2);

    if (answer) {
        cout << "true" << endl;
    }
    else {
        cout << "Flase" << endl;
    }
    return 0;
}