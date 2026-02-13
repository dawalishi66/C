#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;
Node* createNode(int d){
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=d;
	p->next=NULL;
	return p;
}
void printList(Node* cur){
	while(cur!=NULL){
		printf("%d-->",cur->data);
		cur=cur->next;
	}
	printf("NULL\n");
}
void deleteNode(Node **pphead,int key){
	if(*pphead==NULL)return;
	Node* cur=*pphead;
	Node* prev=NULL;
	if(cur->data==key){
		*pphead=(*pphead)->next;
		free(cur);
		return;
	}
	while(cur !=NULL&&cur->data!=key){
		prev=cur;
		cur=cur->next;
	}
	if(cur==NULL){
		return;
	}
	prev->next=cur->next;
	free(cur);
	cur=NULL;
}
int main(){
	Node* p1=createNode(1);
	Node* p2=createNode(2);
	Node* p3=createNode(3);
	p1->next=p2;
	p2->next=p3;
	printList(p1);
	deleteNode(&p1,2);
	printList(p1);
	return 0;
}
