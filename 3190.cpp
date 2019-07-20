#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

struct pos{
    int x; 
    int y; 
    pos (int _x, int _y){
        x = _x;
        y = _y;
    }
};

int N, K, L, ans;
typedef vector<vector<int> > mat;
int dir[4][2] = { {-1, 0}, {1, 0}, {0,-1}, {0, 1} }; //상 하 좌 우
deque<pos> snake;

bool finish(mat arr, pos p){
    if(p.x < 0 || p.x >= N || p.y < 0 || p.y >= N || arr[p.x][p.y] == 1)
        return 1;
    return 0;
}
int get_direction(int cur, char turn){
    if(cur == 0){
        if(turn == 'L')
            return 2;
        if(turn == 'D')
            return 3;
    }
    else if(cur == 1){
        if(turn == 'L')
            return 3;
        if(turn == 'D')
            return 2;
    }
    else if(cur == 2){
        if(turn == 'L')
            return 1;
        if(turn == 'D')
            return 0;
    }
    else if(cur == 3){
        if(turn == 'L')
            return 0;
        if(turn == 'D')
            return 1;
    }
    return 100;
}
bool finish(int nx, int ny){
    if(nx <0 || nx >=N || ny<0 || ny >=N)
        return 1;
        
    for(int i=0; i<snake.size(); i++){
        if(snake[i].x == nx && snake[i].y == ny)
            return 1;
    }
    return 0;
}
int solve(mat arr, vector<pair<int, char>> direction){
    int cd = 3;
    snake.push_front(pos(0, 0));
    for(int i=0; i<direction.size()+1; i++){
        int t = 1000000000;
        char d;
        if( i != direction.size()){
            t = direction[i].first;
            d = direction[i].second;    
        }
        for(int j=0; j<t - ans; j++){
            int nx = snake[0].x + dir[cd][0];
            int ny = snake[0].y + dir[cd][1];
            
            if(finish(nx, ny)){
                cout << ans + j + 1 << endl;
                return ans;
            }
            else if(arr[nx][ny] == 2){
                arr[nx][ny] = 0;
                snake.push_front(pos(nx, ny));
            }
            else{
                snake.push_front(pos(nx, ny));
                snake.pop_back();
            }   
        }
    
        cd = get_direction(cd, d);
        ans = t;
    }
    return 0;
    
    
}
int main(){
    scanf("%d %d", &N, &K);
    mat board(N, vector<int>(N));

    for(int i=0; i<K; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        board[x-1][y-1] = 2;
    }
    scanf("%d", &L);
    
    vector< pair<int, char> > direction;
    for(int i=0; i<L; i++){
        int t; char d;
        scanf("%d %c", &t, &d);
        direction.push_back(make_pair(t, d));
    }

    solve(board, direction);
    return 0;

}