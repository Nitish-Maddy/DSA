// Count triplets whose sum is strictly less than sum
// Strictly less than" means: currentSum < sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tripletsWithSmallerSum(vector<int>& arr, int sum) {
    int n = arr.size();
    int count = 0;

    //Step 1: Sort the array
    sort(arr.begin(), arr.end());

    //Step 2: Fix the first element
    for (int i=0; i < n-2; i++)
    {
        int left = i+1;
        int right = n-1;

        //Use the two pointers
        while (left < right) {
            int currentSum = arr[i] + arr[left] + arr[right];

            if (currentSum < sum) {

                //All the elements from the left+1 to right 
                //will also make a valid triplet
                count += right - left;

                left++;
            }
            else {
                right--;
            }
        }
    }
    return count;
}

int main() {
    vector<int> arr = {-2, 0, 1, 3};
    int sum = 2;

    cout << "Number of Triplets = "
         << tripletsWithSmallerSum(arr, sum);

         return 0;
}
