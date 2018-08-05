#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <functional>

#define INF 8765432
using namespace std;

int V, E, sta;
vector<pair<int, int> > adj[20001];
int dist[20001];
int visit[20001];

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

int main(){
  cin >> V >> E >> sta;

  for(int i=0; i<E; i++){
    int s,e,w;
    cin >> s >> e >> w;
    adj[s].push_back(make_pair(w,e));
  }
  for(int i=1; i<=V; i++)
    dist[i] = INF;

  dist[sta] = 0;
  pq.push(make_pair(0, sta));

  while(!pq.empty()){
    int cost = pq.top().first;
    int now = pq.top().second;
    pq.pop();

    if(dist[now] < cost) continue;
    //if(dist[now] == cost && visit[now] == 1 ) continue;
    //visit[now] = 1;
    for(int i=0; i<adj[now].size(); i++){
      pair<int, int> next = adj[now][i];
      //cout << next.second << " " << next.first << endl;
      //cout << dist[next.second] << " " <<  next.first + cost << endl;
      if(dist[next.second] > next.first + cost){
        pq.push(make_pair(next.first + cost, next.second));
        dist[next.second] = next.first + cost;
      }
    }
  }

  for(int i=1; i<=V; i++){
    if(dist[i] >= INF) cout<<"INF" << "\n";
    else cout<< dist[i] << "\n";
  }


}
