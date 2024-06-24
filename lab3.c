#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    char data;
    struct node* next;
};
void forwardList(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%c->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void backwardList(struct node* tail){
    struct node* temp=tail;
    while(temp!=NULL){
        printf("%c->",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
}
struct node* insertAtBegin(struct node *head,struct node **tail,char data){
    struct node* newnode=malloc(sizeof(struct node*));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if (head == NULL) {
        *tail = newnode;
        return newnode;
    }
    newnode->next = head;
    head->prev = newnode;
    newnode->prev=NULL;
    return newnode;
}
struct node* insertAtEnd(struct node *head,struct node **tail,char data){
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    struct node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    *tail=temp;
    return head;
}
struct node* delAtBegin(struct node* head){
    if(head==NULL){
        printf("Empty list");
        return NULL;
    }
    struct node* temp=head;
    head=temp->next;
    head->prev=NULL;
    free(temp);
    return(head);
}
struct node* delAtEnd(struct node* tail){
    if(tail==NULL){
        printf("Empty lis ");
        return NULL;
    }
    struct node* temp=tail;
    tail=temp->prev;
    tail->next=NULL;
    free(temp);
    return tail;
}
void main(){
    struct node* head=NULL;
    struct node* tail=NULL;
    printf("Initial double linked list : \n");
    forwardList(head);
    backwardList(tail);
    printf("After inserting three nodes at beginning : \n");
    head=insertAtBegin(head,&tail,'U');
    head=insertAtBegin(head,&tail,'G');
    head=insertAtBegin(head,&tail,'R');
    forwardList(head);
    backwardList(tail);
    printf("After inserting two nodes at end : \n");
    head=insertAtEnd(head,&tail,'K');
    head=insertAtEnd(head,&tail,'T');
    forwardList(head);
    backwardList(tail);
    printf("After deleting two nodes at beginning : \n");
    head=delAtBegin(head);
    head=delAtBegin(head);
    forwardList(head);
    backwardList(tail);
    printf("After deleting two nodes at end : \n");
    tail=delAtEnd(tail);
    tail=delAtEnd(tail);
    forwardList(head);
    backwardList(tail);
}