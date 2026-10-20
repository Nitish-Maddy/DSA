#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int maxNumberOfBalloons(string s) {
     int n = s.size();
     unordered_map<char, int> have;

     //Count the frequency of every character in s
     for(int i = 0; i < n; i++) {
        have[s[i]]++;
     }

     //Required frequency to make "balloon"
     unordered_map<char, int> need;
     need['b'] = 1;
     need['a'] = 1;
     need['l'] = 2;
     need['o'] = 2;
     need['n'] = 1;
    
     int res = INT_MAX;

     //Find how many complete "balloon" word we can make
     for(auto i : need) {
     char c = i.first;
     int fneed = i.second;
     int fhave = have[c];
     int times = fhave/fneed;
     res = min(res, times);
     }
     
     return res;

    }
};

int main() {
    Solution obj;
    cout << obj.maxNumberOfBalloons("loonbalxballpoon") << endl;
    return 0;
}