/*
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Hint:

Expected runtime complexity is in O(log n) and the input is sorted.
*/

/*
same
maybe I can do better
*/

class Solution {
public:
    int hIndex01(vector<int>& citations) {
        
        if(citations.empty()){return 0;}
        if(citations.size()==1){return bool(citations[0]);}
        int h = 0;
        while(true)
        {
            if(citations[citations.size() - h - 1] > h && h < citations.size())
            {
                h++;
            }else{
                return h;
            }
        }
        return h;
    }
    
    int hIndex(vector<int>& citations) {
        
        if(citations.empty()){return 0;}
        if(citations.size()==1){return bool(citations[0]);}
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