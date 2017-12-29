#include "header_file.h"

typedef int (*cmp)(void *, void *);

int intCmp(void *key, void *elem) {
  //return (int *)key - (int *)elem;
  return (*(int *)key - *(int *)elem);
  /*
  int *ip1 = key;
  int *ip2 = elem;
  return *ip1 - *ip2;
  */
}

int strCmp(void *key, void *base) {

  char *s1 = *(char **)key;
  char *s2 = *(char **)base;
  return strcmp(s1, s2);

}

void* lsearch(void *key,
              void *base,
	      int  n,
	      int elemSz,
	      cmp Cmp
             ) {
  for(int i = 0; i < n ; ++i) {
    void* elemAddr = (char *)base + i*elemSz;
    if(Cmp(key, elemAddr) == 0) {
      return elemAddr;
    }
  }

  return NULL;
}


int main() {

  //ints
  int intKey = 7;
  int intArr[] = {5,6,7,8,9};
  int* found = lsearch(&intKey, intArr, 5, sizeof(int), intCmp);
  assert(found != NULL);
  printf("%d\n", *found);

  //c-strings
  char *strArr[] = {"C", "C++", "Java", "Python", "Scala", "Go"};
  char *strKey = "Hello";
  char *lang = lsearch(&strKey, strArr, 6, sizeof(char *), strCmp);
  assert(lang == NULL); 

  strKey = "Scala";
  lang = lsearch(&strKey, strArr, 6, sizeof(char *), strCmp);
  assert(lang != NULL); 
  printf("%s\n", *(char **)lang);
  return 0;
}
