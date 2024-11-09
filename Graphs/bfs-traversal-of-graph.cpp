class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        unordered_map<int,bool> visited;
        vector<int> ans;
        queue<int> q;
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for(int i = 0; i < adj[frontNode].size(); i++){
                if(visited[adj[frontNode][i]] == 0)
                    q.push(adj[frontNode][i]);
                    visited[adj[frontNode][i]]=1;
            }
        }
        return ans;
    }
};
