#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* top=NULL;
int isempty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(top==NULL){
        top=temp;
        printf("\n%d Inserted successfully",data);
    }
    else{
        temp->next=top;
        top=temp;
        printf("\n%d Inserted successfully",data);
    }
}
void pop(){
    struct node* temp=top;
    if(isempty()){
        printf("\nThe stack is empty \n");
    }
    else{
        top=temp->next;
        printf("\n%d is deleted successfully",temp->data);
    }
}
void peek(){
    if(isempty()){
        printf("\nThe stack is empty \n");
    }
    else{
        printf("\nTop element is %d",top->data);
    }
}
void display(){
    if(isempty()){
        printf("\nThe stack is empty \n");
    }
    else{
        struct node* temp=top;
        printf("\nStack elements are : ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void search(int val){
    if(isempty()){
        printf("\nThe stack is empty \n");
    }
    else{
        int flag=0;
        struct node* temp=top;
        while(temp!=NULL){
            printf("A");
            if(val==temp->data){
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==1){
            printf("\n%d is found in stack",val);
        }
        else{
            printf("\n%d is not found in stack",val);
        }
    }
}
void main(){
    push(10);
    push(20);
    push(30);
    display();
    pop();
    peek();
    display();
    search(10);
}