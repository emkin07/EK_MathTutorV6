/**********************************************************************************************************************************
Program......:  Math_Tutor_V5
 Programmer(s):  Cody Hittle, Emma Kinney
 Description..:  Header file containing constants, includes, and function prototypes
*********************************************************************************************************************************/
#ifndef MATH_TUTOR_H
#define MATH_TUTOR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Global constants
const int MAX_ATTEMPTS = 3;
const int LEVEL_RANGE_CHANGE = 10;
const string FILE_NAME = "math_tutor.txt";

// Function prototypes
void DisplayGameIntro();
string GetUserName();
int LoadPreviousGame(string userName, vector<vector<int>>& allQuestions);
vector<int> GenerateRandomQuestion(int mathLevel);
int GetNumericValue();
bool GiveThreeAttempts(string userName, vector<int> &currentQuestion);
int CheckForLevelChange(int totalCorrect, int totalIncorrect, int mathLevel);
char YesNoQuestion(const string & string);
void DisplaySummaryReport(const vector<vector<int>> &questions);
void SaveCurrentGame(string userName, const vector<vector<int>>& allQuestions);

#endif //MATH_TUTOR_H