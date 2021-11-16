#include <stdio.h>
#include <string.h>
#include <algorithm>

/* 贪心LIS:
设输入序列: 300 200 200 250 180
1 3 3 2 4
LIS数组状态:
 1
 1 3
 1 3 3
 1 2 3
 1 2 3 4
 len(LDS) == 4
 每加入一个元素，一次binary search, 替换
 最终得到的数组是一个伪序列，只能得到LIS长度
 若要输出整个LIS，可以在二分查找时保存当前元素前驱
 */

int LIS[10005];

int main(){
    int M, N, val, t;
    int *p;
    scanf("%d", &M);
    while(M--){
        scanf("%d", &N);
        t = 1; LIS[0] = -999999;
        for(int i = 0; i < N; i++){
            scanf("%d", &val);
            p = std::upper_bound(LIS, LIS+t, val);  //返回第一个大于val的元素地址
            *p = val;
            if(p - LIS == t)
                t++;
        }
        printf("%d\n", t-1);
    }
    return 0;
}
