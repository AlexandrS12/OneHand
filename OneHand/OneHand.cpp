#include "OneHand.h"
#include <iostream>
using namespace std;

void OneHand::Show() {
    cout << "\n";
    for (int i = 0; i < length; i++) {
        cout << " _____ ";
    }
    cout << "\n";

    for (int i = 0; i < length; i++) {
        cout << "|     |";
    }
    cout << "\n";

    for (int i = 0; i < length; i++) {
        cout << "|  " << Wait[i] << "  |";
    }
    cout << "\n";

    for (int i = 0; i < length; i++) {
        cout << "|_____|";
    }
    cout << "\n";
}

int OneHand::GetItemAt(int index) {
    if (index >= 0 && index < length) {
        return Wait[index];
    }
    return -1;
}

OneHand::~OneHand() {
    delete[] Wait;
}

OneHand::OneHand(int m) {
    MaxLength = m;
    Wait = new int[MaxLength];
    length = 0;
}

void OneHand::Clear() {
    length = 0;
}

bool OneHand::IsEmpty() {
    return length == 0;
}

bool OneHand::IsFull() {
    return length == MaxLength;
}

int OneHand::GetCount()
{
    return 0;
}

void OneHand::Add(int c) {
    if (!IsFull())
        Wait[length++] = c;
}

int OneHand::Extract() {
    if (!IsEmpty()) {
        int temp = Wait[0];

        for (int i = 1; i < length; i++)
            Wait[i - 1] = Wait[i];
        Wait[length - 1] = temp;
        return temp;
    }
    else {
        return -1;
    }
}

void OneHand::spin(int spins) {
    int* newSymbols = new int[spins];

    for (int i = 0; i < spins; i++) {
        int symbol = rand() % 10;
        newSymbols[i] = symbol;
    }

    for (int i = 0; i < spins; i++) {
        Extract();
        Add(newSymbols[i]);
    }

    delete[] newSymbols;
}

bool OneHand::check() {
    int firstSymbol = GetItemAt(0);
    for (int i = 1; i < length; i++) {
        if (GetItemAt(i) != firstSymbol) return false;
    }
    return true;
}