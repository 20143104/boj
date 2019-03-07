#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos{
    int x, y, id;
    pos(int _x, int _y, int _id){
        x = _x;
        y = _y;
        id = _id;
    }
};
int map[15][15];
int N, M, res = 1e9;
vector<pos> v;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            cin >> map[i][k];
            if(map[i][k]>0 && map[i][k]<6)
                v.push_back(pos(i, k, map[i][k]));
        }
    }
}
void print(int a[15][15]){
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            cout << a[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void copymap(int a[15][15], int b[15][15]){
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            b[i][k] = a[i][k];
        }
    }
}
void see(int x, int y, int d, int tmp_map[15][15]){
    int nx = x + dir[d][0];
    int ny = y + dir[d][1];

    while(1){
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) return ;
        if(tmp_map[nx][ny] == 6) return ;
        if(tmp_map[nx][ny] == 0) tmp_map[nx][ny] = 7;

        nx += dir[d][0];
        ny += dir[d][1];
    }
}
void dfs(int pmap[15][15], int cnt){
    if(cnt == v.size()){
        // print(pmap);
        int tmp = 0;
        for(int i=0; i<N; i++){
            for(int k=0; k<M; k++){
                if(pmap[i][k] == 0)
                    tmp ++;
            }
        }

        res = min(res, tmp);
        return;
    }

    int tmp_map[15][15];
    copymap(pmap, tmp_map);

    int x = v[cnt].x;
    int y = v[cnt].y;
    int camera = v[cnt].id;

    if(camera == 1){
        for(int i=0; i<4; i++){
            see(x, y, i, tmp_map);
            dfs(tmp_map, cnt+1);
            copymap(pmap, tmp_map);
        }
    }
    else if(camera == 2){
        for(int i=0; i<2; i++){
            see(x, y, i, tmp_map);
            see(x, y, i+2, tmp_map);
            dfs(tmp_map, cnt+1);
            copymap(pmap, tmp_map);
        }
    }
    else if(camera == 3){
        for(int i=0; i<4; i++){
            see(x, y, i, tmp_map);
            see(x, y, (i+1)%4, tmp_map);
            dfs(tmp_map, cnt+1);
            copymap(pmap, tmp_map);
        }
    }
    else if(camera == 4){
        for(int i=0; i<4; i++){
            see(x, y, i, tmp_map);
            see(x, y, (i+1)%4, tmp_map);
            see(x, y, (i+2)%4, tmp_map);
            dfs(tmp_map, cnt+1);
            copymap(pmap, tmp_map);
        }

    }
    else if(camera == 5){
        for(int i=0; i<4; i++){
            see(x,y,i,tmp_map);
        }
        dfs(tmp_map, cnt+1);
        copymap(pmap, tmp_map);
    }
}
int main()
{
    input();
    dfs(map, 0);
    cout << res;
}