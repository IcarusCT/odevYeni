#include<iostream>

using namespace std;

void evaluateGuess(string guess, string target) {
    string result = "";

    string targetUsed = "0000";
    string guessUsed = "0000";

    for (int i = 0; i < 4; i++) {
        if(target[i] == guess[i]) {
            result += "+";
            targetUsed[i] = '1';
            guessUsed[i] = '1';
        }
    }

    for(int i = 0; i < 4; i++) {
        if(guessUsed[i] == '0') {
            for (int j = 0; j < 4; j++) {
                if(targetUsed[j] == '0' && guess[i] == target[j]) {
                    result += "o";
                    targetUsed[j] = '1';
                    guessUsed[i] = '1';
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if(guessUsed[i] == '0') {
            result += "x";
        }
    }
    cout << result << endl;

}

int main(){
    srand(time(0));
    int targetNum = rand() % 9000 + 1000;
    string target = to_string(targetNum);
    cout << "target: " << target << endl;

    string guess;

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
//test