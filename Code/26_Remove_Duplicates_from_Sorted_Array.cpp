/********************************************************************************** 
* Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

* Do not allocate extra space for another array, you must do this in place with constant memory.

* For example,
* Given input array nums = [1,1,2],

* Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
* It doesn't matter what you leave beyond the new length.
**********************************************************************************/

class Solution {
public:
    int removeDuplicates01(vector<int>& nums) {
        if(nums.empty()){return 0;}
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); ++i)
        {
            mp[nums[i]] = 1;
        }

        int i = 0;
        int size = mp.size();
        for(auto item:mp)
        {
            nums[i++] = item.first;
        }
        sort(nums.begin(),nums.begin()+size);
        return size;
    }
    
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){return 0;}
        int count = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i]==nums[i-1]){continue;}
            else{
                nums[count++] = nums[i]; 
            }
        }
        return count;
    }
};