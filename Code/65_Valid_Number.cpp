/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

/*
USE FINITE ATOMINA!!!
*/

class Solution {
public:
        // 6 type of input: invalid, space, sign-+, radix point, e, 0~9
	    // 9+1 state:
	    // -1: error state
	    //  0: initial state
	    //  1: init with sign
	    //  2: init with radix point
	    //  3: normal init 0~9
	    //  4: sign + '.' + normal number
	    //  5: number + space(number may be end with spaces)
	    //  6: valid number without exp
	    //  7: valid number + e + sign + number
	    //  8: valid number + e + number
    bool isNumber(string s) {
	    enum Input_type {INVALID, SPACE, SIGN, POINT, EXP, NUM};
	    vector<vector<int>> trans_maxtix = 
	    {
	        {-1, 0, 1, 2,-1, 3},
	        {-1,-1,-1, 2,-1, 3},
	        {-1,-1,-1,-1,-1, 4},
	        {-1, 5,-1, 4, 6, 3},
	        {-1, 5,-1,-1, 6, 4},
	        {-1, 5,-1,-1,-1,-1},
	        {-1,-1, 7,-1,-1, 8},
	        {-1,-1,-1,-1,-1, 8},
	        {-1, 5,-1,-1,-1, 8}
	    };
	    
	    int state = 0;
	    for(int i = 0; i < s.size(); ++i)
	    {
	        Input_type input;
	        
	        if(s[i]==' ') input = SPACE;
	        else if(s[i]=='+' || s[i]=='-') input = SIGN;
	        else if(s[i]=='.') input = POINT;
	        else if(s[i]=='e') input = EXP;
	        else if(s[i]>='0' && s[i] <= '9') input = NUM;
	        else input = INVALID;
	        
	        state = trans_maxtix[state][input];
	        if(state==-1) return false;
	    }
	    return state == 3 || state == 4 || state == 5 || state == 8;
    }
};