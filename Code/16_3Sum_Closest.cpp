/********************************************************************************** 
* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
* Return the sum of the three integers. 
* You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
**********************************************************************************/


/********************************************************************************** 
* first sort array
* use brute force to check:
*     initial: num[0] + num[1] + num[num.size()-1]
*     by comparing the sum and the target to decide to move the larger or smaller number
**********************************************************************************/
class Solution {
public:
 int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  sort(num.begin(),num.end());
  int n = num.size();
  int min = 0x7fffffff;
  int sum = 0;
  int result;
  for(int i=0; i<n; ++i)
  {
   int j = i+1;
   int k = n-1;
   while(j<k)
   {
    sum = num[i] + num[j] + num[k];
    if(sum == target)
    {
     return sum;
    }
    if(sum < target)
    {
     if(abs(sum - target) < min)
     {
      min = abs(sum - target);
      result = sum;
     }
     ++j;
    }
    else
     if( sum > target)
     {
      if(abs(sum - target) < min)
      {
       min = abs(sum - target);
       result = sum;
      }
      --k;
     }
   }
  }
  return result;
    }
};