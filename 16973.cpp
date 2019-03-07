#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>
#include <vector>
using namespace std;

int N, M, H, W;
int Sr, Sc, Fr, Fc;
int puzzle[1003][1003];
int tmp[1003][1003];
int visit[1003][1003];
int res = 999999;
int dir[4][2] = { {0, 1},
                  {0, -1},
                  {1, 0},
                  {-1, 0} };

struct pos{
    int x, y, d;
    pos(int _x, int _y, int _d){
        x = _x;
        y = _y;
        d = _d;
    }
};

vector<pos> v;
bool is_(int x, int y){
    for(int i=0; i<H; i++){
        for(int k=0; k<W; k++){
            if(puzzle[x+i][y+k] == 1)
                return false;
        }
    }

    return true;
    
}
int main()
{
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int k=1; k<=M; k++){
            cin >> puzzle[i][k];
            tmp[i][k] = puzzle[i][k];
        }
    }

    cin >> H >> W >> Sr >> Sc >> Fr >> Fc;

    // for(int i=1; i<= N; i++){
    //     for(int k=1; k<=M; k++)
    //         cout << tmp[i][k] << " ";
    //     cout << endl;
    // }
    for(int i=1; i<=N; i++){
        for(int k=1; k<=M; k++){
            if(tmp[i][k] == 1){
                int r_Min = max(1, i - H + 1);
                int c_Min = max(1, k - W + 1);
                // cout << r_Min << " " << r_Max << " " << c_Max << " " << c_Min << endl;
                for(int r = r_Min; r<= i; r++){
                    for(int c = c_Min; c<= k; c++){
                        puzzle[r][c] = 1;
                    }
                }
            }
        }
    }

    // for(int i=1; i<= N; i++){
    //     for(int k=1; k<=M; k++)
    //         cout << puzzle[i][k] << " ";
    //     cout << endl;
    // }
    queue<pos> q;
    q.push(pos(Sr, Sc, 0));
    visit[Sr][Sc] = 1;

    while(!q.empty()){
        pos cur = q.front();
        q.pop();
        if(cur.x == Fr && cur.y == Fc)
            res = min(res, cur.d);

        for(int i=0; i<4; i++){
            int next_x = cur.x + dir[i][0];
            int next_y = cur.y + dir[i][1];
            if(next_x >=1 && next_y >= 1 && next_x+H-1 <= N && next_y+W-1 <= M && puzzle[next_x][next_y] == 0 && visit[next_x][next_y] == 0){
                // cout << next_x << " " << next_y << endl;
                q.push(pos(next_x, next_y, cur.d+1));
                visit[next_x][next_y] = 1;
            }
        }
    }


    if(res == 999999)
        cout << -1;
    else
    {
        cout << res;
    }
    

}