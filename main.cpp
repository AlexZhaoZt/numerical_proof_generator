#include <iostream>
#include <string>
#include <stack>
#include <array>

#include "main.h"
using std::cout;
using std::endl;


/*
void save(stack<int> saveStack) {

}

stack<int> read(std::string key){
  return NULL;
}
*/
//const int desired_ = 22;
//const int length_ = 12;
int counter = 0;
const double desired = 42.0;

int main() {
/*
  double inParValue = 0;
  int storedValue [5];
  double a = 1.0, b = 1.0, c = 4.0, d = 5.0, e = 1.0, f = 4.0;
  bool resultFound = false;
  stack<int> storedStack [5];
  */



  int array[11]; //= new int[length_];

  array[0] = 0;
  array[1] = 0;
  put(array, 2, 2, 0);
  int newArr[11];
  newArr[0] = -1;
  newArr[1] = 0;
  put(newArr, 2, 2, 0);
  cout << counter;


  return 0;

}
/*
int * seedGenerator() {

}
*/
/*
void boolPut() {
  bool arr [11];
  int num = 0, sym = 0;

  for (int i = 0; i < 11; i++) {

  }

}
*/
void put(int seed[11], int pos, int numCounter, int symCounter) {
  if (pos == 11) {
    //cout << "done" << endl;
    counter++;
    if (checker(seed)) {
      // for (int i = 0; i < 11; i++) {
      //   cout<<seed[i];
      // }
      // cout << endl;
      print(seed);
    }
    return;
  }
  int lower = 0;
  int upper = 5;
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


bool checker(int seed[11]) {
  using std::stack;
  double a = 1.0, b = 1.0, c = 4.0, d = 5.0, e = 1.0, f = 4.0;
  stack<double> myStack;
  int sign;
  double firstNum, secondNum;
  int numCount = 0;
  for (int i = 0; i < 11; i++) {
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
        }
      }
    }
  if (myStack.top() == desired) {
    return true;
  } else {
    return false;
  }

}


void print(int seed[11]) {
  int numCount = 0;
  int i;
  for (int k = 0; k < 11; k++) {
    i = seed[k];
    switch (i) {
      case -1: cout << "-1";
               numCount++;
               break;
      case 0: switch (numCount) {
               case 0: cout << "1";
                       break;
               case 1: cout << "1";
                       break;
               case 2: cout << "4";
                       break;
               case 3: cout << "5";
                       break;
               case 4: cout << "1";
                       break;
               case 5: cout << "4";
                       break;
              }
              numCount++;
              break;
      case 1: cout << "+";
              break;
      case 2: cout << "-";
              break;
      case 3: cout << "*";
              break;
      case 4: cout << "/";
              break;
    }
  }
  cout << endl;
}

