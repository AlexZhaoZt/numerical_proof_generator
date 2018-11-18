#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <array>
#include <queue>
#include <cmath>
#include <vector>
using std::queue;
using std::vector;
using std::pow;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::stack;
using std::stoi;

void put(vector<int> v, int pos, int numCounter, int symCounter, int length_);
void put(vector<int> v, int max_length);
bool checker(vector<int> seed);
void print(vector<int> seed);
string translate(string input);
void choose(queue<char> remain, vector<double> current);
void strongProof();
void weakProof();
