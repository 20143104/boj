#include <iostream>

using namespace std;

int N, M, arr[100001], maxv, sum;

int main(){
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
        maxv = max(arr[i], maxv);
        sum += arr[i];
    }

    int l = maxv, r = sum;
    
    while(l <= r){
        int mid = (l + r) / 2;
        sum = 0;
        int cnt = 1;
        for(int i=0; i<N; i++){
            if(sum + arr[i] > mid){
                cnt++;
                sum = arr[i];
                continue;
            }
            sum+=arr[i];
        }
        // cout << mid << " " << cnt << endl;
        if(cnt <= M)
            r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%d", l);
}

