#include <iostream>
#include <vector>
using namespace std;

//function to find pivot
int pivotIndex(vector<int>& a)
{
    int n = a.size();
    //Step1. Calculate total sum of the array
    int sum = 0;
    for(int i=0; i<n; i++) 
    {
        sum += a[i];
    } 

    //Step2. Initially, nothing is present on the left
    int left = 0;

    //step3. Check every index as a possible pivot
    for(int i=0; i<n; i++)
    {
        //Right side = Total - Left side - Current element
        int right = sum - left - a[i];

        //If left sum == right sum, we found pivot
        if (left == right)
        {
            return i;
        }

            //move the current element into left side
            left = left + a[i];
    }
    //no pivot index found
    return -1;
}

int main() {
  vector<int> a = {1, 7, 3, 6, 5, 6};
  int answer = pivotIndex(a);
  cout << "Pivot Index = " << answer << endl;
  return 0;
}