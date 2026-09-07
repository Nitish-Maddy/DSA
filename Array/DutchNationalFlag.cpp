#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {

            //If current element is 0, swap it with the element at low pointer and move both pointers forward
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            //If current element is 1, just move the mid pointer forward
            else if (nums[mid] == 1) {
                mid++;
            }

            //If current element is 2, swap it with the element at high pointer and move the high pointer backward
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution obj;
    obj.sortColors(nums);

    cout << "Sorted array: ";

    for (int x : nums) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}