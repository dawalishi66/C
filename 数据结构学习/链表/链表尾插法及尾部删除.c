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
void pushBack(Node **pphead,int d){
	Node* newNode=createNode(d);
	if(*pphead==NULL)*pphead=newNode;
	else{
		Node *tail=*pphead;
		while(tail->next!=NULL){
			tail=tail->next;
		}
		tail->next=newNode;
	}
}
void popBack(Node** pphead){
	if(*pphead==NULL){
		printf("链表为空，无法删除");
	}
	else if((*pphead)->next==NULL){
		free(*pphead);
		*pphead=NULL;
	}
	else{
		Node *tail=*pphead;
		while(tail->next->next!=NULL){
			tail=tail->next;
		}
		free(tail->next);
		tail->next=NULL;
	}
} 
int main(){
	Node* phead=NULL;
	pushBack(&phead,1);
	pushBack(&phead,2);
	pushBack(&phead,3);
	printList(phead);
	popBack(&phead);
	printList(phead);
	popBack(&phead);
	printList(phead);
	popBack(&phead);
	printList(phead);
	return 0;
}
