/**********************************************************************************************************************************
 Program......:  Math_Tutor_V5
 Programmer(s):  Cody Hittle, Emma Kinney
 Description..:  Function implementations for Math Tutor
*********************************************************************************************************************************/
#include "math_tutor.h"
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

/*----------------------------------------------------*
 * Introduction to the math tutor with fancy ASCII art.
 *----------------------------------------------------*/
void DisplayGameIntro() {
    cout << R"(   /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\   )" << endl;
    cout << R"(  //\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\  )" << endl;
    cout << R"(  \\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//  )" << endl;
    cout << R"(   \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/   )" << endl;
    cout << R"(   /\                                                                          /\   )" << endl;
    cout << R"(  //\\ ______                               _____         _                   //\\  )" << endl;
    cout << R"(  \\// |  _  \                             |_   _|       (_)                  \\//  )" << endl;
    cout << R"(   \/  | | | |_ __ __ _  __ _  ___  _ __     | |_ __ __ _ _ _ __   ___ _ __    \/   )" << endl;
    cout << R"(   /\  | | | | '__/ _` |/ _` |/ _ \| '_ \    | | '__/ _` | | '_ \ / _ \ '__|   /\   )" << endl;
    cout << R"(  //\\ | |/ /| | | (_| | (_| | (_) | | | |   | | | | (_| | | | | |  __/ |     //\\  )" << endl;
    cout << R"(  \\// |___/ |_|  \__,_|\__, |\___/|_| |_|   \_/_|  \__,_|_|_| |_|\___|_|     \\//  )" << endl;
    cout << R"(   \/                    __/ |                                                 \/   )" << endl;
    cout << R"(   /\                   |___/                                                  /\   )" << endl;
    cout << R"(  //\\          ___  ___      _   _       _____     _                         //\\  )" << endl;
    cout << R"(  \\//          |  \/  |     | | | |     |_   _|   | |                        \\//  )" << endl;
    cout << R"(   \/           | .  . | __ _| |_| |__     | |_   _| |_ ___  _ __              \/   )" << endl;
    cout << R"(   /\           | |\/| |/ _` | __| '_ \    | | | | | __/ _ \| '__|             /\   )" << endl;
    cout << R"(  //\\          | |  | | (_| | |_| | | |   | | |_| | || (_) | |               //\\  )" << endl;
    cout << R"(  \\//          \_|  |_/\__,_|\__|_| |_|   \_/\__,_|\__\___/|_|               \\//  )" << endl;
    cout << R"(   \/                                                                          \/   )" << endl;
    cout << R"(   /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\   )" << endl;
    cout << R"(  //\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\  )" << endl;
    cout << R"(  \\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//  )" << endl;
    cout << R"(   \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/  \/   )" << endl;
    cout << endl;
    cout << "Welcome to the Dragon Trainer Math Tutor v6.0!" << endl;
    return;
}

//----------------------------------------------------
// Get the user's name
//----------------------------------------------------
string GetUserName() {
    string userName;
    cout << "What's your name, brave trainer: ";
    getline(cin, userName);
    cout << "Nice to meet you, " << userName << "!" << endl;
    cout << endl;
    return userName;
}

int LoadPreviousGame(string userName, vector<vector<int>>& allQuestions) {
    string userInput;
    ifstream inFS;
    int mathLevel;
    int leftNum;
    int mathSymbol;
    int rightNum;
    int correctAns;
    int attempts;

    inFS.open(FILE_NAME);
    if (inFS.eof()) {
        cout << userName << ", it looks like you haven't played this game before. Good Luck!" << endl;
        return 1;
    }

    string question = "Would you like to load your previous game? (y/n): ";
    userInput = YesNoQuestion(question);
    if (userInput == "n") {
        cout << "You canceled the load, restarting game." << endl;
        return 1;
    }

    cout << "Loading previous game. Please wait...." << endl;

    while (inFS >> mathLevel >> leftNum >> mathSymbol >> rightNum >> correctAns >> attempts) {
        allQuestions.push_back({mathLevel, leftNum, mathSymbol, rightNum, correctAns, attempts});
    }

    if (!inFS.is_open()) { throw runtime_error("Something went wrong with reading the " + FILE_NAME + " file.");}

    inFS.close();
    cout << allQuestions.size() << " questions loaded from " << FILE_NAME << endl;
    cout << "Previous game loaded successfully. " << endl;

    return mathLevel;
}

//----------------------------------------------------
// Generate a random math question
//----------------------------------------------------
vector<int> GenerateRandomQuestion(int mathLevel) {
    int leftNum = rand() % (mathLevel * LEVEL_RANGE_CHANGE) + 1;
    int rightNum = rand() % (mathLevel * LEVEL_RANGE_CHANGE) + 1;
    int operation = rand() % 4 + 1;
    char mathSymbol = '?';
    int correctAns = 0;

    switch (operation) {
        case 1: mathSymbol = '+'; correctAns = leftNum + rightNum; break;
        case 2: mathSymbol = '-'; if(leftNum < rightNum) swap(leftNum, rightNum); correctAns = leftNum - rightNum; break;
        case 3: mathSymbol = '*'; correctAns = leftNum * rightNum; break;
        case 4: mathSymbol = '/'; if(rightNum == 0) rightNum = 1; leftNum = leftNum * rightNum; correctAns = leftNum / rightNum; break;
        default:
            cout << "Invalid question type: " << mathSymbol << endl;
            cout << "Please report this error to Emma Kinney." << endl;
            throw runtime_error("Invalid Math Type: " + mathSymbol);
            exit(-1);
    }

    return {mathLevel, leftNum, mathSymbol, rightNum, correctAns};
}

