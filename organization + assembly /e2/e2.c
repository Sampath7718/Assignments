#include <stdio.h>

int main (int argc, const char * argv[]) {

    int i;    
    int n =4;
    
    int foo[]={1,4,3,7,6};
    

    for(i=1; i<=n; i++){
    
      foo[i]+=foo[i-1];
      
      printf("%d ", foo[i]);

    
  }  
    
    
    printf("n=%d\n", n);
    
    printf("foo=%p, &n=%p &i=%p\n", foo, &n, &i);
    
    
    
}

