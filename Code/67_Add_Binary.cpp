/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

/*
refer to full adder
first normalizing 2 number: same length
realizing 1-bit-adder algorithm
apply to eachbit
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string tmp1 = a;
	    string tmp2 = b;
	    string sum = "";
	    string tmpsum;
	    int len = normalizing(&tmp1, &tmp2);
	    for (int i = len - 1; i > -1; i--) {
		    int a1 = (tmp1[i] == '1' ? 1 : 0);
		    int a2 = (tmp2[i] == '1' ? 1 : 0);
		    if (i == len - 1) { 
			    tmpsum = onebitadder(a1, a2, 0); 
			    sum = tmpsum[0] + sum;
		    }
		    else {
			    int co = (tmpsum[1] == '1' ? 1 : 0);
			    tmpsum = onebitadder(a1, a2, co);
			    sum = tmpsum[0]+sum;
		    }
	    }
	    if (tmpsum[1] == '1') { sum = "1" + sum; }
	    int z = 0;
	    for (unsigned int i = 0; i < sum.length(); i++) {
		    if (sum[i] == '1') {
			    z = i;
			    break;
		    }
	    }
	    sum = sum.substr(z);
	    return sum;
        }
        
    string onebitadder(int a, int b, int c)
{
	int out = a^b^c;
	int ct = (a&&b) || (c && (a || b));
	string t = (out == 1 ? "1":"0");
	string p = (ct == 1 ? "1" : "0");
	return t+p;
}

int normalizing(string *a, string *b)
{
	if (a->length() == b->length()) { NULL; }
	else {
		int n = (a->length() > b->length() ? (a->length() - b->length()) : (b->length() - a->length()));
		string zero(n, '0');
		if (a->length() > b->length()) { *b = zero + (*b); }
		if (a->length() < b->length()) { *a = zero + (*a); }
	}
	return a->length();
}
        
        
};