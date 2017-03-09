/*
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither. 
IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1; 
Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid. 
IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases). 
However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address. 
Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid. 
Note: You may assume there is no extra space or special characters in the input string. 
Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".

Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".

Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
*/


/*
Very brute force solution
assign possible IP for target function
decide number by number
reunion
*/


class Solution {
public:
    string validIPAddress(string IP) {
        vector<string> res = {"Neither","IPv4","IPv6"};
        if(IP.length()<=15 && isIPV4(IP)) return res[1];
        if(isIPV6(IP)) return res[2];
        return res[0];
    }
    
    bool isIPV6(string IP)
    {
        vector<string> part;
        int start = 0;
        for(int i = 1; i < IP.length(); ++i)
        {
            if(IP[i]==':')
            {
                part.push_back(IP.substr(start,i-start));
                start = i+1;
            }
            
        }
        part.push_back(IP.substr(start));
        if(part.size()==8)
        {
            for(int i = 0; i <8; ++i)
            {
                if(!validNumIPV6(part[i])) return false;
            }
            return true;
        }
        return false;
    }
    
    bool validNumIPV6(string num)
    {
        if(num.empty() || num.size()>4) return false;
        for(auto i:num)
        {
            if(!((i>='0'&& i<='9') || (i>='a'&&i<='f') || (i>='A'&&i<='F') )) return false;
        }
        return true;
    }
    
    
    
    
    
    bool isIPV4(string IP)
    {
        vector<string> part;
        int start = 0;
        for(int i = 1; i < IP.length(); ++i)
        {
            if(IP[i]=='.')
            {
                part.push_back(IP.substr(start,i-start));
                start = i+1;
            }
            
        }
        part.push_back(IP.substr(start));
        if(part.size()==4)
        {
            for(int i = 0; i <4; ++i)
            {
                if(!validNumIPV4(part[i])) return false;
            }
            return true;
        }
        return false;
    }
    
    bool validNumIPV4(string num)
    {
        if(num.size()>3 || num.empty()) return false;
        if(num[0]=='0') return num.size()==1;
        int cnt = 0;
        for(int i = 0; i < num.length(); i++)
        {
            if(num[i]>'9' || num[i]<'1') return false;
            cnt = 10*cnt + num[i]-'0';
        }
        return cnt <= 255;
    }
};