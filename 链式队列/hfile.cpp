#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hfile.h"
#define SIZE 10

//���������������ͺͳ����Ƿ���ȷ
int chk_data(char *num) {
	int i;
	for (i = 0; num[i] != '\0'; i++) {
		if (num[i] > '9' || num[i] < '0') {
			printf("\n����ֵ���з���ֵ\n");
			return 0;
		}
	}
	if (i > 10) {
		printf("\n���������ֳ���\n");
		return 0;
	}
	return 1;
}


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
	Node *head=(Node*)malloc(sizeof(Node));
	Q->front=Q->rear=head;
	head->next=NULL;
	head->data=0;
	Q->length=0;
	printf("\n��ʼ�����гɹ�\n");
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
	printf("\n���ٶ��гɹ�\n");
	printf("\n");
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e) {
	if(Q->length==0) {
		printf ("\n����Ϊ�գ�û��ͷԪ��\n");
		return FALSE;
	}
	e=Q->front->next->data;
	if(Q->front->next->type==1) {
		printf("\nͷԪ��Ϊ%d\n",*(int*)e);
	}
	if(Q->front->next->type==3) {
		printf("\nͷԪ��Ϊ%lf\n",*(double*)e);
	}
	if(Q->front->next->type==2) {
		printf("\nͷԪ��Ϊ%s\n",(char*)e);
	}
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
	if(Q==NULL) {
		printf("\n�ڴ����ʧ��\n");
		return FALSE;
	}
	int length=Q->length;
	printf("\n���г��ȣ� %d\n",length);
	printf("\n");
	return TRUE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data) {
	Node *node=(Node*)malloc(sizeof(Node));
	if(node==NULL) {
		printf("\n�ڴ����ʧ��\n");
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q) {
	if(Q->length==0) {
		printf("\n����Ϊ��\n");
		printf("\n");
		return FALSE;
	}
	if(Q->length==1) {
		Node *p=Q->front->next;
		Q->front->next=p->next;
		free(p);
		Q->rear=Q->front;
		Q->length--;
		printf("\n���ӳɹ�\n");
		printf("\n");
		return TRUE;
	}
	Node *p=Q->front->next;
	Q->front->next=p->next;
	free(p);
	Q->length--;
	printf("\n���ӳɹ�\n");
	printf("\n");
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
	if(Q->length==0) {
		printf("\n����Ϊ��\n");
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
	printf("\n�ɹ���ն���\n");
	printf("\n");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,int type)) {
	if(Q->length==0) {
		printf("����Ϊ��");
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
 *    @description : ��������
 *    @param         q ָ��q

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


