#include <iostream>
#include <string>         // std::string
#include <algorithm>
#include <fstream>
 
#include "top_k.h"

 
using namespace std;
 
int main()
{
	Top_k top_15(15);

    fstream file;
    string data, filename;
    filename = "words.txt";
    file.open(filename.c_str());
 
    while (file >> data)
    {
        transform(data.begin(), data.end(), data.begin(), ::tolower);
		top_15.insert(data);
    }

    cout << "Please select an option to continue: " << endl;
    cout << "1. Insert string into tree." << endl;
    cout << "2. Print hash table." << endl;
    cout << "3. Print heap." << endl;
    cout << "4. End the program." << endl;
    int val;
    cin >> val;

    while(val !=4){
        if(val == 1){
            string word;
            cout << "Please insert a new word into the tree." << endl;
            cin >> word;
            //insert word to topk here
        }
        else if(val == 2){
			top_15.print_hash();
        }
        else if(val == 3){
            top_15.print_heap();
        }
 
        cout << "Please select an option to continue: " << endl;
        cout << "1. Insert string into tree." << endl;
        cout << "2. Print hash table." << endl;
        cout << "3. Print heap." << endl;
        cout << "4. End the program." << endl;
        cin >> val;
    }
 
 
    return 0;
}
