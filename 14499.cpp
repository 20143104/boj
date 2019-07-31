#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

struct pos{
    int x; int y;
    pos(int _x, int _y){
        x = _x; y = _y;
    }
};
int N, M, x, y, k;
int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
pos cur(0, 0);
int board[21][21], dice[6];

bool valid(int nx, int ny){
    if(nx <0 || nx >= N || ny <0 || ny>=M)
        return 0;
    return 1;
}
void turn(int d){
    int q, w, e ,r;
    if(d == 0){
        q = dice[2];
        w = dice[1];
        e = dice[5];
        r = dice[3];
        dice[2] = r;
        dice[1] = q;
        dice[5] = w;
        dice[3] = e;
    }
    else if(d == 1){
        q = dice[2];
        w = dice[1];
        e = dice[5];
        r = dice[3];

        dice[2] = w;
        dice[1] = e;
        dice[5] = r;
        dice[3] = q;
    }
    else if(d == 2){
        q = dice[2];
        w = dice[0];
        e = dice[5];
        r = dice[4];

        dice[2] = r;
        dice[0] = q;
        dice[5] = w;
        dice[4] = e;
    }
    else if(d == 3){
        q = dice[2];
        w = dice[0];
        e = dice[5];
        r = dice[4];

        dice[2] = w;
        dice[0] = e;
        dice[5] = r;
        dice[4] = q;
    }
}
void solve(int d){
    int nx = cur.x + dir[d][0];
    int ny = cur.y + dir[d][1];
    if(!valid(nx, ny)){
        return ;
    }

    turn(d);

    if(board[nx][ny] == 0){
        board[nx][ny] = dice[2];
    }

    else{
        dice[2] = board[nx][ny];
        board[nx][ny] = 0;
    }

    cur = pos(nx, ny);
    printf("%d\n", dice[5]);
}

int main(){
    scanf("%d %d", &N, &M);
    scanf("%d %d", &x, &y);
    scanf("%d", &k);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int t; scanf("%d", &t);
            board[i][j] = t;
        }
    }
    cur = pos(x, y);
    for(int i=0; i<k; i++){
        int d; scanf("%d", &d);
        solve(d-1);
    }
}
