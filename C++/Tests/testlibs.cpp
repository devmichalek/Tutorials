// author: Adrian Michałek
// email: devmichalek@gmail.com

0.0 // Assume you have test.c with function func() and main.c which uses function func() from the static library libtest.a. Give the proper order of compilation, creation of executable binary and static library on linux. Write commands for the required needs.

0.1 // Do the same thing as in the previous task but now for the dynamic library.

0.2 // Assume you have the following files:
// part.c:
int add2(int a, int b) {
  return a + b;
}

int add3(int a, int b, int c) {
  return a + b + c;
}

//  test.c
int func(int x) {
  int add2(int, int);
  return x + add2(1, 2);
}

// main.c
#include <stdio.h>

int main()
{
  int func(int);
  int add3(int, int, int);
  int ret = func(3) + add3(1, 2, 3);
  printf("ret=%d\n", ret);
  return ret;
}
//  How would you create an exectutable main which uses dynamic library libtest.so which includes static library libpart.a? Note that shared library does not know that function add2() will be used by the library users.
