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
        void insert(string key, int value);
        void get(string str);
        void delete_entry(string key);

    private:
        vector<vector<pair <int location, int amount_occurances>>> hash_table;

}

#endif