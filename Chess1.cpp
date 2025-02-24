# include <iostream>
# include <string>
# include <iomanip>
using namespace std;
// Player 1 and Player 2 passed by reference
// Player 1 will play as White and Player 2 will play as Black
// all xs' and ys' are indices of the matrix (chessboard), they are in the range of 0 to 7 both inclusive
void assign(string ** &p1,string ** &p2)
{
   string a[8]={"WR1","WK1","WB1","WKI","WQ","WB2","WK2","WR2"};
   string c[8]={"BR1","BK1","BB1","BKI","BQ","BB2","BK2","BR2"};
   string b[8]={"1","2","3","4","5","6","7","8"};
   for(int i=0;i<8;i++)
   {
      p1[1][i]="WP"+b[i];
      p1[6][i]="BP"+b[i];
      p1[0][i]=a[i];
      p1[7][i]=c[i];
   }
}

//Printing the chess board in the console 
void display( string ** p, string ** q,int player)
{
   string **r=new string *[8];
   int num=0;
   for(int i=0;i<8;i++)
      r[i]=new string[8];
   for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
           if(p[i][j]!="\0")
                r[i][j]=p[i][j];
           else
                r[i][j]==" ";
        }
   cout<<left<<setfill('-')<<setw(82)<<"-"<<endl;
   while(num<9)
    {
        cout<<setfill(' ')<<'|';
        cout<<setw(8)<<num++;
    }
   cout<<'|'<<endl<<left<<setfill('-')<<setw(82)<<"-"<<endl;
   for(int i=0;i<8;i++)
   {
      cout<<setfill(' ')<<"|"<<setw(8)<<i+1<<'|';
      for(int j=0;j<8;j++)
         cout<<setw(8)<<r[i][j]<<"|";
      cout<<endl;
      cout<<left<<setfill('-')<<setw(82)<<"-"<<endl;
   }
   for(int i=0;i<8;i++)
      delete []r[i];
   delete []r;
}

//Function Overloading 'string b' is extra over here!
//i - player
//a - the piece to be searched for and set to null since it is captured by the oponent
//b - the piece to be moved to the location (x,y)
//Assumption to be confirmed is that a is replaced by b
void update(int i,string **&p,string **&q,string a,string b,int x,int y)
{
   //cout<<a<<endl;
      int j,k,count=0;
      for(j=0;j<8;j++)
      {
          for(k=0;k<8;k++)
          {
             if(p[j][k]==a)
              {
                p[j][k]="\0";
              }
          }
      }
      p[x-1][y-1]=b;
}

//Function Overloading 'string b' is not here
//The piece - a is moving to the location (x,y)
void update(int i,string **&p,string **&q,string a,int x,int y)
{
      int j,k,count=0;
      for(j=0;j<8;j++)
      {
          for(k=0;k<8;k++)
          {
             if(p[j][k]==a)
              {
                p[j][k]="\0";
              }
          }
      }
       p[x-1][y-1]=a;
}

//a is the piece and p is the player. x1 and y1 are passed by reference to get the current position
void cur_pos(string a,string **p,int i,int &x1,int &y1)
{
      for(int i=0;i<8;i++)
      {
         for(int j=0;j<8;j++)
         {
            if(p[i][j]==a)
            {
               x1=i;
               y1=j;
            }
         }
      }
}

//Prints the possible moves given all the moves in m and number of elements as n
void print_moves(string *m,int n)
{
   cout<<"The possible moves for the piece are :\n";
   for(int i=0;i<n;i++)
   {
      string h=m[i];
      cout<<"("<<h[0]<<","<<h[1]<<")"<<endl;
   }
}

//Checks whether the move entered by the user is valid
int movecheck(int x,int y,string *m,int n)
{
   string coordinate="\0";
   coordinate+=to_string(x);
   coordinate+=to_string(y);
   for(int i=0;i<n;i++)
   {
      if(coordinate==m[i])
         return 1;
   }
   return 0;
}

//moves is passed by reference 
int possible_moves_check(string piece,string *&moves,string **checkstop)
{
   int j=1,k=0;
   for(int i=0;i<16;i++)
   {
      if(checkstop[i][0]==piece)
      {
         while(checkstop[i][j]!="\0")
         {
            moves[k++]=checkstop[i][j++];
         }
         break;
      }
   }
   return k;
}

