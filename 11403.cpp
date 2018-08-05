#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

#include <queue>

using namespace std;

int adj[101][101];
int result[101][101];
int visit[101];
int node;

void invisit(){
  for(int i=0; i<node; i++)
    visit[i] = 0;
}
int dfs(int v){

  for(int i=0; i<node; i++){
    if(adj[v][i] == 1 && visit[i] == 0){
      visit[i] = 1;
      dfs(i);
    }
  }
}

int main(void){
  cin >> node;
  for(int i=0; i<node; i++){
    for(int k=0; k<node; k++){
      cin >> adj[i][k];
    }
  }

  for(int i=0; i<node; i++){
    invisit();
    dfs(i);
    for(int j=0; j<node; j++)
      result[i][j] = visit[j];
  }


  for(int i=0; i<node; i++){
    for(int k=0; k<node; k++){
      cout<< result[i][k]<<" ";
    }
    cout<<endl;
  }
}
