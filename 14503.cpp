#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, board[51][51], visit[51][51], r, c, d, ans;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // 상 우 하 좌
bool valid(int nx, int ny){
    if(nx > 0 && nx <=  N && ny > 0 && ny <= M && board[nx][ny] == 0) {
        return true;
    }
    return false;
}
int turn(int cd){
    return (cd+3)%4;
}
void dfs(int x, int y, int cd){
    if(board[x][y] == 0 && visit[x][y] == 0){
        ans ++;
        visit[x][y] = 1;
    }
    int td = turn(cd);
    bool chk = false, chk1 = false;
    while(true){
        if(td == turn(cd) && chk1){
            chk = true;
            break;
        }
        chk1 = true;
        if(valid(x + dir[td][0], y + dir[td][1]) && visit[x+dir[td][0]][y+dir[td][1]] == 0){
            dfs(x + dir[td][0], y + dir[td][1], td);
            break;
        }   
        td = turn(td);
    }
    if(chk){
        int nx = x - dir[cd][0], ny = y - dir[cd][1];
        if(valid(nx, ny))
            dfs(nx, ny, cd);
        else
            return ;
    }    
}

int main(){

    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &r, &c, &d);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%d", &board[i][j]);
        }
    }

    dfs(r+1, c+1, d);

    printf("%d", ans);
       
}