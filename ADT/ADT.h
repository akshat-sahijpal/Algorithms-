//
// Created by Ghost on 02-09-2021.
//
#ifndef STRUCTURES_ADT_H
#define STRUCTURES_ADT_H
#include <iostream>
class ADT {
    int size;
    int length;
    int *Array;
public:
    ADT(int size,
        int length,
        int *Array);
    void display();
    int* add(int element);
    void insertAt(int index, int element);
    void deleteAt(int index);
    int linearSearch(int element);
    int get(int index);
    int* getArray();
    bool inRange(int element);
    int max();
    int min();
    int* arrrev();
    int* lShift();
    int* lRotate();
    int* increaseArraySize(int newSize);
    auto multiDimensionalArray(int size);
};

#endif //STRUCTURES_ADT_H