#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<string, int, greater<string> > mp;
string str;
string cmd;

int main(){
  int N;
  cin >> N;

  for(int i=0; i<N; i++){
    cin >> str >> cmd;
    if(cmd == "enter")
      mp.insert(pair<string, int>(str, 1));
    else if(cmd == "leave")
      mp.erase(str);
  }


  map<string, int, greater<string> >::iterator i;
  for(i=mp.begin(); i!=mp.end(); i++)
    cout << i->first<<"\n";

}
