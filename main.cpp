
#include "main.h"



double desired;

vector<double> base;

/* Maintains the number of ways to decompose the given number. */
int counter = 0;

/* Maintains the number of calculations performed. */
int calculation = 0;

int main() {
  cout << "Enter a number for 114514 decomposition:" << endl;
  cin >> desired;
  //Attempt Strong Numerical Proof.
  //尝试强算术论证
  // int array[length_]; //= new int[length_];
  strongProof();

  string answer;
  cout << "Do you wish to continue with weak numerical proof? (Y/N)" << endl;
  cin >> answer;

  if (answer == "N") {
    cout << "Quitting..." << endl;
    return 0;
  }


//Attempt Weak Numerical Proof.
//尝试弱算术论证
//incomplete
  weakProof();

  answer = "";
  cout << "Do you wish to continue with summation proof? (Y/N)" << endl;
  cin >> answer;

  if (answer == "N") {
    cout << "Quitting..." << endl;
    return 0;
  }

  double sum = 0.0;
  string number = to_string(desired);
  int notZero = 0;
  for (int i = 0; i < (int) number.size(); i++) {
    if (number.at(i) != '0') {
      notZero = i;
    }
  }
  number = number.substr(0, notZero);
  for (size_t i = 0; i < number.size(); i++) {
    sum += (double) (number.at(i) - '0');
    if (i == number.size() - 1) {
      cout << number.at(i);
    } else {
      cout << number.at(i) << "+";
    }
  }
  cout << "=" << sum << endl;
  desired = sum;
  strongProof();
  if (counter == 0) {
    cout << "Proceeding with weak numerical proof..." << endl;
    weakProof();
  }





  answer = "";
  cout << "Do you wish to continue with Po Zhen proof? (Y/N)" << endl;
  cin >> answer;

  if (answer == "N") {
    cout << "Quitting..." << endl;
    return 0;
  }

  int i = 0;
  for (char ch : number) {
    string output;
    switch (ch) {
      case '0': output = string(1, ch) + "=1-1^(4+5+1+4)";
                break;
      case '1': output = string(1, ch) + "=1^(1+4+5+1+4)";
                break;
      case '2': output = string(1, ch) + "=1+1^(4-5-1+4)";
                break;
      case '3': output = string(1, ch) + "=1-1+(4-5)^1+4";
                break;
      case '4': output = string(1, ch) + "=1*1*4^(5*1-4)";
                break;
      case '5': output = string(1, ch) + "=1-(1+(4-5)^1)+4";
                break;
      case '6': output = string(1, ch) + "=1*1-(4-5*1)+4";
                break;
      case '7': output = string(1, ch) + "=1+1^(4+5)+1+4";
                break;
      case '8': output = string(1, ch) + "=(1*1-(4-5)*1)*4";
                break;
      case '9': output = string(1, ch) + "=(1-1+4+5)*(1^4)";
                break;
    }

    cout << output << endl;
    i++;
  }



  return 0;

}

void strongProof() {
  calculation = 0;
  counter = 0;
  base.clear();
  base.push_back(1.0);
  base.push_back(1.0);
  base.push_back(4.0);
  base.push_back(5.0);
  base.push_back(1.0);
  base.push_back(4.0);
  vector<int> array;
  array.push_back(0);
  array.push_back(0);
  // array[0] = 0;
  // array[1] = 0;

  put(array, 11);

  array.clear();
  array.push_back(-1);
  array.push_back(0);
  // int newArr[length_];
  // newArr[0] = -1;
  // newArr[1] = 0;
  put(array, 11);
  if (counter >= 1) {
    cout << "Strong numerical proof found " + std::to_string(counter) + " solutions." << endl;
  } else {
    cout << "Strong numerical proof found " + std::to_string(counter) + " solution." << endl;
  }
  cout << "Performed " << calculation << " calculations." << endl;
}

void weakProof() {
  calculation = 0;
  counter = 0;
  queue<char> q;
  q.push('1');
  q.push('1');
  q.push('4');
  q.push('5');
  q.push('1');
  q.push('4');
  vector<double> v;
  choose(q, v);
  // string put_in = "";
  // char charArr[6] = {'1', '1', '4', '5', '1', '4'};
  // for (int firstSize = 1; firstSize < 6; firstSize++) {
  //
  //
  //
  // }
  if (counter >= 1) {
    cout << "Weak numerical proof found " + std::to_string(counter) + " solutions." << endl;
  } else {
    cout << "Weak numerical proof found " + std::to_string(counter) + " solution." << endl;
  }
  cout << "Performed " << calculation << " calculations." << endl;
}

