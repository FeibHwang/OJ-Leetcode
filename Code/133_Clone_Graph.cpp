/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/*
dfs solution:
new function clonedfs:
using haswh map to check whether the point is record
if not record, creat new UndirectedGraphNode, associate with hash map,
search the original neighbor: 
    if not record, clonedfs(neighbor), push return node to cloned neighbor
    if record, push the hash map value into cloned neighbor
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if (!node) return nullptr;
    	return clonedfs(node);
    }
    
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> clone_rec;
    
    UndirectedGraphNode * clonedfs(UndirectedGraphNode *node)
    {
        UndirectedGraphNode* tmp = new UndirectedGraphNode(node->label);
    	clone_rec[node] = tmp;
    	for (int i = 0; i < node->neighbors.size(); ++i)
    	{
    		if (clone_rec.find(node->neighbors[i]) == clone_rec.end())
    		{
    			UndirectedGraphNode *tmp_node = clonedfs(node->neighbors[i]);
    			tmp->neighbors.push_back(tmp_node);
    		}else{
    			tmp->neighbors.push_back(clone_rec[node->neighbors[i]]);
    		}
    	}
    	return tmp;
    }
};