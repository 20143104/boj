#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct pos{
    int x;
    int y;
    pos(int _x, int _y){ x = _x; y = _y;}
};

int R, C, T;
int board[52][52], tmp[52][52];
pos cleaner(0, 0);
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<pos> v;

void copy(int src[][52], int trg[][52]){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            trg[i][j] = src[i][j];
        }
    }
}
bool valid(int x, int y){
    if( x < 1 || x > R || y < 1 || y > C || board[x][y] == -1)
        return false;
    return true;
}
void spread(){
    memset(tmp, 0, sizeof(tmp));
    tmp[cleaner.x][cleaner.y] = -1;
    tmp[cleaner.x-1][cleaner.y] = -1;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(board[i][j] <= 0) continue;
            v.clear();
            for(int k=0; k<4; k++){
                int nx = i + dir[k][0]; int ny = j + dir[k][1];
                if(valid(nx, ny)) v.push_back(pos(nx, ny));
            }
            int t = board[i][j] / 5;
            for(int k=0; k<v.size(); k++){
                tmp[v[k].x][v[k].y] += t;
            }
            tmp[i][j] += (board[i][j] - t * v.size());
        }
    }

    copy(tmp, board);
}
void clean_up(){
    //반시계
    int sx = cleaner.x-1, sy = cleaner.y, cd = 3;
    int t = 3;
    while(true){
        int nx = sx+dir[cd][0], ny = sy+dir[cd][1];
        if(!valid(nx, ny) && cd == 1){
            tmp[nx][ny] = -1;
            break;
        }
        if(!valid(nx, ny)){
            if(cd == 3) cd = 0;
            else if(cd == 0) cd = 2;
            else if(cd == 2) cd = 1;
        }
        nx = sx+dir[cd][0]; ny = sy+dir[cd][1];
        
        if(board[nx - dir[cd][0]][ny - dir[cd][1]] == -1)
            tmp[nx][ny] = 0;
        else
            tmp[nx][ny] = board[nx - dir[cd][0]][ny - dir[cd][1]];
        
        sx = nx; sy = ny;
    }

    copy(tmp, board);

}
void clean_down(){
    // 시계
    int sx = cleaner.x, sy = cleaner.y, cd = 3;

    while(true){
        int nx = sx+dir[cd][0], ny = sy+dir[cd][1];
        if(!valid(nx, ny) && cd == 0){
            tmp[nx][ny]= -1;
            break;
        }
        if(!valid(nx, ny)){
            if(cd == 3) cd = 1;
            else if(cd == 1) cd = 2;
            else if(cd == 2) cd = 0;
        }
        nx = sx+dir[cd][0]; ny = sy+dir[cd][1];
        
        if(board[nx - dir[cd][0]][ny - dir[cd][1]] == -1)
            tmp[nx][ny] = 0;
        else
            tmp[nx][ny] = board[nx - dir[cd][0]][ny - dir[cd][1]];
        
        sx = nx; sy = ny;
    }
    copy(tmp, board);

}
int main(){
    scanf("%d %d %d", &R, &C, &T);
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            scanf("%d", &board[i][j]);
            if(board[i][j] == -1){
                tmp[i][j] = -1;
                cleaner = pos(i, j);
            }
        }
    }

    for(int i=0; i<T; i++){
        spread();
        clean_up();
        clean_down();
    }
    int ans = 0;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(board[i][j] > 0)
                ans += board[i][j];
        }
    }
    printf("%d", ans);
}