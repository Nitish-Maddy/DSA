#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int countTriplets(int sum, vector<int>&arr){
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int ans = 0;

        for( int i = 0; i < n-2; i++){
            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                int currentSum = arr[i] + arr[left] + arr[right];

                if(currentSum > sum) {
                    right--;
                }
                else {
                    ans += (right - left); // ans = ans + (right - left)
                    left++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {5, 1, 3, 4, 2};
    int sum = 10;

    int result = obj.countTriplets(sum, arr);
    cout << "Number of triplets: " << result <<endl;

    return 0;
}