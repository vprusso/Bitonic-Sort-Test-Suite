/*
Resources.h:
	Contains various include libraries / namespaces.
*/
#ifndef RESOURCES
#define RESOURCES


/*STL Libraries*/
#include <vector>																//STL vector class.
#include <cmath>																//Various math functions.
#include <string>																//String manipulations
#include <iostream>																//I/O.
#include <algorithm>															//Various algorithms
#include <ctime>																//Timing program execution
#include <iterator>																//Iterate through STL containers.
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>																//Text file I/O.
#include <queue>

/*Namespaces*/
using namespace std;

/*Macros*/
typedef vector<int> vi;															//Shorthand int vector.
typedef vector<vi> vvi;															//Shorthand int 2d vector.
typedef pair<int,int> ii;														//Shorthand for pair.
#define sz(a) int((a).size())													//Returns size of any STL container.
#define pb push_back															//Shorthand for push_back.
#define all(c) (c).begin(),(c).end()											//STL container shorthand from beg to end.
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)	//Allows traversal of any STL container (not just vec).
#define present(c,x) ((c).find(x) != (c).end())									//Map/Set/etc.: checks if element exists.
#define cpresent(c,x) (find(all(c),x) != (c).end())								//Vector: checks if element exists.

#endif