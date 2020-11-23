#include <stdio.h>
/*6 Passeggiate aleatorie
Scrivete un programma che generi una ?passeggiata aleatoria? (in inglese random walk in un array bidimensionale di dimensione 10×10.
 L?array sarà riempito di caratteri (inizialmente da punti). Il programma dovrà muoversi
di elemento in elemento spostandosi ogni volta di un passo in direzione su, giù, destra o sinistra. Gli elementi
visitati andranno etichettati con le lettere dalla A alla Z, nell?ordine in cui vengono visitati. E? importante controllare ad ogni passo che
la passeggiata non esca dall?array e che non ritorni su posizioni già visitate. Quando si verifica una di queste condizioni, provate in altre direzioni.
Se tutte e quattro le direzioni sono bloccate, il programma deve uscire.*/

#include<stdlib.h>
#include<time.h>

#define R 10
#define C 10

int main (void)
{
  int pa[R][C];
  int r=0,c=0;
  int d,uscita=0;
  char valprossimo;
  //inizializzo la matrice con  .
  for(r=0;r<R;r++)
  {
    for (c=0;c<C;c++)
      pa[r][c]='.';
  }
  r=0,c=0;
  //inserisco il primo valore
  valprossimo='A';
  pa[r][c]=valprossimo;
  //
  valprossimo++;
  srand(time(NULL));
  printf ("Direzioni:",d);
  for(;;) {

    if (uscita==0 && valprossimo<='Z'){
      d=rand()%4;
      printf ("%d-",d);//1) chiedo una direzione a caso (1=SU;2=GIU; 3=DX; 4=SX)
      switch (d)
      {
          case 0: //SU
            if(r==0) // se sono nella righa zero non posso salire
              continue;
            else// Controllo se le caselle sono libere
            {
              if(pa[r-1][c]=='.') //vuol dire che è libera
                {
                  pa[r-1][c]=valprossimo++;
                  r=r-1;
                }
              else
                if((pa[r-1][c]!='.' || r==0) && (pa[r+1][c]!='.'|| r==9)
                   && (pa[r][c+1]!='.'|| c==9) && (pa[r][c-1]!='.'|| c==0))
                   uscita=1;
                else continue;
            }
            break;
          case 1://GIU
            if(r==9)
              continue;
            else
            {
              if(pa[r+1][c]=='.')
                {
                  pa[r+1][c]=valprossimo++;
                  r=r+1;
                }
              else
                if((pa[r-1][c]!='.' || r==0) && (pa[r+1][c]!='.'|| r==9)
                   && (pa[r][c+1]!='.'|| c==9) && (pa[r][c-1]!='.'|| c==0))
                   uscita=1;
                else continue;
            }
            break;
          case 2 ://DX
            if(c==9)
              continue;
            else
            {
              if(pa[r][c+1]=='.')
                {
                  pa[r][c+1]=valprossimo++;
                  c=c+1;
                }
              else
                if((pa[r-1][c]!='.' || r==0) && (pa[r+1][c]!='.'|| r==9)
                   && (pa[r][c+1]!='.'|| c==9) && (pa[r][c-1]!='.'|| c==0))
                   uscita=1;
                else continue;
            }
            break;
          default:
            if(c==0)
              continue;
            else
            {
              if(pa[r][c-1]=='.')
                {
                  pa[r][c-1]=valprossimo++;
                  c=c-1;
                }
              else
                if((pa[r-1][c]!='.' || r==0) && (pa[r+1][c]!='.'|| r==9)
                   && (pa[r][c+1]!='.'|| c==9) && (pa[r][c-1]!='.'|| c==0))
                   uscita=1;
                else continue;
            }
            break;
      }
    }else break;
  }

  printf("\n");
  for(r=0;r<R;r++)
  {
    for (c=0;c<C;c++)
      printf("|%c|",pa[r][c]);
    printf("\n");
  }
  return 0;
}
