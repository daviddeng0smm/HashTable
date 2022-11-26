//
// Created by David on 10/11/2022.
//

#include "hash.h"
#include <iostream>
#include <string>
using namespace std;

Hash::Hash() {
    for(int i = 0 ; i<tableSize; i++)
    {
        item *s1 = new item();
        s1->name = "empty";
        s1->ID = "empty";
        s1->nextPtr = nullptr;
        HashTable[i] = s1;

    }
}
int Hash::hashFunc(string key)
{

    int i = 0;
    int hash = 0;
    while(key[i]!='\0')
    {
        hash += (int)key[i];
        i++;
    }
    int index = hash%tableSize;
    return index;
}
void Hash::testPrint() {
    int i = 0;
    cout << HashTable[i]->name;
}
void Hash::AddItem( string name, string ID) {
    int index = hashFunc(name);
    if(HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->ID = ID;
        HashTable[index]->nextPtr = nullptr;
        return;
    }
    if(HashTable[index]->name != "empty")
    {
        item *temp = HashTable[index];
        while(temp->nextPtr != nullptr)
        {
            temp = temp->nextPtr;
        }
        item *holder = new item();
        holder->name = name;
        holder->ID=ID;
        holder->nextPtr = nullptr;
        temp->nextPtr = holder;
        return;
    }
}
void Hash::printTable()
{
    for(int i = 0; i<tableSize+1; i++)
    {
        if(HashTable[i]->name == "empty") //empty index
        {
            cout << "HashTable at index: " << i << "is empty" << endl;
            cout << endl;
        }
        else if(HashTable[i]->nextPtr == nullptr && HashTable[i]->name != "empty")// if index contains 1 element
        {
            cout << "HashTable at index: " << i << " only contains 1 employee's data" << endl;
            cout << "Employee Name: " << HashTable[i]->name << endl;
            cout << "Employee ID: " << HashTable[i]->ID << endl;

        }
        else if(HashTable[i]->nextPtr != nullptr)// index has a collision
        {
            int j = 0;
            cout << "HashTable at index: " << i << " has a collision" << endl;
            item *temp = HashTable[i];
            while(temp->nextPtr != nullptr)
            {
                cout << " At HashTable index: " << i << "." << j << " Employee name is:" <<temp->name << endl;
                cout << " At HashTable index: " << i << "." << j << " Employee ID is:" <<temp->ID << endl;
                j++;
                temp=temp->nextPtr;
            }
        }
    }
}
