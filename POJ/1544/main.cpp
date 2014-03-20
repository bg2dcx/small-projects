#include <iostream>

using namespace std;

struct puzzel_piece{
int anchorx,anchory;
int piece_model[4][4];
};

puzzel_piece pieces[5][8];

int puzzel_board[4][4];

int number_of_pieces,piecex,piecey;

char input_char;

void reflect_board(int piece_number,int model_number)
{
    for (int x=0;x<4;x++)
        for (int y=0;y<4;y++)
    {
        pieces[piece_number][model_number+1].piece_model[x][y]=pieces[piece_number][model_number].piece_model[x][3-y];
    }
    pieces[piece_number][model_number+1].anchorx=pieces[piece_number][model_number].anchorx;
    pieces[piece_number][model_number+1].anchory=3-pieces[piece_number][model_number].anchory;
}

void flip_around(int piece_number)
{
    reflect_board(piece_number,0);
    ////Rotate clockwise 90 degrees////
     for (int x=0;x<4;x++)
        for (int y=0;y<4;y++)
    {
        pieces[piece_number][2].piece_model[x][y]=pieces[piece_number][0].piece_model[y][3-x];
    }
    pieces[piece_number][2].anchorx=pieces[piece_number][0].anchory;
    pieces[piece_number][2].anchory=3-pieces[piece_number][0].anchorx;
    reflect_board(piece_number,2);
    ////Rotate clockwise 180 degrees////
     for (int x=0;x<4;x++)
        for (int y=0;y<4;y++)
    {
        pieces[piece_number][4].piece_model[x][y]=pieces[piece_number][0].piece_model[3-x][3-y];
    }
    pieces[piece_number][4].anchorx=3-pieces[piece_number][0].anchorx;
    pieces[piece_number][4].anchory=3-pieces[piece_number][0].anchory;
    reflect_board(piece_number,4);
     ////Rotate counterclockwise 180 degrees////
     for (int x=0;x<4;x++)
        for (int y=0;y<4;y++)
    {
        pieces[piece_number][6].piece_model[x][y]=pieces[piece_number][0].piece_model[3-y][x];
    }
    pieces[piece_number][6].anchorx=3-pieces[piece_number][0].anchory;
    pieces[piece_number][6].anchory=pieces[piece_number][0].anchorx;
    reflect_board(piece_number,6);
}

void print_solution()
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
          cout<<puzzel_board[i][j];
        cout<<endl;
    }
    cout<<endl;
}

bool check_puzzel(int piece_number,int piece_x,int piece_y, int piece_direction)
{
    int newx,newy;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
    {
        newx=i-pieces[piece_numer][piece_direction].anchorx+piece_x;
        newy=j-pieces[piece_number][piece_direction].anchory+piece_y;
        if ( (newx > -1) && (newx<4) &&  (newy > -1) && (newy < 4)&& (puzzel_board[newx][newy]==0))
            puzzel_board[newx][newy]=-1;
        else return false;
    }
}

bool put_piece(int piece_number,int piece_x,int piece_y)
{
    if (puzzel_board[x][y]!=0) return false;
    bool result=false;
    for (int piece_direction=0;piece_direction<8;piece_direction++)
    {
        int can_put=true;
        can_put=check_puzzel(piece_number,piece_x,piece_y,piece_direction);
        int tmp=piece_number+1;
        if (!can_put) tmp=0;
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++)
              if (puzzel_board[i][j]=-1)
                puzzel_board[i][j]=tmp;
        if (can_put)
        {
            for (int x=0;x<4;x++)
                for (int y=0;y<4;y++)
                 if (puzzel_board[x][y]==0)
            {
                result=put_piece(piece_number+1,x,y);
                if (result) return true;
            }

        }

    }
}

int main()
{
    cin>>number_of_pieces;
    while (number_of_pieces != 0)
    {
       ///////Initialize puzzel pieces/////
        for (int i=0;i<1;i++)
        {
            cin>>piecex>>piecey;
            bool first_one=false;
            for (int x=0;x<piecex;i++)
                for (int y=0;y<piecey;y++)
            {
                cin>>input_char;
                pieces[i][0].piece_model[x][y]=input_char-'0';
                if ( (!first_one) && ((input_char-'0') == 1) )
                {
                    first_one=true;
                     pieces[i][0].anchorx=x;
                     pieces[i][0].anchory=y;
                }
            }
            flip_around(i);
        }
        ////////Start the search/////////
     bool find_result=false;
     for (int x=0;x<2;x++)
        for (int y=0;y<2;y++)
          for (int direction=0;direction<8;direction++)
     {
         find_result=put_piece(0,x,y);
         if (find_result) break;
     }
     if ( !find_result )
        cout<<"No solution possible"<<endl<<endl;
     else print_the_solution();
     cin>>number_of_pieces;
    }
    return 0;
}
