#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int arr[1001][1001];
int visit[1001][1001];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int col,row, cnt;

class point{
public:
  int x,y;
  point(int _x, int _y){
    x = _x;
    y = _y;
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
      if(visit[p1.x][p1.y] == 1)
        continue;
      else
        visit[p1.x][p1.y] = 1;

      for(int k=0; k<4; k++){
        int tx = p1.x + dir[k][0];
        int ty = p1.y + dir[k][1];

        if(tx<0 || tx>= row || ty<0 || ty >= col)
          continue;
        else if(arr[tx][ty] == -1)
          continue;
        else if(arr[tx][ty] == 0){
          q.push(point(tx,ty));
          arr[tx][ty] = 1;
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
  cin >> col >> row;
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      cin >> arr[i][j];
      if(arr[i][j] == 1)
        q.push(point(i,j));
      else if(arr[i][j] == 0)
        cnt++;
    }
  }
  if(cnt == 0){
    cout<< 0 << endl;
    return 0;
  }

  cout<< bfs()<< endl;

}

                if (cnt == 0)
                    return ans;
            }
        }
				printf("\n");
        ans++;
    }
    return -1;
}

int main() {
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &tomato[i][j]);

            if (tomato[i][j] == 1)
                que.push({ i,j });
            else if (tomato[i][j] == 0)
                cnt++;
        }
    }
    printf("%d", bfs());

    return 0;
}
