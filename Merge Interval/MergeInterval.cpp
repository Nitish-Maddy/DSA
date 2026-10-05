#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& a) {
    vector<vector<int>> res;

    int n = a.size();

    //Sort interval according to the starting value
    sort(a.begin(), a.end());

    //First interval 
    int start = a[0][0];  //start1
    int end = a[0][1];    //end1

    //Check remaining intervals
    for(int i = 1; i < n; i++)
    {
        int s = a[i][0]; //start2
        int e = a[i][1]; //end2

        //If the current interval overlaps with the previous one
        if(end >= s) //merge
        {
            start = start;
            end = max(end, e);
            continue;
        }

        //No overlap store -> previous interval
        res.push_back({start, end});

        //Start a new interval
        start = s;
        end = e;
    }

    //Store the last interval
    res.push_back({start, end});
    return res;
}

int main() {
        vector<vector<int>> a = { {1,3}, {2,6}, {8,10}, {9,12} };
        vector<vector<int>> res = merge(a);

        cout << "Merged Intervals: \n";

        for(auto interval : res) {
            cout << "[" << interval[0] << " , " << interval[1] << "]\n";
        }
        return 0;
}

