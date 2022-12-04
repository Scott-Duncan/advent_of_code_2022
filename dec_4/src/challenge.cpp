#include "../include/challenge.hpp"

CleaningPairs::CleaningPairs (const std::string &file_location){
  std::fstream myfile(file_location, std::ios_base::in);
  int total{0};
  std::string line;

  while (getline(myfile, line)) {
    if(line.empty()){break;}
    auto rows = getRows(line);
    if (checkIfRowsMatch(rows)){
      std::cout << "Rows: " << rows.at(0) << "," << rows.at(1) << "," << rows.at(2) << "," << rows.at(3) << std::endl;
      total ++;
    }
  }

  std::cout << "Total: " << total << std::endl;
  
}

std::vector<int> CleaningPairs::getRows(const std::string &line){
  std::vector<int> rows;
  std::string rows_left = line.substr(0,line.find(","));
  std::string rows_right = line.substr(line.find(",")+1, line.size());

  rows.push_back(getInt(rows_left.substr(0,rows_left.find("-"))));
  rows.push_back(getInt(rows_left.substr(rows_left.find("-")+1, rows_left.size())));
  rows.push_back(getInt(rows_right.substr(0,rows_right.find("-"))));
  rows.push_back(getInt(rows_right.substr(rows_right.find("-")+1, rows_right.size())));

  return rows;
}

bool CleaningPairs::checkIfRowsMatch(const std::vector<int> &rows){
  // std::cout << "Rows: " << rows.at(0) << "," << rows.at(1) << "," << rows.at(2) << "," << rows.at(3) << std::endl;
  if (rows.at(0) >= rows.at(2) && rows.at(0) <= rows.at(3)){
    return true; 
   } else if (rows.at(1) >= rows.at(2) && rows.at(1) <= rows.at(3)){
    return true;
   } else if (rows.at(2) >= rows.at(0) && rows.at(2) <= rows.at(1)){
    return true; 
   } else if (rows.at(3) >= rows.at(0) && rows.at(3) <= rows.at(1)){
    return true;
   } else {
    return false;
   }
  
}

int CleaningPairs::getInt(const std::string &row){
    
  int row_number;
  std::istringstream tmp(row);
  tmp >> row_number;
  return row_number;
}


int main(int argc, char *argv[]) {

  CleaningPairs cleaning_pairs{"config/input.txt"};

  return 0;
}
