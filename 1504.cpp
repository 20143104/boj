#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <functional>

#define INF 8765432
using namespace std;

int V, E, node1, node2;
vector<pair<int, int> > adj[20001];
int dist[20001];
int visit[20001];


void process(int sta){
  for(int i=0; i<=V; i++)
    dist[i] = INF;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

  dist[sta] = 0;
  pq.push(make_pair(0, sta));

  while(!pq.empty()){
    int cost = pq.top().first;
    int now = pq.top().second;
    pq.pop();

    if(dist[now] < cost) continue;
    for(int i=0; i<adj[now].size(); i++){
      pair<int, int> next = adj[now][i];
      if(dist[next.second] > next.first + cost){
        pq.push(make_pair(next.first + cost, next.second));
        dist[next.second] = next.first + cost;
      }
    }
  }

}
int main(){
  cin >> V >> E;
  int case1 = 0, case2 = 0;
  for(int i=0; i<E; i++){
    int from, to, weight;
    cin >> from >> to >> weight;
    adj[from].push_back(make_pair(weight, to));
    adj[to].push_back(make_pair(weight, from));
  }
  cin >> node1 >> node2;

  process(1);
  case1 += dist[node1];
  case2 += dist[node2];

  process(node1);
  case1 += dist[node2];
  case2 += dist[V];

  process(node2);
  case1 += dist[V];
  case2 += dist[node1];

  int ans = min(case1, case2);
  if(ans >= INF)
    cout<< -1 << "\n";
  else
    cout << ans << "\n";
}
