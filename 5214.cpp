#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 100000 + 1;

vector<int> adj[MAX+ 2000];
int visit[MAX+ 2000];
queue<int> q;

int main(){
  int N, K, M, flag = 0;
  cin >> N >> K >> M;

  for(int k=1; k<=M; k++){
    for(int i=0; i<K; i++){
      int node;
      cin>> node;
      adj[MAX+k].push_back(node);
      adj[node].push_back(MAX+k);
    }
  }

  q.push(1);
  visit[1] = 1;
  while(!q.empty()){
    int tmp = q.front();
    q.pop();
    if(tmp == N){
      cout<< visit[N]<<endl;
      return 0;
    }
    for(int i=0; i<adj[tmp].size(); i++){
      if(visit[adj[tmp][i]] == 0){
        q.push(adj[tmp][i]);
        if(adj[tmp][i] > MAX)
          visit[adj[tmp][i]] = visit[tmp];
        else
          visit[adj[tmp][i]] = visit[tmp] + 1;
      }
    }
  }

  cout<< -1<<endl;
}
