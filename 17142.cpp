#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

struct pos{
    int x; int y;
    pos(int _x, int _y){
        x = _x; y = _y;
    }
};
int N, M, ans = 1000000;
int board[51][51], tmp[51][51];
int visit[51][51];
int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
vector<pos> virus;

void copy(int src[][51], int trg[][51]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            trg[i][j] = src[i][j];
        }
    }
}
int get_ans(int arr[][51]){
    int time = 0 ;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
                if(arr[i][j] == 0)
                    return -1;
            
                else if(arr[i][j] > 0)
                    time = max(time, arr[i][j]);
        }
    }
    return time;
}
void spread(vector<int> arr){
    copy(tmp, board);
    for(int i=0; i<virus.size(); i++){
        board[virus[i].x][virus[i].y] = -2; // 비활성
    }
    for(int i=0; i<arr.size(); i++){
        board[virus[arr[i]].x][virus[arr[i]].y] = -1; // 활성
    }


    for(int i = 0; i < arr.size(); i++){
        memset(visit, 0, sizeof(visit));
        
        queue<pos> q;
        q.push(virus[arr[i]]);
        visit[virus[arr[i]].x][virus[arr[i]].y] = 1;
        

        while(!q.empty()){
            pos cur = q.front();
            q.pop();
            int time;
            if(board[cur.x][cur.y] == -1)
                time = 0;
            else
                time = board[cur.x][cur.y];
            
            for(int i=0; i<4; i++){
                int next_x = cur.x + dir[i][0];
                int next_y = cur.y + dir[i][1];
                if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && visit[next_x][next_y] == 0 && board[next_x][next_y] != -3){
                    if(board[next_x][next_y] ==0){
                        visit[next_x][next_y] = 1;
                        board[next_x][next_y] = time+1;
                        q.push(pos(next_x, next_y));
                    }
                    else if(board[next_x][next_y] > time+1){
                        visit[next_x][next_y] = 1;
                        board[next_x][next_y] = time+1;
                        q.push(pos(next_x, next_y));
                    }
                    else if(board[next_x][next_y] == -2){
                        for(int j=0; j<4; j++){
                            int nnx = next_x + dir[j][0];
                            int nny = next_y + dir[j][1];
                            if(nnx<0 || nnx >= N || nny <0 || nny >= N) continue;
                            if(board[nnx][nny] == 0){
                                visit[next_x][next_y] = 1;
                                board[next_x][next_y] = time+1;
                                q.push(pos(next_x, next_y));
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    int t = get_ans(board);
    if(t != -1){
        ans = min(t, ans);
    }
}
void dfs(vector<int> q, int s){
    q.push_back(s);
    if(q.size() == M){
        spread(q);
        q.pop_back();
        return ;
    }
    for(int i=s+1; i<virus.size(); i++)
        dfs(q, i);
}
int main(){

    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int t;
            scanf("%d", &t);
            if(t == 1){
                board[i][j] = -3;
            }
            else{
                board[i][j] = t;
            }
            tmp[i][j] = board[i][j];
            if(board[i][j] == 2)
                virus.push_back(pos(i, j));
        }
    }
    
    vector<int> arr;
    for(int i=0; i<virus.size()-1; i++)
        dfs(arr, i);

    if(ans == 1000000)
        printf("%d", -1);
    else
        printf("%d", ans);
}