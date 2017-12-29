//
// Created by adementev on 26.12.2017.
//

#ifndef ARRAY_LINKEDLIST_H
#define ARRAY_LINKEDLIST_H

#include <iostream>
using namespace std;
class Link{
    public:
    int data;
    Link* next;
};

class LinkedList {
    private:
        Link * first;
    public:
    LinkedList(){
        first = NULL;
    }
    void additem(int);
    int get();

};


#endif //ARRAY_LINKEDLIST_H
