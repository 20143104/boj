#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_SIZE 21
using namespace std;
int N, K, res = 0;
char board[MAX_SIZE][MAX_SIZE];
int visit[92];
int dir[4][2] = { {0 , 1}, {0, -1}, {-1, 0}, {1, 0} };
void dfs(pair<int, int> p, int cnt){
    
    res = max(res, cnt);
    
    for(int i=0; i<4; i++){
        int next_x = p.first + dir[i][0];
        int next_y = p.second + dir[i][1];

        if(next_x < 0 || next_x >= N || next_y <0 || next_y >= K)
            continue;
        
        if(visit[board[next_x][next_y]] == 0){
            // cout << next_x << " " << next_y << endl;
            visit[board[next_x][next_y]] = 1;
            dfs(make_pair(next_x, next_y), cnt+1);
            visit[board[next_x][next_y]] = 0;
        }
            
    }
    ans.pop_back();
}
int main() {
    cin >> N >> K;
    ans.clear();
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            cin >> board[i][j];
        }
    }

    visit[board[0][0]] = 1;
    dfs(make_pair(0, 0), 1);

    cout << res;
    return 0;
}
