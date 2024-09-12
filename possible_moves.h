#include<string>
# include "king_move_check.h"
using namespace std;
int possible_moves(string piece,string ** &p,string ** &q,int player,int x,int y,string *moves)
{
   int i=0;
   if(player==1)
   {
      if(piece[1]=='P')
      {
         if(x==1)
         {
            if(p[x+1][y]=="\0")
            {
               moves[i]+=to_string(x+2);
               moves[i]+=to_string(y+1);
               i++;
               if(p[x+2][y]=="\0")
               {
                  moves[i]+=to_string(x+3);
                  moves[i]+=to_string(y+1);
                  i++;
               }
            }
         }
         else if(x>=2 && x<=6)
         {
            if(p[x+1][y]=="\0")
            {
               moves[i]+=to_string(x+2);
               moves[i]+=to_string(y+1);
               i++;
            }
         }
         if((x+1>=2 && x+1<=7)&&(y-1>=0 && y-1<=7)&&(p[x+1][y-1][0]=='B')&&(p[x+1][y-1]!="BKI"))
         {
            moves[i]+=to_string(x+2);
            moves[i]+=to_string(y);
            i++;
         }
         if((x+1>=2 && x+1<=7)&&(y+1>=0 && y+1<=7)&&(p[x+1][y+1][0]=='B')&&(p[x+1][y-1]!="BKI"))
         {
            moves[i]+=to_string(x+2);
            moves[i]+=to_string(y+2);
            i++;
         }
      }
      else if (piece[1]=='R')
      {
         for(int j=x-1;j>=0;j--)
         {
            if(p[j][y]=="\0")
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(y+1);
               i++;
            }
            else if(p[j][y][0]=='W')
               break;
            else if(p[j][y][0]=='B' && (p[j][y]!="BKI"))
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(y+1);
               i++;
               break;
            }
         }
         for(int j=x+1;j<8;j++)
         {
            if(p[j][y]=="\0")
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(y+1);
               i++;
            }
            else if(p[j][y][0]=='W' )
               break;
            else if(p[j][y][0]=='B' && (p[j][y]!="BKI") )
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(y+1);
               i++;
               break;
            }
         }
         for(int j=y-1;j>=0;j--)
         {
            if(p[x][j]=="\0")
            {
               moves[i]+=to_string(x+1);
               moves[i]+=to_string(j+1);
               i++;
            }
            else if(p[x][j][0]='W' )
               break;
            else if(p[x][j][0]=='B' && (p[x][j]!="BKI"))
            {
               moves[i]+=to_string(x+1);
               moves[i]+=to_string(j+1);
               i++;
               break;
            }
         }
         for(int j=y+1;j<8;j++)
         {
            if(p[x][j]=="\0")
            {
               moves[i]+=to_string(x+1);
               moves[i]+=to_string(j+1);
               i++;
            }
            else if(p[x][j][0]=='W' )
               break;
            else if(p[x][j][0]=='B' && (p[x][j]!="BKI"))
            {
               moves[i]+=to_string(x+1);
               moves[i]+=to_string(j+1);
               i++;
               break;
            }
         }
      }
      else if(piece[1]=='B')
      {
         int j=x-1;
         int k=y-1;
         while((j>=0)&&(k>=0))
         {
            if(p[j][k]=="\0")
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
            else if(p[j][k][0]=='W')
               break;
            else if(p[j][k][0]=='B' && (p[j][k]!="BKI"))
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
               break;
            }
            j-=1;
            k-=1;
         }
         j=x-1;
         k=y+1;
         while((j>=0)&&(k<=7))
         {
            if(p[j][k]=="\0")
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
            else if(p[j][k][0]=='W')
               break;
            else if(p[j][k][0]=='B' && (p[j][k]!="BKI"))
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
               break;
            }
            j-=1;
            k+=1;
         }
         j=x+1;
         k=y-1;
         while((j<=7)&&(k>=0))
         {
            if(p[j][k]=="\0")
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
            else if(p[j][k][0]=='W')
               break;
            else if(p[j][k][0]=='B' && (p[j][k]!="BKI"))
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
               break;
            }
            j+=1;
            k-=1;
         }
         j=x+1;
         k=y+1;
         while((j<=7)&&(k<=7))
         {
            if(p[j][k]=="\0")
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
            else if(p[j][k][0]=='W')
               break;
            else if((p[j][k][0]=='B') && (p[j][k]!="BKI"))
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
               break;
            }
            j+=1;
            k+=1;
         }
      }
      else if(piece[1]=='K' && piece[2]!='I')
      {
         int j=x+2;int k=y+1;
         if((j<=7)&&(k<=7)&&((p[j][k]=="\0")|| (p[j][k][0]!='W') )&& (p[j][k]!="BKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+2;k=y-1;
         if((j<=7)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-2;k=y-1;
         if((j>=0)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-2;k=y+1;
         if((j>=0)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y-2;
         if((j<=7)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y+2;
         if((j<=7)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-1;k=y-2;
         if((j>=0)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-1;k=y+2;
         if((j>=0)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
      }
      else if(piece[1]=='K' && piece[2]=='I')
      {
         int temp=0;
         int j=x-1;int k=y-1;
         if((j>=0)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x-1;k=y;
         if((j>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI") && (p[j][k]!="BKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x-1;k=y+1;
         if((j>=0)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x;k=y-1;
         if((k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x;k=y+1;
         if((k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x+1;k=y-1;
         if((j<=7)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x+1;k=y;
         if((j<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x+1;k=y+1;
         if((j<=7)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')) && (p[j][k]!="BKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
      }
      else if(piece[1]=='Q')
      {
        int count=1,j,k;
        while(count<9)
        {
           switch(count)
           {
                case 1: j=x+1;
                        k=y;
                        break;
                case 2: j=x-1;
                        k=y;
                        break;
                case 3: j=x;
                        k=y+1;
                        break;
                case 4: j=x;
                        k=y-1;
                        break;
                case 5: j=x+1;
                        k=y+1;
                        break;
                case 6: j=x+1;
                        k=y-1;
                        break;
                case 7: j=x-1;
                        k=y+1;
                        break;
                case 8: j=x-1;
                        k=y-1;
                        break;
                default:break;
           }
           while((j>=0 && j<=7) && (k>=0 && k<=7))
           {
                if(p[j][k]=="\0")
                {
                        moves[i]+=to_string(j+1);
                        moves[i]+=to_string(k+1);
                        i++;
                }
                else if(p[j][k][0]=='W')
                        break;
                else if(p[j][k][0]=='B'  && (p[j][k]!="BKI"))
                {
                        moves[i]+=to_string(j+1);
                        moves[i]+=to_string(k+1);
                        i++;
                        break;
                }
                switch(count)
                {
                case 1: j++;
                        break;
                case 2: j--;
                        break;
                case 3: k++;
                        break;
                case 4: k--;
                        break;
                case 5: j++;
                        k++;
                        break;
                case 6: j++;
                        k--;
                        break;
                case 7: j--;
                        k++;
                        break;
                case 8: j--;
                        k--;
                        break;
                default:break;
                }
           }
           count++;
        }
      }
   }
   else
   {
      if(piece[1]=='P')
      {
         if(x==6)
         {
            if(p[x-1][y]=="\0")
            {
               moves[i]+=to_string(x);
               moves[i]+=to_string(y+1);
               i++;
               if(p[x-2][y]=="\0")
               {
                  moves[i]+=to_string(x-1);
                  moves[i]+=to_string(y+1);
                  i++;
               }
            }
         }
         else if(x>=1 && x<=5)
         {
            if(p[x-1][y]=="\0")
            {
               moves[i]+=to_string(x);
               moves[i]+=to_string(y+1);
               i++;
            }
         }
         if((x-1>=0 && x-1<=7)&&(y-1>=0 && y-1<=7)&&(p[x-1][y-1][0]=='W') && (p[x-1][y-1]!="WKI"))
         {
            moves[i]+=to_string(x);
            moves[i]+=to_string(y);
            i++;
         }
         if((x-1>=0 && x-1<=7)&&(y+1>=0 && y+1<=7)&&(p[x-1][y+1][0]=='W') && (p[x-1][y+1]!="WKI"))
         {
            moves[i]+=to_string(x);
            moves[i]+=to_string(y+2);
            i++;
         }
      }
      else if(piece[1]=='R')
      {
         for(int j=x-1;j>=0;j--)
         {
            if(p[j][y]=="\0")
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(y+1);
               i++;
            }
            else if(p[j][y][0]=='B' )
               break;
            else if(p[j][y][0]=='W' && (p[j][y]!="WKI") )
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(y+1);
               i++;
               break;
            }
         }
         for(int j=x+1;j<8;j++)
         {
            if(p[j][y]=="\0")
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(y+1);
               i++;
            }
            else if(p[j][y][0]=='B' )
               break;
            else if(p[j][y][0]=='W' && (p[j][y]!="WKI") )
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(y+1);
               i++;
               break;
            }
         }
         for(int j=y-1;j>=0;j--)
         {
            if(p[x][j]=="\0")
            {
               moves[i]+=to_string(x+1);
               moves[i]+=to_string(j+1);
               i++;
            }
            else if(p[x][j][0]=='B' )
               break;
            else if(p[x][j][0]=='W' && (p[x][j]!="WKI"))
            {
               moves[i]+=to_string(x+1);
               moves[i]+=to_string(j+1);
               i++;
               break;
            }
         }
         for(int j=y+1;j<8;j++)
         {
            if(p[x][j]=="\0")
            {
               moves[i]+=to_string(x+1);
               moves[i]+=to_string(j+1);
               i++;
            }
            else if(p[x][j][0]=='B' )
               break;
            else if(p[x][j][0]=='W' && (p[x][j]!="WKI"))
            {
               moves[i]+=to_string(x+1);
               moves[i]+=to_string(j+1);
               i++;
               break;
            }
         }
      }
      else if(piece[1]=='B')
      {
         int j=x-1;
         int k=y-1;
         while((j>=0)&&(k>=0))
         {
            if(p[j][k]=="\0")
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
            else if(p[j][k][0]=='B')
               break;
            else if(p[j][k][0]=='W' && (p[j][k]!="WKI"))
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
               break;
            }
            j-=1;
            k-=1;
         }
         j=x-1;
         k=y+1;
         while((j>=0)&&(k<=7))
         {
            if(p[j][k]=="\0" /*&& q[j][k]=="\0"*/)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
            else if(p[j][k][0]=='B')
               break;
            else if(p[j][k][0]=='W' && (p[j][k]!="WKI"))
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
               break;
            }
            j-=1;
            k+=1;
         }
         j=x+1;
         k=y-1;
         while((j<=7)&&(k>=0))
         {
            if(p[j][k]=="\0" /*&& q[j][k]=="\0"*/)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
            else if(p[j][k][0]=='B')
               break;
            else if(p[j][k][0]=='W' && (p[j][k]!="WKI"))
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
               break;
            }
            j+=1;
            k-=1;
         }
         j=x+1;
         k=y+1;
         while((j<=7)&&(k<=7))
         {
            if(p[j][k]=="\0" /*&& q[j][k]=="\0"*/)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
            else if(p[j][k][0]=='B')
               break;
            else if(p[j][k][0]=='W' && (p[j][k]!="WKI"))
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
               break;
            }
            j+=1;
            k+=1;
         }
      }
      else if(piece[1]=='K' && piece[2]!='I')
      {
         int j=x+2;int k=y+1;
         if((j<=7)&&(k<=7)&&((p[j][k]=="\0")||(p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+2;k=y-1;
         if((j<=7)&&(k>=0)&&((p[j][k]=="\0")||(p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-2;k=y-1;
         if((j>=0)&&(k>=0)&&((p[j][k]=="\0")||(p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-2;k=y+1;
         if((j>=0)&&(k<=7)&&((p[j][k]=="\0")||(p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y-2;
         if((j<=7)&&(k>=0)&&((p[j][k]=="\0")||(p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y+2;
         if((j<=7)&&(k<=7)&&((p[j][k]=="\0")||(p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-1;k=y-2;
         if((j>=0)&&(k>=0)&&((p[j][k]=="\0")||(p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-1;k=y+2;
         if((j>=0)&&(k<=7)&&((p[j][k]=="\0")||(p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }

      }
      else if(piece[1]=='K' && piece[2]=='I')
      {
         int j=x-1;int k=y-1;
         int temp=0;
         if((j>=0)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x-1;k=y;
         if((j>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x-1;k=y+1;
         if((j>=0)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x;k=y-1;
         if((k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x;k=y+1;
         if((k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x+1;k=y-1;
         if((j<=7)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x+1;k=y;
         if((j<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
         j=x+1;k=y+1;
         if((j<=7)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='W')) && (p[j][k]!="WKI"))
         {
            temp=king_move_check(p,j,k,player);
            if(temp==0)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
            }
         }
      }
      else if(piece[1]=='Q')
      {
        int count=1,j=-1,k=-1;
        while(count<9)
        {
           switch(count)
           {
                case 1: j=x+1;
                        k=y;
                        break;
                case 2: j=x-1;
                        k=y;
                        break;
                case 3: j=x;
                        k=y+1;
                        break;
                case 4: j=x;
                        k=y-1;
                        break;
                case 5: j=x+1;
                        k=y+1;
                        break;
                case 6: j=x+1;
                        k=y-1;
                        break;
                case 7: j=x-1;
                        k=y+1;
                        break;
                case 8: j=x-1;
                        k=y-1;
                        break;
                default:break;
           }
           while((j>=0 && j<=7) && (k>=0 && k<=7))
           {
                if(p[j][k]=="\0")
                {
                        moves[i]+=to_string(j+1);
                        moves[i]+=to_string(k+1);
                        i++;
                }
                else if(p[j][k][0]=='B')
                        break;
                else if(p[j][k][0]=='W' && (p[j][k]!="WKI"))
                {
                        moves[i]+=to_string(j+1);
                        moves[i]+=to_string(k+1);
                        i++;
                        break;
                }
                switch(count)
                {
                case 1: j++;
                        break;
                case 2: j--;
                        break;
                case 3: k++;
                        break;
                case 4: k--;
                        break;
                case 5: j++;
                        k++;
                        break;
                case 6: j++;
                        k--;
                        break;
                case 7: j--;
                        k++;
                        break;
                case 8: j--;
                        k--;
                        break;
                default:break;
                }
           }
           count++;
        }
      }
   }
   return i;
}


