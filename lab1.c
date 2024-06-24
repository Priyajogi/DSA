#include<stdio.h>
#include<stdlib.h>
void binarySearch(int arr[],int n,int key){
    int low=0;
    int high=n;
    for(int i=0;i<n;i++){
        int mid=(low+high)/2;
        if(arr[mid]==key){
            printf("%d is found at %d index\n",key,mid);
            break;
        }
        else if(arr[mid]>key){
            high=mid-1;
        } 
        else{
            low=mid+1;
        }
    }
}
void main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements in following array ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int search;
    printf("Enter the element to search ");
    scanf("%d",&search);
    binarySearch(arr,n,search);
}