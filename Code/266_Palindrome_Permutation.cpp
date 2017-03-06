/*
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:

Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
*/

/*
count number of each letter
if string length is even: all letter should appear even
odd: allow one odd
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> rec(256,0);
        for(int i = 0; i < s.length(); ++i) rec[s[i]]++;
        int odd = 0;
        for(auto i:rec) {
            
            odd += i%2;
        }
        
        if(s.length()%2==0) return odd==0;
        return odd == 1;
    }
};