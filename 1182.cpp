#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstdio>
using namespace std;

int data[21];
int N, S, cnt;
queue< pair<int, int> > q;
int main(){
  cin >> N >> S;

  for(int i=0; i<N; i++)
    cin >> data[i];

  q.push(make_pair(1, 0));
  q.push(make_pair(1, data[0]));

  while(!q.empty()){
    int it = q.front().first;
    int sum = q.front().second;

    q.pop();

    if(it == N && sum == S) cnt++;
    if(it < N){
      q.push(make_pair(it+1, sum));
      q.push(make_pair(it+1, sum+ data[it]));
    }
  }

  if(S == 0)   cnt --;

  cout<< cnt << "\n";

}
