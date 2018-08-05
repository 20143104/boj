#include <iostream>

using namespace std;

char graph[66][66];


int process(int l, int x, int y){
  if(l == 1){
    cout << graph[y][x];
    return 0;
  }

  bool flag = true;
  for(int i=y; i<y+l; i++){
    if(!flag) break;
    for(int k=x; k<x+l; k++){
      if(graph[y][x] != graph[i][k]){
        flag = false;
        break;
      }
    }
  }

  if(flag){
    cout << graph[y][x];
    return 0;
  }

  int len = l/2;
  cout << "(";
  process(len, x, y);
  process(len, x+len, y);
  process(len, x, y+len);
  process(len, x+len, y+len);
  cout << ")";

  return 0;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int len;
  cin >> len;

  for(int i=0; i<len; i++){
    for(int k=0; k<len; k++){
      cin >> graph[i][k];
    }
  }

  process(len, 0, 0);
  cout<<"\n";

}
