#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 * Problem: Next Greater Element II (LeetCode 503)
 *
 * Description:
 * Given a circular integer array 'nums' (i.e., the next element of nums[n - 1] is nums[0]),
 * return the next greater number for every element in nums.
 *
 * The next greater number of a number x is the first greater number to its traversing-order
 * next in the array, searching circularly. If it does not exist, return -1 for this number.
 *
 * Approach:
 * - Use a Monotonic Stack (storing elements in strictly decreasing order).
 * - To handle the circular nature of the array:
 *   1. Pre-fill the stack with elements from index (n - 2) down to 0.
 *      This simulates the circular wrap-around by placing candidates to the right of nums[n - 1].
 *   2. Iterate from the last element (n - 1) down to 0:
 *      - Pop elements from the stack that are less than or equal to nums[i],
 *        as they cannot be the next greater element.
 *      - If the stack is empty, no greater element exists in the circular array -> res[i] = -1.
 *      - Otherwise, the top of the stack is the next greater element -> res[i] = st.top().
 *      - Push nums[i] onto the stack so it can serve as a candidate for preceding elements.
 *
 * Complexity:
 * - Time Complexity: O(n), each element is pushed and popped at most a constant number of times.
 * - Space Complexity: O(n), for the stack and the result vector.
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;

        // Pre-populate the stack with elements from index (n - 2) down to 0
        // to handle the circular array condition (elements wrap around to the beginning)
        for (int i = n - 2; i >= 0; i--) {
            st.push(nums[i]);
        }

        // Traverse the array from right to left (n - 1 down to 0) to compute answers
        for (int i = n - 1; i >= 0; i--) {
            // Remove elements from the stack that are smaller than or equal to current element
            // because they cannot be the next greater element
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // If stack is empty, no greater element exists in the circular array
            if (st.empty()) {
                res[i] = -1;
            } else {
                // Top of the stack is the next greater element
                res[i] = st.top();
            }

            // Push current element onto the stack for upcoming comparisons
            st.push(nums[i]);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 3};

    // Find the next greater elements for the circular array
    vector<int> ans = sol.nextGreaterElements(nums);

    // Display the results
    cout << "Next Greater Elements: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
