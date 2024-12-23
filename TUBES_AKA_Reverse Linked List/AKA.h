#ifndef AKA_H_INCLUDED
#define AKA_H_INCLUDED
#include <iostream>
using namespace std;

#define info(p) p->info
#define next(p) p->next

typedef int infotype;

struct elmList {
    infotype info;
    elmList* next;
};

void addElm(elmList*& head, infotype data);
void reverseIterative(elmList*& head);
elmList* reverseRecursive(elmList* current, elmList* prev);
void deleteList(elmList*& head);

#endif // AKA_H_INCLUDED
