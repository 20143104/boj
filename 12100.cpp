#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int N, mv;
int board[21][21], visit[21][21];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 상 하 좌 우

void copy(int src[][21], int trg[][21]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            trg[i][j] = src[i][j];
        }
    }
}
int valid(int arr[][21], int next_x, int next_y){
    if(next_x<0 || next_x>=N || next_y<0 || next_y >= N)
        return 0;
    else if(arr[next_x][next_y] == 0)
        return 1;
    else
        return 2;
}
int move_gravity(int arr[][21], int cur_x, int cur_y, int d){
    int cnt = 0;
    while(true){
        int next_x = cur_x +dir[d][0], next_y = cur_y + dir[d][1];
        int chk = valid(arr, next_x, next_y);
        if(chk == 0){
            return cnt;
        }
        else if(chk == 2){
            
            if(arr[cur_x][cur_y] == arr[next_x][next_y] && visit[next_x][next_y] == 0){
                cnt ++;
                arr[cur_x][cur_y] = 0;
                arr[next_x][next_y] *= 2;
                visit[next_x][next_y] = 1;
            }
            else;
            return cnt;
        }
        else{
            cnt++;
            arr[next_x][next_y] = arr[cur_x][cur_y];
            arr[cur_x][cur_y] = 0;
            cur_x = next_x;
            cur_y = next_y;
        }
    }
    return cnt;
}
int move(int arr[][21], int d){
    memset(visit, 0, sizeof(visit));
    //상 좌
    int cnt = 0;
    if(d ==0 || d == 2){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                    if(arr[i][j] != 0)
                        cnt += move_gravity(arr, i, j, d);
            }
        }
    }
    else{
        for(int i = N-1; i>=0; i--){
            for(int j=N-1; j>=0; j--){
                if(arr[i][j] != 0)
                    cnt += move_gravity(arr, i, j, d);
            }
        }
    }
    return cnt;
}
void get_max(int arr[][21]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            mv = max(mv, arr[i][j]);
        }
    }
}
void dfs(int arr[][21], int prev, int cnt){
    if(cnt > 5)
        return ;
    get_max(arr);
    int tmp[21][21];
    
    for(int i=0; i<4; i++){
        copy(arr, tmp);
        int chk = move(tmp, i);
        if(chk != 0){
            dfs(tmp, i, cnt+1);
        }
    }
}
int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
            mv = max(board[i][j], mv);
        }
    }
    dfs(board, 0, 0);
    cout << mv << endl;
}