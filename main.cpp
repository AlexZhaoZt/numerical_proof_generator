#include <iostream>
#include <string>
#include <stack>
#include <array>
#include <queue>
#include <cmath>

#include <vector>


#include "main.h"
using std::pow;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stack;

int counter = 0;
double desired;
int length_;

int main() {
  using std::vector;
  cout << "Enter a number for 114514 decomposition:" << endl;
  cin >> desired;
//Attempt Strong Numerical Proof.
//尝试强算术论证
  length_ = 11;
  int array[length_]; //= new int[length_];
  array[0] = 0;
  array[1] = 0;
  put(array, 2, 2, 0);
  int newArr[length_];
  newArr[0] = -1;
  newArr[1] = 0;
  put(newArr, 2, 2, 0);
  if (counter >= 1) {
    cout << "Found " + std::to_string(counter) + " solutions." << endl;
  } else {
    cout << "Found " + std::to_string(counter) + " solution." << endl;
  }
//Attempt Weak Numerical Proof.
//尝试弱算术论证
//incomplete
/*
  vector<string> v;
  string put_in = "";
  char charArr[6] = {'1', '1', '4', '5', '1', '4'};
  for (int block = 2; block < 6; block++) {
    for (int chance = 0; chance < charArr.size() - (block - 1); chance++) {
      int used = 0;
      for (size_t index = 0; index < charArr.size() - (block - 1); index++) {
        if (used < chance) {
          for (int i = 0; i < block; i++) {
            put_in += charArr[index + i];
          }
          v.push_back(put_in);
          used++;
          put_in = "";
        } else {
          put_in += charArr[index];
          v.push_back(put_in);
          put_in = "";
        }
      }
    }
  }
  */



  return 0;

}

//recursively put in numbers and symbols in Reverse Polish Notation (RPN).
//-1: -1, 0: number, 1: +, 2: -, 3: *, 4: /, 5: ^.
void put(int seed[length_], int pos, int numCounter, int symCounter) {
  if (pos == length_) {
    if (checker(seed)) {
      counter++;
      print(seed);
    }
    return;
  }
  int lower = 0;
  int upper = 6;
  if (numCounter == 6) {
    lower = 1;
  }
  if (symCounter == 5 || symCounter == numCounter - 1) {
    upper = 1;
  }
  while (lower < upper) {
    seed[pos] = lower;
    if (lower == 0)
      put(seed, pos + 1, numCounter + 1, symCounter);
    else
      put(seed, pos + 1, numCounter, symCounter + 1);
    lower++;

  }

}

//check if the RPN stored in the array gives the desired result.
bool checker(int seed[length_]) {

  double a = 1.0, b = 1.0, c = 4.0, d = 5.0, e = 1.0, f = 4.0;
  stack<double> myStack;
  int sign;
  double firstNum, secondNum;
  int numCount = 0;
  for (int i = 0; i < length_; i++) {
    if (seed[i] == 0) {
      switch (numCount) {
        case 0: myStack.push(a);
                break;
        case 1: myStack.push(b);
                break;
        case 2: myStack.push(c);
                break;
        case 3: myStack.push(d);
                break;
        case 4: myStack.push(e);
                break;
        case 5: myStack.push(f);
                break;
      }
      numCount++;

    } else if (seed[i] == -1) {
      myStack.push(-a);
      numCount++;
    } else {
        sign = seed[i];
        secondNum = myStack.top();
        myStack.pop();
        firstNum = myStack.top();
        myStack.pop();
        //cout << "myStack size: " << myStack.size() << ", i = " << i << endl;
        switch (sign) {
          case 1: myStack.push(firstNum + secondNum);
                  break;
          case 2: myStack.push(firstNum - secondNum);
                  break;
          case 3: myStack.push(firstNum * secondNum);
                  break;
          case 4: myStack.push(firstNum / secondNum);
                  break;
          case 5: myStack.push(pow(firstNum, secondNum));
        }
      }
    }
  if (myStack.top() == desired) {
    return true;
  } else {
    return false;
  }

}

string translate(string input) {
  string symbol = "+-*/^";

  stack<string> output;
  string str1;
  string str2;
  string outstr = "";
  for (size_t i = 0; i < input.size(); i++) {
    if ((int)symbol.find(input.at(i)) == -1) {
      output.push(string(1, input.at(i)));
    } else {
      if (i == 1) {
        output.pop();
        output.push("-1");
        continue;
      }
      str2 = output.top();
      output.pop();
      str1 = output.top();
      output.pop();
      if (i == input.size() - 1) {
        output.push(str1 + string(1, input.at(i)) + str2);
      } else {
        output.push("(" + str1 + string(1, input.at(i)) + str2 + ")");
      }
    }
  }
  return output.top();
}

//print RPN.
void print(int seed[length_]) {
  int numCount = 0;
  int i;
  string output = "";
  for (int k = 0; k < length_; k++) {
    i = seed[k];
    switch (i) {
      case -1: output += "1-";
               numCount++;
               break;
      case 0: switch (numCount) {
               case 0: output += "1";
                       break;
               case 1: output += "1";
                       break;
               case 2: output += "4";
                       break;
               case 3: output += "5";
                       break;
               case 4: output += "1";
                       break;
               case 5: output += "4";
                       break;
              }
              numCount++;
              break;
      case 1: output += "+";
              break;
      case 2: output += "-";
              break;
      case 3: output += "*";
              break;
      case 4: output += "/";
              break;
      case 5: output += "^";
    }
  }
  //cout << output << endl;
  cout << std::to_string(desired) + "=" + translate(output) << endl;
}
