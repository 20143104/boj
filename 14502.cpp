#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

#include <queue>
#include <vector>
using namespace std;

//int adj[10001][10001];
class position{
public:
  int x,y;
  position(int _x, int _y){
    x = _x;
    y = _y;
  }
};

int adj[9][9];
int tmpadj[9][9];
int visit[9][9];
int n,m;
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

vector <int> ans;

int bfs(void){

  int finaladj[9][9];
  queue<position> q;

  for(int i=0; i<n; i++){
    for(int k=0; k<m; k++){
      finaladj[i][k] = tmpadj[i][k];
      if(finaladj[i][k] == 2)
        q.push(position(i,k));
    }
  }

  while(!q.empty()){
    position temp = q.front();
    q.pop();
    int tmpx = temp.x;
    int tmpy = temp.y;
    for(int i=0; i<4; i++){
      int dx = tmpx + dir[i][0];
      int dy = tmpy + dir[i][1];
      if(dx>=0 && dx<n && dy>=0 && dy<m){
        if(finaladj[dx][dy] == 0){
          finaladj[dx][dy] =2;
          q.push(position(dx,dy));
        }
      }
    }
  }

  int cnt=0;
  for(int i=0; i<n; i++){
    for(int k=0; k<m; k++){
      if(finaladj[i][k] == 0)
        cnt++;
    }
  }
  ans.push_back(cnt);
}
void wall(int cnt){
  if(cnt == 3){
    bfs();
    return;
  }
  for(int i=0; i<n; i++){
    for(int k=0; k<m; k++){
      if(tmpadj[i][k] == 0){
        tmpadj[i][k] = 1;
        wall(cnt+1);
        tmpadj[i][k] = 0;
      }
    }
  }
}
void copymap(){
  for(int i=0; i<n; i++){
    for(int k=0; k<m; k++){
      tmpadj[i][k] = adj[i][k];
    }
  }
}
int main(void){
  cin>>n>>m;
  for(int i=0; i<n; i++){
    for(int k=0; k<m; k++){
      cin>>adj[i][k];
    }
  }
  for(int i=0; i<n; i++){
    for(int k=0; k<m; k++){
      if(adj[i][k] == 0){
        copymap();
        tmpadj[i][k] = 1;
        wall(1);
        tmpadj[i][k] = 0;
      }
    }
  }
  printf("%d\n", *max_element(ans.begin(), ans.end() ));
}
