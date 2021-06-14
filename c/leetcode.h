#include <stdbool.h>

int myAtoi(char * s);
bool isPalindrome(int x);
bool isMatch(char * s, char * p);

typedef struct{
    int num_nodes;
    char *graph;
    int status;
} pattern;

pattern * pattern_compile(char * p);
char * ReversePolishNotation(char * s);
