#include <stdio.h>

int a(void) {
  int i=0,g=0;
  while(i++<100000)
  {
     g+=i;
  }
  return g;
}
int b(void) {
  int i=0,g=0;
  while(i++<400000)
  {
    g+=i;
  }
  return g;
}

int main(int argc, char** argv)
{
   int iterations= 50000;

   while(iterations--)
   {
      a();
      b();
   }
}
