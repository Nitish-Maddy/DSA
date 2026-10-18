#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
    bool canConstruct(string ransomNote, string magazine) {
      //Store the frequency of each character available in magazine
      unordered_map<char, int> have;
      //Store the frequency of each character required by ransomNote
      unordered_map<char, int> need;

      //Count how many times each character appear in ransomNote
      for(int i = 0; i < ransomNote.size(); i++) {
        need[ransomNote[i]]++;
      }

      //Count how many times each character appear in magazine
      for(int i = 0; i < magazine.size(); i++) {
        have[magazine[i]]++;
      }

      //Check whether magazine has enough copies of every required character
      return fun(have, need); 
    };

    //Pass both maps by reference to avoid copying them
    bool fun(unordered_map<char, int>& have,
             unordered_map<char, int>& need) 
    {
       //Visit every distinct charcter required by ransomNote
       for(auto i : need) {
        //Character  that we need to construct the ransomNote
        char c = i.first;

        //Number of copies of this character required
        int fneed = i.second;
        
        //Number of copies available in magazine
        //If c is absent, have[c] creates an entry with frequency 0
        int fhave = have[c];

        // If available copies are fewer than required copies,
            // constructing ransomNote is impossible
            if(fhave < fneed) {
              return false;
            }
       }
       // Every required character has enough available copies
       return true;
    }
};

int main() {
  Solution s;

  cout << boolalpha << s.canConstruct("aa", "aab") << endl;
  cout << s.canConstruct("aa", "ab") << endl;

  return 0;
}