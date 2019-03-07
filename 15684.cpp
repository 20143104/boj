#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N, M, H, cnt = 1;
int map[31][31], visit[31][31], tmp[31][31];

struct pos{
    int x, y;
    pos(int _x, int _y){
        x = _x;
        y = _y;
    }
};
vector<pos> v;
void print(){
    for(int i=1; i<=H; i++){
        for(int k=1; k<=N; k++){
            cout << map[i][k] << " ";
        }
        cout << endl;
    }
}
void reset_map(){
    for(int i=1; i<=H; i++){
        for(int k=1; k<=N; k++){
            map[i][k] = tmp[i][k];
        }
    }
}
int see(pos p){
    memset(visit, 0, sizeof(visit));
    int x = p.x;
    int y = p.y;
    while(1){
        // cout << x << " " << y << endl;
        visit[x][y] = 1;
        if(x == H+1)
            return y;
        if(x<=H && y<=N){
            if(map[x][y] == 1 && visit[x][y+1] == 0)
                y+=1;
            else if(y-1>=1 && map[x][y-1] == 1 && visit[x][y-1] == 0)
                y-=1;
            else
                x+=1;
        }
        else
            return 0;
    }
}
int solve(){
    for(int i=1; i<=N; i++){
        if(see(pos(1, i)) == i)
            continue;
        else
        {
            return 0;
        }
    }
    return 1;
}
int func(){
    if(solve())
        return 0;
    for(int i=0; i<v.size(); i++){
        reset_map();
        map[v[i].x][v[i].y] = 1;
        if(solve())
            return 1;
    }

    for(int i=0; i<v.size(); i++){
        for(int k=i+1; k<v.size(); k++){
            reset_map();
            map[v[i].x][v[i].y] = 1;
            map[v[k].x][v[k].y] = 1;
            if(solve())
                return 2;
        }
    }
    for(int i=1; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            for(int k=j+1; k<v.size(); k++){
                reset_map();
                map[v[i].x][v[i].y] = 1;
                map[v[j].x][v[j].y] = 1;
                map[v[k].x][v[k].y] = 1;
                if(solve())
                    return 3;
            }
        }
    }

    return -1;
}

int main()
{
    cin >> N >> M >> H;

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        tmp[a][b] = 1;
    }
    for(int i=1; i<=H; i++){
        for(int k=1; k<=N; k++){
            if(map[i][k] == 0)
                v.push_back(pos(i, k));
        }
    }
    // print();

    // map[]
    cout << func();
    // print();
    // for(int i=1; i<=M; i++)
    //     cout << see(pos(1, i)) << endl;
}