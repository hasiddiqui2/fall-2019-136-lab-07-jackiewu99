#include<iostream>
#include<fstream>

std::string removeLeadingSpaces(std::string line);
std::string unindent();
int countChar(std::string line2,char c);
std::string indent(std::string lineNoIndent);

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
  std::string clean;
  std::string print;
  std::string nonIndent;
  std::ifstream fin("badIndent.cpp");
  while(getline(fin,print))
    {
      nonIndent = removeLeadingSpaces(print);
      //std::cout << nonIndent << std::endl;
      clean = indent(nonIndent);
      std::cout << clean << std::endl;
    }
}

int countChar(std::string line2, char c)
{
  int letCounter = 0;
  for(int i = 0;i <= line2.length();i++)
    {
      if(line2[i] == c)
	{
	  letCounter += 1;
	}
    }
  return letCounter;
}

std::string indent(std::string lineNoIndent)
{
  std::string withIndent = lineNoIndent;
  static int indentCounter = 0;
  char start = '{';
  char end = '}';
  int isEnd = 0;
  isEnd = isEnd + countChar(lineNoIndent,end);
  if(isEnd > 0)
    {
      indentCounter = indentCounter - isEnd;
    }
  for(int i =0; i < indentCounter;i++)
    {
      withIndent = '\t' + withIndent;
    }
  indentCounter = indentCounter + countChar(lineNoIndent,start);
  return withIndent;
}
