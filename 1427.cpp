#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string str;
char A[51];
int B[51];

int main(){
  cin >> str;
  int N = str.size();

  for(int i=0; i<N; i++)
    B[i] = str[i] -48;


  sort(B, B+N, greater<int> ());

  for(int i=0; i<N; i++)
    cout<<B[i];
  cout<<endl;
}
