/**
Common Headers used for all the files
as well as the Global Variables Used across files
*/
#include <iostream>
#include<stdio.h>
#include <string.h>
#include <stack>
#include<math.h>
///Maximum size of a Binary tree
#define Z 1000005
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
///The 2D array that stores all the Binary trees of the rules
char D2[1000][Z];
///The global binary tree used by the Binary Tree function
char heap[Z];
///The stack used to store the postfix of an input string
stack <char> ans;
///Stack used exclusively in the postfix function
stack <char> op;
///Stack used exclusively in the postfix fuction
stack <char> in;
///The maximum length checked in 2 power by the MatchTree function
int height = 15;
