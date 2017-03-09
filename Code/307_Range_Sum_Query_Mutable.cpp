/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
*/

/*

Using segment tree
build: O(n)
update: O(logn)
sumRange: O(logn)

*/

class NumArray {
public:
    NumArray(vector<int> nums) {
        head = build(nums,0,nums.size()-1,head);
    }
    
    void update(int i, int val) {
        renew(i,val,head);
    }
    
    int sumRange(int i, int j) {
        return search(i,j,head);
    }
    
private:
    struct SegmentTreeNode
    {
        int sum;
        int range_left;
        int range_right;
        SegmentTreeNode *left;
        SegmentTreeNode *right;
        SegmentTreeNode(int s, int l,int r):sum(s),range_left(l),range_right(r),left(nullptr),right(nullptr){}
    };
    
    SegmentTreeNode* head;
    SegmentTreeNode* build(vector<int>& nums, int l, int r, SegmentTreeNode* root)
    {
        if(r<0) return nullptr;
        if(l==r) 
        {
            root = new SegmentTreeNode(nums[l],l,r);
        }
        else
        {
            int mid = (l+r)/2;
            root = new SegmentTreeNode(nums[l],l,r);
            root->left = build(nums,l,mid,root->left);
            root->right = build(nums,mid+1,r,root->right);
            root->sum = root->left->sum + root->right->sum;
        }
        return root;
    }
    
    int search(int i, int j, SegmentTreeNode* root)
    {
        if(root->range_left>j || root->range_right < i) return 0;
        if(root->range_right <= j && root->range_left >= i) return root->sum;
        return search(i,j,root->left)+search(i,j,root->right);
    }
    
    void renew(int i, int val, SegmentTreeNode* root)
    {
        if(root->range_left==root->range_right && root->range_left==i) 
        {
            root->sum = val;
            return;
        }
        if(root->range_left>i || root->range_right<i) return;
        renew(i,val,root->left);
        renew(i,val,root->right);
        root->sum = root->left->sum+root->right->sum;
        
    }
    
};