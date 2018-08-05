#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;

long long int data[1000001];
int main(){
  int n;
  scanf("%d", &n);

  for(int i=0; i<n; i++)
    scanf("%lld", &data[i]);

  sort(data,data+n);

  int count=1;
  int max=0;
  long long result = data[0];
  for(int i=0; i<n-1; i++){
    if(data[i]==data[i+1])
      count++;
    else
      count=1;
      if(max<count){
        max = count;
        result = data[i];
      }

  }

  printf("%lld\n", result);
}
