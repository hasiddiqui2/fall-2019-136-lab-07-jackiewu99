#include<iostream>
#include<string>
#include "funcs.h"

int main()
{
  std::string out = removeLeadingSpaces("           int x = 1;  ");
  std::cout << out << std::endl;

  std::string noIndents = unindent();

}
