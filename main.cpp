#include<iostream>
#include<string>

using namespace std;

void evaluateGuess(string guess, string target) {
    string result;
    int count[10] = {0}; // her rakamın kaç kez geçtiğini tutacak dizi

    // hedefteki rakamların sıklığını say
    for (char c : target)
        count[c - '0']++;

    // tahmindeki her rakam için kontrol et
    for (int i = 0; i < 4; i++) {
        count[guess[i] - '0']--; // bu rakamı bir kez daha saymamak için
        if (guess[i] == target[i])
            result += '+';
        else if (count[guess[i] - '0'] >= 0)
            result += 'o';
        else
            result += 'x';
    }
    cout << result << endl;
}

int main(){
    // random sayı oluşturma
    srand(time(0));
    int targetNum = rand() % 9000 + 1000;
    string target = to_string(targetNum);
    cout << "target: " << target << endl;

    string guess;

    // player sırası ve yanlış input girilmemesi için kontrol
    int player = 1;
    while(true) {
        cout<< "player " << player <<" make your guess: " << endl;
        cin >> guess;

        if(guess.size() != 4 || !isdigit(guess[0])) {
            cout << "wrong input" << endl;
        }

        evaluateGuess(guess, target);
        player = (player == 1) ? 2 : 1;

        if(guess == target) {
            cout << "player "<< player << " wins." << endl;
            break;
        }
    }
    return 0;
}
