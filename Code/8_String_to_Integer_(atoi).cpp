/********************************************************************************** 
* 
*Implement atoi to convert a string to an integer.

*Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

*Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*   

*Requirements for atoi:
*The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.            
**********************************************************************************/

/********************************************************************************** 
*Not really hard to think about it but there are a lot to consider, therefor I use the state machine to avoid some corner error

* 4 possible input: invalid char, space, sign +/-, normal number

* state 0: initial state, also extra space will remain in this state

* state 1: number with sign

* state 2: number without sign

* state -1: invalid state, throw err

* P.S in order to prevent the number growing beyond the boundry, I use long long type to hold the record   

**********************************************************************************/

class Solution {
public:

int myAtoi(string str) {
    	enum input_type { INVALID, SPACE, SIGN, NUM };
    	int sign = 1;
    	int state = 0;
    	long long result = 0;
    
    	for (int i = 0; i < str.size(); ++i)
    	{
    		input_type input;
    		if (str[i] == ' ') input = SPACE;
    		else if (str[i] == '+' || str[i] == '-') input = SIGN;
    		else if (str[i] >= '0' && str[i] <= '9') input = NUM;
    		else input = INVALID;
    
    		if (state == 0)
    		{
    			if (input == SPACE)
    			{
    				continue;
    			}
    			else if (input == SIGN)
    			{
    				state = 1;
    				sign = (str[i] == '-') ? -1 : 1;
    			}
    			else if (input == NUM)
    			{
    				state = 2;
    				result = str[i] - '0';
    			}
    			else
    			{
    				state = -1;
    			}
    		}
    		else if (state == 1)
    		{
    			if (input == SPACE)
    			{
    				state = 3;
    			}
    			else if (input == NUM)
    			{
    				result = sign * (str[i] - '0');
    				state = 2;
    			}
    			else
    			{
    				state = -1;
    			}
    		}
    		else if (state == 2)
    		{
    			if (input == SPACE)
    			{
    				state = 3;
    			}
    			else if (input == NUM)
    			{
    				if (sign == 1)
    				{
    					long long tmp = 10 * result + (str[i] - '0');
    					result = (tmp > INT_MAX)?INT_MAX:tmp;
    				}
    				else
    				{
    					long long tmp = 10 * result - (str[i] - '0');
    					result = (tmp < INT_MIN)? INT_MIN : tmp;
    				}
    			}
    			else
    			{
    				state = -1;
    			}
    		}
    		else if (state == 3)
    		{
    			state = -1;
    		}
    		else if (state == -1)
    		{
    			return (int)result;
    		}
    	}
    	return (int)result;
    }
};