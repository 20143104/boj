#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

#include <queue>
#include <vector>
using namespace std;

//int adj[10001][10001];
vector <int>adj[10001];
int visit[10001];
int node, edge;
vector<int> ans;
void unvisit(void){
  for(int i=1; i<= node; i++)
    visit[i] = 0;
}
int bfs(void){

  for(int i=1; i<= node; i++){
    int cnt = 0;
    queue<int> q;
    q.push(i);
    visit[i] = 1;
    cnt++;
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(int k=0; k<adj[v].size(); k++){
        int tmp = adj[v][k];
        if(visit[tmp] == 0){
          q.push(tmp);
          visit[tmp] = 1;
          cnt++;
        }
      }
    }
    ans.push_back(cnt);
    unvisit();
  }

  int max = *max_element(ans.begin(), ans.end());
  for(int i=0; i<ans.size(); i++){
    if(max == ans[i])
      cout<<i+1<<" ";
  }
  cout<<endl;
  /*
  for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<endl;
  */
}

int main(void){
  cin >> node >> edge;

  for(int i=0; i<edge; i++){
    int a, b;
    cin >> a >> b;
    adj[b].push_back(a);
  }
  bfs();
}
