#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N, ans, board[12][12];
int visit_a[30], visit_b[30];

void dfs(int row, int col, int cnt, int flag){ 
    if(cnt > ans)
        ans = cnt;
    if(!flag){
        if(col > N){
            row ++;
            if(row%2 == 0)
                col = 2;
            else
                col = 1;
        }

        if(row > N)
            return ;
        if(visit_a[row+col] == 0 && visit_b[10+row-col] == 0 && board[row][col] == 1){
            visit_a[row+col] = 1;
            visit_b[10+row-col] = 1;
            dfs(row, col+2, cnt+1, 0);
            visit_a[row+col] = 0;
            visit_b[10+row-col] = 0;
        }   
        dfs(row, col+2, cnt, 0);
    }
    else{
        if(col>N){
            row ++;
            if(row%2 ==0)
                col =1;
            else
                col =2;
        }
        if(row > N)
            return ;
        if(visit_a[row+col] == 0 && visit_b[10+row-col] == 0 && board[row][col] == 1){
            visit_a[row+col] = 1;
            visit_b[10+row-col] = 1;
            dfs(row, col+2, cnt+1, 1);
            visit_a[row+col] = 0;
            visit_b[10+row-col] = 0;
        }   
        dfs(row, col+2, cnt, 1);
    }
    
}


int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> board[i][j];
        }
    }
    
    dfs(1, 1, 0, 0);
    int result = ans;
    ans = 0;
    dfs(1, 2, 0, 1);
    result += ans;
    cout << result;
}