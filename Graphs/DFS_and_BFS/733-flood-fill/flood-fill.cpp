class Solution {

private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newcolor, int inicolor){
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = newcolor;
        int delcol[4] = {-1,0,1,0};
        int delrow[4] = {0,-1,0,1};

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && ans[nrow][ncol] != newcolor && image[nrow][ncol] == inicolor){
                dfs(nrow,ncol,ans,image,newcolor,inicolor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr,sc,ans,image,color,inicolor);
        return ans;
    }
};