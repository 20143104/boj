#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define INF 100001


vector<int> adj[51];
int parent[51];

int min(int a, int b){
	if(a<b)
		return a;
	return b;
}

int count(int root){
	int cnt = 0;
	int ret = 0;
	for(int i=0; i<adj[root].size(); i++){
		if(adj[root][i] == -1) continue;
		cnt++;
		ret += count(adj[root][i]);
	}
	if(cnt== 0) return 1;
	return ret;
}
int main(int argc, char* argv[]) {
	int node_num;
	cin>>node_num;

	for(int i=0; i<node_num; i++){
		int num;
		cin>> num;
		parent[i] = num;
	}
	int root = 0;
	for(int i=0; i<node_num; i++){
		int v = parent[i];
		if(v == -1){
			root = i;
			continue;
		}
		adj[v].push_back(i);
	}

	int remove_num;
	cin >> remove_num;
	if(remove_num == root){
		cout<<0<<endl;
		return 0;
	}

	int a = parent[remove_num];
	for(int i=0; i<adj[a].size(); i++){
		if(adj[a][i] == remove_num)
			adj[a][i] = -1;
	}
	cout<<count(root)<<endl;
}
