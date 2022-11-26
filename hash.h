#ifndef YOUTUBE_HASH_H
#define YOUTUBE_HASH_H
#include <iostream>
#include <string>
using namespace std;

class Hash {
private:
    const static int tableSize = 160;
    struct item{

        string name;
        string ID;
        item*nextPtr;

    };
    item* HashTable[tableSize];
public:


    Hash();
    static int hashFunc(string key);
    void AddItem( string name, string drink);
    void printTable();
    void testPrint();
};
#endif //YOUTUBE_HASH_H
