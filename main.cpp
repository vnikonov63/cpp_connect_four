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

int main()
{
  string redName;
  string yellowName;

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
}
