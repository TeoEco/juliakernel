/*
Простейшая хэш-таблица и менеджер памяти
*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <tr1/functional>
#include <unistd.h>
#include <sys/sysinfo.h>

struct visual_patterns
{
public:
	char pattern[50];
	unsigned int z1; 
	unsigned int z2; 
};

struct HashTable
{
	
};
using namespace std;
int main()
{
  struct sysinfo info;
  sysinfo(&info);
  printf("Секунд с момента начальной загрузки: %lu (%lu минут)\n", info.uptime, info.uptime/60);
  printf("Общее количество оперативной памяти: %lu (%lu MB)\n", info.totalram, info.totalram/(1024*1024));
  printf("Объём доступной памяти: %lu (%lu MB)\n", info.freeram, info.freeram/(1024*1024));
  //printf("Объем раздела подкачки: %lu (%lu MB)\n", info.totalswap, info.totalswap/(1024*1024));
  //printf("Объём доступной памяти радела подкачки: %lu (%lu MB)\n", info.freeswap, info.freeswap/(1024*1024));
/*
Простейшая хэш-таблица
1)Создаем массив с указаелем pointer от 1 до 100000 в heap
2)Заполняем нулями массив
3)Создаем hash - функцию для строки которая возварщает остаток до 1000000
4)Записываем по этому адресу значение 
*/
unsigned int size=(info.freeram-(400*1024*1024))/sizeof(visual_patterns);
std::cout<<"Будет создано место для "<<size << " шаблонов" << endl;

visual_patterns *pointer=new visual_patterns[size];
for(int i=0;i<size;i++)
{
pointer->z1=0;
pointer->z2=0;
}
string str="blablab";
std::tr1::hash<std::string> hash_fn;
size_t str_hash = hash_fn(str);
int key=(str_hash%size)-1;//Вычисление ключа массива
pointer[key].z1=5;
cout<<pointer[key].z1<<endl;
sleep(1000);
return 0;
}
