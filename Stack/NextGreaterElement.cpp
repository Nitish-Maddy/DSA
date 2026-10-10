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
 * - Use a Monotonic Stack (storing elements in decreasing order).
 * - Since the array is circular, we can simulate traversing the array twice by running
 *   a loop from index (2 * n - 1) down to 0, using modulo arithmetic (i % n).
 * - For each element nums[i % n]:
 *   1. Pop elements from the stack that are smaller than or equal to nums[i % n],
 *      because they cannot be the next greater element for the current or preceding elements.
 *   2. If i < n (we are in the first pass where actual results are recorded):
 *      - If the stack is empty, no greater element exists in the circular array -> res[i] = -1.
 *      - Otherwise, the element at the top of the stack is the next greater element -> res[i] = st.top().
 *   3. Push the current element nums[i % n] onto the stack.
 *
 * Complexity:
 * - Time Complexity: O(n), each element is pushed and popped at most twice.
 * - Space Complexity: O(n), for the stack and the result vector.
 */

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();

    stack<int> st;       // Monotonic decreasing stack to store potential next greater elements
    vector<int> res(n);  // Stores the next greater element for each index

    // Traverse the array twice (from 2*n - 1 down to 0) to simulate circular array behavior
    for (int i = 2 * n - 1; i >= 0; i--) {
        // Remove elements that are smaller than or equal to current element
        // as they cannot be the next greater element
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }

        // Only populate result for the first pass (actual indices 0 to n - 1)
        if (i < n) {
            if (st.empty()) {
                res[i] = -1;  // No greater element found
            } else {
                res[i] = st.top();  // Top of stack is the next greater element
            }
        }

        // Push current element onto the stack for upcoming comparisons
        st.push(nums[i % n]);
    }

    return res;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Find the next greater elements for the circular array
    vector<int> res = nextGreaterElements(nums);

    // Display the results
    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }

    cout << endl;
    return 0;
}
