#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
using namespace std;

string str;
deque<int> dq;
int data[500001];
int main(){
  int N, K;
  int cnt = 0;
  cin >> N >> K;

  cin >> str;

  for(int i=0; i<N; i++)
    data[i] = str[i] - 48;

  dq.push_back(data[0]);

  for(int i=1; i<N; i++){
    int x= data[i];
    if(dq.back() < x){
      while(!dq.empty() && dq.back() < x && cnt!=K){
        dq.pop_back();
        cnt++;
      }
      dq.push_back(x);
    }
    else
      dq.push_back(x);
  }
  for(int i=0; i<N-K; i++)
    cout<<dq[i];
  cout<<endl;
}
