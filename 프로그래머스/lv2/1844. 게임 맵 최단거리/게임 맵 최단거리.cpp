#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int col = maps.size(); // col == 열, row의 사이즈
    int row = maps[0].size(); //row == 행, col의 사이즈
    int dx[4]{1,-1,0,0};
    int dy[4]{0,0,1,-1};
    vector<vector<int>> visited;
    queue<pair<int,int>> q;
    visited.resize(col,vector<int>(row,-1));
    
    visited[0][0] = 1;
    q.push({0,0});
    
    while(!q.empty()){
        auto a = q.front();
        int x = a.first;
        int y = a.second;
        q.pop();
        
        
        
        for(int i =0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= col|| ny >= row ) continue;
            if(visited[nx][ny] == -1 && maps[nx][ny] == 1)
            {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
    
    answer = visited[col-1][row-1];
    return answer;
}