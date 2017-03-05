/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/

/*
First part: partition the original words to each line, record the words lenth 
Second part: add space for each line
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
	 if (maxWidth == 0) return{ "" };
	 vector<vector<string>> hold;
	 vector<string> path;
	 vector<int> line_len;
	 int len = 0;
	 for (int i = 0; i < words.size(); ++i)
	 {
		 if (len + words[i].length()<=maxWidth- path.size())
		 {
			 path.push_back(words[i]);
			 len += words[i].length();
		 }
		 else {
			 if (!path.empty()) {
				 hold.push_back(path);
				 line_len.push_back(len);
			 }
			 path.clear();
			 len = 0;
			 path.push_back(words[i]);
			 len = words[i].size();
		 }
	 }
	 if (!path.empty()) { hold.push_back(path); line_len.push_back(len); }
	 return generate(hold, line_len, maxWidth);
 }
    
    vector<string> generate(vector<vector<string>>& hold,vector<int>& len, int maxWidth)
    {
        vector<string> res;
        for(int i = 0; i < hold.size()-1; ++i)
        {
            int space = maxWidth - len[i];
            if(hold[i].size()==1)
            {
                string tmp = hold[i][0] + string(space,' ');
                res.push_back(tmp);
            }else{
                vector<int> line_space(hold[i].size()-1,space/(hold[i].size()-1));
                int left = space%(hold[i].size()-1);
                int cnt = 0;
                while(left>0) {line_space[cnt++]++;left--;}
                string tmp = "";
                for(int k = 0; k < line_space.size(); ++k)
                {
                    tmp = tmp + hold[i][k] + string(line_space[k],' ');
                }
                tmp += hold[i].back();
                res.push_back(tmp);
            }
        }
        int space = maxWidth - len.back();
        string tmp = "";
        for(int k = 0; k < hold.back().size(); ++k)
        {
            tmp = tmp + hold.back()[k] + (space>0?" ":"");
            space--;
        }
        tmp += space > 0 ? string(space,' '):"";
        res.push_back(tmp);
        return res;
    }
};