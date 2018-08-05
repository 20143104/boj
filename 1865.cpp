#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

#define INF 987654321

int T, V, E, W;

int main() {
  cin >> T;

	while(T--){
		cin >> V >> E >> W;
		vector< pair<int, int> > adj[501];
		vector<int> distance(501, INF);

		for(int i=0; i<E; i++){
			int from, to, weight;
			cin >> from >> to >> weight;
			adj[from].push_back(make_pair(to, weight));
			adj[to].push_back(make_pair(from, weight));
		}
		for(int i=0; i<W; i++){
			int from, to, weight;
			cin >> from >> to >> weight;
			adj[from].push_back(make_pair(to, -weight));
		}
		queue<int> q;
		q.push(1);
		distance[1] = 0;
		int flag = 1;

		while(!q.empty() && flag){
			int cur = q.front();
			/*
			for(int i=1; i<=V; i++)
				cout << distance[i] << " ";
			cout << endl;
			*/
			q.pop();
			for(int i=0; i<adj[cur].size(); i++){
				//cout << distance[adj[cur][i].first] <<" "<< (distance[cur] + adj[cur][i].second)<<endl;
				if(distance[adj[cur][i].first] > (distance[cur] + adj[cur][i].second)){
					distance[adj[cur][i].first] = distance[cur] + adj[cur][i].second;
					if(adj[cur][i].first == 1){
						flag = 0;
						break;
					}
					q.push(adj[cur][i].first);
				}
			}

		}
		if(flag)
			cout<< "NO" << "\n";
		else
			cout<< "YES" << "\n";
	}
}
