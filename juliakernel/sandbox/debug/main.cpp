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

std::string debug_info_output(std::string output,const unsigned int type)
{
	switch (type) {
	case 2:
	  {
	  // File
	  std::ofstream myfile;
	  myfile.open ("debug.txt",std::ios::app);
	  myfile << output << std::endl;
	  myfile.close();
	  break;
	  }
	case 1:
	  // Std::cout<<
		std::cout<< output << std::endl;
	  break;
	case 3:
	  // String
	  return output;
	  break;
	default:
	  // Code
	  
	  break;
	}
return "";
}

//Bool
std::string debug_info(bool var,const unsigned int type)
{
std::string result="";
if(var)
{
result="true";
}
else
{
result="false";
}
std::string output="(boolean)="+result;
return debug_info_output(output,type);
}
//Int
std::string debug_info(int var,const unsigned int type)
{
std::string output="(int)="+convert::to_string(var);
return debug_info_output(output,type);
}
//String
std::string debug_info(std::string var,const unsigned int type)
{
std::string output="(string)="+var;
return debug_info_output(output,type);
}
//Two-demision int array
//String
std::string debug_info(std::string var,const unsigned int type)
{
std::string output="(string)="+var;
return debug_info_output(output,type);
}

/*
int main()
{
std::string y="5";
//Массивы,vectors,maps

string str = new string(msv);
debug_info(y,1);
}
*/

#include <vector>
#include "prettyprint.hpp"

int main() { 
std::vector<int> foo; 
foo.push_back(1);
foo.push_back(2);
foo.push_back(3); 
int array[25];
array[1]=9;
bool name=false;

std::cout << "My array: " << name << std::endl; 
}


