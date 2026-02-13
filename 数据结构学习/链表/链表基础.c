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
int main(){
	Node* p1=createNode(1);
	Node* p2=createNode(2);
	Node* p3=createNode(3);
	p1->next=p2;
	p2->next=p3;
	printList(p1);
	return 0;
}
