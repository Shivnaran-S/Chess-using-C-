#include<string>
using namespace std;
// For user readability the moves array will be having the coordinates of the locations from 1 to 8
// Comments are written with the assumption that the chessboard printed such that the white is printed at the bottom and the down left most piece's index is 0,0
// While reading the comments, make yourself conscious that x represents the rows and y represents the columns in the form of a matrix but one thing to note is that the matrix indexing starts from the left down corner
/*
* Function : possible_moves_k
* Description : Updates the moves array with all the possible moves of the piece(passed as an argument) using the current state which is in p
* Parameters:
*     - string piece : piece for which we need to find the possible moves
*     - string p     : current state of the chessboard populated with pieces
*     - string q     : ignore
*     - int player   : color of the piece = { if(player==1) White; else Black; } 
*     - int x        : x coordinate of the piece in p
*     - int y        : y coordinate of the piece in p
*     - string moves : array which stors the possible moves of piece
* Returns:
*     - int : Number of elements/ moves in the array moves 
*/
int possible_moves_k(string piece,string ** &p,string ** &q,int player,int x,int y,string *moves)
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
            if(p[x+1][y]=="\0"/* && q[x+1][y]=="\0"*/)
            {
               moves[i]+=to_string(x+2);
               moves[i]+=to_string(y+1);
               i++;
            }
         }
         if((x+1>=2 && x+1<=7)&&(y-1>=0 && y-1<=7)&&(p[x+1][y-1][0]=='B'))
         {
            moves[i]+=to_string(x+2);
            moves[i]+=to_string(y);
            i++;
         }
         if((x+1>=2 && x+1<=7)&&(y+1>=0 && y+1<=7)&&(p[x+1][y+1][0]=='B'))
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
            if(p[j][y]=="\0" /*&& q[j][y]=="\0"*/)
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(y+1);
               i++;
            }
            else if(p[j][y][0]=='W')
               break;
            else if(p[j][y][0]=='B' )
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
            else if(p[j][y][0]=='B' )
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
            else if(p[x][j][0]=='B' )
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
            else if(p[x][j][0]=='B' )
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
            else if(p[j][k][0]=='B')
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
            else if(p[j][k][0]=='B')
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
            else if(p[j][k][0]=='B')
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
            else if(p[j][k][0]=='B')
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
         if((j<=7)&&(k<=7)&&(p[j][k]=="\0")&& (p[j][k][0]!='W'))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+2;k=y-1;
         if((j<=7)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-2;k=y-1;
         if((j>=0)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-2;k=y+1;
         if((j>=0)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y-2;
         if((j<=7)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y+2;
         if((j<=7)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-1;k=y-2;
         if((j>=0)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-1;k=y+2;
         if((j>=0)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
      }
      else if(piece[1]=='K' && piece[2]=='I')
      {
         int j=x-1;int k=y-1;
         if((j>=0)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-1;k=y;
         if((j>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-1;k=y+1;
         if((j>=0)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x;k=y-1;
         if((k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x;k=y+1;
         if((k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y-1;
         if((j<=7)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y;
         if((j<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y+1;
         if((j<=7)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='B')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
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
                else if(p[j][k][0]=='B')
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
   else  // player = 2, the player is playing as white but have passed the variable player by setting it to 2, to get the possible moves of the black coins and to move the White king to a position that is not present in the moves array
   {
      // Pawn
      if(piece[1]=='P')  
      {
         if(x==6)  // If pawn has not moved yet, it can either move one step or two steps forward
         {
            if(p[x-1][y]=="\0")  // Checking whether the piece could move forward/ (down - according to the standard board commented in the starting)
            {
               moves[i]+=to_string(x);    // for player readability the index x-1 is stored as x itself 
               moves[i]+=to_string(y+1);  // for user readability the indices are stored after incrementing
               i++;  // One element has been inserted into the moves array 
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
         // Checking whether the pawn could capture any of the white pieces so that, that move could be added to the moves array
         if((x-1>=0 && x-1<=7)&&(y-1>=0 && y-1<=7)&&(p[x-1][y-1][0]=='W'))
         {
            moves[i]+=to_string(x);
            moves[i]+=to_string(y);
            i++;
         }
         if((x-1>=0 && x-1<=7)&&(y+1>=0 && y+1<=7)&&(p[x-1][y+1][0]=='W'))
         {
            moves[i]+=to_string(x);
            moves[i]+=to_string(y+2);
            i++;
         }
      }

      // Rook
      else if(piece[1]=='R')  
      {
         // Updating the moves array with possible moves to the down of the Rook
         for(int j=x-1;j>=0;j--)
         {
            if(p[j][y]=="\0")
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(y+1);
               i++;
            }
            else if(p[j][y][0]=='B' )  // If the first piece to the down of the Rook is Black leave without adding it to moves 
               break;
            else if(p[j][y][0]=='W' )  // If the first piece to the down of the Rook is White add it to the moves array and leave
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(y+1);
               i++;
               break;
            }
         }
         // Updating the moves array with possible moves towards the upward direction of the Rook
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
            else if(p[j][y][0]=='W' )
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(y+1);
               i++;
               break;
            }
         }
         // Updating the moves array with possible moves to the left of the Rook
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
            else if(p[x][j][0]=='W' )
            {
               moves[i]+=to_string(x+1);
               moves[i]+=to_string(j+1);
               i++;
               break;
            }
         }
         // Updating the moves array with possible moves to the right of the Rook
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
            else if(p[x][j][0]=='W' )
            {
               moves[i]+=to_string(x+1);
               moves[i]+=to_string(j+1);
               i++;
               break;
            }
         }
      }
      // Bishop
      else if(piece[1]=='B')
      {
         // Left diagonal down
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
            else if(p[j][k][0]=='W')
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
               break;
            }
            j-=1;
            k-=1;
         }

         // Left diagonal up
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
            else if(p[j][k][0]=='B')
               break;
            else if(p[j][k][0]=='W')
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
               break;
            }
            j-=1;
            k+=1;
         }

         // Right diagonal down
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
            else if(p[j][k][0]=='W')
            {
               moves[i]+=to_string(j+1);
               moves[i]+=to_string(k+1);
               i++;
               break;
            }
            j+=1;
            k-=1;
         }

         // Right diagonal up
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
            else if(p[j][k][0]=='B')
               break;
            else if(p[j][k][0]=='W')
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
      // Knight ( ensuring it is not King )
      else if(piece[1]=='K' && piece[2]!='I')
      {
         int j=x+2;int k=y+1;
         if((j<=7)&&(k<=7)&&((p[j][k]=="\0")||(p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+2;k=y-1;
         if((j<=7)&&(k>=0)&&((p[j][k]=="\0")||(p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-2;k=y-1;
         if((j>=0)&&(k>=0)&&((p[j][k]=="\0")||(p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-2;k=y+1;
         if((j>=0)&&(k<=7)&&((p[j][k]=="\0")||(p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y-2;
         if((j<=7)&&(k>=0)&&((p[j][k]=="\0")||(p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y+2;
         if((j<=7)&&(k<=7)&&((p[j][k]=="\0")||(p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-1;k=y-2;
         if((j>=0)&&(k>=0)&&((p[j][k]=="\0")||(p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-1;k=y+2;
         if((j>=0)&&(k<=7)&&((p[j][k]=="\0")||(p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }

      }
      // King
      else if(piece[1]=='K' && piece[2]=='I')
      {
         int j=x-1;int k=y-1;  // Left diagonal down
         if((j>=0)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-1;k=y;  // One step downwards
         if((j>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x-1;k=y+1;  // Right diagonal down
         if((j>=0)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x;k=y-1;  // One step to the left
         if((k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x;k=y+1;  // One step to the right
         if((k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y-1;  // Left diagonal up 
         if((j<=7)&&(k>=0)&&(p[j][k]=="\0" || (p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y;  // One step up
         if((j<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
         j=x+1;k=y+1;  // Right diagonal up
         if((j<=7)&&(k<=7)&&(p[j][k]=="\0" || (p[j][k][0]=='W')))
         {
            moves[i]+=to_string(j+1);
            moves[i]+=to_string(k+1);
            i++;
         }
      }

      // Queen
      // Count is set to 1 initially and it is updated till 8 to search for the possible moves in all the 8 directions
      else if(piece[1]=='Q')
      {
        int count=1,j=-1,k=-1;
        while(count<9)
        {
           switch(count)
           {
                case 1: j=x+1;  // One step up
                        k=y;
                        break;
                case 2: j=x-1;  // One step down
                        k=y;
                        break;
                case 3: j=x;    // One step right
                        k=y+1;
                        break;
                case 4: j=x;    // One step left
                        k=y-1;
                        break;
                case 5: j=x+1;  // Right diagonal up
                        k=y+1;
                        break;
                case 6: j=x+1;  // Left diagonal up
                        k=y-1;
                        break;
                case 7: j=x-1;  // Right diagonal down
                        k=y+1;
                        break;
                case 8: j=x-1;  // Left diagoanl down 
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
                else if(p[j][k][0]=='W')
                {
                        moves[i]+=to_string(j+1);
                        moves[i]+=to_string(k+1);
                        i++;
                        break;
                }
                switch(count)  // In this switch case the value of the indices j and k are updated to the next location | increment or decrement takes place
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
   return i; // The total number of possible moves
}


