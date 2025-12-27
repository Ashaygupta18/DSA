class Solution {
public:
    bool bfs(int start, vector<vector<int>>& adj, vector<int>& visited) {
        queue<pair<int,int>> q;
        q.push({start, -1});
        visited[start] = 1;

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = 1;
                    q.push({nei, node});
                }
                // if visited and not parent → cycle
                else if (nei != parent) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // Build UNDIRECTED adjacency list
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(V, 0);

        // Check each component
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfs(i, adj, visited)) 
                    return true;
            }
        }
        return false;
    }
};