/*
void generator(stack<int> * myStack) {

  for (int i = 0; i < 2; i++) {
    stack<int> myStack;
    int counter = 0;
    myStack.push(a);
    counter++;
    switch (i) {
      case 0: storedValue[0] = counter;
              stored = myStack;
              myStack.push(b);
              counter++;
              break;
      case 1: counter = storedValue[0];
              myStack = stored;
              int temp = myStack.top();
              myStack.pop();
              myStack.push(-temp);
              myStack.push(b);
              counter++;
              break;
    }
    for (int j = 0; j < 5; j++) {
      int tempY, tempZ;
      switch (j) {
        case 0: storedValue[1] = counter;
                myStack.push(c);
                counter++;
                break;

        case 1: counter = secondLayer;
                tempY = myStack.top();
                myStack.pop();
                tempZ = myStack.top();
                myStack.pop();
                myStack.push(tempZ + tempY);
                myStack.push(c);
                break;

        case 2: counter = secondLayer;
                tempY = myStack.top();
                myStack.pop();
                tempZ = myStack.top();
                myStack.pop();
                myStack.push(tempZ - tempY);
                myStack.push(c);
                break;

        case 3: counter = secondLayer;
                tempY = myStack.top();
                myStack.pop();
                tempZ = myStack.top();
                myStack.pop();
                myStack.push(tempZ * tempY);
                myStack.push(c);
                break;

        case 4: counter = secondLayer;
                tempY = myStack.top();
                myStack.pop();
                tempZ = myStack.top();
                myStack.pop();
                myStack.push(tempZ / tempY);
                myStack.push(c);
                break;

      }
      for (int k = 0; k < 5; k++) {
        switch (k) {
          case 0: storedValue[2] = counter;
                  myStack.push(d);
                  counter++;
                  break;

          case 1: counter = storedValue[2];
                  tempY = myStack.top();
                  myStack.pop();
                  tempZ = myStack.top();
                  myStack.pop();
                  myStack.push(tempZ + tempY);
                  myStack.push(d);
                  break;

          case 2: counter = storedValue[2];
                  tempY = myStack.top();
                  myStack.pop();
                  tempZ = myStack.top();
                  myStack.pop();
                  myStack.push(tempZ + tempY);
                  myStack.push(d);
                  break;

          case 3: counter = storedValue[2];
                  tempY = myStack.top();
                  myStack.pop();
                  tempZ = myStack.top();
                  myStack.pop();
                  myStack.push(tempZ + tempY);
                  myStack.push(d);
                  break;

          case 4: counter = storedValue[2];
                  tempY = myStack.top();
                  myStack.pop();
                  tempZ = myStack.top();
                  myStack.pop();
                  myStack.push(tempZ + tempY);
                  myStack.push(d);
                  break;

        }
        for (int l = 0; l < 5; l++) {
          switch (l) {
            case 0: storedValue[3] = counter;
                    myStack.push(e);
                    counter++;
                    break;

            case 1: counter = storedValue[3];
                    tempY = myStack.top();
                    myStack.pop();
                    tempZ = myStack.top();
                    myStack.pop();
                    myStack.push(tempZ + tempY);
                    myStack.push(e);
                    break;

            case 2: counter = storedValue[3];
                    tempY = myStack.top();
                    myStack.pop();
                    tempZ = myStack.top();
                    myStack.pop();
                    myStack.push(tempZ + tempY);
                    myStack.push(e);
                    break;

            case 3: counter = storedValue[3];
                    tempY = myStack.top();
                    myStack.pop();
                    tempZ = myStack.top();
                    myStack.pop();
                    myStack.push(tempZ + tempY);
                    myStack.push(e);
                    break;

            case 4: counter = storedValue[3];
                    tempY = myStack.top();
                    myStack.pop();
                    tempZ = myStack.top();
                    myStack.pop();
                    myStack.push(tempZ + tempY);
                    myStack.push(e);
                    break;

          }
          for (int m = 0; m < 5; m++) {
            switch (m) {
              case 0: storedValue[4] = counter;
                      myStack.push(f);
                      counter++;
                      break;

              case 1: counter = storedValue[4];
                      tempY = myStack.top();
                      myStack.pop();
                      tempZ = myStack.top();
                      myStack.pop();
                      myStack.push(tempZ + tempY);
                      myStack.push(f);
                      break;

              case 2: counter = storedValue[4];
                      tempY = myStack.top();
                      myStack.pop();
                      tempZ = myStack.top();
                      myStack.pop();
                      myStack.push(tempZ + tempY);
                      myStack.push(f);
                      break;

              case 3: counter = storedValue[4];
                      tempY = myStack.top();
                      myStack.pop();
                      tempZ = myStack.top();
                      myStack.pop();
                      myStack.push(tempZ + tempY);
                      myStack.push(f);
                      break;

              case 4: counter = storedValue[4];
                      tempY = myStack.top();
                      myStack.pop();
                      tempZ = myStack.top();
                      myStack.pop();
                      myStack.push(tempZ + tempY);
                      myStack.push(f);
                      break;

            }

            //Deal with all the remaining numbers.
            int m = 0;
            int array[counter - 1] = {};
            while(counter > 1) {
                  switch (array[m]) {
                    case 0: tempY = myStack.top();
                            myStack.pop();
                            tempZ = myStack.top();
                            myStack.pop();
                            myStack.push(tempZ + tempY);
                            counter--;
                            array[m]++;
                            break;
                    case 1: tempY = myStack.top();
                            myStack.pop();
                            tempZ = myStack.top();
                            myStack.pop();
                            myStack.push(tempZ - tempY);
                            counter--;
                            array[m]++;
                            break;
                    case 2: tempY = myStack.top();
                            myStack.pop();
                            tempZ = myStack.top();
                            myStack.pop();
                            myStack.push(tempZ * tempY);
                            counter--;
                            array[m]++;
                            break;
                    case 3: tempY = myStack.top();
                            myStack.pop();
                            tempZ = myStack.top();
                            myStack.pop();
                            myStack.push(tempZ / tempY);
                            counter--;
                            array[m]++;
                            break;
                  }
                  m++;
                }


            if (myStack.top() == desired) {
              cout << "Possible solution found" << endl;
            }





            }
          }
        }
      }
    }


}
*/







