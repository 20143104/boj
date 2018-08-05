#include <cstdio>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int> pq1, pq2;

int main(){
    int numtestcases;
    scanf("%d", &numtestcases);
    while(numtestcases--){
      int num;
      scanf("%d", &num);
      if(num > 0)
        pq1.push(-num);
      if(num < 0)
        pq2.push(num);
      if(num == 0)
      {
        if(pq1.empty() && pq2.empty())
          printf("0\n");
        else if(!pq1.empty() && !pq2.empty())
        {
          if(-pq1.top() >= -pq2.top())
          {
            printf("%d\n", pq2.top());
            pq2.pop();
          }
          else if(-pq1.top() < -pq2.top())
          {
            printf("%d\n", -pq1.top());
            pq1.pop();
          }
        }
        else if(pq1.empty() && !pq2.empty())
        {
          printf("%d\n", pq2.top());
          pq2.pop();
        }
        else if(!pq1.empty() && pq2.empty())
        {
          printf("%d\n", -pq1.top());
          pq1.pop();
        }
      }
    }
}
