/*************************************************************************
	> File Name: 生产者消费者模型.c
	> Author: sunxingying
	> Mail: 1159015605@qq.com 
	> Created Time: 2017年07月10日 星期一 23时59分44秒
 ************************************************************************/

#include"myList.h"
#include<pthread.h>
pthread_mutex_t mylock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t mycond=PTHREAD_COND_INITIALIZER;
void *pthread_Product(void *arg)
{
	Node_p head=(Node_p)arg;
	while(1)
	{
		usleep(124);
		pthread_mutex_lock(&mylock);
		int data=rand()%1000;
		PushHead(head,data);
		printf("I am producter %d\n",data);
		pthread_cond_signal(&mycond);
		pthread_mutex_unlock(&mylock);
	}
}
void pthread_Consumer(void *arg)
{
	Node_p head=(Node_p)arg;
	int data=0;
	while(1)
	{
		pthread_mutex_lock(&mylock);
		if(IsEmpty(head))
		{
			pthread_cond_wait(&mycond,&mylock);
		}
		PopHead(head,&data);
		printf("I am consumer ..%d\n",data);
		sleep(1);
		pthread_mutex_unlock(&mylock);
	}
}
int main(void)
{
	Node_p head=NULL;
	ListInit(&head);
	pthread_t tid1,tid2;
	int ret1=pthread_create(&tid1,NULL,pthread_Product,(void *)head);
	int ret2=pthread_create(&tid2,NULL,pthread_Consumer,(void *)head);
	printf("ret1:%d,ret2:%d\n",ret1,ret2);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_mutex_destroy(&mylock);
	pthread_cond_destroy(&mycond);
	return 0;
}

