#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int N, M, ans;
int farm[101][101];
int visit[101][101];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
struct pos{
    int x, y;
    pos(int _x, int _y){
        x = _x;
        y = _y;
    }
};
vector<pos> v;
void bfs(pos start){
    queue<pos> q;

    visit[start.x][start.y] = 1;
    q.push(start);

    while(!q.empty()){
        pos cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int next_x = cur.x + dir[i][0];
            int next_y = cur.y + dir[i][1];

            if(next_x>=0 && next_x<N && next_y>= 0 && next_y < M && farm[next_x][next_y] == 1 && visit[next_x][next_y] == 0){
                visit[next_x][next_y] = 1;
                q.push(pos(next_x, next_y));
            }
        }
    }
}
void print(int board[][101]){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int numtestcases;
    cin >> numtestcases;
    while(numtestcases--){
        int cnt;
        cin >> M >> N >> cnt;

        memset(farm, 0, sizeof(farm));
        memset(visit, 0, sizeof(visit));
        v.clear();
        for(int i=0; i<cnt; i++){
            int x, y;
            cin >> y >> x;
            farm[x][y] = 1;
            v.push_back(pos(x, y));   
        }
        int ans = 0;
        for(int i=0; i<v.size(); i++){
            if(visit[v[i].x][v[i].y] == 0){
                bfs(v[i]);
                ans ++;
            }   
        }
        cout << ans << "\n";
    }
    


}