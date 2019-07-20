#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
char board[12][12];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 상 하 좌 우
int ans = 100;

void print(char arr[][12]){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << arr[i][j] ;
        }
        cout << endl;
    }
    cout << endl;
}
void copy(char src[][12], char trg[][12]){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            trg[i][j] = src[i][j];
        }
    }
}
int count_red(char arr[][12]){
    int cnt = 0;
    for(int i=1; i<N-1; i++){
        for(int j=1; j<M-1; j++){
            if(arr[i][j] == 'R')
                cnt ++;
        }
    }
    return cnt;
}
int move_gravity(char arr[][12], int cur_x, int cur_y, int dx, int dy){
    int cnt = 0;
    while(true){
        int next_x = cur_x + dx;
        int next_y = cur_y + dy;
        if(arr[cur_x][cur_y] == 'B'){
            if(arr[next_x][next_y] == 'O')
                return -1;    
            else if(arr[next_x][next_y] == '.'){
                arr[next_x][next_y] = arr[cur_x][cur_y];
                arr[cur_x][cur_y] = '.';
                cnt ++;
            }
            else
                break;
                        
        }
        else if(arr[cur_x][cur_y] == 'R'){
            if(arr[next_x][next_y] == 'O'){
                arr[cur_x][cur_y] = '.';
                cnt++;
                break;
            }
            else if(arr[next_x][next_y] == '.'){
                arr[next_x][next_y] = arr[cur_x][cur_y];
                arr[cur_x][cur_y] = '.';
                cnt++;
            }
            else{
                break;
            }
        }
        cur_x = next_x;
        cur_y = next_y;
    }
    return cnt;
}
int move(char arr[][12], int d){
    int cnt = 0;
    if(d == 0 || d == 2){  // 상 좌
        for(int i=1; i<N-1; i++){
            for(int j=1; j<M-1; j++){

                if(arr[i][j] == 'O' || arr[i][j] == '#' || arr[i][j] == '.')
                    continue;

                int a = move_gravity(arr, i, j, dir[d][0], dir[d][1]);                

                if(a == -1)
                    return 0;
                cnt += a;
            }
        }
    }
    else{
        for(int i=N-2; i>0; i--){
            for(int j=M-2; j>0; j--){
                if(arr[i][j] == 'O' || arr[i][j] == '#' || arr[i][j] == '.')
                    continue;

                int a =  move_gravity(arr, i, j, dir[d][0], dir[d][1]);                
                if(a == -1)
                    return 0;
                cnt += a;
            }
        }
    }
    if(cnt == 0)
        return 0;
    return 1;
}

void dfs(char arr[][12], int his, int cnt){
    if(cnt == 11){
        return ;
    }
    if(count_red(arr) == 0){
        ans = min(cnt, ans);
        return;
    }
    for(int i=0; i<4; i++){
        if(his == 0 || his == 1){
            if(i == 0 || i == 1)
                continue;
        }
        if(his == 2 || his == 3){
            if(i == 2 || i ==3)
                continue;
        }
        char tmp[12][12];
        copy(arr, tmp);
        
        int a = move(tmp, i);
        
        if(a == 1)
            dfs(tmp, i, cnt+1);
            
        else{
            copy(arr, tmp);
            continue;
        }
    }
}


int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }
    
    dfs(board, 0, 0);
    
    dfs(board, 2, 0);
    
    if(ans > 10)
        cout << -1 << endl;
    else
        cout << ans << endl;

    
    
}