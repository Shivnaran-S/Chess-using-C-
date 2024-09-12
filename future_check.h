#include<string>
//#include"linked_list.h"
using namespace std;
void future_check(string **&p,string piece,string *&moves,int &no_moves,int player)
{
    string temp;
    int dum=0;
    while(dum<no_moves)
    {
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
        update(1,q,q,piece,moves[dum][0]-48,moves[dum][1]-48);
        temp=check(q,q,player);
        if(temp[2]!='0')
        {
            no_moves-=1;
            for(int s=dum;s<(no_moves-1);s++)
            {
                moves[s]=moves[s+1];
            }
        }
        else
            dum++;
        for(int l=0;l<8;l++)
                delete [] q[l];
        delete [] q;
    }
}