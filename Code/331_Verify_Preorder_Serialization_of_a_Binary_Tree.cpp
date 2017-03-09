/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
*/

/*
I use 2 stack
1: to hold fake tree node
2: to hold the state of this node searching state: 0:search the left, 1:search the right, 2:pop

once there is a new non empty node:
push value to stack 1
push 0 to stack 2, indicating I will continue search the node left

once there is an empty node:
if stack 2 top is 0, modify it to 1, meaning I will search the right
if stack 2 top is 1, meaning I have search the right
    while stack not empty
        if stack 2 top is 1, pop stack 1/2
        else modify the stack 2 top to 1, break
        

special cases:
"#" is valid
"#,#" is invalid
if stack empty in the middle, meaning the previous node form a valid tree, if there is rest node, then it's invalid
if stack not empty after sweeping, not valid
*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty() || preorder=="#") return true;
        stack<int> rec;
        stack<int> state;
        preorder.push_back(',');
        
        for(int i = 0; i < preorder.length(); ++i)
        {
            if(preorder[i]==',')
            {
                if(preorder[i-1]=='#')
                {
                    if(state.empty() || rec.empty()) return false;
                    if(state.top()==0)
                    {
                        state.pop();
                        state.push(1);
                    }
                    else
                    {
                        while(!state.empty())
                        {
                            if(state.top()==1) {rec.pop();state.pop();}
                            else{state.pop();state.push(1);break;}
                        }
                    }
                }else{
                    rec.push(preorder[i-1]);
                    state.push(0);
                }
                if(rec.empty() && i!=preorder.size()-1) return false; 
            }
        }
        
        return rec.empty();
    }
};