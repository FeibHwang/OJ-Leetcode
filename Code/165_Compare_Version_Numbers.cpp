/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

/*
Critical part is to convert string to integer
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ver1,ver2;
        int index1 = 0, index2 = 0;
        while(index1 < version1.size() || index2 < version2.size())
        {
            ver1 = 0;
            while(index1 < version1.size())
            {
                if(version1[index1]=='.')
                {
                    index1++;
                    break;
                }
                ver1 = 10 * ver1 + (version1[index1] - '0');
                index1++;
            }
            
            ver2 = 0;
            while(index2 < version2.size())
            {
                if(version2[index2]=='.')
                {
                    index2++;
                    break;                       //important
                }
                ver2 = 10 * ver2 + (version2[index2] - '0');
                index2++;
            }
            
            if(ver1 > ver2) return 1;
            if(ver1 < ver2) return -1;
        }
        return 0;
    }
    

};