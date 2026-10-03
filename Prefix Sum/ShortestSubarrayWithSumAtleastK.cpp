#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();

    //Prefix Sum
    vector<long long> prefix(n + 1, 0);
    for(int i=0; i<n; i++) {
        prefix[i+1] = prefix[i] + nums[i];
    }
    deque<int> dq;
    int ans = INT_MAX;

    for(int i=0; i<=n; i++) {
        //Condition1: Current Subarray sum >= k
        while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
            ans = min(ans, i-dq.front());
            dq.pop_front();
        }

        //Condition2: Remove useless prefix sums from the back
        while(!dq.empty() && prefix[i] <= prefix[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    if(ans == INT_MAX) {
        return -1;
    }

    return ans;
}

int main() {
    vector<int> nums = {2, -1, 2};
    int k = 3;
    cout << shortestSubarray(nums, k) << endl;
    return 0;
}