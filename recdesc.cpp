#include "iostream"
#include "fstream"

bool B(std::ifstream &in)
{
  char c = in.get();
  if (in.eof())
  {
    return true;
  }
  switch (c)
  {
  case 'b':
    return A(in) && in.get() == 'c';
  case 'c':
    return B(in);
  default:
    return false;
  }
}

bool A(std::ifstream &in)
{
  char c = in.get();
  switch (c)
  {
  case 'a':
    return A(in);
  case 'b':
    in.putback(c);
    return B(in);
  case 'c':
    char next = in.get();
    if (in.eof())
      return true;
    else
    {
      in.putback(next);
      in.putback(c);
      return B(in);
    }
  default:
    return false;
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Please enter file name";
    return;
  }
  std::ifstream file(argv[1]);
  if (A(file))
  {
    std::cout << "Passed!";
  }
  else
  {
    std::cout << "Denied!";
  }
  file.close();
}