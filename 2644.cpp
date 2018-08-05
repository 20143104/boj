#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

#include <queue>

using namespace std;

int adj[101][101];
int visit[101];
int person, start, arrive, relation;

int bfs(int v){
  queue<int> q;
  q.push(v);

  while(!q.empty()){
    int a = q.front();
    q.pop();
    for(int i=1; i<=person; i++){
      if(adj[a][i] == 1 && visit[i] == 0){
        q.push(i);
        visit[i] = visit[a] + 1;
        //cout<<a<<" "<<i<<endl;
      }
    }
  }
  if(visit[arrive] == 0 ){
    cout<<-1<<endl;
    return 0;
  }
  cout<<visit[arrive]<<endl;
  return 0;
}

int main(void){
  cin >> person >> start >> arrive >> relation;

  for(int i=0; i<relation; i++){
    int a, b;
    cin >> a >> b;
    adj[a][b] = adj[b][a] = 1;
  }
  bfs(start);
}
