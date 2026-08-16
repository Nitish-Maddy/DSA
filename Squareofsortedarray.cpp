#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg, pos;

        //Separate negative and positive numbers
        for (int x : nums) {
            if (x < 0) {
                neg.push_back(x * x);
            }
                else{
                pos.push_back(x * x);
                }
            }
             // Negative squares are currently in decreasing order,
             // so we reverse them to make them increasing
             reverse(neg.begin(), neg.end());

             int i = 0, j = 0;
             vector<int> result;

             // Merge the two sorted arrays
             while (i < neg.size() && j < pos.size()) {
                if (neg[i] < pos[j]) {
                result.push_back(neg[i]);
                i++;
             }
                else{
                result.push_back(pos[j]);
                j++;
             }
            }

             // Add remaining negative squares
             while (i < neg.size()) {
             result.push_back(neg[i]);
             i++;
             }
               
             // Add remaining positive squares
             while (j <pos.size()){
             result.push_back(pos[j]);
             j++;
            }
             
             return result;
        }
    };

    int main() {
        //Input array
        vector<int> nums = {-7, -3, 2, 3, 11};

        //Create object
        Solution obj;

        //Call the function
        vector<int> result = obj.sortedSquares(nums);

        //Print the result
        cout << "Sorted squares: ";

        for (int x : result) {
            cout << x << " ";
        }
        cout <<endl;

        return 0;
    }
