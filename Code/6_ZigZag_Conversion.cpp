/********************************************************************************** 
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

********************************
P   A   H   N
A P L S I I G
Y   I   R
********************************

* And then read line by line: "PAHNAPLSIIGYIR"

* Write the code that will take a string and make this conversion given a number of rows:
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
**********************************************************************************/

/********************************************************************************** 
* Basic Idea:
* there is a pattern between the original string and the Zigzag string, which will allow you to calculate directly

convert("PAYPALISHIRING", 3):


P <---4---> A           H           N              <--first line the length between the adjacent is 4 = 2*3-2
A <2> P <2> L     S     I     I     G              <--the second line the length is 2 = 4-2, and then the difference is switched to (2*3-2) - (4-2) 
Y <---4---> I           R                          <--the last line the length is also 4, same to the first line

lets look at a more obvious example:
convert("ABCDEFGHIJKLMNOPQRST", 5):

A       I       Q               <-- d = 2*5-2 = 8
B     H J     P R               <-- d11 = 8-2 = 6, d12 = 8 - 6 = 2     6,2,6,2,6... 
C   G   K   O   S               <-- d21 = 6-2 = 4, d12 = 8 - 4 = 4     4,4,4,4,4...
D F     L N     T               <-- d31 = 4-2 = 2, d32 = 8 - 2 = 6     2,6,2,6,2... 
E       M                       <-- d41 = 2-2 = 0 <--oops! this is the last line: d = 8


**********************************************************************************/

class Solution {
public:
    string convert(string s, int numRows) {
        
	string tmp;
	if (numRows == 1) return s;
	if (s == "") return s;
		unsigned int i = 2 * numRows - 2;              //initial setp length
		for (unsigned int j = 0; j < numRows; j++) {
		    if (j < s.size())
			    tmp.push_back(s[j]);                   //push the first element in j line
			unsigned int m = j;                
			unsigned int k = i - j*2;                  // set length in line j
			if (k == 0) k = i - k;                     // last line
			while (m + k < s.length()) {
				m = m + k;                             // push rest of the element
				tmp.push_back(s[m]);			
				if (j == 0 || j == numRows - 1) k = k; // the step won't change in the first/ last line
				else k = i - k;                        //swith length
			}
		}
	
	return tmp;
    }
};