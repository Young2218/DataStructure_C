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
	if (stack->top == -1)
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

/*
 * set to dynamic stack and data size before to use
 * this stack can be used every data type(int, float, structure etc...)
 * param size_t: byte size of data
 * return DynamicStack*: return dynamic stack structure
 */
DS* set_dynamic_stack(size_t size)
{
	DS* stack = (DS*)malloc(sizeof(DS));
	stack->head = NULL;
	stack->size = size;
	return stack;
}

/*
 * push given data to dynamic stack
 * param DynamicStack*: given dynamic stack
 * param void*: pointer of data
 */
void d_push(DS * stack, void* data)
{
	Node *dataNode;

	if (data == NULL) return;

	dataNode = (Node*)malloc(sizeof(Node));
	dataNode->data = malloc(sizeof(stack->size));
	memcpy_s(dataNode->data, stack->size, data, stack->size);
	dataNode->next = stack->head;
	stack->head = dataNode;
}

/*
 * pop a data from given dynamic stack
 * you must deallocate data to manage memory
 * param DynamicStack*: given dynamic stack
 * return: return pointer of data
 */
void* d_pop(DS * stack)
{
	Node* temp;
	void* result;

	if (d_is_empty(stack)) return NULL;
	temp = stack->head;
	stack->head = stack->head->next;

	result = temp->data;
	free(temp);

	return result;
}

/*
 * check if dyanmic stack is empty
 * param DynamicStack: given dynamic stack
 * return: return 1 if stack is empty
 */
int d_is_empty(DS * stack)
{
	if (stack->head == NULL)
		return 1;
	return 0;
}

/*
 * deallocate all data of stack
 * param DynamicStack: given dynamic stack
 */
void free_to_stack(DS * stack)
{
	Node *cur, *next;

	cur = stack->head;
	while (cur != NULL) {
		next = cur->next;
		free(cur->data);
		free(cur);
		cur = next;
	}
	stack->head = NULL;
}

/*
 * print every data in dynamic stack
 * param DynamicStack*: given dynamic stack
 */
void print_dynamic_stack(DS * stack)
{
	Node* temp = stack->head;

	while (temp != NULL) {
		printf("%p\n", temp->data);
		temp = temp->next;
	}
}

void test_stacks()
{
	int opt;

	printf("Choose number which you want to test:\n");
	printf("1: Basic Stack - integer\n");
	printf("2: Dynamic Stack - every type\n");
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
	else if (2 == opt) {
		char str[20], *temp;
		DS* stack = set_dynamic_stack(sizeof(str));
		
		printf("%d\n", sizeof(str));
		do {
			printf("(0)free   (1)push   (2)pop   (3)print   (4)exit\n");
			scanf_s("%d%*c", &opt);

			if (1 == opt) { // push
				printf("Enter a string: ");
				scanf_s(" %s%*c", str, sizeof(str));
				d_push(stack, str);
			}
			else if (2 == opt) { // pop
				if (d_is_empty(stack)) {
					printf("Stack is empty.\n");
				}
				else {
					temp = (char*)d_pop(stack);
					printf("%s is poped\n", temp);
					free(temp);
				}
			}
			else if (3 == opt) { // print
				if (d_is_empty(stack)) {
					printf("Stack is empty.\n");
				}
				else print_dynamic_stack(stack);
			}
			else if (0 == opt) { // free
				free_to_stack(stack);
			}
		} while (4 != opt);
		free_to_stack(stack);
	}
	else return;
}



