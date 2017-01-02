/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
*/

/*
same as what we do multiplication
*/


class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
	 int M = num1.length();
	 int N = num2.length();
	 vector<vector<int>> rec(N + 1, vector<int>(M + N - 1, 0));
	 vector<int> res(M + N - 1, 0);
	 for (int i = 0; i < N; ++i)
	 {
		 for (int j = 0; j < M; ++j)
		 {
			 rec[i][M + N - 2 - j-i] = (num1[M - 1 - j] - '0') * (num2[N - 1 - i] - '0');
		 }
	 }

	 for (int k = M + N - 2; k > 0; k--)
	 {
		 int temsum = 0;
		 for (int i = 0; i < N+1; ++i) temsum += rec[i][k];
		 res[k] = temsum % 10;
		 rec[N][k - 1] = temsum / 10;
	 }
	 for (int i = 0; i < N+1; ++i) res[0] += rec[i][0];
	 string str = "";
	 for (int i = 0; i < res.size(); ++i) str += to_string(res[i]);
	 return str;
    }
};