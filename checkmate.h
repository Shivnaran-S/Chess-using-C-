#include<string>
using namespace std;
void new_board(string **&p,string piece,int player,string **&checkstop,int k)
{
    int i,j,x,y,z=1,no_moves,l;
    string temp;
    string *moves=new string[40];
    cur_pos(piece,p,player,x,y);
    no_moves=possible_moves(piece,p,p,player,x,y,moves);
    cout<<piece<<" ";print_moves(moves,no_moves);
    if(no_moves>0)
    {
        for(i=0;i<no_moves;i++)
        {
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
            update(player,q,q,piece,moves[i][0]-48,moves[i][1]-48);
            temp=check(q,q,player);
            if(temp[2]=='0')
            {
                checkstop[k][z]=moves[i];
                z++;
            }
            for(l=0;l<8;l++)
                delete [] q[l];
            delete []q;
        }
    }
    delete []moves;
}
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
            checkstop[i][0]=str[i];
            new_board(p,str[i],player,checkstop,i);
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
        cout<<endl<<checkstop[i][0]<<" : ";
        j=1;
        while(checkstop[i][j]!="\0")
        {
            cout<<checkstop[i][j]<<" ";
            j++;
        }
    }
    for(i=0;i<16;i++)
    {
        if(checkstop[i][1]!="\0")
            temp++;
    }
    if(temp==0)
        return 1;
    else
        return 0;
}