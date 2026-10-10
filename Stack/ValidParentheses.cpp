#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
 * Problem: Valid Parentheses (LeetCode 20)
 *
 * Description:
 * Given a string 's' containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 *
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 3. Every close bracket has a corresponding open bracket of the same type.
 *
 * Approach:
 * - Use a Stack data structure (Last-In-First-Out / LIFO).
 * - Traverse the string character by character:
 *   - If an opening bracket '(', '[', '{' is encountered, push it onto the stack.
 *   - If a closing bracket ')', ']', '}' is encountered:
 *       a. If the stack is empty, it means there is no matching opening bracket -> return false.
 *       b. Check if the top of the stack matches the current closing bracket.
 *          If it matches, pop the opening bracket from the stack.
 *          Otherwise, brackets are mismatched -> return false.
 * - At the end, if the stack is empty, all brackets were properly matched and closed -> return true.
 * - If the stack is not empty, some opening brackets were never closed -> return false.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the length of the string, since we traverse the string once.
 * - Space Complexity: O(n), in the worst case (e.g., all opening brackets like "((((("), the stack stores all n characters.
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        // Traverse each character in the string
        for (int i = 0; i < n; i++) {
            // Case 1: If it's an opening bracket, push it onto the stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            // Case 2: If it's a closing bracket
            else {
                // If stack is empty, there is no corresponding opening bracket
                if (st.empty()) {
                    return false;
                }

                // Check if current closing bracket matches the most recent opening bracket on top
                if (s[i] == ')' && st.top() == '(') {
                    st.pop();
                }
                else if (s[i] == ']' && st.top() == '[') {
                    st.pop();
                }
                else if (s[i] == '}' && st.top() == '{') {
                    st.pop();
                }
                // Mismatch between opening and closing bracket types
                else {
                    return false;
                }
            }
        }

        // If the stack is empty, all opening brackets had matching closing brackets
        return st.empty();
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter parentheses: ";
    cin >> s;

    // Validate the input string and display the result
    if (obj.isValid(s)) {
        cout << "Valid Parentheses" << endl;
    }
    else {
        cout << "Invalid Parentheses" << endl;
    }

    return 0;
}