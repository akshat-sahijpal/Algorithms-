//
// Created by Ghost on 06-09-2021.
//

#include "LinkedList.h"

LinkedList::LinkedList() {}


struct Node *LinkedList::init(int *initDataSet, int size) {
    this->firstNode = (struct Node *) malloc(sizeof(struct Node));
    this->lastNode = (struct Node *) malloc(sizeof(struct Node));
    this->trav = (struct Node *) malloc(sizeof(struct Node));
    this->firstNode->data = initDataSet[0];
    this->firstNode->nextLink = NULL;
    this->firstNode = this->lastNode;
    for (int i = 0; i < size; ++i) {
        insert(initDataSet[i]);
    }
    this->length = size;
    return this->firstNode;
}


void LinkedList::insert(int element) {
    auto temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = element;
    temp->nextLink = NULL;
    this->lastNode->nextLink = temp;
    this->lastNode = temp;
    this->length++;
}

int LinkedList::getLength() {
    return this->length;
}

void LinkedList::see() {
    auto temp = this->firstNode;
    for (int i = 0; i < this->length; i++) {
        print(temp->data)
        temp = temp->nextLink;
    }
}

int LinkedList::peek() {
    return this->firstNode->data;
}

void LinkedList::deleteAtFirst() {
    auto first = this->firstNode;
    this->firstNode = this->firstNode->nextLink;
    delete[] first;
}

void LinkedList::deleteAtIndex(int index) {
    auto cont = this->firstNode;
    if (index > this->length) return;
    for (int i = 0; i < this->length; i++) {
        if (i == index) {
            auto del = cont->nextLink;

        }
        cont = cont->nextLink;
    }
}

void LinkedList::showAll(struct Node *p) {
    if (p != NULL) {
        print(p->data)
        showAll(p->nextLink);
    }
}

int LinkedList::sum() {
    auto firstNode = this->firstNode;
    int counter = 0;
    while (firstNode != NULL) {
        counter += firstNode->data;
        firstNode = firstNode->nextLink;
    }
    return counter;
}

int LinkedList::max(struct Node *nod) {
    auto firstNode = nod;
    int Max = firstNode->data;
    print(Max)
    while (firstNode != NULL) {
        if (firstNode->data > Max) {
            Max = firstNode->data;
        }

        firstNode = firstNode->nextLink;
    }

    return Max;
}

// Linear Search
struct Node *LinkedList::findElement(struct Node *crNode, int element) {
    if (crNode == NULL) return NULL;
    else if (crNode->data == element) return crNode;
    return findElement(crNode->nextLink, element);
}

struct Node *LinkedList::findElementAtIndex(int index) {
    auto firstNode = this->firstNode;
    for (int i = 0; i < this->length; ++i) {
        if (i == index) {
            return firstNode;
        }
        this->firstNode = this->firstNode->nextLink;
    }
}

void LinkedList::insertAtStart(int element) {
    auto temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = element;
    temp->nextLink = this->firstNode;
    this->firstNode = temp;
}

void LinkedList::insertAtIndex(int index, int element) {
    auto temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = element;
    auto post = findElementAtIndex(index);
    temp->nextLink = post->nextLink;
    post->nextLink = temp;
}

struct Node *LinkedList::reverseData() {
    int *arr = new int[this->length];
    int i = 0;
    while (this->firstNode != NULL) {
        arr[i++] = this->firstNode->data;
        this->firstNode = this->firstNode->nextLink;
    }
    while (this->firstNode != NULL) {
        this->firstNode->data = arr[i--];
        this->firstNode = this->firstNode->nextLink;
    }
    return this->firstNode;
}