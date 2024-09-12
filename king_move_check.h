#include<string>
using namespace std;
int king_move_check(string **&p,int x,int y,int player)
{
    int x2,y2,no_moves,temp=0;
    string pos;
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
    if(player==1)
    {
        string str[16]={"BR1","BK1","BB1","BQ","BKI","BB2","BK2","BR2",
                        "BP1","BP2","BP3","BP4","BP5","BP6","BP7","BP8"};
        update(1,q,q,"WKI",x+1,y+1);
        x++;y++;
        pos+=to_string(x);
        pos+=to_string(y);
           for(int k=0;k<16;k++)
           {
                cur_pos(str[k],p,player,x2,y2);
                string *moves=new string[40];
                no_moves=possible_moves_k(str[k],q,q,2,x2,y2,moves);
                for(int l=0;l<no_moves;l++)
                {
                        if(pos==moves[l])
                                temp++;
                }
                delete []moves;
           }
           return temp;
    }
    else
    {
        x++;y++;
        pos+=to_string(x);
        pos+=to_string(y);
           string str[16]={"WR1","WK1","WB1","WQ","WKI","WB2","WK2","WR2",
                           "WP1","WP2","WP3","WP4","WP5","WP6","WP7","WP8"};
           for(int k=0;k<16;k++)
           {
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