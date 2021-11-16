#include <stdio.h>
#include <string.h>
#include <algorithm>

//问题1为最长不上升子序列 LDS
/* 贪心LDS:
设输入序列: 300 200 200 250 180
LDS数组状态:
 300
 300 200
 300 200 200
 300 250 200
 300 250 200 180
 len(LDS) == 4
 每加入一个元素，一次binary search, 替换
 最终得到的数组是一个伪序列，只能得到LDS长度
 若要输出整个LDS，可以在二分查找时保存当前元素前驱
 */
//问题2, 需要部署的系统数，解法类似贪心LDS


bool cmp(int a, int b){
    return a > b;
}

int main(){
    int M, N, val, k, t;
    int *p;
    int num[105];  //每个系统当前能发射的最大高度
    int LDS[105];
    scanf("%d", &M);
    while(M--){
        scanf("%d", &N);
        k = 1; t = 1; num[0] = 0; LDS[0] = 999999;
        for(int i = 0; i < N; i++){
            scanf("%d", &val);
            p = std::lower_bound(num, num+k, val);  //返回第一个不大于val的元素地址
            *p = val;
            if(p - num == k)
                k++;
            p = std::upper_bound(LDS, LDS+t, val, cmp);  //返回第一个小于val的元素地址
            *p = val;
            if(p - LDS == t)
                t++;
        }
        printf("%d %d\n", t-1, k-1);
    }
    return 0;
}
