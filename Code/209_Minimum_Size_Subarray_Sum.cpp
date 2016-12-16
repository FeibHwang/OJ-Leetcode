/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

/*
back tracking is the most obvious and efficient way
*/

class Solution {
public:
    int minSubArrayLen02(int s, vector<int>& nums) {
        if(nums.empty()){return 0;}
        vector<int> tmp = nums;
        sort(tmp.begin(),tmp.end());
        int sum = 0;
        for(int i = nums.size()-1; i >= 0; --i)
        {
            sum+=tmp[i];
            if(sum >= s)
            {
                return nums.size()-i;
            }
            else{
                continue;
            }
        }
        return 0;
    }
    
    int minSubArrayLen01(int s, vector<int>& nums) {
        if(nums.empty()){return 0;}
        if(nums.size()==1){
            if(nums[0]>=s){return 1;}
            else{
                return 0;
            }
        }
        int end;
        int sum = 0;
        vector<int> num;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            num.push_back(nums[i]);
            if(i == nums.size()-1 && sum < s){return 0;}
            if(i == nums.size()-1 && sum >= s){return nums.size();}
            if(sum >= s)
            {
                end = ++i;
                break;
            }
        }
        

        for(int k = end; k < nums.size(); ++k)
        {
            int cnt = 0;
            sort(num.begin(),num.end());
            if(nums[k]<=num[0]){continue;}
            for(int j = 0; j < num.size(); ++j)
            {
                cnt += num[j];
                if(nums[k]>=cnt)
                {
                    continue;
                }else{
                    num.assign(num.begin()+j-1,num.end());
                    break;
                }
                
            }
            
        }
        return num.size();
        
    }
    
    int minSubArrayLen(int s, vector<int>& nums) {  
        int n = nums.size();  
        if (n < 1)  
        {  
            return 0;  
        }  
        int result = n+1;  
        int sum = 0;  
        int left = 0;  
        int right = 0;  
  
        while (right < n)  
        {  
            sum += nums[right];  
            if (sum >= s)  
            {  
                while (sum >= s)  
                {  
                    int temp = right-left+1;  
                    if (temp < result)  
                    {  
                        result = temp;  
                    }  
                    sum -= nums[left];  
                    left++;  
                }  
            }  
            right++;  
        }  
  
        if (result > n)  
        {  
            return 0;  
        }  
  
        return result;   
    }  
};