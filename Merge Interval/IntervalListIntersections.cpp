#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: Interval List Intersections (LeetCode 986)
// Given two lists of closed intervals, each list is pairwise disjoint and sorted by start time.
// Return the intersection of these two interval lists.
//
// Time Complexity: O(n + m) where n and m are the sizes of the two interval lists
// Space Complexity: O(1) auxiliary space (excluding the output result list)

vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
    // a = firstList, b = secondList
    vector<vector<int>> res;

    // Two pointers: i tracks list 'a', j tracks list 'b'
    int i = 0, j = 0;
    int n = a.size();
    int m = b.size();

    // Iterate as long as both lists have intervals left to process
    while( i < n && j < m)
    {
        // Current interval from list 'a'
        int start1 = a[i][0];
        int end1 = a[i][1];

        // Current interval from list 'b'
        int start2 = b[j][0];
        int end2 = b[j][1];

        // Check if interval from 'a' starts before or at the same time as 'b'
        if(start1 <= start2)
        {
            // Overlap exists if 'a' ends after or when 'b' starts
            if(end1 >= start2) {
                int s = max(start1, start2); // Start of intersection is max of start points
                int e = min(end1, end2);     // End of intersection is min of end points
                res.push_back({s, e});
            }
        }
        // Interval from 'b' starts before 'a'
        else
        {
            // Overlap exists if 'b' ends after or when 'a' starts
            if(end2 >= start1) {
                int s = max(start1, start2); // Start of intersection is max of start points
                int e = min(end1, end2);     // End of intersection is min of end points
                res.push_back({s, e});
            }
        }

        // Advance the pointer of the interval that finishes earlier,
        // since it cannot intersect with any remaining future intervals
        if(end1 <= end2)
            i++;
        else
            j++;
    }

    return res;
}

int main() {
    // Example test case: two sorted and non-overlapping interval lists
    vector<vector<int>> a = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> b = {{1,5},{8,12},{15,24},{25,26}};

    vector<vector<int>> result = intervalIntersection(a, b);

    cout << "Intersection Intervals are :\n";

    // Print all intersected intervals
    for(auto interval : result) {
        cout << "[" << interval[0] << " , " << interval[1] << "]\n";
    }
    return 0;
}