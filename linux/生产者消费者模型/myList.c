/*************************************************************************
	> File Name: 生产者消费者模型.c
	> Author: sunxingying
	> Mail: 1159015605@qq.com 
	> Created Time: 2017年07月10日 星期一 23时37分32秒
 ***********************************************************************/
#include"myList.h"
Node_p AllocNode(int data)
{
	Node_p newNode=(Node_p)malloc(sizeof(Node));
	if(newNode==NULL)
	{
		perror("malloc.. \n");
		return;
	}
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}
int IsEmpty(Node_p list)
{
	assert(list);
	if(list->next!=NULL)
		return 0;
	else
		return 1;
}
void ListInit(Node_pp head)
{
	*head=AllocNode(0);
}
void PushHead(Node_p list,int data)
{
	assert(list);
	Node_p newNode=AllocNode(data);
	newNode->next=list->next;
	list->next=newNode;
}
void DelNode(Node_p node)
{
	assert(node);
	free(node);
	node=NULL;
}
void PopHead(Node_p list,int *data)
{
	assert(data);
	if(IsEmpty(list))
	{
		printf("the list is empty..\n");
	}
	Node_p delNode=list->next;
	list->next=delNode->next;
	*data=delNode->data;
	DelNode(delNode);
}
void ShowList(Node_p list)
{
	assert(list);
	Node_p cur=list->next;
	while(cur)
	{
		printf("%d",cur->data);
		cur=cur->next;
	}
	printf("\n");
}
void Destroy(Node_p list)
{
	assert(list);
	int data=0;
	while(list->next)
	{
		PopHead(list,&data);
	}
	free(list);
	list=NULL;
	printf("list is Destroy...\n");
}
