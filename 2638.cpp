//
//  main.cpp
//  boj
//
//  Created by 조승현 on 2018. 9. 3..
//  Copyright © 2018년 csh. All rights reserved.
//

#include <iostream>
#include <queue>

int N, M, cnt, res;
int graph[101][101];
int tmp_graph[101][101];
int visit[101][101];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
using namespace std;

void is_air(){
    queue<pair <int , int>> q;
    q.push(make_pair(0, 0));
    visit[0][0] = 1;
    graph[0][0] = 2;
    
    while(!q.empty()){
        int cur_x = q.front().first, cur_y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int next_x = cur_x + dir[i][0], next_y = cur_y + dir[i][1];
            if(next_x >=0 && next_x<= N && next_y>=0 && next_y <= M && visit[next_x][next_y] == 0 &&
               graph[next_x][next_y] == 0){
                q.push(make_pair(next_x, next_y));
                visit[next_x][next_y] = 1;
                graph[next_x][next_y] = 2;
            }
        }
    }
    
}
void roop(){
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            visit[i][k] = 0;
            graph[i][k] = tmp_graph[i][k];
        }
    }
}
int main(int argc, const char * argv[]) {
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            int a;
            cin >> a;
            if(a == 1)
                cnt++;
            graph[i][k] = a;
            tmp_graph[i][k] = a;
        }
    }
    
    
    while(cnt != 0){
        is_air();
        for(int i=0; i<N; i++){
            for(int k=0; k<M; k++){
                if(graph[i][k] == 1){
                    int air = 0;
                    for(int j=0; j<4; j++){
                        if(graph[i + dir[j][0]][k + dir[j][1]] == 2)
                            air ++;
                    }
                    if(air >= 2){
                        tmp_graph[i][k] = 0;
                        cnt--;
                    }
                }
            }
        }
        roop();
        res++;
    }
    cout << res << endl;
    
}
