#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "customArr.h"

const std::string MENU = "1. Find value\n2. Modify value\n3. Append value\n4. Remove value\n5. Print array\n6. Quit";

int getInput(int range);

template <typename T>
customArr<T> import(std::string & fname);

void printArray(const customArr<int>& arr);
