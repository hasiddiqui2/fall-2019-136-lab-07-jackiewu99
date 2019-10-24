#include<iostream>

std::string removeLeadingSpaces(std::string line)
{
  char letter;
  int holder = 0;
  std::string noLead = "";
  
  for(int i = 0; i < line.length();i++)
    {
      letter = line[i];
      if(isspace(letter))
	{
	  holder += 1;
	}
      else
	{
	  noLead = line.substr(i,line.length());
	  return noLead;
	}
    }	  
}

std::string unindent()
{
  while(getline(
  
}
