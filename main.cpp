#include <iostream>
#include <string>
#include <vector>
#define RESET "\033[0m"

#define RED "\033[31m"
#define YELLOW "\033[33m"

using namespace std;

void WrapMessage(string message)
{
  cout << string(100, '-') << endl;
  cout << string(100, '&') << endl;
  cout << string(100, '-') << endl;

  cout << message << endl;

  cout << string(100, '-') << endl;
  cout << string(100, '&') << endl;
  cout << string(100, '-') << endl;
}

void CheckIfQuit(string input)
{
  if (input == "Q")
  {
    exit(0);
  }
}

void Space(int number)
{
  cout << string(number, '\n') << endl;
}

void DisplayTheGameField(vector<vector<string> > gameField)
{
  for (int i = 0; i < gameField.size(); ++i)
  {
    cout << "|";
    for (int j = 0; j < gameField[i].size(); ++j)
    {
      cout << gameField[i][j] + "|";
    }
    cout << "\n";
  }
  cout << "---------------";
  cout << "\n";
}

bool CheckIfFull(vector<vector<string> > gameField) {
  bool result = true;
  for (int i = 0; i < gameField.size(); ++i)
  {
    for (int j = 0; j < gameField[i].size(); ++j)
    {
      if (gameField[i][j] == " ") {
        result = false;
      }
    }
  }
  return result;
}

bool CheckWinnerExistance(vector<vector<string> > gameField) {
  bool result = true;
  return result;
}

string DetermineWinner(vector<vector<string> > gameField) {
  string result = " ";
  return result;
}

void AddTheStep(vector<vector<string> > gameField, int numberOfThColumn, string letter) {

}

int main()
{
  string redName;
  string yellowName;

  // initialize the game field
  vector<vector<string> > mainField;
  for (int i = 0; i < 6; ++i)
  {
    vector<string> tempStep;
    for (int j = 0; j < 7; ++j)
    {
      tempStep.push_back(" ");
    }
    mainField.push_back(tempStep);
  }
  WrapMessage("To start the game press Y, to exit the game at any time print Q");
  string response;
  getline(cin, response);
  if (response == "Y")
  {
    Space(4);
    WrapMessage("Glad you are with us");
  }
  CheckIfQuit(response);
  Space(2);
  cout << RED << "Red player, enter the name:" << RESET << endl;
  cin >> redName;
  Space(1);
  cout << YELLOW << "Yellow player, enter the name:" << RESET << endl;
  cin >> yellowName;
  Space(2);
  DisplayTheGameField(mainField);
  // the game loop
  int order = 0;
  while (CheckIfFull(mainField) == false) {
    if (order % 2 == 0) {
      cout << redName + " please enter the number of the column (0-6)" << endl;
      ++order;
    }
    else {
      cout << yellowName + " please enter the number of the column (0-6)" << endl;
      ++order;
    }
    string response;
    cin >> response;
    CheckIfQuit(response);
  }
}
