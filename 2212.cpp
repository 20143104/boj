#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N, K, ans;
int data[10001];
priority_queue<int> pq;

int main(){
  cin >> N >> K;

  for(int i=0; i<N; i++)
    cin >> data[i];

  sort(data, data + N);

  for(int i=1; i<N; i++)
    pq.push(data[i] - data[i-1]);

  for(int i=0; i<K-1; i++){
    if(pq.empty())  break;
    pq.pop();
  }

  while(!pq.empty()){
    ans += pq.top();
    pq.pop();
  }

  cout<< ans << "\n";
}
