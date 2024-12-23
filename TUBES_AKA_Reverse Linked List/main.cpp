#include "AKA.h"
#include <iostream>
#include <chrono>
using namespace std;

int main() {
    elmList* head = NULL;

    cout << "n: ";
    int ukuran;
    cin >> ukuran;

    while (ukuran != 0) {

        //menginput element
        for (int i = 0; i < ukuran; ++i) {
            addElm(head, i);
        }

        //iteratif
        const int ITERATIONS = 10000;
        auto startIterative = chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; ++i) {
            reverseIterative(head);
            reverseIterative(head);
        }
        auto endIterative = chrono::high_resolution_clock::now();
        auto durationIterative = chrono::duration_cast<chrono::milliseconds>(endIterative - startIterative).count();
        cout << "Iteratif: " << durationIterative << " milliseconds" << endl;

        reverseIterative(head);

        //rekursif
        auto startRecursive = chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; ++i) {
            head = reverseRecursive(head, nullptr);
            head = reverseRecursive(head, nullptr);
        }
        auto endRecursive = chrono::high_resolution_clock::now();
        auto durationRecursive = chrono::duration_cast<chrono::milliseconds>(endRecursive - startRecursive).count();
        cout << "Rekursif: " << durationRecursive << " milliseconds" << endl;

        //perbandingan waktu iteratif dan rekursif
        double comparison = durationRecursive / durationIterative;
        cout << "-> Algoritma Rekursif lebih lambat sekitar " << comparison << "x lipat dibandingkan Algoritma Iteratif." << endl;

        //menghapus linked list sebelumnya
        deleteList(head);

        cout << endl;
        cout << "n: ";
        cin >> ukuran;
    }
    return 0;
}
