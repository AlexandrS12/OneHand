#include <iostream>
#include "OneHand.h"
#include <windows.h>
using namespace std;


int main() {
    srand(time(NULL));
    int spin;
    int balance = 777;
    int bet;

    cout << "Welcome to the casino!" << endl;
    cout << "Start balance: $" << balance << endl;

    OneHand casino(3);

    while (balance > 0) {
        cout << "\n------------------------------------------" << endl;
        cout << "Put your bet (1$-" << balance << "$): $";
        cin >> bet;

        if (bet < 1 || bet > balance) {
            cout << "Invalid $. Please enter > 1$!." << endl;
            continue;
        }

        balance -= bet;
        casino.Clear();
        casino.spin(3);

        system("cls");
        casino.Show();
        Sleep(500);

        if (casino.check()) {
            int win = bet * 100;
            balance += win;
            cout << "\nCongratulations! You've won $" << win << "!" << endl;
        }
        else {
            cout << "\nSorry, you lose..." << endl;
        }

        cout << "Balance: " << balance <<"$"<< endl;

        if (balance <= 0) {
            cout << "\nYou lost all money!" << endl;
            return 0;
        }

        char playAgain;
        cout << "\nDo you want to play again? yes/no: ";
        cin >> playAgain;

        if (playAgain != 'yes' && playAgain != 'Yes') {
            cout << "\nThanks for playing!" << endl;
            break;
        }
    }

    if (balance > 10) {
        cout << "\nCongratulations, you're a winner!" << endl;
    }
    else {
        cout << "\nSorry, you're out of luck." << endl;
    }

    return 0;
}