void choose(queue<char> remain, vector<double> current) {
  string input = "";
  if (remain.empty()) {
    base = current;
    int max_length = current.size() * 2 - 1;
    if (max_length > 2 && max_length < 11) {
      vector<int> array;
      array.push_back(0);
      array.push_back(0);
      put(array, max_length);
      array.clear();
      array.push_back(-1);
      array.push_back(0);
      put(array, max_length);
    }
    return;
  }
  while (!remain.empty()) {
    input += remain.front();
    remain.pop();
    current.push_back((double) stoi(input));
    // used++;

    choose(remain, current);
    current.pop_back();
  }
}

void put(vector<int> v, int max_length) {
  put(v, 2, 2, 0, max_length);
}

//recursively put in numbers and symbols in Reverse Polish Notation (RPN).
//-1: -1, 0: number, 1: +, 2: -, 3: *, 4: /, 5: ^.
void put(vector<int> v, int pos, int numCounter, int symCounter, int length_) {
  //cout << "put called" << endl;
  if (pos == length_) {
    if (checker(v)) {
      counter++;
      print(v);
    }
    calculation++;
    return;
  }
  int lower = 0;
  int upper = 6;
  if (numCounter == (length_ + 1) / 2) {
    lower = 1;
  }
  if (symCounter == (length_ + 1) / 2 - 1 || symCounter == numCounter - 1) {
    upper = 1;
  }
  while (lower < upper) {
    if (pos == (int) v.size())
      v.push_back(lower);
    else if (pos > (int) v.size())
      cout << "something went wrong" << endl;
    else
      v[pos] = lower;
    if (lower == 0)
      put(v, pos + 1, numCounter + 1, symCounter, length_);
    else
      put(v, pos + 1, numCounter, symCounter + 1, length_);
    lower++;

  }

}

//check if the RPN stored in the array gives the desired result.
bool checker(vector<int> seed) {

  // double a = 1.0, b = 1.0, c = 4.0, d = 5.0, e = 1.0, f = 4.0;
  //cout << "checker called" << endl;
  stack<double> myStack;
  int sign;
  double firstNum, secondNum;
  int numCount = 0;
  for (int i : seed) {
    if (i == 0) {
      myStack.push(base[numCount]);
      numCount++;
    } else if (i == -1) {
      myStack.push(-1 * base[0]);
      numCount++;
    } else {
        sign = i;
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
  // cout << "checker done" << endl;
  if (myStack.top() == desired) {
    return true;
  } else {
    return false;
  }

}

string translate(string input) {
// cout << "translate called" << endl;

  string symbol = "+-*/^";

  stack<string> output;
  string str1;
  string str2;
  string outstr = "";
  for (size_t i = 0; i < input.size(); i++) {
    if (input.at(i) == ' ') {
      continue;
    }
    if ((int)symbol.find(input.at(i)) == -1) {
      string total = "";
      while (input.at(i) != ' ') {
        if (i == 1) {
          if (input.at(i) == '-') {
            total = "-1";
            break;
          }
        }
        total += string(1, input.at(i));
        i++;
      }
      output.push(total);
    } else {
      str2 = output.top();
      output.pop();
      str1 = output.top();
      output.pop();
      if (i == input.size() - 2) {
        output.push(str1 + string(1, input.at(i)) + str2);
      } else {
        output.push("(" + str1 + string(1, input.at(i)) + str2 + ")");
      }
    }
  }
  return output.top();
}

//print RPN.
void print(vector<int> seed) {
  // cout << "print called" << endl;

  int numCount = 0;
  // int i;
  string output = "";
  for (int i : seed) {
    switch (i) {
      case -1: output += to_string((int) base[0]);
               output += "- ";
               numCount++;
               break;
      case 0: output += to_string((int) base[numCount]);
              output += " ";
              numCount++;
              break;
      case 1: output += "+ ";
              break;
      case 2: output += "- ";
              break;
      case 3: output += "* ";
              break;
      case 4: output += "/ ";
              break;
      case 5: output += "^ ";
    }
  }
  //cout << output << endl;
  // cout << std::to_string(desired) + "=" + output << endl;
  cout << std::to_string(desired) + "=" + translate(output) << endl;
}
