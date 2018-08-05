#include <iostream>
#include <cmath>

using namespace std;

int Y, X, number;
bool flag = false;

int process(int l, int x, int y){
  if(l == 2){
    if(flag)
      return 0;
    if(y == Y && x == X){
      flag = true;
      return 0;
    }
    number++;
    if(y == Y && x+1 == X){
      flag = true;
      return 0;
    }
    number++;
    if(y+1 == Y && x == X){
      flag = true;
      return 0;
    }
    number++;
    if(y+1 == Y && x+1 == X){
      flag = true;
      return 0;
    }
    number++;
    return 0;
  }
  else{
    int len = l/2;
    process(len, x, y);
    process(len, x+len, y);
    process(len, x, y+len);
    process(len, x+len, y+len);
  }
  return 0;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int len;
  cin >> len >> Y >> X;
  len = pow(2, len);

  process(len,0, 0);

  cout << number << "\n";

}
