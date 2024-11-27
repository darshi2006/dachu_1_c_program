#include<stdio.h>
void swap(int x,int y){
int temp=x ;
x=y;
y=temp;
printf("a=%d,b=%d\n",x,y);
}
void main(){
int a=5,b=10;

swap(a,b);
printf("********************************");
//printf("a=%d,b=%d\n",a,b);
}