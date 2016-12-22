/********************************************************************************** 
*Given an integer, convert it to a roman numeral.

*Input is guaranteed to be within the range from 1 to 3999.
**********************************************************************************/

/********************************************************************************** 
*Directly using the definition, the code may be numerous and jumbled, but the effeciency is actually pretty good
**********************************************************************************/

class Solution {
public:
    string intToRoman(int num) {
	string result = "";
	string ch = "IVXLCDM";
	
	if (num >= 1000)
		result = ch.substr(6,1) + intToRoman(num - 1000);
	if (num < 1000 && num >= 900)
		result = ch.substr(4,1) + ch.substr(6,1) + intToRoman(num - 900);
	if (num < 900 && num >= 500)
		result = ch.substr(5,1) + intToRoman(num - 500);
	if (num < 500 && num >= 400)
		result = ch.substr(4,1) + ch.substr(5,1) + intToRoman(num - 400);
	if (num < 400 && num >= 100)
		result = ch.substr(4,1) + intToRoman(num - 100);
	if (num < 100 && num >= 90)
		result = ch.substr(2,1) + ch.substr(4,1) + intToRoman(num - 90);
	if (num < 90 && num >= 50)
		result = ch.substr(3,1) + intToRoman(num - 50);
	if (num < 50 && num >= 40)
		result = ch.substr(2, 1) + ch.substr(3, 1) + intToRoman(num - 40);
	if (num < 40 && num >= 10)
		result = ch.substr(2,1) + intToRoman(num - 10);
	if (num == 9)
		result = ch.substr(0,1) + ch.substr(2,1);
	if (num < 9 && num >= 5)
		result = ch.substr(1,1) + intToRoman(num - 5);
	if (num == 4)
		result = ch.substr(0,1) + ch.substr(1,1);
	if (num < 4 && num >= 1)
		result = ch.substr(0,1) + intToRoman(num - 1);
	if (num == 0) { return ""; }
	return result;
}
};