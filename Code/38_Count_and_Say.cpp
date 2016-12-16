/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

/*
Direct approach: recurrently call function, but efficiency is poor
There is a efficient way, I'm not sure precisely how it did
*/
class Solution {
public:
    string countAndSay01(int n) {
	if (n == 1) return "1";

	unordered_map<char, int> mp;

	string last = countAndSay(n - 1);

	char tail = last[0];
	mp[tail] = 0;

	string result;
	string tmp;

	for (int i = 0; i < last.size(); ++i)
	{
		if (tail == last[i])
		{
			mp[last[i]]++;
		}
		else {

			result = result + to_string(mp[tail]) + tail;
			mp[tail] = 0;
			tail = last[i];
			mp[tail]++;
		}
		if (i == last.size() - 1)
		{
			result = result + to_string(mp[tail]) + tail;
		}
	}
	return result;
}

    string countAndSay02(int n) {
        if (n == 1) return "1";
        return countAndSay_s(countAndSay(n-1));
    }
    
    string countAndSay_s(string s)
    {
        char st = s[0];
        int cnt = 1;
        for(;cnt<s.length();++cnt)
        {
            if(s[cnt]!=st) break;
        }
        return to_string(cnt)+st+ (cnt < s.length() ? countAndSay_s(s.substr(cnt,s.length()-cnt)) : "");
    }
    
    string countAndSay(int n) {
        if (n <= 0)
            return NULL;

        //n=1时，结果为"1"
        string ret = "1";
        if (n == 1)
            return ret;
        else
        {
            for (int i = 2; i <= n; i++)
                ret = Count(ret);
        }//else
        return ret;

    }

    string Count(const string &str)
    {
        int size = strlen(str.c_str());
        //保存结果
        stringstream ret;
        //保存标识字符
        char flag = str[0];
        //计算标识字符的出现次数
        int count = 0 , i = 0;
        while( i < size )
        {
            //临时循环位
            int pos = i;
            while (str[pos] == flag)
            {
                count++;
                pos++;
            }//while
            ret << count << flag;
            flag = str[pos];
            count = 0;
            //设置下一个循环位
            i = pos;
        }//for
        return ret.str();
    }
    //http://blog.csdn.net/fly_yr/article/details/48000713
};