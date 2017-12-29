#ifndef __STACK_H__
#define __STACK_H__

#include<stdbool.h>

#define INITIAL_STACK_SIZE 4

typedef struct {
  void *elems;
  int elem_sz;
  int log_len; // no. of items in the stack
  int alloc_len; // total size of stack
} stack;


void stack_new(stack *s, size_t elem_sz);
void stack_del(stack *s);
void stack_push(stack *s, void *elem);
void stack_pop(stack *s, void *elem_addr);
int  stack_depth(stack *s);
bool is_empty(stack *s);
#endif
