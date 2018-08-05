#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

#include <queue>
#include <vector>

using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  for(int i=0; i<n-m; i++){
    cout<< i<<" "<< i+1<<endl;
  }
  cout<<endl;
  for(int i=n-m+1; i<n; i++){
    cout<<n-m<<" "<<i<<endl;
  }
}
