#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "hfile.h"

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
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q) {
	Q->front=Q->rear=0;
	Q->length=0;
	int i;
	for(i=0; i<MAXQUEUE; i++) {
		Q->data[i]=(void *)malloc(21);
	}
	printf("\n初始化队列成功\n");
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q) {
	int i;
	Q->front=Q->rear=0;
	for(i=0; i<MAXQUEUE; i++) {
		free(Q->data[i]);
	}
	Q->data[0]=NULL;
	printf("\n销毁队列成功\n");
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q) {
	if(Q->length==MAXQUEUE-1) {
		printf("\n队列已满\n");
		return TRUE;
	}
	if(Q->front==Q->rear) {
		printf("\n队列为空\n");
		return FALSE;
	}
	printf("\n队列未满\n");
	return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q) {
	if(Q->front==Q->rear) {
		printf("\n队列为空\n");
		return TRUE;
	}
	printf("\n队列不为空\n");
	return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e) {
	if(Q->front==Q->rear) {
		printf("\n队列为空\n");
		return FALSE;
	}
	memcpy(e,Q->data[Q->front],20);
	if(datatype[Q->front]=='i') {
		printf("\n");
		printf("头元素：%d    类型为int\n",*(int*)e);
	}
	if(datatype[Q->front]=='s') {
		printf("\n");
		printf("头元素：%s    类型为string\n",(char*)e);
	}if(datatype[Q->front]=='d') {
		printf("\n");
		printf("头元素：%lf   类型为double\n",*(double*)e);
	}
	return TRUE;
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q) {
	int count;
	count=Q->length;
	//count=(Q->rear+MAXQUEUE-Q->front)%MAXQUEUE;
	return count;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data) {
	if(Q->length==MAXQUEUE-1) {
		printf("队列已满");
		return FALSE;
	}
	if(Q->front==Q->rear) {
		memcpy(Q->data[Q->front],data,20);
		Q->length++;
		Q->rear++;
		if(Q->rear==MAXQUEUE) {
			Q->rear=0;
		}
		return TRUE;
	}
	memcpy(Q->data[Q->rear],data,20);
	Q->rear=(Q->rear+1)%MAXQUEUE;
	Q->length++;
	return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q) {
	if(Q->front==Q->rear) {
		printf("队列为空");
		return FALSE;
	}
	Q->length--;
	Q->front=(Q->front+1)%MAXQUEUE;
	return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q) {
	if(Q->front==Q->rear) {
		printf("队列已经为空");
		return;
	}
	Q->front=Q->rear=0;
	printf("成功清空队列");
}


/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,const AQueue *Q,int k)) {
	if(Q->front==Q->rear) {
		printf("队列为空");
		return FALSE;
	}
	int i=Q->front;

	int j=Q->length;
	for(j; j>0; j--) {
		foo(Q->data[i],Q,i);
		i=(i+1)%MAXQUEUE;
	}
	return TRUE;
}



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q,const AQueue *Q,int k) {
	if(datatype[k]=='d') {
		printf("-->%lf",*(double*)q);
	} else if(datatype[k]=='i') {
		printf("-->%d",*(int*)q);
	} else if(datatype[k]=='s') {
		printf("-->%s",(char*)q);
	} else if(datatype[k]=='c') {
		printf("-->%c",*(char*)q);
	}
}