# include "possible_moves_k.h"
# include "possible_moves.h"
# include "check.h"
#include "checkmate.h"
#include"future_check.h"
int main()
{
   string **p1=new string * [8];
   string **p2=new string * [8];
   for(int i=0;i<8;i++)
   {
      p1[i]=new string[8];
      p2[i]=new string[8];
   }
   int check1=0,check2=0,illegal=0,checkm=0,count=1;
   string temp,b;
   char dup;
   assign(p1,p2);
   do
   {
      for(int i=1;i<3;i++)
      {
         string a;
         int x1,y1,x2,y2,z,no_moves=0;
         if(count==0)
         {
            p1[6][2]="\0";

            count++;
         }
         display(p1,p2,i);
         string **checkstop=new string*[16];
         for(int j=0;j<16;j++)
            checkstop[j]=new string[40];
         string *mov=new string[40];
         temp=check(p1,p2,i);
         if(temp[2]!='0')
         {
                checkm=checkmate(p1,i,checkstop);
                if(checkm==1)
                {
                     cout<<"Checkmate";
                     cout<<"\nPlayer "<<(i==1?2:1)<<" wins the game.";
                     return 0;
                }
                cout<<"Player "<<i<<" Check your King\n";
         }
         cout<<"Player "<<i<<" 's turn:\n";
        while(1)
        {
         if(i==1)
         {
           do
           {
                cout<<"Enter a valid WHITE piece that you wish to move :";
                cin>>a;
           }while(a!="WR1" && a!="WK1" && a!="WB1" && a!="WQ"  && a!="WKI" && a!="WB2" && a!="WK2" && a!="WR2" &&
                  a!="WP1" && a!="WP2" && a!="WP3" && a!="WP4" && a!="WP5" && a!="WP6" && a!="WP7" && a!="WP8" );
         }
         else
         {
           do
           {
                cout<<"Enter a valid BLACK piece that you wish to move : ";
                cin>>a;
           }while(a!="BR1" && a!="BK1" && a!="BB1" && a!="BQ"  && a!="BKI" && a!="BB2" && a!="BK2" && a!="BR2" &&
                  a!="BP1" && a!="BP2" && a!="BP3" && a!="BP4" && a!="BP5" && a!="BP6" && a!="BP7" && a!="BP8" );
         }
          string *moves=new string[40];
         if(temp[2]=='0')
         {
            cur_pos(a,p1,i,x1,y1);
            no_moves=possible_moves(a,p1,p2,i,x1,y1,moves);
         }
         else
         {
            no_moves=possible_moves_check(a,moves,checkstop);
         }
         if(no_moves>0)
         {
              future_check(p1,a,moves,no_moves,i);
         }
         if(no_moves<=0)
         {
            cout<<"You can't move that piece Please select any other piece.\n";
            delete []moves;
            continue;
         }
         else
         {
            for(int l=0;l<no_moves;l++)
               mov[l]=moves[l];
            print_moves(mov,no_moves);
            delete []moves;
            break;
         }
         }
         while(no_moves>0)
         {
            cout<<"Enter a correct location where the piece is to be moved (row,column) , (from the above stated possible moves) :-\n";
            do
            {
               cout<<"Enter a valid row (1 to 8)   : ";
               cin>>x2;
               if(cin.fail())
               {
                  cin.clear();
                  cin.ignore(100,'\n');
                  continue;
               }
            } while (x2<1 || x2>8);
            do
            {
               cout<<"Enter a valid column (1 to 8): ";
               cin>>y2;
               if(cin.fail())
               {
                  cin.clear();
                  cin.ignore(100,'\n');
                  continue;
               }
            } while (y2<1 || y2>8);
            z=movecheck(x2,y2,mov,no_moves);
            if(z==0)
            {
               cout<<"Invalid move...\n";
               cout<<"Enter again :-\n";
               continue;
            }
            else
            {
               delete [] mov;
               for(int bin=0;bin<16;bin++)
                   delete [] checkstop[bin];
               delete [] checkstop;
               break;
            }
         }
         while(a[1]=='P' && (x2==1 || x2==8))
         {
               cout<<"Since you have successfully moved your Pawn to other player's last row ,\n";
               cout<<"You can change your pawn to any other powerful piece.\n";
               do
               {
                  cout<<"Do you want to replace your Pawn ? [y/n] : ";
                  cin>>dup;
               } while (dup!='n' && dup!='y');
               if(dup=='n')
                  break;
               dup=a[0];
               do
               {
                  cout<<"Enter any powerful piece other than : King and oponent's pieces to which you want to change your Pawn : ";
                  cin>>b;
               }while(b[2]=='I' || (dup=='W' && b[0]=='B') || (dup=='B' && b[0]=='W'));
               update(i,p1,p2,a,b,x2,y2);
               z=0;
               break;
         }
         if(z!=0)
         {
               update(i,p1,p2,a,x2,y2);
         }
      }
   }while(1);
}
//Populated the code with comments