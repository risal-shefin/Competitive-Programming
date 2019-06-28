#include<bits/stdc++.h>
using namespace std;
int check[100][100];
void fn(int x,int y,int n,int a)
{
    if(n<0)
        return;
    printf("%c%d\n",'a'+x-1,y);
    if(y==7&&n==3&&x==7){
        printf("g8\nf8\nh8\n");
        return;
    }
    else if(n==2&&x==8){
        printf("h7\nh8\n");
        return;
    }
    if(y<8&&n==2){
        fn(x,8,n-1,a);
        return;
    }
    if(y==8&&n==1){
        fn(8,8,n-1,a);
        return;
    }
    if(y==8){
        if(x==6){
            fn(x+1,y,n-1,-2);
        }
        else{
            fn(x+a,y,n-1,a);
        }
        return;
    }
    else{
        int z=x+a;
        if(z>8){
            if(x==8)
                z=7;
            else
                z=8;
            fn(z,y,n-1,-2);
        }
        else if(z<=0){
            fn(x,y+1,n-1,2);
        }
        else{
            fn(x+a,y,n-1,a);
        }
        return;
    }
}
int main()
{
    int n,m,i,j,k,a,b,c,x,y,z;
    cin>>n;
    fn(1,1,n,2);
    return 0;
}
