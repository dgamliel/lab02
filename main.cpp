#include <iostream>
#include <fstream>
 
#include "top_k.h"
 
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
