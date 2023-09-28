#pragma once
class OneHand
{
    int* Wait;
    int MaxLength;
    int length;
public:
    OneHand(int m);
    ~OneHand();
    bool IsEmpty();
    bool IsFull();
    bool check();
    int Extract();
    int GetCount();
    int GetItemAt(int index);
    void Add(int c);
    void Clear();
    void Show();
    void spin(int spins);

    static int count;
};