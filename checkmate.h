#include<string>
using namespace std;

/**
* @brief Updates checkstop[k] a 1d array of 2d array checkstop with the possible moves of piece to stop the check on king 
* @param p Contains the chessoard
* @param piece The piece which could be moved to stop the check on king
* @param player Current player is Black or White
* @param checkstop A 2d array of size 16*40, which needs to updated with the possible moves of piece to stop the check on king
* @param k Denotes the row index of checkstop which needs to be updated with the moves to stop the check 
*/
void new_board(string **&p,string piece,int player,string **&checkstop,int k)
{
    int i,j,x,y,z=1,no_moves,l;
    string temp;
    string *moves=new string[40];
    cur_pos(piece,p,player,x,y);  // The current position of piece in the chessboard of p is updated in x and y which are passed by reference
    no_moves=possible_moves(piece,p,p,player,x,y,moves);  // To update moves array with no_moves possible moves of piece at (x,y) in p
    cout<<piece<<" ";print_moves(moves,no_moves);  // //Prints the possible moves given all the moves in m and number of elements as n
    if(no_moves>0)
    {
        for(i=0;i<no_moves;i++)
        {
            // chessboard p is copied to q
            string **q=new string*[8];
            for(l=0;l<8;++l)
                q[l]=new string[8];
            for(int m=0;m<8;m++)
            {
                for(int n=0;n<8;n++)
                {
                        q[m][n]=p[m][n];
                }   
            }
            update(player,q,q,piece,moves[i][0]-48,moves[i][1]-48);  // The piece is moving to the location (moves[i][0]-48,moves[i][1]-48)
            temp=check(q,q,player);  // The current location of king(not as matrix indices) in string[0] and string[1] and the rest(string[2:]) contains the number of attackers on king
            if(temp[2]=='0')  // No opponent is attacking the king
            {
                checkstop[k][z]=moves[i];  // Updating checkstop with the moves that could stop the check on king
                z++;
            }
            for(l=0;l<8;l++)
                delete [] q[l];
            delete []q;
        }
    }
    delete []moves;
}

/**
* @brief Is it a checkmate or not
* @param p Contains the chessoard
* @param player Current player is Black or White
* @param checkstop A new 2-d array of size 16*40, which needs to updated with the possible moves of each piece to stop the check on king
* @return Returns 1 if there are no possible moves to stop the check on king i.e., it is a checkmate. Returns 0 if it is not a checkmate
*/
int checkmate(string **&p,int player,string **&checkstop)
{
    int i=0,j=0,k=0;
    int temp=0;
    if(player==1)
    {
        string str[16]={"WR1","WB1","WK1","WQ","WKI","WB2","WK2","WR2",
                        "WP1","WP2","WP3","WP4","WP5","WP6","WP7","WP8"};
        for(i=0;i<16;i++)
        {
            checkstop[i][0]=str[i];  // First index stores the piece
            new_board(p,str[i],player,checkstop,i);  // new_board function is called to populate the checkstop[i] with possible moves of piece str[i] 
        }
    }
    else
    {
        string str[16]={"BR1","BK1","BB1","BQ","BKI","BB2","BK2","BR2",
                        "BP1","BP2","BP3","BP4","BP5","BP6","BP7","BP8"};
        for(i=0;i<16;i++)
        {
            checkstop[i][0]=str[i];
            new_board(p,str[i],player,checkstop,i);
        }
    }
    cout<<"The possible moves to stop the check on king are : "<<endl;
    for(i=0;i<16;i++)
    {
        cout<<endl<<checkstop[i][0]<<" : ";  // Print the piece that could be moved to stop the check on king
        j=1;
        while(checkstop[i][j]!="\0")  
        {
            cout<<checkstop[i][j]<<" ";  // Prints the possible moves of the above piece to stop the check on king
            j++;
        }
    }
    for(i=0;i<16;i++)
    {
        if(checkstop[i][1]!="\0")  // There are no possible moves for the piece str[i] to stop the attack on king
            temp++;  // Counts the number of pieces that can stop the threat to king
    }
    if(temp==0)  // If there are no piece with the required move then it is a checkmate
        return 1;  // So return 1 to indicate that it is a checkmate
    else
        return 0;  // So return 1 to indicate that it is not a checkmate
}