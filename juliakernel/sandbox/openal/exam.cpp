#include <stdlib.h>
#include <stdio.h>
#include <iostream>
//ex-ghashtable-1.c
#include <glib.h>

int main(int argc, char** argv) {
 GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
 g_hash_table_insert(hash, (gpointer)"Virginia", (gpointer)"Richmond");
 g_hash_table_insert(hash, (gpointer)"Texas", (gpointer)"Austin");
 g_hash_table_insert(hash, (gpointer)"Ohio", (gpointer)"Columbus");
 printf("There are %d keys in the hash\n", g_hash_table_size(hash));
 printf("The capital of Texas is %s\n", g_hash_table_lookup(hash, (gpointer)"Texas"));
 gboolean found = g_hash_table_remove(hash, (gpointer)"Virginia");
 printf("The value 'Virginia' was %sfound and removed\n", found ? "" : "not ");
 g_hash_table_destroy(hash);
 return 0;
}


