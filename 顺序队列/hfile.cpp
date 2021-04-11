#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "hfile.h"

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
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q) {
	Q->front=Q->rear=0;
	Q->length=0;
	int i;
	for(i=0; i<MAXQUEUE; i++) {
		Q->data[i]=(void *)malloc(21);
	}
	printf("\n��ʼ�����гɹ�\n");
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q) {
	int i;
	Q->front=Q->rear=0;
	for(i=0; i<MAXQUEUE; i++) {
		free(Q->data[i]);
	}
	Q->data[0]=NULL;
	printf("\n���ٶ��гɹ�\n");
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q) {
	if(Q->length==MAXQUEUE-1) {
		printf("\n��������\n");
		return TRUE;
	}
	if(Q->front==Q->rear) {
		printf("\n����Ϊ��\n");
		return FALSE;
	}
	printf("\n����δ��\n");
	return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q) {
	if(Q->front==Q->rear) {
		printf("\n����Ϊ��\n");
		return TRUE;
	}
	printf("\n���в�Ϊ��\n");
	return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e) {
	if(Q->front==Q->rear) {
		printf("\n����Ϊ��\n");
		return FALSE;
	}
	memcpy(e,Q->data[Q->front],20);
	if(datatype[Q->front]=='i') {
		printf("\n");
		printf("ͷԪ�أ�%d    ����Ϊint\n",*(int*)e);
	}
	if(datatype[Q->front]=='s') {
		printf("\n");
		printf("ͷԪ�أ�%s    ����Ϊstring\n",(char*)e);
	}if(datatype[Q->front]=='d') {
		printf("\n");
		printf("ͷԪ�أ�%lf   ����Ϊdouble\n",*(double*)e);
	}
	return TRUE;
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data) {
	if(Q->length==MAXQUEUE-1) {
		printf("��������");
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q) {
	if(Q->front==Q->rear) {
		printf("����Ϊ��");
		return FALSE;
	}
	Q->length--;
	Q->front=(Q->front+1)%MAXQUEUE;
	return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q) {
	if(Q->front==Q->rear) {
		printf("�����Ѿ�Ϊ��");
		return;
	}
	Q->front=Q->rear=0;
	printf("�ɹ���ն���");
}


/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,const AQueue *Q,int k)) {
	if(Q->front==Q->rear) {
		printf("����Ϊ��");
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
 *    @description : ��������
 *    @param         q ָ��q
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




