#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


void read_i(int* a){
    int t=0;
    char ts[256];
    scanf("%d",&t);
    gets(ts);
    while(t==0){
        printf("Enter the number ");
        scanf("%d",&t);
        gets(ts);
    }
    (*a)=t;
}

void read_f(float* a){
    float t=0;
    char ts[256];
    scanf("%f",&t);
    gets(ts);
    while(t==0){
        printf("Enter the number ");
        scanf("%f",&t);
        gets(ts);
    }
    (*a)=t;
}

void read_d(double* a){
    double t=0;
    char ts[256];
    scanf("%lf",&t);
    gets(ts);
    while(t==0){
        printf("Enter the number ");
        scanf("%lf",&t);
        gets(ts);
    }
    (*a)=t;
}

int main(){
    int v;
    printf("enter variant:\n");
    scanf("%u",&v);
    while(v!=1&&v!=2){
        printf("enter 1 or 2:\n");
        scanf("%u",&v);
    }
    double x1,x2,delta;
    int n;
    printf("enter data:\n");
    printf("enter X1:\n");
    scanf("%lf",&x1);
    printf("enter X2:\n");
    scanf("%lf",&x2);
    if(v==1){
        printf("enter N:\n");
        scanf("%d",&n);
        --n;
        delta=fabs((x1-x2)/n);
    }else{
        printf("enter delta:\n");
        scanf("%lf",&delta);
        n=(int)fabs((x1-x2)/delta);
    }
    for(int i=0;i<58;++i){
        printf("*");
    }
    printf("\n*     N*                       X*                    F(X)*\n");
    for(int i=0;i<58;++i){
        printf("*");
    }
    printf("\n+------+------------------------+------------------------+\n");
    char first=1;
    int k=9;
    double x=x1;
    int i=0;
    while(i<=n){
        int tmp=0;
        while(tmp<k&&i<=n){
            printf("|%6d|%24.3lf|%24.3lf|\n",i+1,x,pow(x+50,5)*sin(x-5/60)-pow(x-15,3),3*pow(x,2)-20);
            ++i;
            ++tmp;
            x+=delta;
            printf("+------+------------------------+------------------------+\n");
        }
        if(first&&i<=n){
           printf("press any key to continue...");
           k=11;
           first=0;
        }
        if(i<=n){
            getch();
            printf("\r");
        }
    }

    return 0;
}
