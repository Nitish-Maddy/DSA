#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSubarraySum(vector<int> &arr)
{
    int n = arr.size();
    int bestending = arr[0];
    int ans = arr[0];

    for(int i = 1; i < n; i++)
    {
        int v1 = bestending + arr[i];
        int v2 = arr[i];

        bestending = min(v1, v2);
        ans = min(ans, bestending);
    }
    return ans;
}

int main() {
    vector<int> arr = {3,-4,2,-3,-1,7,-5};
    
    int answer = minSubarraySum(arr);
    cout << "Minimum Subarray sum = " << answer <<endl;
    return 0;
}