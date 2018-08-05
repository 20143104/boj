#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
using namespace std;

string dogam[100001];
unordered_map <string, int> mp;
int n, m;



int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;

  for(int i=0; i<n; i++){
    string str;
    cin >> str;
    dogam[i] = str;
    mp.insert(pair<string, int>(str, i));
  }

  for(int i=0; i<m; i++){
    string str;
    cin >> str;
    if(str[0]>= '0' && str[0] <= '9'){
      int num;
      num = stoi(str);
      cout << dogam[num-1]<<"\n";
    }
    else{
      cout << mp[str] + 1 << "\n";
    }
  }

}
