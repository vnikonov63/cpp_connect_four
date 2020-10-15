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
  for (int i = gameField.size() - 1; i >= 0; --i)
  {
    cout << "|";
    for (int j = 0; j < gameField[i].size(); ++j)
    {
      if (gameField[i][j] == "Y") {
        cout << YELLOW << gameField[i][j] << RESET << "|";
        continue;
      }
      if (gameField[i][j] == "R") {
        cout << RED << gameField[i][j] << RESET << "|";
        continue;
      }
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

bool CheckLine(vector<string> gameLine) {
  int sameCount = 0;
  for (int i = 0; i < gameLine.size() - 1; ++i) {
    if (gameLine[i] == gameLine[i + 1] && gameLine[i] != " ") {
      ++sameCount;
    }
    else {
      sameCount = 0;
    }
    if (sameCount == 3) {
      return true;
    }
  }
  return false;
}

vector<vector<string> > TransposeAMatrix(vector<vector<string> > gameField) {
  vector<vector<string> > result;
  return result;
}

bool CheckWinnerExistance(vector<vector<string> > gameField) {
  for (int i = 0; i < gameField.size(); ++i) {
    if (CheckLine(gameField[i])) {
      return true;
    }
  }
  return false;
}

string DetermineWinner(vector<vector<string> > gameField) {
  string result = " ";
  return result;
}

vector<vector<string> >AddTheStep(vector<vector<string> > gameField, int numberOfThColumn, string letter) {
  int row = -1;
  for (int i = 0; i < gameField.size(); ++i)
  {
    for (int j = 0; j < gameField[i].size(); ++j)
    {
      if (j == numberOfThColumn && gameField[i][j] != " ") {
        row = i;
      }
    }
  }
  gameField[row + 1][numberOfThColumn] = letter;

  return gameField;
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
  while (CheckIfFull(mainField) == false && CheckWinnerExistance(mainField) == false) {
    string response;
    if (order % 2 == 0) {
      cout << redName + " please enter the number of the column (0-6)" << endl;
      ++order;
      cin >> response;
      int choice = stoi(response);
      CheckIfQuit(response);
      mainField = AddTheStep(mainField, choice, "R");
    }
    else {
      cout << yellowName + " please enter the number of the column (0-6)" << endl;
      ++order;
      cin >> response;
      CheckIfQuit(response);
      int choice = stoi(response);
      mainField = AddTheStep(mainField, choice, "Y");
    }
    Space(1);
    DisplayTheGameField(mainField);
    Space(15);
  }
  if (CheckIfFull(mainField)) {
    Space(2);
    cout << "Sorry, the game resuted in a draw" << endl;
    return 0;
  }
  if ((order + 1) % 2 == 0) {
    Space(2);
    cout << redName + " has won, he was playing red" << endl;
    return 0;
  }
  else {
    Space(2);
    cout << yellowName + " has won, he was playing yellow" << endl;
    return 0;
  }
}
