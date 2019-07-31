#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

struct shark{
    int x, y, v, d, z; // 좌표 속력 방향 크기
    shark(int _x, int _y, int _v, int _d, int _z){
        x = _x; y = _y; v = _v; d = _d; z = _z;
    }
};
int R, C, M, ans;
int islive[10000];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} }; // 상 하 우 좌
vector<shark> v;

int turn(int d){
    if(d == 0)
        return 1;
    else if(d == 1)
        return 0;
    else if(d == 2)
        return 3;
    else if(d == 3)
        return 2;

    return 100;
}
void _catch(int row){
    int sx = 0, sy = row;
    while(sx <= R){
        for(int i=0; i<v.size(); i++){
            if(islive[i]){
                if(sx == v[i].x && sy == v[i].y){
                    islive[i] = 0;
                    ans += v[i].z;
                    return ;
                }       
            }
        }
        sx++;
    }
}
void move(int row){

    for(int i=0; i<v.size(); i++){
        if(!islive[i]) continue;
        int cx = v[i].x, cy = v[i].y, cv = v[i].v, cd = v[i].d, cz = v[i].z;
        for(int j=0; j<cv; j++){
            int nx = cx + dir[cd][0], ny = cy + dir[cd][1], nd = cd;
            if(nx < 1 || nx > R || ny < 1 || ny > C){
                nd = turn(cd);
                nx = cx + dir[nd][0]; ny = cy + dir[nd][1];
            }
            cx = nx; cy = ny; cd = nd;
        }

        v[i].x = cx; v[i].y = cy; v[i].d = cd;

        for(int j=0; j<i; j++){
            if(!islive[j]) continue;
            if(v[j].x == v[i].x && v[j].y == v[i].y){
                if(v[j].z > v[i].z){
                    islive[i] = 0;
                }
                else{
                    islive[j] = 0;
                }
            }
        }
    }
}
void solve(int row){
    if(row == C){
        return ;
    }
    row++;
    
    _catch(row);
    move(row);
    solve(row);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    scanf("%d %d %d", &R, &C, &M);
    int tx, ty, tv, td, tz;
    for(int i=0; i<M; i++){
        scanf("%d %d %d %d %d", &tx, &ty, &tv, &td, &tz);
        v.push_back(shark(tx,ty,tv,td-1,tz));
        islive[i] = 1;
    }
    solve(0);
    cout << ans;
}