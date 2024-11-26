#include<stdio.h>
int main(){
  int num;
  printf("Enter a number:");
  scanf("%d",&num);
  for(int num=2; num<=10; num++){
    int prime=1;
    for(int i=2; i<num/2; i++){
      if(num%i==0){
        prime=0;
        break;
      }
    }
  }
  return 0;
}
