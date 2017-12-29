//
// Created by adementev on 26.12.2017.
//

#include "LinkedList.h"

void LinkedList::additem(int d) {
    Link* link = new Link;
    link -> data = d;
    link -> next = first;
    first = link;
}

