#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M, start, en, maxcost, ans, visit[10001];
vector<vector<pair<int, int> > > v(10001);

int bfs(int cost){
    memset(visit, 0, sizeof(visit));
    queue<int> q;
    
    q.push(start);
    visit[start] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i].first, limit = v[cur][i].second;
            if(cost <= limit && !visit[next]){
                visit[next] = 1;
                q.push(next);
            }
        }
    }
    return visit[en];
}
void bisearch(){
    int l = 0, r = maxcost;

    while(l <= r){
        int mid = (l + r ) / 2;
        if(bfs(mid)){
            ans = max(mid, ans);
            l = mid+1;
        }
        else
            r = mid-1;
    }
}
int main(){
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<M; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
        maxcost = max(maxcost, c);
    }

    scanf("%d %d", &start, &en);

    bisearch();

    printf("%d", ans);



}