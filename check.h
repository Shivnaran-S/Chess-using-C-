#include<string>
#include<iostream>
using namespace std;

/**
* @brief Checks whether the king is being attacked by opponent. Is the king need to be checked?
* @param p Contains the chessoard
* @param q Ignore
* @param player Current player is Black or White
* @return The current location of king(not as matrix indices) in string[0] and string[1] and the rest contains the number of attackers on king
*/
string check(string **&p,string **&q,int player)
{
        int x,y,x2,y2,no_moves,temp=0;
        string pos;  // stores the current position of king in the user readable format not the direct indexes of the array
        if(player==1)
        {
           cur_pos("WKI",p,1,x,y);  // current position of king is updated in x and y where x and y ranges from 0 to 7 both inclusive
           x++;y++;  // Incrementing it, as the moves array will be storing the coordinates in user readable format only not as indexes
           pos+=to_string(x);
           pos+=to_string(y);
           string str[16]={"BR1","BK1","BB1","BQ","BKI","BB2","BK2","BR2",
                           "BP1","BP2","BP3","BP4","BP5","BP6","BP7","BP8"};
           for(int k=0;k<16;k++)
           {
                string *moves=new string[40];
                cur_pos(str[k],p,1,x2,y2);
                no_moves=possible_moves_k(str[k],p,q,2,x2,y2,moves); // returns the possible moves of str[k] through the moves array
                for(int l=0;l<no_moves;l++)
                {
                        if(pos==moves[l])
                        {
                                temp++;
                        }
                }
                delete [] moves;
           }
           pos+=to_string(temp);  // number of opponents attacking the king right now. it could be more than one as moving a piece and placing it in a new place such that it attacks the king directly. this may indirectly lead another piece to attack the king which was blocked by the recently moved piece.  
           return pos;
        }
        else
        {
           cur_pos("BKI",p,1,x,y);
           x++;y++;
           pos+=to_string(x);
           pos+=to_string(y);
           string str[16]={"WR1","WK1","WB1","WQ","WKI","WB2","WK2","WR2",
                           "WP1","WP2","WP3","WP4","WP5","WP6","WP7","WP8"};
           for(int k=0;k<16;k++)
           {
                cur_pos(str[k],p,1,x2,y2);
                string *moves=new string[40];
                no_moves=possible_moves_k(str[k],p,q,1,x2,y2,moves);
                for(int l=0;l<no_moves;l++)
                {
                        if(pos==moves[l])
                        {
                                temp++;
                        }
                }
                delete [] moves;
           }
           pos+=to_string(temp);
           return pos;
        }
}