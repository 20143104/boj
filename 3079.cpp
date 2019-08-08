#include <iostream>
#include <vector>

using namespace std;

long long N, M;
long long ans = 1000000000000000000LL;
vector<long long> t;

int main(){
    scanf("%lld %lld", &N, &M);

    for(int i=0; i<N; i++){
        long long tmp; scanf("%lld", &tmp);
        t.push_back(tmp);
    }

    long long l = 1, r = 1000000000000000000LL;
    while(l <= r){
        long long mid = (l+r) / 2;

        long long cnt = 0;
        for(int i=0; i<N; i++){
            cnt += mid/t[i];
        }

        if(cnt >= M){
            ans = min(mid, ans);
            r = mid - 1;

        }
            
        else
            l = mid + 1;
    }

    printf("%lld", ans);
}