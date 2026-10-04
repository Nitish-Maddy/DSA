#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem: Count of Range Sum (LeetCode 327)
 *
 * Goal: Given an integer array nums and two integers lower and upper, return the
 *       number of range sums S(i, j) = sum(nums[i...j]) that lie in [lower, upper] inclusive.
 *
 * Core Concept:
 * 1. Prefix Sum Representation:
 *    Let prefix[k] = sum(nums[0...k-1]) with prefix[0] = 0.
 *    Any subarray sum from index i to j is:
 *        sum(nums[i...j]) = prefix[j + 1] - prefix[i]
 *    We need to count pairs (i, j+1) where i < j+1 such that:
 *        lower <= prefix[j + 1] - prefix[i] <= upper
 *
 * 2. Divide and Conquer (Merge Sort):
 *    This problem reduces to counting pairs (l, r) with l < r such that:
 *        lower <= prefix[r] - prefix[l] <= upper
 *    This is similar to counting inversions using Merge Sort.
 *    - In mergeSort(prefix, low, high):
 *        - Left half: [low, mid]
 *        - Right half: [mid + 1, high]
 *    - Recursively count valid pairs within the left half and right half.
 *    - Count "cross pairs" where left index i is in [low, mid] and right index is in [mid + 1, high].
 *    - Because both left and right halves are already sorted, we can use two pointers (j and k)
 *      in O(n) to find all valid right indices for each left index i.
 *    - Finally, merge the two sorted halves so the array remains sorted for parent calls.
 *
 * Time Complexity:  O(N log N)
 * Space Complexity: O(N) for prefix sums and temporary merge array
 */

class Solution {
    public:
        // Helper function: Counts valid pairs and sorts prefix[low...high]
        long long mergeSort(vector<long long>& prefix, int low, int high, int lower, int upper) {
            // Base Case: A single element or empty range cannot form a pair (l < r requires at least 2 elements)
            if (low >= high) {
                return 0;
            }

            int mid = low + (high - low) / 2;
            long long count = 0;

            // Step 1: Count valid pairs completely within the left half [low, mid]
            count += mergeSort(prefix, low, mid, lower, upper);

            // Step 2: Count valid pairs completely within the right half [mid + 1, high]
            count += mergeSort(prefix, mid + 1, high, lower, upper);

            // Step 3: Count "cross pairs" where index i is in left half and index is in right half
            // At this point, both prefix[low...mid] and prefix[mid+1...high] are independently sorted.
            // For a fixed i in [low, mid], we want to find all indices in [mid+1, high] such that:
            // lower <= prefix[index] - prefix[i] <= upper
            //
            // We maintain two pointers in the right half:
            //   - j: first index where prefix[j] - prefix[i] >= lower
            //   - k: first index where prefix[k] - prefix[i] > upper
            // Any index in [j, k - 1] satisfies the condition, so there are (k - j) valid pairs for this i.
            // Since prefix[low...mid] is sorted, as prefix[i] increases, prefix[i] + lower and prefix[i] + upper
            // also increase, so j and k only move forward across the entire loop (O(N) total for counting).
            int j = mid + 1;
            int k = mid + 1;

            for (int i = low; i <= mid; i++) {
                // Advance j until prefix[j] - prefix[i] >= lower
                while (j <= high && prefix[j] - prefix[i] < lower) {
                    j++;
                }
                // Advance k until prefix[k] - prefix[i] > upper
                while (k <= high && prefix[k] - prefix[i] <= upper) {
                    k++;
                }

                // All indices from j to k-1 are valid right endpoints for the current prefix[i]
                count += (k - j);
            }

            // Step 4: Standard Merge step of Merge Sort
            // Merge two sorted subarrays [low, mid] and [mid + 1, high] into sorted order
            vector<long long> temp;
            int left = low;
            int right = mid + 1;

            while (left <= mid && right <= high) {
                if (prefix[left] <= prefix[right]) {
                    temp.push_back(prefix[left]);
                    left++;
                } else {
                    temp.push_back(prefix[right]);
                    right++;
                }
            }

            // Append remaining elements from the left subarray (if any)
            while (left <= mid) {
                temp.push_back(prefix[left]);
                left++;
            }

            // Append remaining elements from the right subarray (if any)
            while (right <= high) {
                temp.push_back(prefix[right]);
                right++;
            }

            // Copy the merged elements back into the original prefix array
            for (int i = low; i <= high; i++) {
                prefix[i] = temp[i - low];
            }

            return count;
        }

        long long countRangeSum(vector<int>& nums, int lower, int upper) {
            int n = nums.size();

            // Create prefix sum array of size n + 1.
            // Use long long to prevent integer overflow from large element sums.
            // prefix[0] = 0 represents the sum before any elements (empty prefix),
            // which allows subarrays starting at index 0 to be represented as prefix[j+1] - prefix[0].
            vector<long long> prefix(n + 1, 0);

            for (int i = 0; i < n; i++) {
                prefix[i + 1] = prefix[i] + nums[i];
            }

            // Count pairs in prefix[0...n] using modified merge sort
            return mergeSort(prefix, 0, n, lower, upper);
        }
};

int main() {
    Solution s;
    // Example: nums = [-2, 5, -1], lower = -2, upper = 2
    // Subarrays with sum in [-2, 2]:
    //   nums[0..0] = -2   (valid)
    //   nums[2..2] = -1   (valid)
    //   nums[0..2] =  2   (valid)
    // Expected output: 3
    vector<int> nums = {-2, 5, -1};
    int lower = -2;
    int upper = 2;
    cout << s.countRangeSum(nums, lower, upper) << endl;
    return 0;
}

