#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

class hashTable
{
public:
    const int TABLESIZE = 10001;
    int table[10001] = {-1};
    int collisions = 0;
    int mode;

    void tableInsert(int);
    int hashFunction(int);
    int hashFunction2(int);
    int nextFree(int);

    hashTable(){};
    ~hashTable(){};
};

#endif // HEADER_H_INCLUDED
