#include <iostream>
using namespace std;

int maxPizzaPieces(int n) {
    return (n * (n + 1)) / 2 + 1;
}

int main() {
    int cuts;
    cout << "Enter the number of cuts: ";
    cin >> cuts;

    if (cuts < 0) {
        cout << "The number of cuts cannot be negative!" << endl;
    } else {
        int pieces = maxPizzaPieces(cuts);
        cout << "With " << cuts << " cuts, you can get a maximum of " << pieces << " pizza pieces." << endl;
    }

    return 0;
}
