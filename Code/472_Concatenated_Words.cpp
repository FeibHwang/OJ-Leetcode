/*
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.
*/

/*
use a char-vector<string> hash map to hold the word
then search for each word in DFS
*/

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
	 for (int i = 0; i < words.size(); ++i)
	 {
		 if (words[i] != "") dict[words[i][0]].push_back(words[i]);
	 }

	 vector<string> res;

	 for (int i = 0; i < words.size(); ++i)
	 {
		 if (words[i] != "" && search_word(words[i], 0)) res.push_back(words[i]);
	 }
	 return res;
 }
    
private:
    unordered_map<char,vector<string>> dict;
    
    bool search_word(string word, int depth)
 {
	 if (word == "" && depth != 0) return true;
	 if (dict.find(word[0]) != dict.end())
	 {
		 for (int i = 0; i < dict[word[0]].size(); i++)
		 {
			 if (dict[word[0]][i].length() <= word.length())
			 {
				 if (dict[word[0]][i].length() == word.length())
				 {
					 if ((dict[word[0]][i] == word) && (depth != 0)) return true;
				 }
				 else if (word.substr(0, dict[word[0]][i].length()) == dict[word[0]][i])
					 if (search_word(word.substr(dict[word[0]][i].length()), 1)) return true;
			 }
		 }
	 }
	 return false;
 }
};