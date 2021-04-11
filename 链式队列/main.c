#include <stdio.h>
#include <stdlib.h>
#include "hfile.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LQueue *Q=(LQueue *)malloc(sizeof(LQueue));
	int flag=0;
	while(1) {
		printf("[1]初始化队列                   [2]判断队列是否为空\n");
		printf("[3]入队                         [4]出队\n");
		printf("[5]得到对头元素                 [6]清空队\n");
		printf("[7]销毁队                       [8]检测队长度\n");
		if(flag==1) {
			printf("\n");
			TraverseLQueue(Q,LPrint);
			printf("\n");
		} else {
			printf("\n未初始化栈\n");
		}
		int chk_data(char *num);
		char str[SIZE];
		printf("\n请输入要执行的操作对应的数字:");
		scanf("%s", &str);
		while (chk_data(str) == 0) {
			printf("输入数据错误，请重新输入:");
			scanf("%s", &str);
			continue;
		}
		int k=atoi(str);
		if(k<=0||k>=9) {
			printf("\n没有对应的操作\n");
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
						printf("\n链表队列为空\n");
					} else {
						printf("\n链表队列有元素\n");
					}
				} else {
					printf("\n未初始化栈\n");
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
					printf("\n选择要输入的类型对应的数字:");
					scanf("%s", &str);
					while (chk_data(str) == 0) {
						printf("输入错误，请重新输入:");
						scanf("%s", &str);
						continue;
					}
					int k=atoi(str);
					if(k<=0||k>=4) {
						printf("\n没有对应的操作\n");
						printf("\n");
						system("pause");
						system("cls");
						break;
					}
					switch(k) {
						case 1: {
							int *aa;
							printf("\n请输入数据");
							scanf("%d",&aa);
							EnLQueue(Q,&aa);
							Q->rear->type=1;
							break;
						}
						case 2: {
							char *bb;
							printf("\n请输入数据");
							scanf("%s",&bb);
							EnLQueue(Q,&bb);
							Q->rear->type=2;
							break;
						}
						case 3: {
							double *dd;
							printf("\n请输入数据");
							scanf("%lf",&dd);
							EnLQueue(Q,&dd);
							Q->rear->type=3;
							break;
						}
					}
					printf("\n");
					TraverseLQueue(Q,LPrint);
				} else {
					printf("\n未初始化栈\n");
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
					printf("\n未初始化栈\n");
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
					printf("\n未初始化栈\n");
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
					printf("\n未初始化栈\n");
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
					printf("\n未初始化栈\n");
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
					printf("\n未初始化栈\n");
					printf("\n");
				}
				system("pause");
				system("cls");
				break;
			}
		}
	}
}
