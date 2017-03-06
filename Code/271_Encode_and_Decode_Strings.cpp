/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:
The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
*/

/*
Here I use a unique prefix "/*!*/ /*" to identify the string, which is not safe
more clever way is to use coding techniques:
'/' + length of string:
"abc" "aa" "t"    -->   /3abc/2aa/1t
*/



class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string mark = "/*!*/";
        string res;
        for(auto s:strs) res = res + s + mark;
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
    	vector<string> res;
    	if (s.empty()) return{};
    	if (s.size() == 5) return{ "" };
    	int start = 0;
    	for (int i = 0; i < s.length() - 4; ++i)
    	{
    		if (s[i] == '/' && s[i + 1] == '*')
    		{
    			if (s.substr(i, 5) == "/*!*/")
    			{
    				res.push_back(s.substr(start, i - start));
    				start = i + 5;
    			}
    		}
    	}
    	return res;
    }
};