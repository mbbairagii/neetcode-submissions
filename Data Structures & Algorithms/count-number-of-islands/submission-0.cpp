class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]=='0'){
            return;
        }

        grid[r][c]='0';

        dfs(r-1,c,grid);
        dfs(r+1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]=='1'){
                    islands++;
                    dfs(r,c,grid);
                }
            }
        }
        return islands;
    }
};
