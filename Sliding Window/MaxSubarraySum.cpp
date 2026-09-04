#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySum(vector<int>& arr, int k) {
    int n = arr.size();

    //If array has fewer than k elements
    if (n < k) {
        return 0;
    }
    int sum = 0;

    //Calculate the sum of the first window
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    int maxSum = sum;

    //Slide the window
    for (int i = k; i < n; i++) {
        sum += arr[i];        //Add new element
        sum -= arr[i - k];    //Remove old element

        maxSum = max(maxSum, sum);    //Update maxSum if current sum is greater
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    cout<< "Maximum subarrary sum = "
        << maxSubarraySum(arr, k) << endl;

        return 0;
}