/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/


/*
Leetcode top solution
using two mid pointer to perform binary search
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size(); 
        
        if(N1 < N2) return findMedianSortedArrays(nums2,nums1);
        if(N2 == 0) return ((double)nums1[(N1-1)/2] + (double)nums1[N1/2])/2;
        
        int lo = 0, hi = 2*N2;
        while(lo <= hi)
        {
            int mid2 = (lo + hi)/2;
            int mid1 = N1 + N2 - mid2;
            
            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2]; 
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2]; 
            double R1 = (mid1 == N1*2) ? INT_MAX : nums1[mid1 / 2];
            double R2 = (mid2 == N2*2) ? INT_MAX : nums2[mid2 / 2];
            
            if(L1 > R2) lo = mid2 + 1;
            else if(L2 > R1) hi = mid2 - 1;
            else return (max(L1,L2) + min(R1,R2)) / 2;
        }
        return -1;
    }
};