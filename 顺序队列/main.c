#include <stdio.h>
#include <stdlib.h>
#include "hfile.cpp"
#define SIZE 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	AQueue *Q=(AQueue *)malloc(sizeof(AQueue));
	int flag=0;
	while(1) {
		printf("[1]初始化队列                     [2]销毁队列 \n");
		printf("[3]入队                           [4]出队\n");
		printf("[5]得到头元素                     [6]获取队列的长度\n");
		printf("[7]判断队列是否满                 [8]判断队列是否为空\n");
		printf("[9]清空队列\n");
		if(flag==1) {
			printf("\n");
			TraverseAQueue(Q,APrint);
			printf("\n");
		} else {
			printf("\n未初始化栈\n");
		}
		int chk_data(char *num);
		char str[SIZE];
		printf("\n请输入要执行的操作对应的数字:");
		scanf("%s", &str);
		while (chk_data(str)==0) {
			printf("输入错误，请重新输入:");
			scanf("%s", &str);
			continue;
		}
		int k=atoi(str);
		if(k<=0||k>=10) {
			printf("\n没有对应的操作\n");
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
					printf("\n队列未初始化\n");
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
					printf("\n请选择要输入的类型对应的数字:");
					scanf("%s", &str);
					while (chk_data(str)==0) {
						printf("输入数据，请重新输入:");
						scanf("%s", &str);
						continue;
					}
					int m=atoi(str);
					if(m<=0||m>=4) {
						printf("\n没有对应的类型\n");
					}
					switch(m) {
						case 1: {
							int *d;
							printf("请输入数据:");
							scanf("%d",&d);
							datatype[Q->rear]='i';
							EnAQueue(Q,&d);
							break;
						}
						case 2 : {
							char *s[20];
							printf("请输入数据:");
							scanf("%s",&s);
							datatype[Q->rear]='s';
							EnAQueue(Q,&s);
							break;
						}
						case 3 : {
							double *lf;
							printf("请输入数据:");
							scanf("%lf",&lf);
							datatype[Q->rear]='d';
							EnAQueue(Q,&lf);
							break;
						}
					}
					printf("\n");
					TraverseAQueue(Q, APrint);
				} else {
					printf("\n队列未初始化\n");
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
					printf("\n队列未初始化\n");
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
					printf("\n队列未初始化\n");
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
					printf("队列长度为%d\n",L);
				} else {
					printf("\n队列未初始化\n");
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
					printf("\n队列未初始化\n");
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
					printf("\n队列未初始化\n");
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
					printf("\n队列未初始化\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
		}
	}
}


