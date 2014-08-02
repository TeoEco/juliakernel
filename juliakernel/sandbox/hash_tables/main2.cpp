#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
/**
Обучение работе с укзателями и gdb .Передача массивов и объектов по указателям
*/

////////////////////////////////Hash_Table class//////////////////////////////////////////
template < typename TKey, typename TValue>
class Hash_Table {
private:
 unsigned static const defaultCapacity=17;
 std::vector< Single_Linked_List< std::pair< TKey,TValue> > > table;
 unsigned capacity;
 unsigned count;

public:
 Hash_Table();
 Hash_Table(unsigned divisor);
 ~Hash_Table();
 unsigned HashIntKey(int key) const;
 unsigned DataToKey(const TValue& Data) const;
 const TValue& Search(const TKey& key) const;
 void Insert(const TKey& key_val,TValue& el_value);
 void Output() const;// output the hash table
 void Delete(TValue element);
 const TValue& operator[](int key);
};

template < typename TKey, typename TValue>
unsigned Hash_Table< TKey,TValue>::HashIntKey(int key) const{
 return key%capacity;
}


template < typename TKey, typename TValue>
Hash_Table< TKey,TValue>::Hash_Table(){
 //////////////////////////////////////////////////////////////////////////
 count=0;
 capacity=defaultCapacity;
 //////////////////////////////////////////////////////////////////////////
 table.resize(defaultCapacity, Single_Linked_List >());
}

template < typename TKey, typename TValue>
Hash_Table< TKey,TValue>::Hash_Table(unsigned divisor){
 count=0;
 capacity=divisor;
 //////////////////////////////////////////////////////////////////////////
 table.resize(capacity, Single_Linked_List< pair< TKey,TValue> >());
}

template < typename TKey, typename TValue>
Hash_Table< TKey,TValue>::~Hash_Table(){
 table.clear();
}

template < typename TKey, typename TValue>
const TValue& Hash_Table< TKey,TValue>::Search(const TKey& key) const{
 unsigned pos=HashIntKey(key);
 //////////////////////////////////////////////////////////////////////////
 Single_Linked_List< pair< TKey,TValue> >& lst = table.at(pos);
 try {
  if(lst.GetSize()< 1) //if list hasnt elements
   throw inv_ex;
  for(Single_Linked_List< pair< TKey,TValue> >::iterator it = lst.begin(); it != lst.end(); ++it) {
   if(it->first == key){
    return (it->second); 
   } 
  }
 }
 catch(exception &e){
  cout< < e.what()< < endl;
 }
 Insert(key,TValue()); //insert element with default data
 return operator[](key);
}

template < typename TKey, typename TValue>
void Hash_Table< TKey,TValue>::Insert(const TKey& key_val,TValue& el_value){
 unsigned pos=HashIntKey((int)key_val); //get pos by hashing
 //////////////////////////////////////////////////////////////////////////
 pair< TKey,TValue> toInsert(key_val, el_value);
 //////////////////////////////////////////////////////////////////////////
 Single_Linked_List< pair >& lst = table.at(pos);
   //If key already store, replace data
  if(!lst.isEmpty()) {
  for(Single_Linked_List< pair >::iterator it = lst.begin(); it != lst.end(); ++it) {
   if(it->first == key_val){
    //it->second=el_value;
    it.SetValue(toInsert);
        return;
      } 
    }
  }
    //No items with that key, store a new one
  table[pos].Push_Front(toInsert);
 count++;
}

template < typename TKey, typename TValue>
void Hash_Table< TKey,TValue>::Output() const {
 int NumOfCollision = 0;
 //////////////////////////////////////////////////////////////////////////
 cout< < "Hash table capacity "< 1) {
   NumOfCollision += table[i].GetSize() - 1;
  }
  //////////////////////////////////////////////////////////////////////////
    for(Single_Linked_List< pair >::const_iterator it = table[i].begin(); it != table[i].end();it++) {
   cout< < "HashTable["< < i< < "]: "< < (it->second)< < endl;
    }
  }
 cout< < "N.Hash collisions: "< < NumOfCollision< < endl;
}


template < typename TKey, typename TValue>
const TValue& Hash_Table< TKey,TValue>::operator[](int key){
 unsigned pos=HashIntKey(key);
 //////////////////////////////////////////////////////////////////////////
 Single_Linked_List< pair< TKey,TValue> >& lst = table.at(pos);
 try {
  if(lst.GetSize()< 1)
   throw inv_ex;
  for(Single_Linked_List< pair< TKey,TValue> >::iterator it = lst.begin(); it != lst.end(); ++it) {
   if(it->first == key){
    return (it->second);
   } 
  }
 }
 catch(exception &e){
  cout< < e.what()< < endl;
 }
 Insert(key,TValue());
 return operator[](key);
}

int main()
{
  Hash_Table< int,string> ht(9);
  ht.Insert(223,string("Ololoshenka"));
  ht.Insert(5345,string("This is matrix, Neo"));
  ht.Insert(1,string("Use yourrr power, Luke"));


  ht.Output();
 cout<<ht[1]<<endl;
return 0;
}
