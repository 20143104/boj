#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, m, l, g;
int garo[101][101];
int sero[101][101];
int dp[101][101][300][2];
int main(){
    int numtestcases;
    cin >> numtestcases;
    while(numtestcases--){
        cin >> n >> m >> l >> g;
        for(int i=0;i<n;i++)
            for(int j=0;j<m-1;j++)
                scanf("%d", &garo[i][j]);
        for(int i=0;i<n-1;i++)
            for(int j=0;j<m;j++)
                scanf("%d", &sero[i][j]);
        for (int i = 0; i < 101; i++){
			for (int j = 0; j < 101; j++){
				for (int k = 0; k < 300; k++){
					for (int w = 0; w < 2; w++){
						dp[i][j][k][w] = INF;}}}}
        dp[0][0][0][0]=0;
        dp[0][0][0][1]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                for(int k=0;k<300;k++){
                    if(i+1!=n){
                        dp[i+1][j][k][0]=min(dp[i+1][j][k][0], dp[i][j][k][0]+sero[i][j]);
                        dp[i+1][j][k+1][0]=min(dp[i+1][j][k+1][0], dp[i][j][k][1]+sero[i][j]);
                    }
                    if(j+1!=m){
                        dp[i][j+1][k][1]=min(dp[i][j+1][k][1], dp[i][j][k][1]+garo[i][j]);
                        dp[i][j+1][k+1][1]=min(dp[i][j+1][k+1][1], dp[i][j][k][0]+garo[i][j]);
                    }
                }
            }
        int ans=INF;
        for(int i=0;i<250;i++){
            if(dp[n-1][m-1][i][0]<=g)
                ans=min(ans, i);
            if(dp[n-1][m-1][i][1]<=g)
                ans=min(ans, i);
        }
        if(ans == INF)	 cout << -1 << "\n";
		else cout << (n-1)*l+(m-1)*l+ans << "\n";
    }
    return 0;
}