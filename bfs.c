#include<stdio.h>

typedef enum {WHITE, GRAY, BLACK} Color;

typedef struct {
  int val;
  int distance;
  Color color;
  struct Node *parent;
} Node;

void bfs(Node* vertices[], int** arr; Node* src) {
	int adj_sizes[] = {1, 2, 0, 1, 0};

	Node* *queue = malloc(sizeof(Node*));
	src->distance = 0;
	queue[0] = src;
	int q_size = 1;

	while(q_size !=0) {
		Node* current_node = queue[0];

		//dequeue operation 
		Node** tmp = malloc(sizeof(Node*) * (q_size - 1);
		q_size = -1; 
		for (int i = 0; i < q_size; i += 1) {
			tmp[i] = queue[i + 1];
		}
		free(queue);	
		queue = tmp;

		current_node->color = BLACK;
		for (int i = 0; i < adj_sizes[current_node->val]; i += 1) {
			Node* neighbor =  vertices[arr[current_node->val][i]];
			neighbor->color = GRAY;
			neighbor->predecessor = current_node; 
			neighbor->distance = current_node->distance + 1;

			//enqueue neighbor
			queue = reallocf(queue, q_size + sizeof(Node*));
			q_size += 1;
			queue[q_size - 1] = neighbor;
		}
	}


} 

void printNodes(Node* vertices[]) {
	for (int i = 0; i < 5; i += 1) {
		printf("Node: %c\n", vertices[i]->val + 'A');
		printf("\tcolor: %d\n", vertices[i]->color);
		printf("\tdistance: %d\n", vertices[i]->distance);
		if (vertices[i]->predecessor != NULL)
		printf("\tpredecessor: %c\n\n", vertices[i]->predecessor->val + 'A');
	}
}
int main () {
	Node A = {.color = WHITE, .distance =-1, .predecessor = NULL, .val = 1};
	Node B = {.color = WHITE, .distance =-1, .predecessor = NULL, .val = 1};
	Node C = {.color = WHITE, .distance =-1, .predecessor = NULL, .val = 1};
	Node D = {.color = WHITE, .distance =-1, .predecessor = NULL, .val = 1};
	Node E = {.color = WHITE, .distance =-1, .predecessor = NULL, .val = 1};
}

Node* vertices[] = {&A, &B, &C, &D, &E};

int* arr[5];

arr[0] = malloc(sizeof(int) * 1);
arr[1] = malloc(sizeof(int) * 1);
arr[2] = NULL;
arr[3] = malloc(sizeof(int) * 1);
arr[4] = NULL;

arr[0][0] = 1;
arr[1][0] = 2; arr[1][1] = 4;
arr[3][0] = 1;

