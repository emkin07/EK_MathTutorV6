# MathTutorV5
# Silly Math Tutor — Release v3.0.0

## Table of Contents
- [Summary](#summary)
- [Console Output Example](#console-output-example)
- [How to build & Run](#how-to-build--run)
- [Maintainers](#maintainers)

## Summary
```
    Get ready for a new adventure with Dragon Trainer Math Tutor v5! In this program, you hatch a dragon egg and level 
up your dragon by solving randomized math problems, including addition, subtraction, multiplication, and division. Each 
correct answer earns points and helps you progress, while incorrect answers allow multiple attempts before potentially
lowering your level. The difficulty dynamically adjusts to your performance, giving you a personalized challenge. 
All questions, attempts, and results are tracked, and at the end of the session, a detailed summary report shows how 
well you and your dragon performed. With friendly prompts, adaptive learning, and a fun interactive interface, this
program makes practicing math engaging and rewarding.
```
## Console Output Example

```
Welcome to the Dragon Trainer Math Tutor v5.0!
Let's get started by getting to know each other.
What's your name, brave trainer:Player1


Nice to meet you, Player1! Iggy already seems to like you.

[Level #1] Player1, what does 10*4=40

Correct! Great job, Player1!

Would you like to answer another question?
Yes = y, No = n
Choice:y


[Level #1] Player1, what does 24/6=1

Incorrect. Try again.
[Level #1] Player1, what does 24/6=2

Incorrect. Try again.
[Level #1] Player1, what does 24/6=3

Incorrect. Try again.
The correct answer was 4.
Would you like to answer another question?
Yes = y, No = n
Choice:y


[Level #1] Player1, what does 15/5=2

Incorrect. Try again.
[Level #1] Player1, what does 15/5=3

Correct! Great job, Player1!

Would you like to answer another question?
Yes = y, No = n
Choice:y


[Level #1] Player1, what does 2-1=`

Please enter a number:1

Correct! Great job, Player1!

Would you like to answer another question?
Yes = y, No = n
Choice:y


[Level #2] Player1, what does 11*2=22

Correct! Great job, Player1!

Would you like to answer another question?
Yes = y, No = n
Choice:n


==============================================
             Pet Summary Report
==============================================
Level | Question | Correct Ans | Attempts
----------------------------------------------
  1   10 *  4 =  40      Correct in 1
  1   24 /  6 =   4      Incorrect
  1   15 /  5 =   3      Correct in 2
  1    2 -  1 =   1      Correct in 1
  2   11 *  2 =  22      Correct in 1

Total Questions: 5
Correct Answers: 4
Incorrect Answers: 1
Accuracy: 80%

Thanks for training, Player1!
Your pet awaits your next visit.
END OF PROGRAM

Process finished with exit code 0

```

## How to build & run
```
Prerequisites:
    * A C++ compiler (g++, clang++, or IDE like Visual Studio, Code::Blocks, CLion).
    * All three files in the same folder: main.cpp, math_tutor.h, math_tutor.cpp.
    
Building from the Command Line:
    * Open a terminal in your project folder.
    * Compile the program
    * Run the program
        Windows: MathTutorV5.exe
        
Building in an IDE:
    * Create a new C++ project.
    * Add all three files to the project.
    * Build/compile using the IDE’s build option.
    * Run the program from the IDE.
    
Gameplay Notes:
    * Each math question shows the current level and operation.
    * You have 3 attempts per question.
    * After each question, choose whether to continue.
    * At the end, a summary report displays all questions, attempts, and accuracy.
```
## Maintainers
[@JD-4450](https://github.com/JD-445) Emma Kinney
[@cohitt01](https://github.com/cohitt01) Cody Hittle

[Back to Top](#table-of-contents)
