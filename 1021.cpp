//dp[j] = max(dp[j], dp[j-c[i]] + w[i]), j: c[i] to V
#include <stdio.h>
#include <string.h>

int dp[10005]={0};
int c[1005];
int w[1005];

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
	int v, n, m;
    scanf("%d", &m);
    while(m--){
        scanf("%d%d", &v, &n);
        memset(dp, 0, (v+1)*sizeof(int));
        //完全背包的优化
        for(int i=1;i<=n;){
            scanf("%d%d", &c[i], &w[i]);
            if(c[i]>v||dp[c[i]]>=w[i])n--;
            else{
                dp[c[i]]=w[i];
                i++;
            }
        }
        memset(dp, 0, (v+1)*sizeof(int));
        for (int i=1;i<=n;i++)
            for (int j = c[i]; j <= v; j++)
                dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
            
        printf("%d\n", dp[v]);
    }
	return 0;
}


/*
w[]={0,1,2,6},v=8,n=3
	  0 1 2 3 4 5 6 7 8 j
ci	0 0 0 0 0 0 0 0 0 0
3	1 0 0 0 1 1 1 2 2 2
4	2 0 0 0 1 2 2 2 3 3
5	3 0 0 0 1 2 6 6 6 7
6	4 0
7	5 0
	6 0
	7 0
	i

w[]={0,1,2,6},v=8,n=3
	  0 1 2 3 4 5 6 7 8 j
ci	0 X X X X X X X X X
3	1 X X X 1 X X 2 X X
4	2 X X X 1 2 X 2 3 3
5	3 X X X 1 2 6 2 3 7
	i
*/
