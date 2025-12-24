class Solution {
public:
    void dfs(vector<vector<char>>& grid, int m, int n) {
        grid[m][n] = '0';
        if (m != 0 && grid[m - 1][n] != '0'){
            dfs(grid, m - 1, n);
        }
        if (n != 0 && grid[m][n - 1] != '0'){
            dfs(grid, m, n - 1);
        }
        if (m < grid.size() - 1 && grid[m + 1][n] != '0'){
            dfs(grid, m + 1, n);
        }
        if (n < grid[0].size() - 1 && grid[m][n + 1] != '0'){
            dfs(grid, m, n + 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int m = 0; m < grid.size(); m++)
        {
            for (int n = 0; n < grid[0].size(); n++)
            {
                if (grid[m][n] == '1'){
                    dfs(grid, m, n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};