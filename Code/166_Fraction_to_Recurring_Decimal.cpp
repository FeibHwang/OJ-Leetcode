/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Hint:

No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.
*/

/*
Key thing is to record the pattern
here I use hash map
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    long start = numerator;
    long end = denominator;
	long divide = abs(end);
	long num = abs(start);

	if (num == 0) { return "0"; }

	if (divide == 1) return to_string(end*start);

	long int_start = num / divide;
	long remain = num % divide;

	if (remain == 0) 
	return( (num == start && divide == end)||(num != start && divide != end)) ? to_string(int_start) : "-" + to_string(int_start);

	string repeat = "";
	long rec = 0;
	unordered_map<long, long> mp;
	while (true)
	{
		remain *= 10;
		string tmp = to_string(remain / divide);
		repeat += tmp;
		remain = remain % divide;
		if (remain == 0) { break; }
		if (mp.find(remain) == mp.end()) mp[remain] = ++rec;
		else if (mp[remain] == 1 && repeat[mp[remain]-1]==tmp[0])
		{
			repeat = repeat.substr(0, mp[remain] - 1) + "(" + repeat.substr(mp[remain] - 1, rec) + ")"; break;
		}
		else { repeat = repeat.substr(0, mp[remain]) + "(" + repeat.substr(mp[remain], rec) + ")"; break; }
	}

	if ((num == start && divide == end)||(num != start && divide != end)) 
	{ return to_string(int_start) + "." + repeat; }
	else { return "-" + to_string(int_start) + "." + repeat; }
	return NULL;
}
};