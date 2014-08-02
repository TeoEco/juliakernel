/*Лист*/
#include <stdlib.h>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

#include <fstream>
//Для перевода int в string
#include <sstream>
/*
Функция вывода перменных- массивов ,многомерных массивов,типов int и т д либо в строку,либо в файл,либо 

#define SHOW(a) std::cout << #a << ": " << (a) << std::endl
int i = 2;
SHOW (i);
*/
using namespace std;

///Конвертирование из int в string
namespace convert
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}


//стуктура, описывающая узел связанного списка
struct Node
{
   int data;
   Node *next;
};

//класс, описывающих объект "связанный список"
class List
{
private:
   Node *head; //"голова" связанного списка
   
public:
   List() //конструктор класса без параметров
   {
      head = NULL; //первого элемента пока нет
   }
   
   //метод, добавляющий новый узел в список
   void addNode(int d)
   {
      Node *nd = new Node; //динамически создаем новый узел
      
      nd->data = d;        //задаем узлу данные
      nd->next = NULL;     //новый узел в конце, поэтому NULL
      
      if(head == NULL)     //если создаем первый узел
         head = nd;
      else                 //если узел уже не первый
      {
         Node *current = head;
         
         //ищем в цикле предшествующий последнему узел
         while(current->next != NULL)
            current = current->next;
            
         //предшествующий указывает на последний
         current->next = nd;
      }
   }
   
   //метод, выводящий связанный список на экран
   void printList()
   {
      Node *current = head;
      
      while(current != NULL)
      {
         cout << current->data << endl;
         current = current->next;
      }
   }
};

int main()
{
   List myList;
   myList.addNode(5);
   myList.addNode(11);
   myList.addNode(27);
   myList.addNode(35);
   myList.addNode(50);
   
   myList.printList();
/*
std::vector<int> foo; 
foo.push_back(1);
foo.push_back(2);
foo.push_back(3); 
int array[25];
array[1]=9;
bool name=false;

std::cout << "My array: " << name << std::endl; 
*/
   return 0;
}

