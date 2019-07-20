#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N, M, ans;
int city[101][101];
int visit[101][101];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
struct pos{
    int x, y;
    pos(int _x, int _y){
        x = _x;
        y = _y;
    }
};

void bfs(pos start, int rain){
    queue<pos> q;
    q.push(start);
    visit[start.x][start.y] = 1;
    while(!q.empty()){
        pos cur = q.front();
        visit[cur.x][cur.y] = 1;
        q.pop();

        for(int i=0; i<4; i++){
            int next_x = cur.x + dir[i][0];
            int next_y = cur.y + dir[i][1];

            if(next_x>=0 && next_x<N && next_y>=0 && next_y<N && visit[next_x][next_y] == 0 && city[next_x][next_y] > rain){
                visit[next_x][next_y] = 1;
                q.push(pos(next_x, next_y));
            }
                
        }
    }
}

int get_result(int rain){
    int cnt = 0;
    memset(visit, 0, sizeof(visit));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(city[i][j] > rain && visit[i][j] == 0){
                cnt++;
                bfs(pos(i, j), rain);
            }
        }
    }
    return cnt;
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> city[i][j];
            M = max(M, city[i][j]);
        }
    }

    for(int i=0; i<M; i++)
        // cout << i << " ";
        ans = max(ans, get_result(i));
    cout << ans << endl;


}