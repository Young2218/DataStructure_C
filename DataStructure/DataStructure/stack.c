#include "stack.h"

/*
 * set a stack before operate stack
 * param int: fixed stack size
 * return: retrun Stack structure pointer 
 */
Stack* set_stack(int stack_size)
{
	Stack* ss = (Stack*)malloc(sizeof(Stack));

	ss->stack = (int*)malloc(sizeof(int)*stack_size);
	ss->stack_size = stack_size;
	ss->top = -1;

	return ss;
}

/*
 * push a integer to given stack
 * param Stack*: it is stack pointer which you want to operatration
 * param int: data which you want to push to stack
 */
void push(Stack* stack, int data)
{
	stack->stack[++stack->top] = data;
}

/*
 * pop a integer from given stack
 * param Stack*: it is stack pointer which you want to operatration
 * return: return data
 */
int pop(Stack* stack)
{
	return stack->stack[stack->top--];
}

/*
 * check if given stack is full or isn't
 * param Stack*: it is stack pointer which you want to operatration
 * return: if stack is full return 1
 */
int is_full(Stack* stack)
{
	if (stack->top >= stack->stack_size - 1)
		return 1;
	return 0;
}

/*
 * check if given stack is empty or isn't
 * param Stack*: it is stack pointer which you want to operatration
 * return: if stack is empty return 1
 */
int is_empty(Stack* stack)
{
	if(stack->top == -1)
		return 1;
	return 0;
}

/*
 * print given stack's data
 * param Stack*: stack pointer which you want to operatration
 */
void print_stack(Stack * stack)
{
	for (int i = stack->top; i >= 0; i--) {
		printf("%d\n", stack->stack[i]);
	}
}

DS* set_dynamic_stack(size_t size)
{
	DS* stack = (DS*)malloc(sizeof(DS));
	stack->head = NULL;
	stack->size = size;
	return stack;
}

void d_push(DS * stack, void* data)
{
	void* temp;

	if (data == NULL) return;
	if (stack->head == NULL) {
		stack->head = (Node*)malloc(sizeof(Node));
		((Node*)stack->head)->data = malloc(stack->size);
		*(((Node*)stack->head)->data) = *data;
	}

	while (temp != NULL) {
		temp
	}

	if(stack->head == NULL)
}

void test_stacks()
{
	int opt;

	printf("Choose number which you want to test:\n");
	printf("1: Basic Stack - Integer\n");
	scanf_s("%d", &opt);

	if (1 == opt) {
		printf("Enter size of stack: ");
		do	
			scanf_s("%d", &opt); 
		while (opt <= 0);
		Stack* stack = set_stack(opt);

		do {
			printf("(1)push   (2)pop   (3)print   (4)exit\n");
			scanf_s("%d", &opt);

			if (1 == opt) { // push
				if (is_full(stack)) {
					printf("Stack is full.\n");
				}
				else {
					printf("Enter a data: ");
					scanf_s("%d", &opt);

					push(stack, opt);
				}
			}
			else if (2 == opt) { // pop
				if (is_empty(stack)) {
					printf("Stack is empty.\n");
				}
				else printf("%d is poped\n", pop(stack));
				
			}
			else if (3 == opt) { // print
				if (is_empty(stack)) {
					printf("Stack is empty.\n");
				}
				else print_stack(stack);
			}
		} while (4 != opt);
	}
	else return;
}



