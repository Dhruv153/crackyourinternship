class Solution {
  public:
  void dfs(vector<int>& ans,unordered_map<int,bool>& visited,vector<vector<int>>& adj,int start){
      visited[start]=1;
      ans.push_back(start);
      for(auto i : adj[start]){
          if(!visited[i])
            dfs(ans,visited,adj,i);
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int,bool> visited;
        vector<int> ans;
        dfs(ans,visited,adj,0);
        return ans;
    }
};
