
#include<stdio.h>
#include<string.h>
int main(){
    printf("hello world!\n");
    int i,n;
    char* x="Hacker";
    n=strlen(x);
    // string s="sdjfsd";
    *x=x[n-1];
    for(int i=0;i<=n-1;i++){
        printf("%s ",x);
        x++;
    }


    return 0;
}