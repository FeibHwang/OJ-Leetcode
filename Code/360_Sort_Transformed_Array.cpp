/*
Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
*/

/*
a mathmatical problem
the min/max value is at -b/2a
just calculate value by the abs distance around it using two pointer

corner case: a = 0
*/

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        double mid = a!=0 ? (-(double)b/(double)a/2):(b>0 ? (double)nums[0]:(double)nums.back());
        int i = 0, status;
        if(nums[0]>=mid) status = 2;
        else if(nums.back()<=mid) status = 0;
        else
        {
            for(; i<nums.size()-1; ++i)
            {
                if(nums[i] <= mid && nums[i+1]>=mid) break;
            }
            status = 1;
        }
        
        vector<int> res;
        if(status == 0)
        {
            for(int i = nums.size()-1; i>=0; --i)
            {
                res.push_back(a*nums[i]*nums[i]+b*nums[i]+c);
            }
        }
        else if(status == 2)
        {
            for(int i = 0; i<nums.size(); ++i)
            {
                res.push_back(a*nums[i]*nums[i]+b*nums[i]+c);
            }
        }else{
            int j = i+1;
            while(i >= 0 || j < nums.size())
            {
                if(i<0) 
                {
                    res.push_back(a*nums[j]*nums[j]+b*nums[j]+c);
                    j++;
                }
                else if(j >= nums.size())
                {
                    res.push_back(a*nums[i]*nums[i]+b*nums[i]+c);
                    i--;
                }
                else
                {
                    if(abs(mid - (double)nums[i]) > abs(mid - (double)nums[j]))
                    {
                        res.push_back(a*nums[j]*nums[j]+b*nums[j]+c);
                        j++;
                    }else{
                        res.push_back(a*nums[i]*nums[i]+b*nums[i]+c);
                        i--;
                    }
                }
            }
        }
        
        if(res.back()<res[0]) reverse(res.begin(),res.end());
        return res;
    }
};