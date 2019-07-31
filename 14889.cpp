#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, board[21][21], ans = 987654321;
bool visit[21];


void cal(bool visit[21]){
    vector<int> start, link;

    for(int i=0; i<N; i++){
        if(visit[i])
            start.push_back(i);
        else
            link.push_back(i);
    }

    int stat_start = 0, stat_link = 0;
    for(int i=0; i<N/2; i++){
        for(int j = i+1; j<N/2; j++){
            int start_x = start[i], start_y = start[j];
            int link_x = link[i], link_y = link[j];
            stat_start += board[start_x][start_y] + board[start_y][start_x];
            stat_link += board[link_x][link_y] + board[link_y][link_x];
        }
    }

    ans = min(ans , abs(stat_start - stat_link));
    if(ans == 0)
        exit(0);
    // cout << abs(stat_start - stat_link) << endl;

}
void dfs(int p, int cnt){
    if(cnt == N/2){
        cal(visit);
        return ;
    }

    for(int i = p+1; i<N; i++){
        if(!visit[i]){
            visit[i] = true;
            dfs(i, cnt+1);
            visit[i] = false;
        }
    }
}
int main(){
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &board[i][j]);
        }
    }

    for(int i=0; i<N; i++)
        dfs(i, 0);

    cout << ans << endl;
}


