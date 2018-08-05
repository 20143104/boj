#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <functional>

#define INF 87654321
using namespace std;


struct KS{
  int from;
  int to;
  int val;
};

vector <KS> edge;
int V, E;
int parent[100002];
vector<int> ans;
int res;
bool chk;

bool comp(KS d1, KS d2)
{
    return d1.val < d2.val;
}
int find(int u){
  if(u == parent[u])
    return u;
  return parent[u] = find(parent[u]);
}
void merge(int u, int v){
  chk = false;
  u = find(u);
  v = find(v);

  if(u == v)
    return;
  parent[u] = v;
  chk = true;
}

int main(){
  cin >> V >> E;
  for(int i=1; i<=V; i++)
    parent[i] = i;

  for(int i=0; i<E; i++){
    KS ks;
    cin >> ks.from >> ks.to >> ks.val;
    edge.push_back(ks);
  }

  sort(edge.begin(), edge.end(), comp);

  for(int i=0; i<E; i++){
    merge(edge[i].from, edge[i].to);
    if(chk)
      ans.push_back(edge[i].val);
  }

  sort(ans.begin(), ans.end());

  for(int i=0; i<ans.size()-1; i++)
    res+= ans[i];

  cout << res << "\n";
}
