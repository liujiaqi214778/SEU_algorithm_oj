#include <stdio.h>

int num[20008];
int n, k;

void binary_search(){
    int low = 0, high = n-1, mid=0, father;
    while(low <= high){
        father = num[mid];
        mid = (low + high)/2;
        if(k == num[mid]){
            printf("success, father is %d\n", father);
            return;
        }
        else if(k < num[mid]) high = mid - 1;
        else low = mid + 1;
    }
    father = num[mid];
    printf("not found, father is %d\n", father);
}


int main(){
    int m;
    char str[64];
    scanf("%d", &m);
    while(m--){
        scanf("%d%d", &n, &k);
        for(int i=0; i<n; i++)
            scanf("%d", &num[i]);
        binary_search();
    }
    return 0;
}
