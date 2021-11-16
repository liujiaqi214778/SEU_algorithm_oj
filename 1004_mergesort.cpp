#include <stdio.h>
#include <string.h>

int num[1005];
int numtmp[1005];
int n;

//depth begin with 0
void mergesort(int s, int e, int depth){
    if(!(s<e-1)) return;
    int mid = s + (e - 1 - s)/2 + 1;
    mergesort(s, mid, depth+1);
    mergesort(mid, e, depth+1);
    if(depth < 2) return;
    int i = s, j = mid, k=s;
    for(; i<mid && j<e; k++){
        if(num[j] < num[i])
            numtmp[k] = num[j++];
        else
            numtmp[k] = num[i++];
    }
    for(; i<mid; i++, k++)
        numtmp[k] = num[i];
    for(; j<e; j++, k++)
        numtmp[k] = num[j];
    for(; s < e; s++)
        num[s] = numtmp[s];
}

int main(){
    int m;
    scanf("%d", &m);
    while(m--){
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d", &num[i]);
        mergesort(0, n, 0);
        for(int i=0; i<n; i++){
            printf("%d ", num[i]);
        }
        printf("\n");
    }
    return 0;
}
