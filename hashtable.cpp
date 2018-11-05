#include "hashtable.h"
#include <iostream>
#include <sstream>

#define PRIME 8081

using namespace std;

HashTable::HashTable()
{
    this->CAPACITY = 100391; //Large Prime
    this->hash_table = new vector<pair<string, int> >[CAPACITY];
    for (unsigned int i = 0; i < CAPACITY; i++)
    {
        vector<pair<string, int> > vec;
        hash_table[i] = vec;
    }

}

HashTable::~HashTable()
{
    delete [] this->hash_table;
}

//--------------- GET / INSERT / SET ----------------------
pair<string, int> HashTable::get(string str){


    unsigned int hashed_index = hash_string(str);
    vector<pair<string, int> > indexed_vector = this->hash_table[hashed_index]; 
    pair<string, int> not_found("", -1);


    //If hashed index is empty we were unable to find string in the hash table
    //Return pair p with special values (empty string, neg 1)
    if (indexed_vector.size() == 0){
        return not_found;
    }

    //if our vector only contains 1 element the element either is or is not what we are searching for
    else if (indexed_vector.size() == 1 ){
        //if our element is found, return it
        if (indexed_vector.at(0).first == str){
            return indexed_vector.at(0);
        }
        //o.w. return "not found" flag value
        else{
            return not_found;
        }
    }

    else {
        vector<pair<string, int> >::iterator it = indexed_vector.begin();
        while (it != indexed_vector.end()){
            if (it->first == str){
                return *it;
            }
            it++;
        }
        return not_found;
    }
}


void HashTable::insert(string key, int value){
    pair<string, int> p(key, value);
    unsigned int table_index = hash_string(p.first);
    vector<pair<string, int> > *indexed_vector = &this->hash_table[table_index];
    indexed_vector->push_back(p);
}

void HashTable::setIndexAtString(string str, int value){

	//If the value does not exist in the hashtable we just insert
	if (!this->exists_in_heap(str)){
		this->insert(str, value);
	}

	else {
		//Search for the vector that our pair is in
		unsigned int index = hash_string(str);
		vector<pair<string, int> > *vec = &this->hash_table[index];

		//Loop through the vector and find our string
		for (vector<pair<string,int> >::iterator it = vec->begin(); it != vec->end() ; it++){
				
				pair<string, int> p = *it;

				if (p.first == str){		
					//Set the new value to be our set value;
					pair<string, int> p(str, value);
					*it = p;
				}	
		}
	}
}

//----------------------------------------------------------------------------------

int HashTable::getIndexAtString(string s){
    pair<string,int> index = this->get(s);
    return index.second;
}

bool HashTable::exists_in_heap(string s){
    int index = this->getIndexAtString(s);
    if (index == -1){
        return false;
    }
    return true;
}

/* Sums up ASCII value of string
 * Multiplies it by some prime * strlen
 * XOR's with table capacity
 * Mods with capacity so it fits in table
 */
unsigned int HashTable::hash_string(string input_string){
    unsigned int sum = 0;
    for (unsigned int i = 0 ; i < input_string.length(); i++){
        sum += (int) input_string[i];
    }
    return (((sum * PRIME * input_string.length()) ^ this->CAPACITY) % this->CAPACITY); 
}

void HashTable::print(){

	ostringstream oss; 

	for (unsigned int i = 0; i < this->CAPACITY; i++){
		vector<pair<string, int> > vec = this->hash_table[i];
		if( !vec.empty() ){
			oss << "Vector at hash_table[" << i << "] is : ";
			for (vector<pair<string, int> >::iterator it = vec.begin(); it+1 != vec.end(); it++){
				oss << "(" << it->first << ", " << it->second << ")->";
			}
			oss << "(" << vec.back().first << ", " << vec.back().second << ")"  << endl; 
		}
	}

	cout << oss.str() << endl;

}
