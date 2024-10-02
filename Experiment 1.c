// Array insertion at beginning ,at end ,at specific position

#include<stdio.h>
int size=5;
int currsize=0;

void addBeg(int arr[],int value){
    if (currsize<size){
        for(int i=currsize;i>0;i--){
            arr[i]=arr[i-1];
        }
       arr[0]=value;
       currsize++;
    }
    else{
        printf("array is full \n");
    }
}
void addend(int arr[],int val){
    if(currsize<size){
        arr[currsize]=val;
        currsize++;
    }
    else{
        printf("sizee is full \n");
    }
}
void addAtPosition(int arr[],int value,int pos){
    if(currsize<size){
        for(int i=currsize;i>pos;i--){
            arr[i]=arr[i-1];
        }
        arr[pos]=value;
        currsize++;
    }
    else{
        printf("size is not attained! \n");
    }
}

void show(int arr[]){
    for(int i=0;i<currsize;i++){
        printf("%d\t",arr[i]);
        }
     printf("\n %d is the cuurent size  \n",currsize);
}




int main(){
    int arr[size];

    addBeg(arr,1);

    addBeg(arr,5);

    addBeg(arr,6);
    
    addend(arr,3);

    addAtPosition(arr,4,3);

    show(arr);

    return 0;
    

}
