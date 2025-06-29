class Solution {
private:
    void bfs(int i , int j , vector<vector<char>> & grid , vector<vector<bool>> &visited){
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = true;
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if(x-1 >=0  && visited[x-1][y] == false && grid[x-1][y] == '1'){
                q.push({x-1,y});
                visited[x-1][y] = true;
            }

            if(y-1 >= 0 && visited[x][y-1] == false && grid[x][y-1] == '1'){
                q.push({x,y-1});
                visited[x][y-1] = true;
            }

            if(x+1 < n && visited[x+1][y] == false && grid[x+1][y] == '1'){
                q.push({x+1,y});
                visited[x+1][y] = true;
            }

            if(y+1 < m && visited[x][y+1] == false && grid[x][y+1] == '1'){
                q.push({x,y+1});
                visited[x][y+1] = true;
            }
        }


    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int count = 0;
        for(int i=0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++ ){
                if(!visited[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }


        return count;

    

         
    }
};