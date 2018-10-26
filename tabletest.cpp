#include "hashtable.h"
#include <iostream>

using namespace std;

int main() 
{
    HashTable h_table;
    cout << "----------- Table made -----------\n" << endl;
    h_table.insert("test string", 5);
    h_table.insert("OwO", 19);
    h_table.insert("This is", 19);
    h_table.insert("How we do it", 19);

    pair<string, int> a = h_table.get("test string");
    pair<string, int> b = h_table.get("OwO");
    pair<string, int> c = h_table.get("This is");
    pair<string, int> d = h_table.get("How we do it");

    cout << "\nGet is :" << "[" << a.first << "," << a.second << "]" << endl;
    cout << "Get is :" << "[" << b.first << "," << b.second << "]" << endl;
    cout << "Get is :" << "[" << c.first << "," << c.second << "]" << endl;
    cout << "Get is :" << "[" << d.first << "," << d.second << "]" << endl;



    return 0;
}