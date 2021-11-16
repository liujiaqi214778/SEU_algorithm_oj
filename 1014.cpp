#include <stdio.h>
#include <string.h>
#include <algorithm>

int main(){
    int M;
    scanf("%d", &M);
    while(M--){
        int now = -9999;
        int l, cur, maxn=now, n, k = now;
        scanf("%d%d", &n, &l);
        for (int i = 1;i < n; i++){
            scanf("%d", &cur);
            if(cur > k)
                k = cur;
            now = std::max(now, l) + cur;
            l = cur;
            if (now > maxn)
                maxn = now;
        }
        printf("%d\n", maxn > k ? maxn : k);
    }
    return 0;
}
