class Solution {
public:
    //[2 1 1 2]
    int bfs(vector<vector<int>>& grid,queue<pair<int,int>>&q) {
        int minute=-1;
        int col = grid[0].size();
        int row = grid.size();
        vector<pair<int,int>> elem={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int size = q.size(); //2
            minute++;
            for(int loop=0;loop<size;loop++){
                auto ele = q.front(); 
                int i = ele.first;
                int j = ele.second;
                q.pop();
                for (int t = 0; t<4; t++) {
                    int new_i = i+elem[t].first;
                    int new_j = j+elem[t].second;
                    if ( new_i <0 || new_i>=row || new_j <0 || new_j>=col) {
                        continue;
                    }
                    if( grid[new_i][new_j] == 1){
                        q.push({new_i,new_j});
                        grid[new_i][new_j] = 2;
                    }

                }
            }
        }
        return minute;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if( grid[i][j]==2 ){
                    q.push({i,j});
                }
            }
        }
        int result=0;
        result = bfs(grid,q);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if( grid[i][j]==1 ){
                   return -1;
                }
            }
        }
        return result<0 ? 0:result;
    }
};
