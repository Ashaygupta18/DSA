//Basic DFS
class Solution {
  public:
    
    void dfs(int node,vector<vector<int>>& adj,int vis[],vector<int>& dfsOrder){
        vis[node] = 1;
        dfsOrder.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it,adj,vis,dfsOrder);
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        int vis[n] = {0};
        vector<int> dfsOrder;
        dfs(0,adj,vis,dfsOrder);
        return dfsOrder;
        
    }
};
