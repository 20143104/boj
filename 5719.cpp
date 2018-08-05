#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

#define INF 987654321

class node{
public:
  int to, weight;
  node(int _to, int _weight){
    to = _to;
    weight = _weight;
  }
};

int V, E, sta, des;
vector<node> adj[500];
vector<pair<int, int> > trace[500];
int dist[500];

void process(){
  for(int i=0; i<V; i++) dist[i] = INF;
  for(int i=0; i<V; i++) trace[i].clear();

  priority_queue<pair<int, int> > pq;

  dist[sta] = 0;
  pq.push(make_pair(0, sta));

  while(!pq.empty()){
    int cost = -pq.top().first;
    int now = pq.top().second;
    pq.pop();
    if(dist[now] < cost) continue;

    for(int i=0; i<adj[now].size(); i++){
      int next = adj[now][i].to;
      int nextcost = cost + adj[now][i].weight;

      if(adj[now][i].weight == -1)
        continue;

      if(dist[next] > nextcost){
        dist[next] = nextcost;
        pq.push(make_pair(-nextcost, next));
        trace[next].clear();
        trace[next].push_back(make_pair(now, nextcost));
      }
      else if(dist[next] == nextcost){
        trace[next].push_back(make_pair(now, nextcost));
      }
    }
  }
}
int main() {
  while(1){
    cin >> V >> E;
    if(V == 0 && E == 0) break;
    cin >> sta >> des;

    for(int i=0; i<V; i++)
      adj[i].clear();

    for(int i=0; i<E; i++){
      int from, to, weight;
      cin >> from >> to >> weight;
      adj[from].push_back(node(to, weight));
    }

    process();

    queue<int> q;
    q.push(des);
    while(!q.empty()){
      int now = q.front();
      q.pop();
      for(int i=0; i<trace[now].size(); i++){
        int next = trace[now][i].first;

        for(int i=0; i<adj[next].size(); i++){
          if(adj[next][i].to == now)
            adj[next][i].weight = -1;
        }
        q.push(next);
      }
    }

    process();

    if(dist[des] == INF)
      cout << -1 <<"\n";
    else
      cout << dist[des] << "\n";
  }
}
