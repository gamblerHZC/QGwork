#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct one_way_work {//单向链表
	int num;
	struct one_way_work* next;
};
#define ONE_WAY_WORK sizeof(struct one_way_work)
struct one_way_work* OWCreateWork(int n) {//根据输入数据创建单向链表
	if (n <= 0) {
		printf("您输入的节点数据有误，请重新输入");
		return NULL;
	}
	struct one_way_work* head, * p, * q;
	head = (struct one_way_work*)malloc(ONE_WAY_WORK);
	head->num = 1;
	head->next = NULL;
	int i = 1;
	for (p = head; i < n; i++) {
		q = (struct one_way_work*)malloc(ONE_WAY_WORK);
		q->num = i + 1;
		p->next = q;
		p = p->next;
	}
	p->next = NULL;
	return head;
}
struct two_way_work {//双向链表
	struct two_way_work* prev;
	int num;
	struct two_way_work* next;
};
#define TWO_WAY_WORK sizeof(struct two_way_work)
struct two_way_work* TWCreateWork(int n) {//根据输入数建立双向链表
	if (n <= 0) {
		printf("您输入的节点数据有误，请重新输入");
		return NULL;
	}
	struct two_way_work* head, * p, * q;
	head = (struct two_way_work*)malloc(TWO_WAY_WORK);
	head->num = 1;
	head->next = NULL;
	head->prev = NULL;
	int i = 1;
	for (p = head; i < n; i++) {
		q = (struct two_way_work*)malloc(TWO_WAY_WORK);
		q->num = i + 1;
		q->prev = p;
		p->next = q;
		p = p->next;
	}
	p->next = NULL;
	return head;
}
int main() {
	int a, b;
	for (;;) {
		system("cls");
		printf("1、单向链表\n2、双向链表\n3、退出\n请输入你的选择：");
		scanf("%d", &a);
		fflush(stdin);
		switch (a) {
		case 1:
			system("cls");//清屏
			printf("单向链表的建立，请输入你设定的节点数：");
			scanf("%d", &b);
			{struct one_way_work* oww = OWCreateWork(b);
			printf("\n输出链表节点：");
			for (struct one_way_work* p = oww; p != NULL; p = p->next) {
				printf("  %d  ", p->num);
				if (p->next == NULL) {
					break;
				}
			}
			printf("\n");
			Sleep(1000);
			}
			break;
		case 2:
			system("cls");//清屏
			printf("双向链表的建立，请输入你设定的节点数：");
			scanf("%d", &b);
			{struct two_way_work* tww = TWCreateWork(b);
			printf("正向链表节点：");
			for (struct two_way_work* p = tww;; p = p->next) {
				printf("  %d  ", p->num);
				if (p->next == NULL) {
					printf("\n反向链表节点：");
					for (struct two_way_work* q = p;; q = q->prev) {
						printf("  %d  ", q->num);
						if (q->prev == NULL) {
							break;
						}
					}
					break;
				}
			}
			printf("\n");
			Sleep(1000);
			 }
			break;
		case 3:
			system("cls");
			return 0;
		}
	}
}