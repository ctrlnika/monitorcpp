#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <limits>
#include "monitor.cpp"

#define RED "\033[31m"
#define YELLOW "\x1b[33m"  
#define GREEN "\033[32m"
#define RESET "\x1b[0m"

double num1;
double num2;
double num3;

string operation;
double value = 0.0;
int again = 'y';
using namespace std;
int main() {
  Monitor * m = 0;


  string banner = 
" _______                __  __    __         _______                __  __                 \n"
" |   |   |.-----..---.-.|  ||  |_ |  |--.    |   |   |.-----..-----.|__||  |_ .-----..----. \n"
" |       ||  -__||  _  ||  ||   _||     |    |       ||  _  ||     ||  ||   _||  _  ||   _| \n"
" |___|___||_____||___._||__||____||__|__|    |__|_|__||_____||__|__||__||____||_____||__|   \n";

  while (true) {
    while (true) {



      cout << banner << endl;
      cout << "Enter diagnostics:"  << endl;
      cout << "1: Heart Rate" << endl;
      cout << "2: Blood Pressure" << endl;
      cout << "3: Temperature" << endl;
      cout << "4: Quit" << endl;
      cout << endl;

      cin >> operation; 
      if (operation == "1" || operation == "2" || operation == "3" || operation == "4") {
        break;
      }
      else
      {
        cout << endl << YELLOW << "Invalid Input" << RESET << endl << endl;
      }
    }



    if (operation == "4") {
        break;
    }

    while (true) {

      cout << "Enter value: ";
      cin >> value;
      if (cin.good()) {
        // valid number
        break;
      } 
      else
      {
        cout << YELLOW << "Invalid Input! Please input a numerical value." << RESET << endl;
        cin.clear();
        cin.ignore(100000, '\n');
      }
    }



    switch (stoi(operation))
    {
    case 1:
        m = new Heart(value);
        break;
    case 2:
        m = new Pressure(value);
        break;    
    case 3:
        m = new Temperature(value);
        break;\

    }
    if (m) {
      m->print();
      cout << endl;
    }


    if (m != 0) {
      delete m;
      m = 0;
    }
  }
    return 0;
}
