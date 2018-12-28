#pragma once
#include "data_structure.h"

struct Stack {
	int top;
	int* stack;
	int stack_size;
};
typedef struct Stack Stack;

struct DynamicStack {
	void* head;
	size_t size;
};
typedef struct DynamicStack DS;

struct Node {
	void* data;
	struct Node* next;
};
typedef struct Node Node;

Stack* set_stack(int stack_size);
void push(Stack* stack, int data);
int pop(Stack* stack);
int is_full(Stack* stack);
int is_empty(Stack* stack);
void print_stack(Stack* stack);

DS* set_dynamic_stack(size_t size);
void d_push(DS* stack, void* data);
void* d_pop(DS* stack);
int is_empty(DS* stack);
void free_to_stack(DS* stack);
void print_dynamic_stack(DS* stack);


void test_stacks();