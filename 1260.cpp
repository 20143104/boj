#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
int node, edge, start;
int adj[1001][1001];
int visit[1001];

void dfs(int v){
  cout<< v << " ";
  visit[v] = 1;

  for(int i=1; i<=node; i++){
    if(adj[v][i] == 1 && visit[i] == 0)
      dfs(i);
  }
}
void bfs(int start){
  queue<int> q;
  q.push(start);
  visit[start] = 1;
  cout<< start << " ";
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(int i=0; i<=node; i++){
      if(adj[v][i] == 1 && visit[i] == 0){
        q.push(i);
        visit[i] = 1;
        cout<< i << " ";
      }
    }
  }
}
int main(void){
  cin>>node>>edge>>start;
  for(int i=0; i<edge; i++){
    int a,b;
    cin>>a>>b;
    adj[a][b] = 1;
    adj[b][a] = 1;
  }
  dfs(start);
  cout<<endl;
  for(int i=0; i<=node; i++)
    visit[i] = 0;
  bfs(start);
  cout<<endl;

}
