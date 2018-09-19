#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int numtestcases, N, M;


bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first) return true;
    if(a.first > b.first) return false;
    return a.second < b.second;
}
int main(int argc, const char * argv[]) {
    
    
    cin >> numtestcases;
    while(numtestcases--){
        vector<pair<int, int> > v;
        cin >> N;
        for(int i=0; i<N; i++){
            int x, y;
            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }
        v.push_back(make_pair(-1, 0));
        sort(v.begin(), v.end(), cmp);
        
//        for(int i=0; i<N; i++){
//            cout << v[i].first << " " << v[i].second << endl;
//        }
        
        for(int i=1; i<=N; i++){
            if(v[i-1].first != v[i].first){
                int start = i, end = i;
                for( ; end <= N; end++){
                    if(v[start].first != v[end].first)
                        break;
                }
                if(v[i-1].second != v[start].second)
                    reverse(v.begin() + start, v.begin() + end);
            }
        }
        cin >> N;
        for(int i=0; i<N; i++){
            int a;
            cin >> a;
            cout << v[a].first << " " << v[a].second << "\n";
        }
    }
    
    
}