/*

  for (int i = 0; i < 4; i++) {
    double result = 0;
    int inParFirst = 0;


    if (i == 0) {
      inParValue += a;
      inParFirst = 0;
    }
    if (i == 1) {
      inParValue += a;
      inParFirst = 1;
    }
    if (i == 2) {
      inParValue -= a;
      inParFirst = 0;

    }
    if (i == 3) {
      inParValue -= a;
      inParFirst = 1;

    }

    for (int j = 0; j < 4; j++) {
      if (j == 0) {
        secondLayer = result;
        result += b;
      }
      if (j == 1) {
        result = secondLayer;
        result -= b;
      }
      if (j == 2) {
        result = secondLayer;
        result *= b;

      }
      if (j == 3) {
        result = secondLayer;
        result /= b;

      }

      for (int k = 0; k < 4; k++) {
        int inParThird = 0;
        if (k == 0) {
          storedValue[2] = result;
          result += c;

        }
        if (k == 1) {
          result = storedValue[2];
          result -= c;

        }
        if (k == 2) {
          result = storedValue[2];
          result *= c;


        }
        if (k == 3) {
          result = storedValue[2];
          result /= c;


        }
        for (int x = 0; x < 4; x++) {
          if (x == 0) {
            storedValue[3] = result;
            result += d;

          }
          if (x == 1) {
            result = storedValue[3];
            result -= d;

          }
          if (x == 2) {
            result = storedValue[3];
            result *= d;


          }
          if (x == 3) {
            result = storedValue[3];
            result /= d;


          }
          for (int y = 0; y < 4; y++) {
            if (y == 0) {
              storedValue[4] = result;
              result += e;

            }
            if (y == 1) {
              result = storedValue[4];
              result -= e;

            }
            if (y == 2) {
              result = storedValue[4];
              result *= e;


            }
            if (y == 3) {
              result = storedValue[4];
              result /= e;


            }
            for (int z = 0; z < 4; z++) {
              if (z == 0) {
                sixthLayer = result;
                result += f;

              }
              if (z == 1) {
                result = sixthLayer;
                result -= f;

              }
              if (z == 2) {
                result = sixthLayer;
                result *= f;

              }
              if (z == 3) {
                result = sixthLayer;
                result /= f;


              }
              if (result == desired) {
                string first, second, third, fourth, fifth, sixth;
                if (i == 0) {
                  first = "";
                }
                if (i == 1) {
                  first = "-";
                }

                if (j == 0) {
                  second = "+";
                }
                if (j == 1) {
                  second = "-";
                }
                if (j == 2) {
                  second = "*";
                }
                if (j == 3) {
                  second = "/";
                }

                if (k == 0) {
                  third = "+";
                }
                if (k == 1) {
                  third = "-";
                }
                if (k == 2) {
                  third = "*";
                }
                if (k == 3) {
                  third = "/";
                }

                if (x == 0) {
                  fourth = "+";
                }
                if (x == 1) {
                  fourth = "-";
                }
                if (x == 2) {
                  fourth = "*";
                }
                if (x == 3) {
                  fourth = "/";
                }

                if (y == 0) {
                  fifth = "+";
                }
                if (y == 1) {
                  fifth = "-";
                }
                if (y == 2) {
                  fifth = "*";
                }
                if (y == 3) {
                  fifth = "/";
                }

                if (z == 0) {
                  sixth = "+";
                }
                if (z == 1) {
                  sixth = "-";
                }
                if (z == 2) {
                  sixth = "*";
                }
                if (z == 3) {
                  sixth = "/";
                }

                cout << "Possible solution found: "
                << (
                  ( == 0)
                  ? "("
                  : ""
                )
                << first << "1"
                 << second << "1"
                 << (
                  (endLayer == 2)
                  ? ")"
                  : ""
                )
                << third << "4"
                 << (
                  (endLayer == 3)
                  ? ")"
                  : ""
                )
                << fourth << "5"
                 << (
                  (endLayer == 4)
                  ? ")"
                  : ""
                )
                << fifth << "1"
                << (
                  (endLayer == 5)
                  ? ")"
                  : ""
                )
                << sixth << "4"
                << (
                  (endLayer == 6)
                  ? ")"
                  : ""
                )
                << "  Result : "
                << result
                << endl;



                resultFound = true;
              }
            }

          }

        }

      }

    }
  }
  if (resultFound == false) {
    cout << "Found no solution." << endl;
  }
  return 0;
  */
