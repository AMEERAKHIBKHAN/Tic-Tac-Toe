#include<iostream>
#include<string>

using namespace std;

string n1="";
string n2="";
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int col;
bool tie = false;

char token = 'X';
void gameboard()
{
  
  cout<<"   |     |"    <<endl;
  cout<<" "<<board[0][0]<<" |  "<<board[0][1]<<"  | "<<board[0][2]<<endl;
  cout<<"___|_____|___"    <<endl;
  cout<<"   |     |"    <<endl;
  cout<<" "<<board[1][0]<<" |  "<<board[1][1]<<"  | "<<board[1][2]<<endl;
  cout<<"___|_____|___"<<endl;
  cout<<"   |     |"    <<endl;
  cout<<" "<<board[2][0]<<" |  "<<board[2][1]<<"  | "<<board[2][2]<<endl;
  cout<<"   |     |"    <<endl;

}

void move()
{

  int choice;

  if(token=='X')
  {
    cout<<n1<<" please enter ";
    cin>>choice;
  }
  if(token=='O')
  {
    cout<<n2<<" please enter ";
    cin>>choice;
  }
  
  switch(choice){
        case 1: row=0; col=0; break;
        case 2: row=0; col=1; break;
        case 3: row=0; col=2; break;
        case 4: row=1; col=0; break;
        case 5: row=1; col=1; break;
        case 6: row=1; col=2; break;
        case 7: row=2; col=0; break;
        case 8: row=2; col=1; break;
        case 9: row=2; col=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(token == 'X' && board[row][col] != 'X' && board[row][col] != 'O'){
        //updating the position for 'X' 
        board[row][col] = 'X';
        token = 'O';
    }else if(token == 'O' && board[row][col] != 'X' && board[row][col] != 'O'){
        //updating the position for 'O' 
        board[row][col] = 'O';
        token = 'X';
    }else {
        cout<<"no moves left"<<endl;
        move();
    }
}

bool win_draw()
{
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    tie = true;
    return false;
}

int main()
{

  cout<<"T I C K -- T A C -- T O E -- G A M E"<<endl;
  cout<<"2 PLAYERS"<<endl;
  cout<<"Player1 enter your name : "<<endl;
  cin>>n1;
  cout<<"Player2 enter your name : "<<endl;
  cin>>n2;

  cout<<n1<<" is player1 will play first "<<endl;
  cout<<n2<<" is player2 will play second "<<endl;
  while(win_draw())
  {
    gameboard();
    move();
    win_draw();
  }

  if(token == 'X' && tie == false)
  {
      cout<<n2<<" Win!"<<endl;
      gameboard();
  }
  else if(token == 'O' && tie == false)
  {
      cout<<n1<<" Win!"<<endl;
      gameboard();
  }
  else{
    cout<<"It's a draw"<<endl;
  }
}