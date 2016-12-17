/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Hint:

Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
*/

/*
some importand point:
thousand/ million/ billion
*/

class Solution {
public:
    string SM_numberToWords(int num) {
	int tmp = num;

	string temp = "";

	string number[] = { "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
	string tenth2[] = { "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

	int hun = tmp / 100;
	tmp = tmp % 100;

	if (hun != 0) { temp = number[hun - 1] + " Hundred"; }
	if (tmp == 0) { return temp; }
	if (tmp <= 19) { temp += (temp.empty()?"":" ") + number[tmp - 1]; }
	if (tmp > 19) {
		temp += (temp.empty()?"":" ") + tenth2[tmp / 10 - 2];
		if (tmp % 10 != 0)
		{
			temp += (temp.empty()?"":" ") + number[tmp % 10 - 1];
		}
	}
	return temp;
}

string numberToWords(int num) {
	if (num == 0) { return "Zero"; }
	int billion = 1000000000;
	int million = 1000000;
	int thousand = 1000;
	int handred = 100;
	
	string tag[] = { "Billion","Million","Thousand"};
	
	int tmp = num;
	string ans = "";

	int digit = tmp / billion;
	if (digit != 0) { ans += SM_numberToWords(digit) + " " + tag[0]; }
	tmp = tmp % billion;
    
	digit = tmp / million;
	if (digit != 0) { ans += (ans.empty()?"":" ") + SM_numberToWords(digit) + " " + tag[1]; }
	tmp = tmp % million;

	digit = tmp / thousand;
	if (digit != 0) { ans += (ans.empty()?"":" ") + SM_numberToWords(digit) + " " + tag[2]; }
	tmp = tmp % thousand;
	
	if(tmp != 0){
	ans += (ans.empty()?"":" ") + SM_numberToWords(tmp);
	}
	
	return ans;
}
};