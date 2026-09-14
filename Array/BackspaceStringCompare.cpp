#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;

        int skipS = 0;
        int skipT = 0;

        while (i >= 0 || j >= 0) 
        {
            //Process s from right to left
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                }
                else if (skipS > 0) {
                    skipS--;
                    i--;
                }
                else{
                    break;
                }
            }

            //Process t from right to left
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                }
                else if (skipT > 0) {
                    skipT--;
                    j--;
                }
                else {
                    break;
                }
            }

            //Both have valid characters
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }

            //One has a character, other doesn't
            if ((i >= 0) != (j >= 0)) {
                return false;
            }

            //Move the both pointers
            i--;
            j--;
        }
        return true;
    }

};

int main() {
    Solution obj;

    string s = "xywrrmp";
    string t = "xywrrmu#p";

    cout << boolalpha << obj.backspaceCompare(s, t) << endl;
    return 0;
}