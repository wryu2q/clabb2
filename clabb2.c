#include <stdio.h>
#include <stdlib.h>
#include "extension.h"



void main () {
  int ins = 0 ;//antalet input siffror
  int max = 500 ;// max antal input siffror
  int input ;//input talet i ascii
  node *p_node=NULL ;//nasta/sista nod som allt eftersom andras
  node *p_old = NULL ;//den forra listan som matades in
  node *p_sum ; //temprär variabel när två tal sumeras
  FILE *file  ;//pekar på filen vi ska spara på/öpna
  printf("Hej och valkommen!\n");
  printf("Detta program summerar stora positiva heltal som kan besta av max %d siffror.\n",max);
  printf("\nange ett tal:" );

  while ((input= getchar()) != EOF ){ //loopen för input
    if ('0' <= input && input <= '9' && ins<max){//ett tal ska matas in 
      p_node =link_node( (input - '0'), p_node) ;
      ins++;
      }
    else if (input =='\n'){//tal har matats in
      ins =0 ;
      if (p_old == NULL) {
        printf("Ange ett annat tal:");
        p_old = p_node ;
        p_node = NULL ;
        }
      else {//man ska summera två inmattade tal
        p_sum=add_lists(p_old , p_node,NULL,0);//summan
        p_node=reverse_list (NULL,p_node);//man vill reversa för korrekt print
        p_old= reverse_list (NULL,p_old);

        printf("Summan av " );
        print_list(p_old) ;
        printf(" och " );
        print_list(p_node) ;
        printf(" blir " );
        print_list(p_sum) ;

        free_list(p_node) ;//vi vill döda gammla eftersom vi inte vill läcka minne
        free_list(p_old) ;

        printf("\n\nAnge ett annat tal (eller avsluta med Ctrl-d):" );
        p_old =reverse_list(NULL,p_sum) ;//vi vill att suman nu ska reperesentera gammal nod
        p_node=NULL;//vi har inte matat in nya tal än
        }
      }
    else if (ins >= max )//om man redan matatin massa tal ska man helt enkelt ignorera de senaste
      continue ;
    else
      break ;
  }
  
  //för att komma hit borde man ha tryckt på ctrl-d/EOF alltså ska vi spara
  
  p_old = reverse_list(NULL,p_old ) ;//för print och spara i rätt ordning
  file = fopen ("resultat.txt", "a");//filen som sparar talet
  fputc ( '\n' , file) ;//vi vill att talen ska ha egne rader
  save_list (p_old , file ) ;
  fclose (file ) ;
  printf("\nTalet ") ;
  print_list(p_old) ;
  printf (" har nu skrivits i filen resulat.txt\n") ;
  free_list (p_old) ;

}
