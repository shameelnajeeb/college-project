#include <stdio.h>
int main(){
    int array[]={10,23,34,56,45};
    int i,element,len,temp=0;
    len=sizeof(array)/sizeof(array[0]);
    printf("enter element to search");
    scanf("%d",&element);
    for(i=0;i<len;i++){
        if(array[i]==element){
            temp=1;
            break;
        }
    }
    if(temp==1){
        printf("element found at %d",i);
    }
    else{
        printf("element is not found ");
    }


}