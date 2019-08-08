#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, m = 987654321, cnt;
vector<int> s, j, result(500002);


int lower_bound(vector<int>& v, int row){
    int l = 0;
    int r = v.size();
    while(l < r){
        int mid = (l+r) / 2;
        if(v[mid] >= row)
            r = mid;
        else
            l = mid + 1;
    }
    return r;
}

int main(){

    scanf("%d %d", &N, &M);
    
    int t;
    for(int i=0; i<N/2; i++){
        scanf("%d", &t); s.push_back(t);
        scanf("%d", &t); j.push_back(t);
    }

    sort(s.begin(), s.end());
    sort(j.begin(), j.end());

    for(int i=1; i<=M; i++)
        result[i] = N/2 - lower_bound(s, i);
    

    for(int i=M; i>=1; i--)
        result[i] += N/2 - lower_bound(j, M - i +1);
    

    for(int i=1; i<=M; i++){
        if(result[i] < m){
            m = result[i];
            cnt = 1;
        } 
        else if(result[i] == m) cnt++;
    }
    
    printf("%d %d", m, cnt);
}

