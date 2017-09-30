#include <stdio.h>

int solve(int v1, int v2, int depth);

int main(){
    int i;
    for(i=0; ; i++)
        if(solve(0, 0, i))
        break;
    return 0;
}

int solve(int v1, int v2, int depth){
    int t12, t21;
    if(depth <=0)
        return 0;
    if(v1==2 || v2 ==2){
        printf("%d %d\n", v1, v2);
        return 1;
    }
    depth--;
    t12 = 5 - v2;
    if(t12>v1)
        t12=v1;

    t21 = 4-v1;
    if(t21>v2)
        t21=v2;
    if(
       solve(0, v2, depth) ||
       solve(v1, 0, depth) ||
       solve(4, v2, depth) ||
       solve(v1, 5, depth) ||
       solve(v1-t12, v2+ t12, depth) ||
       solve(v1+t21, v2 - t21, depth)
       )
    {
        printf("%d %d\n", v1, v2);
        return 1;
    }

    return 0;
}