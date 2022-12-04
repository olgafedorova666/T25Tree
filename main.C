#include "T25.h"
void main(void)
{  
  TREE *head = NULL;
  int quit = 0, c = 0;
  int n;
  while(!quit)
  {
   // system("cls");
    printf("\n\n0-exit\n"
           "1-AddKey\n"
           "2-Display\n"
           "3-Add\n"
           "4-Remove\n"
           "5-Display2\n"
           "6-Linearize\n"
           "7-BalanceTREE\n\n");
    c =_getch();
    switch(c)
    {
      case '0':
        quit = 1;                              
        break;
      case '1':
        printf("New key: ");
        scanf("%i", &n);
        Access(&head, n);
        break;
      case '2':
        DisplayTREE(head);
        break;
      case '3':
        printf("New key: ");
        scanf("%i", &n);
        Add(&head, n);
        break;
      case '4':
        printf("New key: ");
        scanf("%i", &n);
        Remove(&head, n);
        break;
      case '5':
        Display2(head, 1);
        break;
      case '6':
        Linearize(&head);      
        break;
      case '7':
        BalanceTREE(&head);    
        break;  
    } 
  }
FreeTREE(&head);
MC_Stats();
}