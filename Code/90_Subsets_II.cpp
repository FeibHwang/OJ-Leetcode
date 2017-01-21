/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

/*
Since the array may contain dublicate
first find them: using hash map record dublicate, construct vector without duplicate
for the vector without duplicate, treated like subsets I
then sweeping hash map to adding duplicate number
*/

class Solution {
public:
    
    vector<int> only_single;
    unordered_map<int,int> only_dublicate;

    
    void seperate(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            only_dublicate[nums[i]]++;
        }
        
        for(auto item:only_dublicate)
        {
            if(item.second==1) only_single.push_back(item.first);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> start = {};
        result.push_back(start);
        
        if(nums.empty())  return result;
        
        vector<int> body(nums.begin(),nums.end()-1);
        result = subsets(body);
        
        int tail = *(nums.end()-1);
        int length = result.size();
        for(int i = 0; i < length; ++i)
        {
            vector<int> tmp = result[i];
            tmp.push_back(tail);
            result.push_back(tmp);
        }
        
        return result;
    }

    
    vector<vector<int>> subsetsWithDup01(vector<int>& nums) {
        seperate(nums);
        vector<vector<int>> ans = subsets(only_single);
        for(auto item: only_dublicate)
        {
            if(item.second>1)
            {
                vector<vector<int>> tmp = ans;
                for(int j = 1; j <= item.second; j++)
                {
                    for(int k = 0; k < tmp.size(); ++k)
                    {
                        tmp[k].push_back(item.first);
                    }
                    ans.insert(ans.end(),tmp.begin(),tmp.end());
                }
            }
        }
        return ans;
    }


    /*
DFS solution:
each duplicate has multiple choice, 
so need to avoid duplicate solution
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        DFS(nums,0);
        
        return res;
    }
        
    vector<vector<int>> res;
    vector<int> path;
        
    void DFS(const vector<int>& nums, int start)
    {
        res.push_back(path);
        for(int i = start; i < nums.size(); i++)
        {
            if(i!=start && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            DFS(nums,i+1);
            path.pop_back();
        }
    }   
};
};