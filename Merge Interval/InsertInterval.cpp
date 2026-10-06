#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& a)
{
vector<vector<int>> res;
int n = intervals.size();

// Sort intervals according to starting value
  sort(intervals.begin(), intervals.end());

  //New interval
  int start = a[0];
  int end = a[1];

  bool insert = false;

  for(int i = 0; i < n; i++)
  {
    int s = intervals[i][0];    //Current Start
    int e = intervals[i][1];    //Current End

    //Current interval comes Before new interval
    if(e < start)
    {
        res.push_back(intervals[i]);
    }

    //Current interval comes After new interval
    else if(s > end)
    {
        if(insert == false){
            res.push_back({start, end});
            insert = true;
        }
        res.push_back(intervals[i]);
    }

    //Current interval Overlaps with new interval
    else{
        start = min(start, s);
        end = max(end, e);
    }
  }

    // New Interval has not been inserted yet
    if(insert == false) {
        res.push_back({start, end});
    }

    return res;
}

int main() {
    vector<vector<int>> intervals = { {1,3}, {6,9} };
    vector<int> a = {2,5};
    vector<vector<int>> ans = insert(intervals, a);
    cout << "Result: ";
    
    for(auto interval : ans) {
        cout << "[" << interval[0] << "," << interval[1] << "]";
    }

    return 0;
}