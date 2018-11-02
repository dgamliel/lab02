#include "hashtable.h"
#include <iostream>

using namespace std;

int main() 
{
    HashTable h_table;
    cout << "----------- Table made -----------\n" << endl;
    
    h_table.insert("test string", 5);
    h_table.insert("OwO", 19);
    h_table.insert("This is", 24);
    h_table.insert("How we do it", 32);

    pair<string, int> a = h_table.get("test string");
    pair<string, int> b = h_table.get("OwO");
    pair<string, int> c = h_table.get("This is");
    pair<string, int> d = h_table.get("How we do it");

	h_table.print();

    return 0;
}
