#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

//find the maximum frequency in the frequency array
int findMax(vector<int>& a) {
    int maxc = -1;
    for (int i = 0; i < 256; i++) {
      maxc = max(maxc, a[i]);
    }
    return maxc;
}

int characterReplacement(string s, int k) {
    int n = s.size();

    //Frequency of every ASCII character
    vector<int> f(256, 0);

    int low = 0;
    int high = 0;
    int res = 0;
    for (high = 0; high < n; high++) {

        //Add the current character to the window
        f[s[high]]++;

        //Most frequent character in the current window
        int maxcnt = findMax(f);

        //Current window length
        int len = high - low + 1;

        //Characters that needs to be replaced
        int diff = len - maxcnt;

        //if replacements required are more than k,
        //shrink the window from the left
        while (diff > k) {
            f[s[low]]--;
            low++;

            //Recalculate after shrinking
            maxcnt = findMax(f);
            len = high - low + 1;
            diff = len - maxcnt;
        }
        //Update anaswer 
        len = high - low + 1;
        res = max(res, len);
    }
    return res;
}

int main() {
    string s = "AABABBA";
    int k = 1;

    cout << "Longest substring length = "
         << characterReplacement(s, k) << endl;

         return 0;
}