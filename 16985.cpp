#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;

int layer[5][5][5];
int visit[5][5][5];
int v[5] = {0, 1, 2, 3, 4};
int res = 999999;
int dir[6][3] = { { 1, 0, 0},
                  { 0, 1, 0},
                  { 0, 0, 1},
                  {-1, 0, 0},
                  {0, -1, 0},
                  {0, 0, -1} };
void rotation(int layer[5][5]){
    
    int tmp[5][5];

    for(int i=0; i<5; i++){
        for(int k=0; k<5; k++){
            tmp[i][k] = layer[i][k];
        }
    }
    for(int i=0; i<5; i++){
        for(int k=0; k<5; k++){
            layer[k][4-i] = tmp[i][k];
        }
    }
}
struct pos{
    int x, y, z, d;
    pos(int _x, int _y, int _z, int _d){
        x = _x;
        y = _y;
        z = _z;
        d = _d;
    }
};
void reset_visit(){
    // for(int i=0; i<5; i++)
    //     for(int j=0; j<5; j++)
    //         for(int k=0; k<5; k++)
    //             visit[i][j][k] = 0;
    memset(visit, 0, sizeof(visit));
}
int main()
{
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                cin >> layer[i][j][k];
            }
        }
    }
    do{
        int puzzle[5][5][5];
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                for(int k=0; k<5; k++){
                    puzzle[i][j][k] = layer[v[i]][j][k];
                }
            }
        }

        for(int r0=0; r0<4; r0++){
            rotation(puzzle[0]);
            for(int r1 = 0; r1<4; r1++){
                rotation(puzzle[1]);
                for(int r2 = 0; r2<4; r2++){
                    rotation(puzzle[2]);
                    for(int r3 = 0; r3<4; r3++){
                        rotation(puzzle[3]);
                        for(int r4 = 0; r4<4; r4++){
                            rotation(puzzle[4]);

                            reset_visit();
                            queue<pos> q;
                            
                            if(puzzle[0][0][0] == 0)
                                continue;
                            q.push(pos(0, 0, 0, 0));
                            visit[0][0][0] = 1;
                            while(!q.empty()){
                                pos cur = q.front();
                                q.pop();
                                if(cur.x == 4 && cur.y == 4 && cur.z == 4)
                                    res = min(cur.d, res);

                                for(int i=0; i<6; i++){
                                    int next_x = cur.x + dir[i][0];
                                    int next_y = cur.y + dir[i][1];
                                    int next_z = cur.z + dir[i][2];
                                    if(next_x>=0 && next_x <5 && next_y>=0 && next_y<5 && next_z>=0 && next_z<5 && puzzle[next_x][next_y][next_z] == 1 && visit[next_x][next_y][next_z] == 0){
                                        q.push(pos(next_x, next_y, next_z, cur.d+1));
                                        visit[next_x][next_y][next_z] = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
        }
        
    }while(next_permutation(v, v+5));

    if(res == 999999)
        cout << -1;
    else
        cout << res;
    
}