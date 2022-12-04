#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <memcheck.h>
typedef struct tagTREE TREE;
struct tagTREE
{
   int key;
   TREE *left;
   TREE *right;
};
TREE **Access(TREE **T, int x);
void DisplayTREE(TREE *T);
void FreeTREE(TREE **T);
int Add(TREE **T, int x);
int Remove(TREE **T, int x);
void Display2(TREE *T, int h);
void Linearize(TREE **T);
void BalanceTREE(TREE **T);
TREE *GetRoot(TREE *T, int h);
int CountTree(TREE *T);