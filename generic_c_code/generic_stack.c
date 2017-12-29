#include "header_file.h"
#include "stack.h"

void stack_new(stack *s, size_t elem_sz) {
  assert(elem_sz > 0);
  s->elem_sz = elem_sz;
  s->log_len = 0;
  s->alloc_len = INITIAL_STACK_SIZE;
  s->elems = malloc(s->alloc_len * elem_sz);
  assert(s->elems != NULL);
}

bool is_empty(stack *s) {
  assert(s != NULL);
  return (s->log_len == 0);
}

void stack_del(stack *s) {
  assert(s != NULL);
  free(s->elems);
}

int  stack_depth(stack *s) {
  assert(s != NULL);
  return s->log_len;
}

void stack_push(stack *s, void *elem) {
  assert(s != NULL);

  // stack is FULL, resize
  if(s->alloc_len == s->log_len) {
    s->alloc_len *= 2;
    s->elems = realloc(s->elems, s->alloc_len * s->elem_sz);
    assert(s->elems != NULL);
  }
  void *dst = (char *)s->elems + (s->log_len * s->elem_sz);
  memcpy(dst, elem, s->elem_sz);
  s->log_len++;
}

void stack_pop(stack *s, void *elem_addr)  {
  assert(s != NULL && !is_empty(s));

  s->log_len--;
  void *src = (char *)s->elems + (s->log_len * s->elem_sz);
  memcpy(elem_addr, src, s->elem_sz);
}


