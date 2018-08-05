#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int house[200001];

int main(int argc, const char * argv[]) {
  int numtestcases;
  cin >> numtestcases;

  while(numtestcases--){
    int n;
    cin >> n;
    cout << (n+1)/2<<endl;
    priority_queue<int,vector<int>, greater<int> > min_heap;
    priority_queue<int> max_heap;
    for(int i=1; i<=n; i++){
      int num;
      cin >> num;
      if(max_heap.size() == min_heap.size()){
        if(min_heap.empty())
          max_heap.push(num);
        else{
          if(min_heap.top() <= num){
            int tmp = min_heap.top();
            min_heap.pop();
            min_heap.push(num);
            num = tmp;
          }
          max_heap.push(num);
        }
      }
      else{
        if(max_heap.top() > num){
          int tmp = max_heap.top();
          max_heap.pop();
          max_heap.push(num);
          num = tmp;
        }
        min_heap.push(num);
      }
      if(i%2 == 1)
        cout<< max_heap.top() << " " ;
    }
    cout<<endl;
  }

}
