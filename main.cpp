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
            result += "\033[32m+\033[0m";
        else if (count[guess[i] - '0'] >= 0)
            result += "\033[34mo\033[0m";
        else
            result += "\033[31mx\033[0m";
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
        cout<< "\033[35mplayer " << player <<" make your guess: \033[0m" << endl;
        cin >> guess;

        if(guess.size() != 4 || !isdigit(guess[0])) {
            cout << "wrong input" << endl;
        }

        evaluateGuess(guess, target);
        player = (player == 1) ? 2 : 1;

        if(guess == target) {
            cout << "\033[33mplayer "<< player << " wins.\033[0m" << endl;
            break;
        }
    }
    return 0;
}

