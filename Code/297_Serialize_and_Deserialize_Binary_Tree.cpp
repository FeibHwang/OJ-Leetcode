/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

/*
Using BFS
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "[]";
        queue<TreeNode*> que;
        que.push(root);
        vector<string> res;
        bfs(que,res);
        while(res.back()=="null") res.pop_back();
        string resstr = "[";
        for(int i = 0; i < res.size()-1; ++i) resstr += (res[i]+",");
        return resstr + res.back() + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
	if (data == "[]") return{};
	int left = 1;
	data[data.size() - 1] = ',';
	vector<string> rec;
	for (int right = 1; right < data.size(); ++right)
	{
		if (data[right] == ',')
		{
			rec.push_back(data.substr(left, right - left));
			left = right + 1;
		}
	}

	queue<TreeNode*> que;
	TreeNode *root = new TreeNode(string_to_digit(rec[0]));
	que.push(root);
	TreeNode *cnt = root;
	int i = 1;
	while (i < rec.size())
	{
		if (i % 2 == 1)
		{
			if (rec[i] != "null") {
				cnt->left = new TreeNode(string_to_digit(rec[i]));
				que.push(cnt->left);
			}
		}
		else{
			if (rec[i] != "null")
			{
				cnt->right = new TreeNode(string_to_digit(rec[i]));
				que.push(cnt->right);
			}
			que.pop();
			cnt = que.front();
		}
		i++;
	}
	return root;
}
    
private:
    void bfs(queue<TreeNode*>& que, vector<string>& res)
    {
        while(!que.empty())
        {
            TreeNode* cnt = que.front(); que.pop();
            if(cnt!=nullptr)
            {
                que.push(cnt->left);
                que.push(cnt->right);
                res.push_back(to_string(cnt->val));
            }else{
                res.push_back("null");
            }
        }
    }
    
    inline int string_to_digit(string num)
    {
    	int sign = num[0] == '-' ? -1:1;
    	int begin = num[0] == '-' ? 1: 0;
    	int sum = 0;
    	while (begin<num.size())
    	{
    		sum = 10 * sum + num[begin++] - '0';
    	}
    	return sign*sum;
    }
};