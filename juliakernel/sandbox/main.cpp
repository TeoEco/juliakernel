#include <stdio.h>
#include <iostream>

/**
Обучение работе с укзателями и gdb .Передача массивов и объектов по указателям
*/

void for_with_pointer(unsigned int *pointer)
{
	for(int i=0;i<20;++i)
	{
	pointer[i]=1024;
	std::cout<<pointer[i];
	}
}

int main()
{
unsigned int array[20];
//unsigned int *p_array=&array;

for_with_pointer(array);
return 0;
}
