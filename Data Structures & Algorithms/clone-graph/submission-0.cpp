/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*,Node*>&umap){
        if (!node){
            return NULL;
        }
        if (umap.find(node)!=umap.end()){
            return umap[node];
        }
        Node* newNode=new Node(node->val);
        umap[node]=newNode;

        for (auto itr:node->neighbors){
            newNode->neighbors.push_back(dfs(itr, umap));
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> umap;    
        return dfs(node, umap);
    }
};
