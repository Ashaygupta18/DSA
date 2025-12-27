class Solution {
  
  private:
    bool DFS(int node,int parent,vector<int> adj[],vector<int>& vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(DFS(it,node,adj,vis)) return true;
            }
            else if(it != parent) return true;
        }
        return false;
    }
  
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> vis(V,0);
        vector<int> adj[V];
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(DFS(i,-1,adj,vis)) return true;
            }
        }
        return false;
    }
};
