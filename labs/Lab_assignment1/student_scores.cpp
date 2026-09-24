#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gradesLength(vector<int> grades){
  return grades.size() > 0 ? grades.size() : 1;
  
}

double mean(vector<int> grades){
  int total = 0;
  for(int g : grades ) {
    total += g;
  }
  return total / gradesLength(grades);
}

double variance(vector<int> grades){
  int total = 0;
  for(int g : grades){
    total += pow((g - mean(grades)),2);
  }
  int denominator = (gradesLength(grades) - 1) > 0 ? (gradesLength(grades) - 1) : 1;
  return total / denominator;
}

double sd(vector<int> grades){
   return sqrt(variance(grades));
}



int main(){

  vector<int> grades = {};
  const bool inserting = true;
  int counter = 1;
  int newGrade;

  // Take user inputs

  while (inserting){
    cout << "Insert grades[0 - 200] (enter '-1' to stop ) for student " << counter <<": ";
    cin >> newGrade;
    if(newGrade == -1){
      break;
    }else if(newGrade < 0 || newGrade > 200){
      cout << newGrade << " is an invalid grade" << endl;
      continue;
    }else{
      grades.push_back(newGrade);
      counter++;
    }
  }
  //                         A        B        C        D         E          F          G          H 
  vector<string> ranges = {"0–24", "25–49", "50–74", "75–99", "100–124", "125–149", "150–174", "175–200"};
  vector<int> rangeA = {};
  vector<int> rangeB = {};
  vector<int> rangeC = {};
  vector<int> rangeD = {};
  vector<int> rangeE = {};
  vector<int> rangeF = {};
  vector<int> rangeG = {};
  vector<int> rangeH = {};

  for(int g : grades ) {
    if (g <= 24) rangeA.push_back(g);
    else if (g <= 49) rangeB.push_back(g);
    else if (g <= 74) rangeC.push_back(g);
    else if (g <= 99) rangeD.push_back(g);
    else if (g <= 124) rangeE.push_back(g);
    else if (g <= 149) rangeF.push_back(g);
    else if (g <= 174) rangeG.push_back(g);
    else rangeH.push_back(g);    
  }

  cout << endl;

  // Calculate Mean
  cout << "Group Score  Frequency(x)   Mean    Variance   Standard Deviation" << endl;
  cout << "0-24         " << rangeA.size() << "              " << mean(rangeA) <<"        " << variance(rangeA) <<"      " << sd(rangeA) << endl;
  cout << "25-49        " << rangeB.size() << "              " << mean(rangeB) <<"        " << variance(rangeB) <<"      " << sd(rangeB) << endl;
  cout << "50-74        " << rangeC.size() << "              " << mean(rangeC) <<"        " << variance(rangeC) <<"      " << sd(rangeC) << endl;
  cout << "75-99        " << rangeD.size() << "              " << mean(rangeD) <<"        " << variance(rangeD) <<"      " << sd(rangeD) << endl;
  cout << "100-124      " << rangeE.size() << "              " << mean(rangeE) <<"        " << variance(rangeE) <<"      " << sd(rangeE) << endl;
  cout << "125-149      " << rangeF.size() << "              " << mean(rangeF) <<"        " << variance(rangeF) <<"      " << sd(rangeF) << endl;
  cout << "150-174      " << rangeG.size() << "              " << mean(rangeG) <<"        " << variance(rangeG) <<"      " << sd(rangeG) << endl;
  cout << "175-200      " << rangeH.size() << "              " << mean(rangeH) <<"        " << variance(rangeH) <<"      " << sd(rangeH) << endl;

  return 0;
}