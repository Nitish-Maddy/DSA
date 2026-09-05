#include <iostream>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {

    //No positive product can be < 1
    if (k<=1){
     return 0;
    } 

    int left = 0;       //Start of the window
    // int product = 1;   the product of multiple numbers, and that product can become much larger than a normal int can't hold and got overflow and give incorrect answer; int   → about -2.1 billion to +2.1 billion
                    
    long long product = 1; //Product inside window  (long long) to avoid overflow // long long  → about -9.22 quintillion to +9.22 quintillion;

    int ans = 0;  // Total valid subarrays

    //Right expands the window
    for (int right = 0; right < nums.size(); right++) {

        //1.Expand the window by multiplying the new number
        product *= nums[right];

        //2. Shrink if product is too large
        while (product >= k) {
            product /= nums[left];
            left++;
        }

        //3. Count the number of valid subarrays ending at right
        ans += right - left + 1; //The number of valid subarrays ending at right is the length of the window
    }
    return ans;
    
}

int main() {
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout <<  numSubarrayProductLessThanK(nums, k) << endl;

     return 0;
}