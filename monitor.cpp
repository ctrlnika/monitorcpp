#include <iostream>
#include <string>
#include <limits>

#define RED  "\033[31m" 
#define YELLOW  "\x1b[33m" 
#define GREEN "\033[32m"
#define RESET "\x1b[0m"

using namespace std;

class Monitor {
protected:
    double value;

public:
    Monitor(double v) : value(v)
    {

    }

    virtual ~Monitor() { };

    virtual void print() {
      cout << "value: " << value;
    };

};

class Heart : public Monitor {
public:
  Heart(double value) : Monitor(value) {};

  virtual void print(){
    if (value >= 80.0 && value <= 100.0)
      cout << GREEN << "Safe" << RESET << endl;
    else
      cout << RED << "Alarm" << RESET << endl;
  }
};

class Pressure : public Monitor {
public:
  Pressure(double value) : Monitor(value) {};

  virtual void print(){
    if (value >= 80.0 && value <= 120.0)
      cout << GREEN << "Safe" << RESET << endl;
    else
      cout << RED << "Alarm" << RESET << endl;
  }
};

class Temperature : public Monitor {
public:
  Temperature(double value) : Monitor(value) {
  };

  virtual void print() {

    if (value >= 36.0 && value <= 37.1)
      cout << GREEN << "Safe" << RESET << endl;
    else
      cout << RED << "Alarm" << RESET << endl;
  }
};