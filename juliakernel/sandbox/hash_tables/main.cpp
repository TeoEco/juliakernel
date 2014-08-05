/*
Simple hash-table ; memory manager 
This overrdrive operators and 
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
public:
	//Creaate hash-map
	void HashTable(void);
	//Get value for this key
	visual_patterns * get(std::string key);
	//Set value for this key
	void set(std::string key,visual_patterns * pointer);
};
void HashTable::HashTable()
{
visual_patterns *pointer=new visual_patterns[size];
	for(int i=0;i<size;i++)
	{
	pointer->z1=0;
	pointer->z2=0;
	}
}

visual_patterns* HashTable::get(std::string key)
{
}

void HashTable::set(std::string key,visual_patterns * pointer)
{
std::tr1::hash<std::string> hash_fn;
size_t str_hash = hash_fn(str);
int key=(str_hash%size)-1;//Вычисление ключа массива
}


using namespace std;
int main()
{
  struct sysinfo info;
  sysinfo(&info);
/*
Простейшая хэш-таблица
1)Создаем массив с указаелем pointer от 1 до 100000 в heap
2)Заполняем нулями массив
3)Создаем hash - функцию для строки которая возварщает остаток до 1000000
4)Записываем по этому адресу значение 
*/
unsigned int size=(info.freeram-(400*1024*1024))/sizeof(visual_patterns);
std::cout<<"Будет создано место для "<<size << " шаблонов" << endl;
HashTable * patterns=new HashTable(size);
patterns->set(1,25);
visual_patterns * patterns->get(1);

string str="blablab";

pointer[key].z1=5;
cout<<pointer[key].z1<<endl;
sleep(1000);
return 0;
}
