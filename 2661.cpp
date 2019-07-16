#include <iostream>
#include <cstring>

using namespace std;

int N;
char arr[3] = {'1', '2', '3'};
char ans[101];
// string ans;

void print(int len){
    for(int i=0; i<len; i++)
        cout << ans[i];
    cout << endl;
}
int solve( int len){
    for(int i=2; i<=len/2; i++){ // 검사할 길이 
        for(int j=0; j<=len-i; j++){ // 시작점
            int cnt = 0;
            for(int k=j; k<j+i; k++){
                if(k+i >= len) break;
                if(ans[k] == ans[k+i]) cnt++;
            }
            if(cnt==i){
                // cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    // print(len);
    return 1;
}
void dfs(int cnt){
    if(cnt == N){
        print(cnt);
        exit(0);
        return ;
    }
        
    for(int i=0; i<3; i++){
        if(ans[cnt-1] == arr[i])
            continue;
        ans[cnt] = arr[i];
        if(solve(cnt+1)) dfs(cnt+1);
        // dfs(cnt+1);
    }
}
int main(){
    cin >> N;

    ans[0] = '1';
    dfs(1);
}