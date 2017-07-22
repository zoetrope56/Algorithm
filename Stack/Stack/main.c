/*
* Author :	Seongchuel Ahn
* E-Mail :	acidlab.help@gmail.com
*
* Summary _
*  Implement 'Stack' by using 'Doubly Linked List'
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

typedef struct Node {
	char	message[16];
	int		id;
	struct	Node* next;
	struct	Node* prev;
}Node;

Node* Push(Node* Get, Node* Tail, char* Message, int Id);
Node* Pop(Node* Post);
void Show(Node* All);

Node* init(void);

Node*	headNode;
Node*	tailNode;
Node*	now;

int			menu;
char		t_Message[16];
int			t_Id;

int main(void) {

	now = init();
	headNode = tailNode = now;

#ifdef DEBUG
	printf(
		"GET[1] : [Message]\t-> %s\nGET[2] : [ID]\t\t-> %d \n",
		headNode->message, headNode->id
	);
	printf(
		"[Address]\nheadNode : %d\nnow : %d\n",
		&headNode, &now
	);
	printf(
		"GET[1] : [Message]\t-> %s\nGET[2] : [ID]\t\t-> %d \n",
		now->message, now->id
	);
	printf("======================================\n\n");
#endif

	while (1) {
		printf("1. PUSH\n2. POP\n3. SHOW\n4. EXIT\n");
		printf("SELECT >> ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			printf("PUSH MESSAGE , ID>> ");

			scanf(
				"%s %d",
				&t_Message, &t_Id
			);
			printf("\n");

			tailNode = Push(now, tailNode, t_Message, t_Id);
			now = tailNode;
			break;
		case 2:
			tailNode = Pop(tailNode);
			now = tailNode;
			break;
		case 3:
			Show(tailNode);
			break;
		case 4:
			free(tailNode);
			return 0;
		}
	}


}

Node* init(void) {
	Node* PathFinder = malloc(sizeof(Node));

	strcpy(PathFinder->message, "First Commit");
	PathFinder->id = 1;
	PathFinder->next = NULL;
	PathFinder->prev = NULL;

	return PathFinder;
}

Node* Push(Node* Get, Node* Tail, char* Message, int Id) {
	Node* AddMore = malloc(sizeof(Node));
	AddMore->next = NULL;
	AddMore->id = Id;
	strcpy(&AddMore->message, Message);
	AddMore->prev = Get;
	Tail->next = AddMore;
	Tail = AddMore;
	return Tail;
}

Node* Pop(Node* Tail) {
	Node* TEMP;
	if (Tail->prev == NULL) {
		printf(
			"{ \"%6d\" : \"%s\" } \n",
			Tail->id, Tail->message
		);
		printf("\n [Warning] Stack UnderFlow..!\n>> Program will be halt !\n");
		return Tail;
	}

	else {
		TEMP = Tail->prev;

		printf(
			"{ \"%6d\" : \"%s\" } \n",
			Tail->id, Tail->message
		);

		TEMP->next = NULL;
		free(Tail);
		return TEMP;
	}
}

void Show(Node* All) {
	Node* forNow;
	forNow = All;
	do {

		printf(
			"{ \"%6d\" : \"%s\" } \n",
			forNow->id, forNow->message
		);

		forNow = forNow->prev;
	} while (forNow != NULL);
}