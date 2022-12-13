#include <string>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>

bool comp(std::string &line, std::string &line2 ){
  auto depth{0}, depth2{0};
  auto position{0};
  auto reshaped{false};
  boost::erase_all(line, ",");
  boost::erase_all(line2, ",");
  
  for(int i = 0; i < line.size(); i ++) {
    if (position > line2.size()){
      break;
    }
    if(line[i] == ']'){
      if(line2[position] == ']'){
          position++;
          reshaped = false;
          continue;
      } else {
          position += line2.substr(position).find(']');
          reshaped = false;
          continue;
      }
    }
    if(line[i] == '['){
      depth ++;
      if(line2[position] == '['){
        depth2 ++;
        position ++;
      } else if ( line2[position] == ']'){
        return false;
      } else {
        reshaped = true;
        int end = line2.substr(position).find(']');
        // std::cout << line2 << std::endl;
        line2 = line2.substr(0,position-1) + "][" + 
                line2.substr(position,end) + "]" +
                line2.substr(position+end);
        // std::cout<< line2 << std::endl;
        position += 2;
      }
      continue;
    } else{
      if(line2[position] == '['){
        return false;
      }
      if(line2[position] == ']'){
        if (reshaped){
          i += line.substr(i).find(']');
          position ++;
          depth --;
          depth2 --;
          reshaped = false;
          continue;
        } else if(line[i] == ']'){
          position ++;
          continue;
        } else {
          return false;
        }
      }
      if(i >= line2.size()){
        // std::cout << "Line 2 is too short" << std::endl;
        return false;
      }
      if(int(line[i] - '0') > int(line2[position] - '0')){
        // std::cout << "Failed because item " << i << " " << line[i] << " is higher than " << line2[position] << std::endl;
        return false;
      }
    }
      position ++;
  }

  return true;
}

int main (int argc, char *argv[])
{
  std::fstream input(argv[1]);
  std::string line1;
  std::string line2;
  auto total{0};
  auto count{1};

  while (getline(input,line1)){
    getline(input, line2);
    if(comp(line1,line2)){
      total += count;
      // std::cout << "Success" <<std::endl;
      // std::cout << count <<std::endl;
      // std::cout << line1 <<std::endl;
      // std::cout << line2 <<std::endl;
    } else {
      // std::cout << "Failure" <<std::endl;
      // std::cout << count <<std::endl;
      // std::cout << line1 <<std::endl;
      // std::cout << line2 <<std::endl;
    }
    count ++;
    getline(input,line1);
  }
  
  std::cout << "Total : " << total << std::endl;
  
  return 0;
}

