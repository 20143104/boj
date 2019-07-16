#include <iostream>
#include <vector>

using namespace std;

int N, M;
int board[302][302];
int visit[302][302], tmp[302][302];
int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

struct pos{
    int x, y, val;
    pos(int _x, int _y, int _v){
        x = _x;
        y = _y;
        val = _v;
    }
};
vector<pos> p;
void copy(int src[][302], int trg[][302]){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            trg[i][j] = src[i][j];
        }
    }
}
void clear(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            visit[i][j] = 0;
        }
    }
}
void dfs(int x, int y){
    visit[x][y] = 1;
    for(int i=0; i<4; i++){
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if(next_x>=0 && next_x < N && next_y >=0 && next_y < M && board[next_x][next_y] != 0 && visit[next_x][next_y] == 0){
            dfs(next_x, next_y);
        }
    }
}
int getNum(){
    int cnt = 0;
    clear();
    for(int i=0; i<p.size(); i++){
        int cur_x = p[i].x, cur_y = p[i].y;
        if(p[i].val != 0 && visit[cur_x][cur_y] == 0){
            cnt++;
            dfs(cur_x, cur_y);
        }
    }
    return cnt;
}

int melt(int cnt){
    while(true){
        cnt++;
        for(int i=0; i<p.size(); i++){
            int cur_x = p[i].x, cur_y = p[i].y, cur_val = p[i].val;
            int water = 0;
            for(int j=0; j<4; j++){
                int next_x = cur_x + dir[j][0];
                int next_y = cur_y + dir[j][1];
                if(next_x>=0 && next_x<N && next_y>=0 && next_y<M && board[next_x][next_y] == 0)
                    water ++;
            }

            if(cur_val - water <= 0){
                p[i].val = 0;
                tmp[p[i].x][p[i].y] = 0;
            }   
            else{
                p[i].val -= water;
                tmp[p[i].x][p[i].y] = p[i].val;
            }
        }
        copy(tmp, board);
        int num = getNum();
        if(num == 0)
            return 0;
        if(num != 1)
            return cnt;
    }
    return 0;
}
int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
            tmp[i][j] = board[i][j];
            if(board[i][j] != 0)
                p.push_back(pos(i, j, board[i][j]));
        }
    }

    cout << melt(0) << endl;
    return 0;
}