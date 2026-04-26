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

BFS
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        unordered_map<Node*, Node*> umap;
        queue<Node*> q;

        Node* newNode = new Node(node->val);
        umap[node] = newNode;

        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (auto neigh : curr->neighbors) {

                if (umap.find(neigh) == umap.end()) {
                    umap[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }
                umap[curr]->neighbors.push_back(umap[neigh]);
            }
        }

        return newNode;
    }
};