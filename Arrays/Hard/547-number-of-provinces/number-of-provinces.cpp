class Solution {
public:
    
    void dfs(int node, vector<vector<int>>& adjLS, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adjLS[node]) {
            if (!vis[it]) {
                dfs(it, adjLS, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adjLS(v);

        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);
                }
            }
        }

        vector<int> vis(v, 0);
        int cnt = 0;

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                dfs(i, adjLS, vis);
                cnt++;
            }
        }
        return cnt;
    }
};
