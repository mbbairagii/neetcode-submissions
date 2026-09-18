class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;

        int fresh=0;

        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]==2){
                    q.push({r,c});
                }
                else if(grid[r][c]==1){
                    fresh++;
                }
            }
        }

        int minutes=0;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};

        while(!q.empty() && fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto cell=q.front();
                q.pop();
                int r=cell.first;
                int c=cell.second;
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
            minutes++;
        }

        if(fresh>0){
            return -1;
        }

        return minutes;
    }
};
