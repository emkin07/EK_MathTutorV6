//Information. Header
/**********************************************************************************************************************************
 Program......:  Math_Tutor_V4
 Version......:  V5
 Programmer(s):  Cody Hittle, Emma Kinney
 Class........:  WSC CSC150 - Section 1 - 9:00 AM
 Date.........:  2025.11.16
 GitHub Repo..:  https://github.com/cohitt01/MathTutorV5
 Description..:  This program is an interactive math-training system designed to help users practice and improve their
    arithmetic skills through randomized addition, subtraction, multiplication, and division problems. The experience begins
    with personalized interaction as the program asks for the player’s name and uses it throughout the session. Each problem
    adapts to the user’s ability level: answering three questions correctly increases the difficulty, while three incorrect
    answers decrease it. The program tracks every question asked—including operands, operator, difficulty level, correct
    answer, and number of attempts—and stores this information for a detailed end-of-session summary. With built-in input
    validation, friendly feedback, and clear formatting, the program offers an engaging, educational, and user-friendly
    environment ideal for practicing essential math skills.

 Program Features:

    Math Practice System: Generates random addition, subtraction, multiplication, and division problems.

    Adaptive Difficulty Scaling: Difficulty increases after three correct answers and decreases after three incorrect answers.

    Personalized User Interaction: Greets the user by name and uses it throughout the session.

    Progress Tracking: Logs every question, including level, problem, correct answer, and attempts used.

    Attempt-Based Feedback: Allows up to three attempts per question with immediate response guidance.

    End-of-Session Summary Report: Displays all questions, correctness, attempts, and overall accuracy.

    Input Validation: Ensures numeric answers only and handles invalid input cleanly.

    User Control: Allows the player to choose whether to continue after each question.

    Friendly Presentation: Uses narration, spacing, and optional ASCII art for a welcoming experience.
*********************************************************************************************************************************/
#include "math_tutor.h"
#include <cstdlib>
#include <ctime>
#include <vector>



int main() {

    srand(time(0)); // Seed random generator

    string userName = "?";
    string userInput = "?";
    int totalCorrect = 0, totalIncorrect = 0, mathLevel = 1;
    bool isCorrect = false;

    vector<int> currentQuestion;
    vector<vector<int>> allQuestions;

    DisplayGameIntro();
    userName = GetUserName();

    try {
        mathLevel = LoadPreviousGame(userName, allQuestions);
    } catch (runtime_error &e) {
        cout << endl;
        cout << e.what() << endl;
    }

    do {
        try {
            currentQuestion = GenerateRandomQuestion(mathLevel);
        } catch (runtime_error &excpt) {
            cout << endl;
            cout << excpt.what() << endl;
            return -1;
        }

        isCorrect = GiveThreeAttempts(userName, currentQuestion);

        if (isCorrect) {
            totalCorrect++;
        } else {
            totalIncorrect++;
        }

        allQuestions.push_back(currentQuestion);
        mathLevel = CheckForLevelChange(totalCorrect, totalIncorrect, mathLevel);

        if (totalCorrect == 3) {
            totalCorrect = 0;
        } else if (totalIncorrect == 3) {
            totalIncorrect = 0;
        }

        string question = "Would you like to continue the tutorial? (y/n): ";

        getline(cin, userInput);

        userInput = YesNoQuestion(question);
    } while (userInput == "y" || userInput == "yes");

    DisplaySummaryReport(allQuestions);

    try {
        SaveCurrentGame(userName, allQuestions);
    } catch (runtime_error &e) {
        cout << endl;
        cout << e.what() << endl;
    }

    cout << "Thanks for training, " << userName << "!" << endl;
    return 0;
}