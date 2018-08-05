//
//  main.cpp
//  boj
//
//  Created by 조승현 on 2018. 7. 12..
//  Copyright © 2018년 csh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[101][101];
int ans[101][101];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

class position{
public:
  int x;
  int y;
  position(int _x, int _y){
    x = _x;
    y = _y;
  }
};
int main(int argc, const char * argv[]) {
  int row, col;
  cin >> row >> col;

  for(int i=0; i<row; i++){
    for(int k=0; k<col; k++){
      char a;
      cin >> a;
      if(a == '1')
        map[i][k] = 1;
      else
        map[i][k] = 0;
    }
  }

  queue<position> q;
  q.push(position(0,0));
  ans[0][0] = 1;
  while(q.size()){
    int x = q.front().x, y = q.front().y;
    q.pop();

    for(int i=0; i<4; i++){
      int tmp_x= x + dir[i][0], tmp_y = y + dir[i][1];
      if(tmp_x >= row || tmp_y >= col || tmp_x<0 || tmp_y<0) continue;
      if(ans[tmp_x][tmp_y] !=0) continue;
      if(map[tmp_x][tmp_y] == 1){
        q.push(position(tmp_x, tmp_y));
        ans[tmp_x][tmp_y] = ans[x][y]+1;
      }
    }

  }
  cout<<ans[row-1][col-1]<<endl;

}
