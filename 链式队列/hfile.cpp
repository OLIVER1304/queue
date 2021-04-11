#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hfile.h"
#define SIZE 10

//检查输入的数据类型和长度是否正确
int chk_data(char *num) {
	int i;
	for (i = 0; num[i] != '\0'; i++) {
		if (num[i] > '9' || num[i] < '0') {
			printf("\n传入值含有非数值\n");
			return 0;
		}
	}
	if (i > 10) {
		printf("\n超出了数字长度\n");
		return 0;
	}
	return 1;
}


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
	Node *head=(Node*)malloc(sizeof(Node));
	Q->front=Q->rear=head;
	head->next=NULL;
	head->data=0;
	Q->length=0;
	printf("\n初始化队列成功\n");
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q) {
	while(Q->front!=Q->rear) {
		Node *L=Q->front;
		Q->front=Q->front->next;
		free(L);
	}
	free(Q->front);
	Q->front=Q->rear=NULL;
	printf("\n销毁队列成功\n");
	printf("\n");
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q) {
	if(Q->length==0) {
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e) {
	if(Q->length==0) {
		printf ("\n队列为空，没有头元素\n");
		return FALSE;
	}
	e=Q->front->next->data;
	if(Q->front->next->type==1) {
		printf("\n头元素为%d\n",*(int*)e);
	}
	if(Q->front->next->type==3) {
		printf("\n头元素为%lf\n",*(double*)e);
	}
	if(Q->front->next->type==2) {
		printf("\n头元素为%s\n",(char*)e);
	}
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
	if(Q==NULL) {
		printf("\n内存分配失败\n");
		return FALSE;
	}
	int length=Q->length;
	printf("\n队列长度： %d\n",length);
	printf("\n");
	return TRUE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data) {
	Node *node=(Node*)malloc(sizeof(Node));
	if(node==NULL) {
		printf("\n内存分配失败\n");
		return FALSE;
	}
	Q->length++;
	if(Q->length==1) {
		node->next=NULL;
		Q->front->next=node;
		Q->rear=Q->rear->next;
		Q->rear->data=(void*)malloc(21);
		memcpy(	Q->rear->data,data,20);
		return TRUE; 
	}
	node->next=Q->rear->next;
	Q->rear->next=node;
	Q->rear=Q->rear->next;
	Q->rear->data=(void *)malloc(21);
	memcpy(	Q->rear->data,data,20);
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q) {
	if(Q->length==0) {
		printf("\n队列为空\n");
		printf("\n");
		return FALSE;
	}
	if(Q->length==1) {
		Node *p=Q->front->next;
		Q->front->next=p->next;
		free(p);
		Q->rear=Q->front;
		Q->length--;
		printf("\n出队成功\n");
		printf("\n");
		return TRUE;
	}
	Node *p=Q->front->next;
	Q->front->next=p->next;
	free(p);
	Q->length--;
	printf("\n出队成功\n");
	printf("\n");
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
	if(Q->length==0) {
		printf("\n队列为空\n");
		printf("\n");
		return;
	}
	while(Q->length!=0) {
		Node *p=Q->front->next;
		Q->front->next=p->next;
		free(p);
		Q->length--;
	}
	free(Q->front);
	Q->rear=Q->front;
	printf("\n成功清空队列\n");
	printf("\n");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,int type)) {
	if(Q->length==0) {
		printf("队列为空");
		return FALSE;
	}
	int i=0;
	Node *p=Q->front->next;
	for(i; i<Q->length; i++) {
		foo(p->data,p->type);
		p=p->next;
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void *q,int type) {
	if(type==1) {
		printf("%d->",*(int*)q);
	}
	if(type==2) {
		printf("%s->",(char*)q);
	}
	if(type==3) {
		printf("%lf->",*(double*)q);
	}
}


