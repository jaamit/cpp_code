#include "header_file.h"

//generic swap func()
void swap(void   *vp1,
          void   *vp2,
	  size_t sz) {
  char *buffer = (char *)malloc(sz);
  memcpy(buffer, vp1, sz);
  memcpy(vp1, vp2, sz);
  memcpy(vp2, buffer, sz);

  free(buffer);
}

int main(){
  double d = 3.14, e = 1.67;
  swap(&d, &e, sizeof(double));
  assert(d == 1.67 && e == 3.14);      
 
  char *src = "SRC";
  char *dst = "DEST";
  swap(&src, &dst, sizeof(char *));
  assert(strcmp(src, "DEST") == 0 && 
         strcmp(dst, "SRC") == 0);
  
  return 0;
}
