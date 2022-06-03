#include <iostream>
#define print std::cout

void AskMathQuestion(std::string question, int answer);
void AnswerNumber(int result);
void ClearInputBuffer();
int ValidateInput(std::string variable);

int points = 0;

int main()
{
    print << "Hello User, lets see if you are good at math!\n";
    system("pause");
    AskMathQuestion("How much is 1 x 1?", 1);
    AskMathQuestion("How much is 64 / 8?", 8);
    print << "Your total score is: " << points;
}

void AskMathQuestion(std::string question, int answer)
{
    print << "QUESTION: " << question << "\n";
    AnswerNumber(answer);
}

void AnswerNumber(int result)
{
    int answer = ValidateInput("ANSWER");
    if (answer == result)
    {
        print << "CORRECT\n";
        points += 100;
    }
    else
    {
        print << "INCORRECT\n";
        if (points >= 100)
            points -= 100;
    }
}


void ClearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}

int ValidateInput(std::string variable)
{
    int input;
    while (true)
    {
        print << variable << ": ";
        if (std::cin >> input)
        {
            ClearInputBuffer();
            break;
        }
        ClearInputBuffer();
        print << "\nInvalid Input.\n";
    }
    return input;
}