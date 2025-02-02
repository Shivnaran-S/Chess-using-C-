#include<string>
//#include"linked_list.h"
using namespace std;

/**
* @brief Function to remove the moves that can push the king to a danger zone
* @param p Contains the chessboard
* @param piece A piece of p, which is going to be moved now, such that the move doesn't affect king
* @param moves Possible moves of the piece
* @param no_moves Number of moves in the array moves
* @param player Current player is Black or White
* @return nothing. will just reduce the no_moves and updates moves such that the moves will not cause the king to be attacked by opponent
*/
void future_check(string **&p,string piece,string *&moves,int &no_moves,int player)
{
    string temp;
    int dum=0;
    while(dum<no_moves)
    {
        // p is copied to q
        string **q=new string*[8];
        for(int l=0;l<8;++l)
            q[l]=new string[8];
        for(int g=0;g<8;g++)
                {
                        for(int h=0;h<8;h++)
                        {
                                q[g][h]=p[g][h];
                        }
                }

        // just execute each move in a dummy chessboard q, and see whether the king is in a safe position or not
        update(1,q,q,piece,moves[dum][0]-48,moves[dum][1]-48);  // ASCII of '0' is 48. On subtracting 48 from a string leaves behind the actual number, here we get the (index in p+1) after subtraction which is required for the update function
        temp=check(q,q,player); // checks whether the king is safe or not after the move has been performed on the piece
        if(temp[2]!='0')
        {
            no_moves-=1;
            for(int s=dum;s<(no_moves-1);s++)  // Can be handled using a linked list also
            {
                moves[s]=moves[s+1];  // Since we are using s+1, the iterator s should go till the last but one index only. since the no_moves is also updated the last moves of moves array will not get executed if no_moves is reduced 
            }
        }
        else
            dum++;

        // Since q is updated with a move, it has to be deleted and re-entered from the first
        for(int l=0;l<8;l++)
                delete [] q[l];
        delete [] q;
    }
}