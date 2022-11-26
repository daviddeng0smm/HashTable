//============================================================================
// Name        : DENGAPA6.cpp
// Author      : Deng
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include <string>
#include "hash.h"
using namespace std;
int main() {
    ifstream inFile;
    string input,id,name;
    Hash y;
    ///"C:\Users\David\Downloads\a6data F22.txt"
    inFile.open ("C:/Users/David/Downloads/a6data F22.txt",ios::in); // windows
// inFile.open ("/Users/admin/sample/physics/tdata.txt",ios::in); // mac /linux

    if (inFile.is_open()) // or (inFile.is_open() == true)
    {
        getline (inFile, input);
        while (!inFile.eof()) // or (inFile.eof() == false) F-not eof,T-eof
            {
                id = input.substr(0,9);
                name = input.substr(9,10);
                y.AddItem(name,id);
                getline(inFile, input);


            }
        cout << endl<< "i got eof" << endl;
        inFile.close();
    }
    else
    {
        cout << "error file did not open" << endl;
        return 4; // !0 means abnormal - abnormal termination
    }
    y.printTable();

    return 0; // 0 usually means "normal" - normal termination
}
