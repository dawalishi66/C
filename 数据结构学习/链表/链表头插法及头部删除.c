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
void pushFront(Node** pphead,int d){
	Node* newNode=createNode(d);
	newNode->next=*pphead;
	*pphead=newNode;
} 
void popFront(Node **pphead){
	if(*pphead==NULL){
		printf("Á´±íÎª¿Õ£¬É¾³ýÊ§°Ü");
	}
	else{
		Node *del=*pphead;
		*pphead=del->next; //*pphead=(*pphaead)->next;
		free(del);
		del=NULL;
	}
}
int main(){
	Node* phead=NULL;
	pushFront(&phead,1);
	pushFront(&phead,2);
	pushFront(&phead,3);
	printList(phead);
	popFront(&phead);
	printList(phead);
	popFront(&phead);
	printList(phead);
	popFront(&phead);
	printList(phead);
	return 0;
}
