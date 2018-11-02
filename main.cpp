#include <iostream>
#include <fstream>
 
#include "minheap.h"
#include "hashtable.h"
 
using namespace std;
 
int main()
{
    fstream file;
    string word, filename;
    filename = "words.txt";
    file.open(filename.c_str());
 
    while (file >> word)
    {
        cout << word << endl;
    }
 
    return 0;
}
