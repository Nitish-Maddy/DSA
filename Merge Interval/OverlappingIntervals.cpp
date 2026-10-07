#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isIntersect(vector<vector<int>>& a) {
    sort(a.begin(), a.end());
    int n = a.size();

    int start1 = a[0][0];
    int end1 = a[0][1];

    for(int i = 1; i < n; i++) {
      int start2 = a[i][0];
      int end2 = a[i][1];

      if(end1 >= start2) {
        return true;
      }

      start1 = start1;
      end1 = max(end1, end2);
    }

    return false;
};

int main() {
    vector<vector<int>> a = { {1,3}, {4,6}, {7,9}, {2,5}};

    if(isIntersect(a))
    {
        cout << "Intervals are intersecting" << endl;
    }
    else {
        cout << "Intervals are not intersecting" << endl;
    }

    return 0;
}