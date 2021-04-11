#include <stdio.h>
#include <stdlib.h>
#include "hfile.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LQueue *Q=(LQueue *)malloc(sizeof(LQueue));
	int flag=0;
	while(1) {
		printf("[1]��ʼ������                   [2]�ж϶����Ƿ�Ϊ��\n");
		printf("[3]���                         [4]����\n");
		printf("[5]�õ���ͷԪ��                 [6]��ն�\n");
		printf("[7]���ٶ�                       [8]���ӳ���\n");
		if(flag==1) {
			printf("\n");
			TraverseLQueue(Q,LPrint);
			printf("\n");
		} else {
			printf("\nδ��ʼ��ջ\n");
		}
		int chk_data(char *num);
		char str[SIZE];
		printf("\n������Ҫִ�еĲ�����Ӧ������:");
		scanf("%s", &str);
		while (chk_data(str) == 0) {
			printf("�������ݴ�������������:");
			scanf("%s", &str);
			continue;
		}
		int k=atoi(str);
		if(k<=0||k>=9) {
			printf("\nû�ж�Ӧ�Ĳ���\n");
			printf("\n");
			system("pause");
			system("cls");
			continue;
		}
		switch(k) {
			case 1: {
				flag=1;
				InitLQueue(Q);
				printf("\n");
				system("pause");
				system("cls");
				flag=1;
				break;
			}
			case 2: {
				if(flag==1) {
					int ifempty=IsEmptyLQueue(Q);
					if(ifempty) {
						printf("\n�������Ϊ��\n");
					} else {
						printf("\n���������Ԫ��\n");
					}
				} else {
					printf("\nδ��ʼ��ջ\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				if(flag==1) {
					printf("\n");
					printf("1.int  2.string  3.double\n");
					int chk_data(char *num);
					char str[SIZE];
					printf("\nѡ��Ҫ��������Ͷ�Ӧ������:");
					scanf("%s", &str);
					while (chk_data(str) == 0) {
						printf("�����������������:");
						scanf("%s", &str);
						continue;
					}
					int k=atoi(str);
					if(k<=0||k>=4) {
						printf("\nû�ж�Ӧ�Ĳ���\n");
						printf("\n");
						system("pause");
						system("cls");
						break;
					}
					switch(k) {
						case 1: {
							int *aa;
							printf("\n����������");
							scanf("%d",&aa);
							EnLQueue(Q,&aa);
							Q->rear->type=1;
							break;
						}
						case 2: {
							char *bb;
							printf("\n����������");
							scanf("%s",&bb);
							EnLQueue(Q,&bb);
							Q->rear->type=2;
							break;
						}
						case 3: {
							double *dd;
							printf("\n����������");
							scanf("%lf",&dd);
							EnLQueue(Q,&dd);
							Q->rear->type=3;
							break;
						}
					}
					printf("\n");
					TraverseLQueue(Q,LPrint);
				} else {
					printf("\nδ��ʼ��ջ\n");
				}
				printf("\n");
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 4: {
				if(flag==1) {
					DeLQueue(Q);
					printf("\n");
					TraverseLQueue(Q,LPrint);
				} else {
					printf("\nδ��ʼ��ջ\n");
				}
				printf("\n");
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 5: {
				if(flag==1) {
					void *e=(void *)malloc(sizeof(void));
					GetHeadLQueue(Q,e);
				} else {
					printf("\nδ��ʼ��ջ\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 6: {
				if(flag==1) {
					ClearLQueue(Q);
				} else {
					printf("\nδ��ʼ��ջ\n");
					printf("\n");
				}
				system("pause");
				system("cls");
				break;
			}
			case 7: {
				if(flag==1) {
					DestoryLQueue(Q);
					flag=0;
				} else {
					printf("\nδ��ʼ��ջ\n");
					printf("\n");
				}
				system("pause");
				system("cls");
				break;
			}
			case 8: {
				if(flag==1) {
					LengthLQueue(Q);
				} else {
					printf("\nδ��ʼ��ջ\n");
					printf("\n");
				}
				system("pause");
				system("cls");
				break;
			}
		}
	}
}
