#include "hashtable.h"

#define PRIME 8081

using namespace std;

HashTable::HashTable()
{
    this->CAPACITY = 100391; //Large Prime
    this->hash_table = new vector<pair<string, int>>[CAPACITY];
    for (int i = 0; i < CAPACITY; i++)
    {
        vector<pair<string, int>> vec;
        hash_table[i] = vec;
    } 
}

/* Sums up ASCII value of string
 * Multiplies it by some Prime
 * XOR's with table capacity
 */
unsigned int HashTable::hash_string(string input_string)
{
    unsigned int sum = 0;
    for (int i = 0 ; i < input_string.length(); i++)
    {
        sum += (int) input_string[i];
    }

    return ((sum * PRIME) ^ this->CAPACITY) % this->CAPACITY); 

}
