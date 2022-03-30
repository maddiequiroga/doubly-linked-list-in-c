#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char[20]  key;
	struct node *next;
	struct node *prev;
};

//struct node *head_x;
//struct node *tail_x;
struct node *head = NULL;
struct node *tail = NULL;
struct node *current = NULL;

int isEmpty(){
	if (head == NULL) return 1;
}

struct node* create(char[20] key){
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->key = key;
	new->prev = NULL;
	new->next = NULL;
	return new;
}


void addHead(char[20] key){
	struct node *new = create(key);
	if(head == NULL){
		head = new;
	//	head->prev = head_x;
	//	head->next = tail_x;
		return;
	}	
	head->prev = new;
	new->next = head;
	head = new;
}

void addTail(char[20] key){
	struct node *temp = head;
	struct node *new = create(key);
	if(head == NULL){
		head = new;
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new;
	new->prev = temp;
	tail = new;
}

void del(char[20] key){
	struct node *curr = head;
	struct node *prev = NULL;
	if(head == NULL){
		return;
	}
	while(curr->key != key){
		if(curr->next == NULL){
			return;
		}
		else{
			prev = curr;
			curr = curr->next;
		}
	}
	if(curr == head){
		head = head->next;
	}
	else{
		curr->prev->next = curr->next;
	}
	if(curr == last){
		last = curr->prev;
	}
	else{
		curr->next->prev = curr->prev;
	}
}

void print(FILE *file){
	struct node *curr = head;
	curr->prev->key = "HEAD";
	if(curr == NULL){
		fputs("EMPTY", file);
		return;
	}
	while(curr != tail){
		if(curr->next == NULL){
			curr->next->key = "TAIL";
		}
		fprintf("(%s, %s, %s), ", curr->key, curr->prev->key, curr->next->key);
		curr = curr->next;
	}
}
		
main(int argc, char **argv[]){
	File *input = fopen(argv[1], "r");
	File *output =fopen(argv[2], "w");
	if(input == NULL || output == NULL){
		printf("Error: File cannot be opened\n");
		exit(-1);
	}


}

