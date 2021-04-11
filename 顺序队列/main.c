#include <stdio.h>
#include <stdlib.h>
#include "hfile.cpp"
#define SIZE 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	AQueue *Q=(AQueue *)malloc(sizeof(AQueue));
	int flag=0;
	while(1) {
		printf("[1]��ʼ������                     [2]���ٶ��� \n");
		printf("[3]���                           [4]����\n");
		printf("[5]�õ�ͷԪ��                     [6]��ȡ���еĳ���\n");
		printf("[7]�ж϶����Ƿ���                 [8]�ж϶����Ƿ�Ϊ��\n");
		printf("[9]��ն���\n");
		if(flag==1) {
			printf("\n");
			TraverseAQueue(Q,APrint);
			printf("\n");
		} else {
			printf("\nδ��ʼ��ջ\n");
		}
		int chk_data(char *num);
		char str[SIZE];
		printf("\n������Ҫִ�еĲ�����Ӧ������:");
		scanf("%s", &str);
		while (chk_data(str)==0) {
			printf("�����������������:");
			scanf("%s", &str);
			continue;
		}
		int k=atoi(str);
		if(k<=0||k>=10) {
			printf("\nû�ж�Ӧ�Ĳ���\n");
			printf("\n");
			system("pause");
			system("cls");
			continue;
		}
		switch(k) {
			case 1: {
				InitAQueue(Q);
				flag=1;
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				if(flag==1) {
					DestoryAQueue(Q);
					flag=0;
				} else {
					printf("\n����δ��ʼ��\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				if(flag==1) {
					printf("\n");
					printf("1.int   2.string  3.double\n");
					int chk_data(char *num);
					char str[SIZE];
					printf("\n��ѡ��Ҫ��������Ͷ�Ӧ������:");
					scanf("%s", &str);
					while (chk_data(str)==0) {
						printf("�������ݣ�����������:");
						scanf("%s", &str);
						continue;
					}
					int m=atoi(str);
					if(m<=0||m>=4) {
						printf("\nû�ж�Ӧ������\n");
					}
					switch(m) {
						case 1: {
							int *d;
							printf("����������:");
							scanf("%d",&d);
							datatype[Q->rear]='i';
							EnAQueue(Q,&d);
							break;
						}
						case 2 : {
							char *s[20];
							printf("����������:");
							scanf("%s",&s);
							datatype[Q->rear]='s';
							EnAQueue(Q,&s);
							break;
						}
						case 3 : {
							double *lf;
							printf("����������:");
							scanf("%lf",&lf);
							datatype[Q->rear]='d';
							EnAQueue(Q,&lf);
							break;
						}
					}
					printf("\n");
					TraverseAQueue(Q, APrint);
				} else {
					printf("\n����δ��ʼ��\n");
				}
				printf("\n");
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 4: {
				if(flag==1) {
					DeAQueue(Q);
					printf("\n");
					TraverseAQueue(Q, APrint);
				} else {
					printf("\n����δ��ʼ��\n");
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
					GetHeadAQueue(Q,e);
				} else {
					printf("\n����δ��ʼ��\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 6: {
				if(flag==1) {
					int L=LengthAQueue(Q);
					printf("\n");
					printf("���г���Ϊ%d\n",L);
				} else {
					printf("\n����δ��ʼ��\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 7: {
				if(flag==1) {
					IsFullAQueue(Q);
				} else {
					printf("\n����δ��ʼ��\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 8: {
				if(flag==1) {
					IsEmptyAQueue(Q);
				} else {
					printf("\n����δ��ʼ��\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 9: {
				if(flag==1) {
					ClearAQueue(Q); 
				} else {
					printf("\n����δ��ʼ��\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
		}
	}
}


