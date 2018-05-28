#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>
#include <map>
#include <utility>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <queue>

	#ifdef _WIN32
		#define OS 1
	#elif defined(_WIN64)
		#define OS 2
	#else
		#define OS 0
	#endif

using namespace std;

extern const char * clear;

class Utils{

public:

	static void printFlags();
	static void UP(string&);
	static void UP(char*);
	static void menu();


};

#endif
