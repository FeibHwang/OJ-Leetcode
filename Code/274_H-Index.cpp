/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

Hint:

An easy approach is to sort the array first.
What are the possible values of h-index?
A faster approach is to use extra space.
*/

/*
the more complex the instruction, the easier the implentation will be
*/

class Solution {
public:
    int hIndex01(vector<int>& citations) {
        if(citations.empty()){return 0;}
        if(citations.size()==1){return bool(citations[0]);}
        
        sort(citations.begin(),citations.end());
        int left = 0;
        int right = citations.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(citations[mid]==citations.size()-mid)
            {
                return citations.size()-mid;
            }
            else if(citations[mid]<citations.size()-mid){
                left = mid+1;
            }
            else right = mid - 1;
        }
        return citations.size()-left;
    }
    
    int hIndex(vector<int>& citations) {
        if(citations.empty()){return 0;}
        if(citations.size()==1){return bool(citations[0]);}
        
        sort(citations.begin(),citations.end());
        int left = 0;
        int right = citations.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(citations[mid]==citations.size()-mid)
            {
                return citations.size()-mid;
            }
            else if(citations[mid]<citations.size()-mid){
                left = mid+1;
            }
            else right = mid - 1;
        }
        return citations.size()-left;
    }
};