//----------------------------------------------------
// Get numeric value from user
//----------------------------------------------------
int GetNumericValue() {
    int userAns;
    while (!(cin >> userAns)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number: ";
    }
    return userAns;
}

//----------------------------------------------------
// Give the user up to 3 attempts to answer
//----------------------------------------------------
bool GiveThreeAttempts(string userName, vector<int> &currentQuestion) {
    int mathLevel = currentQuestion[0];
    int leftNum = currentQuestion[1];
    char mathSymbol = static_cast<char>(currentQuestion[2]);
    int rightNum = currentQuestion[3];
    int correctAns = currentQuestion[4];
    int attempts = 1;

    for (attempts; attempts <= MAX_ATTEMPTS; attempts++) {
        cout << "[Level #" << mathLevel << "] " << userName
             << ", what does " << leftNum << mathSymbol << rightNum << " = ";
        int userAns = GetNumericValue();

        if (userAns == correctAns) {
            cout << "Correct! Great job, " << userName << "!" << endl << endl;
            currentQuestion.push_back(attempts);
            return true;

        } else {
            cout << "Incorrect. Try again." << endl;
        }
    }

    cout << "The correct answer was " << correctAns << "." << endl;
    currentQuestion.push_back(attempts); // failed all attempts
    return false;
}

//----------------------------------------------------
// Adjust difficulty level based on correct/incorrect answers
//----------------------------------------------------
int CheckForLevelChange(int totalCorrect, int totalIncorrect, int mathLevel) {
    if (totalCorrect == 3) {
        mathLevel++;
        cout << "You leveled up! Range increased to: " << (mathLevel * LEVEL_RANGE_CHANGE) << endl;
    }
    if (totalIncorrect == 3){
        mathLevel--;
        cout << "You leveled down. Range changed to: " << (mathLevel * LEVEL_RANGE_CHANGE) << endl;
    }
    if (mathLevel < 1) mathLevel = 1;
    return mathLevel;
}

//----------------------------------------------------
// Ask user if they want to continue
//----------------------------------------------------
char YesNoQuestion(const string &question) {

    string userInput = "?";

    while (true) {

        cout << question << endl;

        getline(cin, userInput);

        for (int i = 0; i < userInput.size(); i++) {
            userInput.at(i) = tolower(userInput.at(i));
        }

        if (userInput == "yes" || userInput == "y" || userInput == "no" || userInput == "n") {
            break;
        } else {
            cout << "Invalid input, please try again... " << endl;
            cout << endl;
        }
    }

    if (userInput == "yes" || userInput == "y") {
        return 'y';
    } else {
        return 'n';
    }
}

//----------------------------------------------------
// Display summary report
//----------------------------------------------------
void DisplaySummaryReport(const vector<vector<int>> &questions) {
    int numCorrect = 0;


    cout << "\n========= Pet Summary Report =========\n";
    cout << "Level | Question | Correct Ans | Attempts\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i < questions.size(); i++) {
        int mathLevel = questions.at(i).at(0);
        int leftNum = questions.at(i).at(1);
        char mathSymbol = static_cast<char>(questions.at(i).at(2));
        int rightNum = questions.at(i).at(3);
        int correctAns = questions.at(i).at(4);
        int attempts = questions.at(i).at(5);

        cout << mathLevel << "      " << leftNum << " " << mathSymbol << " " << rightNum
                << " = " << correctAns << "       ";
        if (attempts < 4) {
            cout << "Correct in " << attempts << " attempts\n";
            numCorrect++;
        } else {
            cout << "Incorrect\n";
        }
    }

    int accuracy = (numCorrect * 100) / questions.size();
    cout << "Total Questions: " << questions.size() << endl;
    cout << "Correct Answers: " << numCorrect << endl;
    cout << "Accuracy: " << accuracy << "%\n";
}



void SaveCurrentGame(string userName, const vector<vector<int>>& allQuestions) {
    string userInput;
    ofstream outFS;

    string question = userName + ", do you want to save your game? (y/n): ";
    userInput = YesNoQuestion(question);
    if (userInput == "n" || userInput == "no") {
        cout << "Save game canceled." << endl;
        return;
    }

    cout << "Saving game. Please wait...." << endl;
    outFS.open(FILE_NAME);
    if (!outFS.is_open()) {throw runtime_error("Could not open file " + FILE_NAME + " for writing.");}

    for (int i = 0; i < allQuestions.size(); i++) {
        outFS << allQuestions.at(i).at(0) << " "
        << allQuestions.at(i).at(1) << " "
        << allQuestions.at(i).at(2) << " "
        << allQuestions.at(i).at(3) << " "
        << allQuestions.at(i).at(4) << " "
        << allQuestions.at(i).at(5) << endl;
    }

    outFS.close();
    cout << allQuestions.size() << " questions saved to " << FILE_NAME << endl;
    cout << "Game saved successfully." << endl;

    return;
}