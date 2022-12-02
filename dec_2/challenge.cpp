#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int rock (const char oponent){
  if (oponent == 'B'){
    return 1;
  } else if ( oponent  == 'A'){
    return 4;
  } else if (oponent == 'C'){
    return 7;
  }
   return 0;
}

int paper (const char oponent){
  if (oponent == 'C'){
    return 2;
  } else if ( oponent  == 'B'){
    return 5;
  } else if (oponent == 'A'){
    return 8;
  }
  return 0;
}

int scissors (const char oponent){
  if (oponent == 'A'){
    return 3;
  } else if ( oponent  == 'C'){
    return 6;
  } else if (oponent == 'B'){
    return 9;
  }
  return 0;
}

int match(const char oponent, const char me){
  if(me == 'X'){
    return rock(oponent);
  } else if (me =='Y'){
    return  paper(oponent);
  } else if (me == 'Z'){
    return scissors(oponent);
  }
  return 0;
}

int main(int argc, char * argv[])
{
    std::fstream myfile("input.txt", std::ios_base::in);

    auto total_score{0};

    string s;
    while (getline(myfile, s))
    {
      char oponent = s[0];
      char me = s[2];

      total_score += match(oponent, me);
    }

    std::cout << "Total score is: " << total_score << std::endl;
    

    return 0;
}
