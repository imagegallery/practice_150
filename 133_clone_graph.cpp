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
    Node* dfs(Node* node, unordered_map<Node*, Node*> &mp){
        vector<Node*> temp;
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(auto iter: node->neighbors){
            if(mp.find(iter) == mp.end())
                temp.push_back(dfs(iter, mp));
            else
                temp.push_back(mp[iter]);
        }
        clone->neighbors = temp;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        if(node->neighbors.size() == 0)
            return new Node(node->val);
        
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
        
        // queue<Node*> q;
        // mp[node] = new Node(node->val);
        // q.push(node);

        // while(!q.empty()){
        //     Node* temp = q.front();
        //     q.pop();

        //     for(auto iter:temp->neighbors){
        //         if(mp.find(iter) == mp.end()){
        //             mp[iter] = new Node(iter->val);
        //             q.push(iter);
        //         }
        //         mp[temp]->neighbors.push_back(mp[iter]);
        //     }
        // }
        // return mp[node];
    }
};                                        