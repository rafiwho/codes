#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
vector<string> alphabet = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                           "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

map<string, int> suits;
map<string, bool> vis;
int match_round = 0;

void fillValues() {
    string ch = "A";
    for (int i = 0; i < 26; ++i) {
        suits[ch] = rng() % 11;
        ch[0]++;
    }
}

void showOctagons() {
    system("cls");
    std::cout << "=============================";

    // Seed for random color generation
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (auto &pair : suits) {
        // Generate a random color code (1-7 for ANSI color codes)
        int colorCode = 1 + (std::rand() % 7);
        // Apply the color and print the alphabet
        std::cout << "\033[" << colorCode << "m  [" << pair.first << "]  \033[0m";
    }

    std::cout << "\n=============================\n";
}


void showValue(string ch, string &name) {
    cout << name << " has revealed [" << ch << "] with a value of " << suits[ch] << endl;
}

bool checkIfAlreadyChosen(string ch) {
    return vis[ch];
}

void setColor(int colorCode) {
    std::cout << "\033[" << colorCode << "m";
}

void resetColor() {
    std::cout << "\033[0m";
}

void menu() {
  system("cls");

    setColor(36); 

  std::cout << 
    "  W   W  EEEEE  L      CCCC   OOO   M   M  EEEEE\n"
    "  W   W  E      L     C      O   O  MM MM  E    \n"
    "  W W W  EEEE   L     C      O   O  M M M  EEEE \n"
    "  W W W  E      L     C      O   O  M   M  E    \n"
    "   W W   EEEEE  LLLLL  CCCC   OOO   M   M  EEEEE\n" << std::endl;


    resetColor();

    std::cout << "\n\t1)  Player Vs. AI"
              << "\n\t2)  Multiplayer"
              << "\n\t0)  EXIT"
              << "\n\nSelect a game mode: ";
}
void checkWinner(string &name, int score, string &otherName, int otherScore) {
    if (score > otherScore) {
        cout << "\nCONGRATULATIONS " << name << " you have won!" << endl;
    } else if (score < otherScore) {
        cout << "\nCONGRATULATIONS " << otherName << " you have won!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}

void playerVsAI() {
    fillValues();

    string playerName;
    cout << "\nWhat's your name? ";
    cin >> playerName;

    string aiName = "AI";
    int playerScore = 0, aiScore = 0;
    vis.clear();

    while (match_round < 26) {
        showOctagons();
        cout << "\n\n" << playerName << " it's your turn...";

        string ch;
        cout << "Please enter the letter of your choice: ";
        cin >> ch;
        while(find(alphabet.begin(),alphabet.end(),ch) == alphabet.end()){
          cout << "Enter a valid move: ";
          cin >> ch;
        }
        ch = toupper(ch[0]);

        bool yo = checkIfAlreadyChosen(ch);
        if (yo) {
            cout << "This character was already chosen.\n";
            cout << "Your score is decreased by " << suits[ch] << '\n';
            playerScore -= suits[ch];
            playerScore = max(0, playerScore);
        } else {
            vis[ch] = true;
            playerScore += suits[ch];
        }
        showValue(ch, playerName);
        cout << playerName << " your score is: " << playerScore << endl;
        match_round++;

        Sleep(1500); // Pause for 1 second

        showOctagons();
        cout << "\n\nIt's the AI's turn...";

        ch = alphabet[rng() % 26];
        yo = vis[ch];
        while (yo) {
            ch = alphabet[rng() % 26];
            yo = vis[ch];
        }
        vis[ch] = true;
        aiScore += suits[ch];
        showValue(ch, aiName);
        cout << "AI your score is: " << aiScore << endl;

        match_round++;
        Sleep(1500); // Pause for 1 second
    }

    showOctagons();
    cout << "\nFinal Score: "
         << "\n" << playerName << ": " << playerScore
         << "\nAI: " << aiScore << endl;

    checkWinner(playerName, playerScore, aiName, aiScore);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void multiplayer() {
    fillValues();

    string player1Name;
    cout << "\nName of Player 1: ";
    cin >> player1Name;

    string player2Name;
    cout << "\nName of Player 2: ";
    cin >> player2Name;

    int player1Score = 0, player2Score = 0;
    vis.clear();

    while (match_round < 26) {
        system("cls");
        showOctagons();
        cout << "\n\n" << player1Name << " it's your turn...";

        string ch;
        cout << "Please enter the letter of your choice: ";
        cin >> ch;
        while(find(alphabet.begin(),alphabet.end(),ch) == alphabet.end()){
          cout << "Enter a valid move: ";
          cin >> ch;
        }
        ch = toupper(ch[0]);

        auto it = vis.find(ch);
        if (it != vis.end()) {
            cout << "This character was already chosen.";
            player1Score -= suits[ch];
            player1Score = max(0, player1Score);
        } else {
            vis[ch] = true;
            player1Score += suits[ch];
        }

        showValue(ch, player1Name);
        cout << player1Name << " your score is: " << player1Score << endl;

        match_round++;

        Sleep(1500); // Pause for 1 second

        showOctagons();
        cout << "\n\n" << player2Name << " it's your turn...";

        cout << "Please enter the letter of your octagon: ";
        cin >> ch;
        ch = toupper(ch[0]);

        it = vis.find(ch);
        if (it != vis.end()) {
            cout << "This character was already chosen.";
            player2Score = max(0, player2Score);
        } else {
            vis[ch] = true;
            player2Score += suits[ch];
        }
        showValue(ch, player2Name);
        cout << player2Name << " your score is: " << player2Score << endl;

        match_round++;
        Sleep(1500); // Pause for 1 second
    }

    showOctagons();
    cout << "\nFinal Score: "
         << "\n" << player1Name << ": " << player1Score
         << "\n" << player2Name << ": " << player2Score << endl;

    checkWinner(player1Name, player1Score, player2Name, player2Score);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    string opt;
    while (opt != "0") {
        menu();
        cin >> opt;
        if (opt == "1") {
            cout << "\n\n[  P L A Y E R    V S.   C P U  ]" << endl;
            playerVsAI();
        } else if (opt == "2") {
            cout << "\n\n[  M U L T I P L A Y E R  ]" << endl;
            multiplayer();
        }
    }

    return 0;
}
