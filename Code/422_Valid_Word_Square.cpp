/*
Given a sequence of words, check whether it forms a valid word square.
A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
Note:
The number of words given is at least 1 and does not exceed 500.
Word length will be at least 1 and does not exceed 500.
Each word contains only lowercase English alphabet a-z.

Example 1: 
Input:
[
  "abcd",
  "bnrt",
  "crmy",
  "dtye"
]

Output:
true

Explanation:
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crmy".
The fourth row and fourth column both read "dtye".

Therefore, it is a valid word square.

Example 2: 
Input:
[
  "abcd",
  "bnrt",
  "crm",
  "dt"
]

Output:
true

Explanation:
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crm".
The fourth row and fourth column both read "dt".

Therefore, it is a valid word square.

Example 3: 
Input:
[
  "ball",
  "area",
  "read",
  "lady"
]

Output:
false

Explanation:
The third row reads "read" while the third column reads "lead".

Therefore, it is NOT a valid word square.
*/

/*
I stuff the string with '0' so that it can form a perfect square shape
then just ordinary check
*/

class Solution {
public:
    bool validWordSquare(vector<string>& words, int i = 0, int j = 0) {
        if(i==0 && j==0)
        {
            int n = words.size();
            for(int i = 0; i < words.size(); ++i)
            {
                while(words[i].size()<n) words[i].push_back('0');
            }
        }
        string a = "", b = "";
        if(i==words.size() || j >= words[i].size()) return true;
        for(int k = i; k < words[i].size(); ++k) a.push_back(words[i][k]);
        for(int k = j; k < words.size() && words[i].size()>i; ++k) b.push_back(words[k][i]);
        if(a.length() != b.length() || a != b) return false;
        return validWordSquare(words,i+1,j+1);
    }
};