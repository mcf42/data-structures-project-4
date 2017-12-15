//Data Structures
//Project 4
//Michael Fiander
//mcf42@zips.uakron.edu

#include <iostream>
#include <iomanip>
#include <ctime>
#include "316p4.h"

void print();
void linearTest();
void quadraticTest();
void doubleTest();

int main()
{
    srand(time(NULL));
    print();
    linearTest();
    quadraticTest();
    doubleTest();
}

void print()
{
    std::cout << "Collision numbers of probing methods:" << std::endl;
    std::cout << std::setw(10) << std::left << "Size";
    std::cout << std::setw(6) << "1000" << std::setw(6) <<  "2000" << std::setw(6) << "3000" << std::setw(6) << "4000" << std::setw(6) << "5000"
    << std::setw(6) << "6000" << std::setw(6) << "7000" << std::setw(6) << "8000" << std::setw(6) << "9000" << std::setw(6) <<  "10000";
    std::cout << std::endl;
}

void linearTest()
{
    //linear probing test
    int linearCollisions[10] = {0};
    int linearIteration = 0;
    for(int i = 1000; i < 10001; i = i + 1000)
    {
        hashTable * newtable = new hashTable;
        newtable->mode = 1;
        for(int j = 0; j < i; j++)
        {
            newtable->tableInsert(abs(rand()));
        }
        linearCollisions[linearIteration] = newtable->collisions;
        linearIteration++;
    }

    std::cout << std::setw(10) << std::left << "Linear";
    for(int i = 0; i < 10; i++)
    {
        std::cout << std::setw(6) << linearCollisions[i];
    }
    std::cout << std::endl;
}

void quadraticTest()
{
    //quadratic probing test
    int quadraticCollisions[10] = {0};
    int quadraticIteration = 0;
    for(int i = 1000; i < 10001; i = i + 1000)
    {
        hashTable * newtable = new hashTable;
        newtable->mode = 2;
        for(int j = 0; j < i; j++)
        {
            newtable->tableInsert(abs(rand()));
        }
        quadraticCollisions[quadraticIteration] = newtable->collisions;
        quadraticIteration++;
    }

    std::cout << std::setw(10) << std::left << "Quadratic";
    for(int i = 0; i < 10; i++)
    {
        std::cout << std::setw(6) << quadraticCollisions[i];
    }
    std::cout << std::endl;
}

void doubleTest()
{
    //double hash probing test
    int doubleCollisions[10] = {0};
    int doubleIteration = 0;
    for(int i = 1000; i < 10001; i = i + 1000)
    {
        hashTable * newtable = new hashTable;
        newtable->mode = 3;
        for(int j = 0; j < i; j++)
        {
            newtable->tableInsert(abs(rand()));
        }
        doubleCollisions[doubleIteration] = newtable->collisions;
        doubleIteration++;
    }

    std::cout << std::setw(10) << std::left << "Double";
    for(int i = 0; i < 10; i++)
    {
        std::cout << std::setw(6) << doubleCollisions[i];
    }
    std::cout << std::endl;
}

void hashTable::tableInsert(int num)
{
    int address = 0;
    if(table[hashFunction(num)] == -1)
    {
        address = hashFunction(num);
    }
    else if(table[hashFunction(num)] != -1)
    {
        address = nextFree(hashFunction(num));
    }
    table[address] = num;
    return;
}

int hashTable::hashFunction(int num)
{
    return num % TABLESIZE;
}

int hashTable::hashFunction2(int num)
{
    return num * num % TABLESIZE;
}

int hashTable::nextFree(int num)
{
    if(mode == 1)
    {
        while(table[num] == -1);
        {
            num = (num + 1) % TABLESIZE;
            collisions++;
        }
        return num;
    }
    else if(mode == 2)
    {
        int counter = 0;
        while(table[num] == -1);
        {
            num = (num + counter * counter) % TABLESIZE;
            counter++;
            collisions++;
        }
        return num;
    }
    else if(mode == 3)
    {
        int counter = 1;
        while(table[num] == -1);
        {
            num = (hashFunction(num) + counter * hashFunction2(num)) % TABLESIZE;
            collisions++;
        }
        return num;
    }
}
