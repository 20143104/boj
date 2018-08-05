#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int adj[51][51];

int main(){
  int N;
  cin >> N;

  for(int i=0; i<N; i++){
    for(int k=0; k<N; k++){
      char c;
      cin >> c;
      if(c == 'Y')
        adj[i][k] = 1;
      else
        adj[i][k] = 0;
    }
  }
  int max_v = 0;
  for(int i=0; i<N; i++){
    int cnt = 0;
    queue<int> q;
    int visit[51] = {};
    visit[i] = 1;
    for(int k=0; k<N; k++){
      if(adj[i][k] == 1 ){
        q.push(k);
        visit[k] = 1;
        cnt++;
      }
    }
    while(!q.empty()){
      int tmp = q.front();
      q.pop();
      for(int k=0; k<N; k++){
        if(adj[tmp][k] == 1 && visit[k] == 0){
          visit[k] = 1;
          cnt++;
        }
      }
    }
    max_v = max(max_v, cnt);
  }
  cout<< max_v<<endl;
}
