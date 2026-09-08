// #include <iostream>
// #include <string>
// #include <unordered_map>
// #include <algorithm>

#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits) {
    unordered_map<int, int> freq;

    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < fruits.size(); right++) {

        freq[fruits[right]]++;  //Add the current fruit to the frequency map(window)

        //If we have more than 2 distinct fruits, we need to shrink the window from the left
        while (freq.size() > 2) {
            freq[fruits[left]]--;

            //If the frequency of the fruit at left becomes 0, we remove it from the map
            if (freq[fruits[left]] == 0) {
                freq.erase(fruits[left]);
            }
            left++;
        }
        //Current window size is (right - left + 1), we update maxLen if this window is larger
        int len = right - left + 1;
        maxLen = max(maxLen, len);  //Update the maximum length found so far
    }
    return maxLen;
}

int main() {
    vector<int> fruits = {1, 2, 1, 2, 3, 2, 2};  //Example input
    int answer = totalFruit(fruits);
    cout << "Maximum fruits = " << answer << endl;
    return 0;
}
