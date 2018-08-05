#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

#include <queue>

using namespace std;

int arr[101][101][101];
int visit[101][101][101];
int dir[6][3] = { {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0},{0,0,1},{0,0,-1} };
int m,n,h, cnt;

class point{
public:
  int x,y,z;
  point(int _x, int _y, int _z){
    x = _x;
    y = _y;
    z = _z;
  }
};

queue<point> q;

int bfs(){
  int ans = 1;
  while(!q.empty()){
    int size = q.size();
    for(int i=0; i<size; i++){
      point p1 = q.front();
      q.pop();
      //cout<< p1.x << " " << p1.y << endl;
      if(visit[p1.x][p1.y][p1.z] == 1)
        continue;
      else
        visit[p1.x][p1.y][p1.z] = 1;

      for(int k=0; k<6; k++){
        int tx = p1.x + dir[k][0];
        int ty = p1.y + dir[k][1];
        int tz = p1.z + dir[k][2];

        if(tx<0 || tx>=h || ty<0 || ty >= n || tz<0 || tz>=m)
          continue;
        else if(arr[tx][ty][tz] == -1)
          continue;
        else if(arr[tx][ty][tz] == 0){
          q.push(point(tx,ty,tz));
          arr[tx][ty][tz] = 1;
          cnt--;
        }

        if(cnt == 0)
          return ans;
      }
    }
    //cout<<endl;
    ans++;
  }
  return -1;
}

int main(void){
  cin >> m >> n >> h;
  for(int i = 0; i<h; i++){
    for(int j = 0; j<n; j++){
      for(int k = 0; k<m; k++){
        cin>>arr[i][j][k];
        if(arr[i][j][k] == 0)
          cnt++;
        else if(arr[i][j][k] == 1)
          q.push(point(i,j,k));
      }
    }
  }
  if(cnt == 0){
    cout<< 0 << endl;
    return 0;
  }

  cout<< bfs()<< endl;
  return 0;

}
