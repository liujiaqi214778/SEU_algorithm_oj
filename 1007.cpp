#include <stdio.h>
#include <string.h>
#include <algorithm>

typedef unsigned long ull;

ull dp[41][8];
ull num[41][41];

int main(){
    int M, N, K, t;
    char str[64];
    scanf("%d", &M);
    while(M--){
        scanf("%d%d%s", &N, &K, str);
        for(int i = 0; i < N; i++){
            t = 0;
            for(int j = i; j < N; j++){
                t = t*10 + str[j] - '0';
                num[i][j] = t;
            }
        }
        memset(dp, 0x00, sizeof(dp));
        for(int i = 0; i < N; i++)
            dp[i][0] = num[0][i];
        for(int i = 0; i < N; i++)
            for(int j = 1; j <= K && j < i+1; j++)
                for(int k = 0; k < i; k++)
                    dp[i][j] = std::max(dp[k][j-1]*num[k+1][i], dp[i][j]);
         printf("%ld\n", dp[N-1][K]);
    }
    return 0;
}




/*
5 3 5 6 3 5 7

dp[i][j] : 0-i 字符串 插入j 个乘号的最大乘积

*/
