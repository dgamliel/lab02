#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#ifndef DGAM_HASH_TABLE
#define DGAM_HASH_TABLE

class HashTable{

    public:
        HashTable();
        ~HashTable();
        void insert(string key, int value);
        pair<string, int> get(string str);
        void delete_entry(string key);

    private:
        unsigned int hash_string(string input_string);
        vector<pair<string, int>> *hash_table;
        unsigned int CAPACITY; 

};

#endif