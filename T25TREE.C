#include "T25.h"
TREE **Access(TREE **T, int x)
{ 
  TREE *newEl;
  while (*T != NULL)
  {
    if ((*T)->key == x)
      return T;   
    else if ((*T)->key > x)
      T = &(*T)->left;
    else
      T = &(*T)->right;
   }
   newEl = malloc(sizeof(TREE));  
   if (newEl == NULL)
   {
     printf("Error");
     return 0;
   }
   newEl->key = x;
   newEl->left = NULL;
   newEl->right = NULL;
   *T = newEl;
   free(newEl);
   return T;
}
/*TREE **Access(TREE **T, int x)
{
  if (*T == NULL)
  {
     TREE *newEl = malloc(sizeof(TREE));
     newEl->key = x;
     newEl->left = NULL;
     newEl->right = NULL;
     *T = newEl;
     free(newEl);
     return T;
  }
  else
    if ((*T)->key == x)
    return T;
  else if((*T)->key < x)
    return Access(&(*T)->right, x);
  else
    return Access(&(*T)->left, x);
  
} */

void DisplayTREE(TREE *T)
{
  if (T == NULL)
    return;
  printf("(");
  DisplayTREE(T->left);
  printf("%i", T->key);
  DisplayTREE(T->right);
  printf(")");
}

void FreeTREE(TREE **T)
{
  if (*T == NULL)
    return;
  FreeTREE(&(*T)->left);
  FreeTREE(&(*T)->right);   
  *T = NULL;
}

int Add(TREE **T, int x)
{
  TREE *newEl;
  while (*T != NULL)
  {
    if ((*T)->key > x)
      T = &(*T)->left;
    else
      T = &(*T)->right;
  }
  //if (*T == NULL)
    //return 0;
  newEl = malloc(sizeof(TREE));
  if(newEl == NULL)
   {
     printf("Error");
     return 0;
   }
   newEl->key = x;
   newEl->left = NULL;
   newEl->right = NULL;
   *T = newEl;
   return 1;
} 
                                                     
int Remove(TREE **T, int x)
{
  TREE *E;
  while (*T != NULL)
  {
    if ((*T)->key == x)
      break;
    else if ((*T)->key > x)
      T = &(*T)->left;
    else
      T = &(*T)->right;
  }
  if (*T == NULL)
    return 0;
  E = *T;
  *T = (*T)->right;
  while (*T != NULL)
    T = &(*T)->left;
  *T = E->left; 
  free(E);
  return 1;  
}


void Display2(TREE *T, int h)
{
  if (T != NULL)
  if (T->right != NULL)
  {
    Display2(T->right, h + 1);
  }
  printf("%*i\n", 3 * h , T->key);
  if (T->left != NULL)
  {
    Display2(T->left, h + 1);
  }
} 

void Linearize(TREE **T)
{
  TREE *head;
  if (*T == NULL)
    return;
  Linearize(&(*T)->left);
  Linearize(&(*T)->right);
  if ((*T)->left == NULL)
    return;
  head = *T;
  *T = (*T)->left; 
  head->left = NULL;
  while (*T != NULL)
    T = &(*T)->right;
  *T = head;  
}

int CountTree(TREE *T)
{
  int sum = 0;
  for ( ; T != NULL; sum++)
    T = T->right;
  return sum;
}

TREE *GetRoot(TREE *T, int h)
{
  while (h-- >= 1)
    T = T->right;
  return T;
}
void BalanceTREE(TREE **T)
{
  TREE *root = NULL;
  int h = 0;
  if(*T == NULL || (*T)->right == NULL)
    return; 
  root = *T;
  h = CountTree(*T) / 2;  
  *T = GetRoot(*T, h);
  (*T)->left = root;
  while (root->right != *T)
    root = root->right;
  root->right = NULL;
  BalanceTREE(&(*T)->left);
  BalanceTREE(&(*T)->right);

}    