#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector <int> adj[503];
int visit[503];
int num_donggi;

int main(int argc, char* argv[]) {
	//int num_donggi;
	cin >> num_donggi;
	int num_list;
	cin >> num_list;

	for(int i=0; i<num_list; i++){
		int a, b;
		cin >> a;
		cin >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> que;
	int cnt= 0;

	int temlen = adj[1].size();
	for(int i=0; i<temlen; i++){
		visit[adj[1][i]] = 1;
		que.push(adj[1][i]);
	}

	while(!que.empty()){
		int temp = que.front();
		que.pop();
		int len = adj[temp].size();
		for(int i=0; i<len; i++){
			if(visit[adj[temp][i]] == 0)
				visit[adj[temp][i]] = 2;
		}
	}

	for(int i=2; i<=num_donggi; i++){
		if(visit[i] == 1 || visit[i] ==2)
			cnt++;
	}
	cout<<cnt<<endl;
}
