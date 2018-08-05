#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int data[10];
vector<int> v;

int main(){
  int ans = 0;
  for(int i=0; i<9; i++){
    cin >> data[i];
    ans += data[i];
  }
  for(int i=0; i<9; i++){
    for(int k=i+1; k<9; k++){
      int tmp = ans;
      tmp-=(data[i]+data[k]);
      if(tmp == 100){
        for(int j=0; j<9; j++){
          if(data[j] == data[i] || data[j] == data[k])
            continue;
          v.push_back(data[j]);
        }
        sort(v.begin(), v.end());
        for(int j=0; j<7; j++)
          cout<< v[j]<<endl;
        return 0;
      }
    }
  }


}
