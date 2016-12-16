/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/

/*
equally to sort an array with only 0,1,2 in it
3 varable count 3 number
then just re-assign each 
time:O(n) space:O(1)
*/


class Solution {
public:
    void sortColors01(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
    
    void sortColors(vector<int>& nums) {
        int red=0,white=0,blue=0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i]==0) red++;
            else if (nums[i]==1) white++;
            else blue++;
        }
        for(int i=0; i < nums.size(); ++i)
        {
            if(red != 0)
            {
                nums[i]=0; red--;
            }
            else if(white != 0)
            {
                nums[i]=1; white--;
            }
            else
            {
                nums[i]=2;
            }
        }
    }
};