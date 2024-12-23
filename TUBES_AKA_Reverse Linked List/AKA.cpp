#include "AKA.h"
#include <iostream>
#include <chrono>
using namespace std;

void addElm(elmList*& head, int data) {
    elmList* newElm = new elmList{data, NULL};
    if (!head) {
        head = newElm;
    } else {
        elmList* temp = head;
        while (next(temp)) {
            temp = next(temp);
        }
        next(temp) = newElm;
    }
}

void reverseIterative(elmList*& head) {
    elmList* current = head;
    elmList* prev = NULL;
    elmList* after = NULL;

    while (current) {
        after = next(current);
        next(current) = prev;
        prev = current;
        current = after;
    }
    head = prev;
}

elmList* reverseRecursive(elmList* current, elmList* prev) {
    if (!current){
        return prev;
    } else {
        elmList* after = next(current);
        next(current) = prev;
        return reverseRecursive(after, current);
    }
}

void deleteList(elmList*& head) {
    while (head) {
        elmList* temp = head;
        head = next(head);
        delete temp;
    }
}
