#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define ITERATIONS 10000000

// This is the result of me mocking other students in a class who insisted on
// printing out the bits of a byte using a for loop. The requirement was to
// print the byte as '0000 0000' with a space. I insisted that a for loop is
// wasteful because you need an incrementer plus a conditional statement to
// insert the space. For 10 Milion iterations, my function, print_fast() saves
// 6 seconds in a virtual machine on (ew) Ubuntu 14.XX-LTS. lol. #til

unsigned char
getBit(const unsigned char c, const int n) {
  assert(n < 8 && n >= 0); // n must be on [0,7]
  return (c & (1 << n))>>n;
}

void
print_stupid_way(const char c)
{
  int i=7;
  for(;i>=0;){
    for(int q=0;q<4;q++,--i){
      printf("%d",getBit(c,i));
    }
    printf(" ");
  }
  printf("\n");

}

void
print_fast(const char c)
{
  printf("%d%d%d%d %d%d%d%d\n",getBit(c,7),getBit(c,6),getBit(c,5),getBit(c,4),getBit(c,3),getBit(c,2),getBit(c,1),getBit(c,0));
}


int
main ()
{
  time_t start, stop;
  double stupid, fast;
  time(&start);
  for(int i=0; i < ITERATIONS; ++i)
    print_fast('a');
  time(&stop);
  fast = difftime(stop,start);
  printf("print_fast took %f\n",fast);
  puts("");

  time(&start);
  for(int i=0; i < ITERATIONS; ++i)
    print_stupid_way('a');
  time(&stop);
  stupid = difftime(stop,start);
  printf("print_stupid_way took %f\n",stupid);
  puts("");

  printf("difference is %f\n",stupid-fast);

  return 0;
}
