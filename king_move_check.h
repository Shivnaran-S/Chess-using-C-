#include<string>
using namespace std;
/*
* Function : king_move_check
* Description : Given the chessboard p, the locations x and y and the player number we have to find the possible
* Parameters:
*     - string p     : current state of the chessboard populated with pieces 
*     - int x        : x coordinate of the piece(king) in p where it is about to move
*     - int y        : y coordinate of the piece(king) in p where it is about to move
*     - int player   : color of the piece = { if(player==1) White; else Black; }
* Returns:
*     - int : number of opponents targetting the location where the piece(king) is about to move
            : it is the number of times the expected position of king, is present in the possible moves of the opponent
            : if it is zero then the king can safely move to that location (x,y)
*/ 
int king_move_check(string **&p,int x,int y,int player)
{
    int x2,y2,no_moves,temp=0;
    string pos;

    // The chessboard from p is copied to q
    string **q=new string *[8];
    for(int i=0;i<8;i++)
        q[i]=new string[8];
    for(int m=0;m<8;m++)
    {
        for(int n=0;n<8;n++)
        {
            q[m][n]=p[m][n];
        }   
    }
    if(player==1)  // White
    {
        string str[16]={"BR1","BK1","BB1","BQ","BKI","BB2","BK2","BR2",
                        "BP1","BP2","BP3","BP4","BP5","BP6","BP7","BP8"};
        
        update(1,q,q,"WKI",x+1,y+1);  // The piece "WKI" is moved to a new place with coordinates (x,y) and the plus one is to tally with the definition of the function where x-1 and y-1 are used to update the chessboard p
        x++;y++;
        pos+=to_string(x);
        pos+=to_string(y);
           for(int k=0;k<16;k++)
           {
                // Returns the current position of str[k] in the chessboard of p through x2 and y2 which are passed by reference
                cur_pos(str[k],p,player,x2,y2);  
                string *moves=new string[40];  // Stores the possible moves in an array of string
                no_moves=possible_moves_k(str[k],q,q,2,x2,y2,moves);  //Function from the header file possible_moves_k.h to find the possible moves of str[k]
                for(int l=0;l<no_moves;l++)
                {
                        if(pos==moves[l]) // if the position pos where the king is about to move is already present in the possible moves of the opponent then increment the temp variable
                                temp++;
                }
                delete []moves;
           }
           return temp;
    }
    else  // Black
    {
        x++;y++;
        pos+=to_string(x);
        pos+=to_string(y);
           string str[16]={"WR1","WK1","WB1","WQ","WKI","WB2","WK2","WR2",
                           "WP1","WP2","WP3","WP4","WP5","WP6","WP7","WP8"};
           for(int k=0;k<16;k++)
           {
                // cur_pos(str[k],p,player,x2,y2); this statement is replaced with the following three nested loops
                for(int g=0;g<8;g++)
                {
                        for(int h=0;h<8;h++)
                        {
                                if(p[g][h]==str[k])
                                {
                                        x2=g;
                                        y2=h;
                                }
                        }
                }
                string *moves=new string[40];
                no_moves=possible_moves_k(str[k],p,q,1,x2,y2,moves);
                for(int l=0;l<no_moves;l++)
                {
                        if(pos==moves[l])
                                temp++;
                }
                delete []moves;
           }
           return temp;
    }
}
