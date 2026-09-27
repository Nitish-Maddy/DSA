#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maximumSum(vector<int>& arr) {
    int n = arr.size();

    //Maximum sum ending at current index without deletion
    int noDel = arr[0];
    //Maximum sum ending at current index with one deletion
    int oneDel = INT_MIN;

    int res = arr[0];

    for (int i=1; i<n; i++)
    {
        //Saves previous values before updating
        int prevNoDel = noDel;
        int prevOneDel = oneDel;

        //Case1: we donot delete anything 
        noDel = max(arr[i], noDel + arr[i]);
        //Case2 : we delete one element
        int v2;
        if(prevOneDel == INT_MIN)
        {
          //No previous deletion was possible
          v2 = arr[i];
        }
        else {
            //Continue a subarray where a element was already deleted
            v2 = prevOneDel + arr[i];
        }
        //Either:
        // 1. Delete current element -> prevNoDel
        // 2. Already delete one element earlier -> v2;
        oneDel = max(v2, prevNoDel);

        //update Answer
        res = max(res, max(noDel, oneDel));
    }
    return res;
}

int main() {
    vector<int> arr = {1, -2, 0, 3};
    int answer = maximumSum(arr);
    cout << "Maximum sum with one deletion = " << answer << endl;
    return 0; 
}