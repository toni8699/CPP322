#include "functions.h"
#include <iostream>
using namespace std;
#include <ostream>


// int board[] =            {1,2,3,   10,11,12,   19,20,21,
        //                 4,5,6,   13,14,15,   22,23,24,
        //                 7,8,9,   16,17,18,   25,26,27};      << board looks like this 
void greetAndInstruct(){
        
        int board [] { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
        cout<<" Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer."<<endl;
        cout <<" The board is numbered from 1 to 27 as per the following:"<<endl ;

       for (int i = 0; i<28;i++){
           if ( board[i] %3 ==0)
           {
               cout <<board[i]<<"  ";

               if (board[i] == 21 || board[i]==24)
               {
                   cout <<endl;
                   cout<<"-----" <<"  "<<"--------"<<"   "<<"-------"<<endl;
               }
               if (board[i]==21)
               {
                   i=2;
               }else if (board[i]==24)
               {
                   i=5;
               }
               else{
                   i +=6;
               }
           }else
           {
                cout <<board[i] <<"|";
           }
           
       }
       cout<<endl<<" Play? (y/n)"<<endl;
       char input;
       cin>>input;
       if (input =='n'){exit('0');}



    }
    /*
    Display the board using an int array if not X or O {1,2,3,   10,11,12,   19,20,21,
                                                        4,5,6,   13,14,15,   22,23,24,
                                                      7,8,9,   16,17,18,   25,26,27};
                                        if X or O then display X and O from the char array
    
     */  
    void displayBoard(char board[]){
        int board1 [] { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
        for (int i = 0; i<28;i++){
           if ( board1[i] %3 ==0)
           {    
               if ( board[i]=='X'|| board[i]=='O')     
               {
                    if (i <=8){cout <<board[i]<<"  "; }else{
                 cout <<board[i]<<" "<<"  ";}
               }else
               {
                cout <<board1[i]<<"  ";
               }
               if (board1[i] == 21 || board1[i]==24)
               {
                   cout <<endl;
                  cout<<"-----" <<"  "<<"--------"<<"  "<<"--------"<<endl;
               }
               if (board1[i]==21){
                   i=2;
              }else if (board1[i]==24){
                   i=5;
               }
               else{
                   i +=6;
               }
           }else
           {
                if ( board[i]=='X'|| board[i]=='O')
                {
                     if (i <=8){cout <<board[i]<<"|"; }else{
                 cout <<board[i]<<" "<<"|";}

                }else
                {
                     cout <<board1[i]<<"|";
                }
                
           }
           
          
       }
       }
       /*

       if the number entered is out of bound or if it's occupy then prompt user to re enter
        */
       bool checkIfLegal(int cellNbre, char board[])
       {

           if ( board[cellNbre-1] =='O' || board[cellNbre-1]=='X' || cellNbre-1 >26||cellNbre-1<0)
           {
            cout <<endl<<"Il legal move bro try again plx "<<endl;
               return false;
           }
           return true;

       }
       /* 
       call a helper function Over()to check for state of game. 
       */
       bool CheckWinner(char board[]){
           if (Over(board) ==1){
               cout<<"You Won !"<<endl;
               return true;
             //  exit(0);
           }
           if (Over(board)==2){
               cout<<"Computer Won !"<<endl;
               return true;
             //  exit(0);

           }
           return false;

       }
       /* 
       check every possible winning conditions
       return an int 1 for user, 2 for computer when the game is over
       */
       int Over(char board[]){
        int who=0;
        bool end=0;
      //  check horizontal
       if(end==0){
           int i=0;
        while(i<27){
            if (board[i]==board[i+1] && board[i+1] == board[i+2]){
                end =true;
                if(board[i]=='X'){
                    who =1;
                }else{who =2;}
                break;
        }else{
            i+=3;
        }
        }
        }
      //  check vertical
        if (end ==0){
        int i=0;
        while (i<27){ 
           // cout<<"i is "<<i<<" i+3 is "<<i+3<<" i+6 is "<<i+6<<endl;
                if(board[i]==board[i+3]&&board[i+3]==board[i+6]){
                end =true;
                if (board[i]=='X'){who=1;}else{who=2;}
                break;
                
            }else{
                if ( i==2||i==11){
                    i+=6;
                }
                i+=1;
              }
        }
        }
        // left to right diag
        if (end==0){
        int i = 0;
        while (i<27){
            if(board[i]==board[i+4]&&board[i+4]==board[i+8]){
                end = true;
                if (board[i]=='X'){who=1;}else{who=2;}
                break;
            }else{
               i+=9;
        }
        }
        }
        //right to left diag
        if (end==0){
        int i=0;
        while (i<27){
            if((board[i+2]==board[i+4]&&board[i+4]==board[i+6])){
                end = true;
                if (board[i+2]=='X'){who=1;}else{who=2;}
                break;
            }else{
               i+=11;
        }
        }
        }
        // x-z
        //1-13-25
        if(end==0){
        int i=0;
        while (i<27){
            if((board[i]==board[i+12]&&board[i+12]==board[i+24])){
                end = true;
                if (board[i]=='X'){who=1;}else{who=2;}
                break;
            }else{
               i+=1;
            }
            }
            }
        //Cross board vertical and horizontal ( 1-10-19)
        if(end==0){
        int i=0;
        while (i<27){
            if((board[i]==board[i+9]&&board[i+9]==board[i+18])){
                end = true;
                if (board[i]=='X'){who=1;}else{who=2;}
                break;
            }else{
               i+=1;
            }
            }
            }
        //7-13-19
       if(end ==0){ 
        int i=6;
        while (i<27){
            if((board[i]==board[i+6]&&board[i+6]==board[i+12])){
                end = true;
                if (board[i]=='X'){who=1;}else{who=2;}
                break;
            }else{
               i+=1;
            }
            }
            }
       // y-z
      // 1 -11 -21
       if(end ==0){
        int i=0;
        while (i<27){
            if((board[i]==board[i+10]&&board[i+10]==board[i+20])){
                end = true;
                if (board[i]=='X'){who=1;}else{who=2;}
                break;
            }else{
               i+=3;
            }
            }
            }
       
       //3-11-19
       if (end ==0){
        int i=0;
       while (i<27){
            if((board[i+2]==board[i+10]&&board[i+10]==board[i+18])){
                end = true;
                if (board[i]=='X'){who=1;}else{who=2;}
                break;
            }else{
               i+=3;
            }
            }
            }
       
       // 4 diags cross board
       if (end ==0){
           if(board[0]==board[13]&&board[13]==board[26]){
               end =true;
               if(board[0]=='X'){who=1;}else{who=2;}
               }
           if (board[2]==board[13]&&board[13]==board[24]){
               end =true;
               if(board[2]=='X'){who=1;}else{who=2;}
               }
           if( board[8]==board[13]&&board[13]==board[18]){
               end =true;
               if(board[8]=='X'){who=1;}else{who=2;}
               }
           if(board[6]==board[13]&&board[13]==board[20]){
               end =true;
               if(board[6]=='X'){who=1;}else{who=2;}
               }
       }

        return who;
       }
       /*
       play an X or O on all possible slots, if it's a winning move for player then replace it with O
       if
       
        */
       void computerMove(char board[]){
           bool moved;
        if (!moved){
            for (int i=0;i<27;i++){
                char tmp;
                if (board[i] !='O' && board[i]!='X'){
                    tmp = board[i];
                    board[i]='O';       //place an O if win then move there, if not then remove the O
                    if (Over(board)){
                        moved=true;
                        cout<<"Computer moving to "<<i+1<<endl;
                        break;
                    }else{
                        board[i]=tmp;
                    }
                }
            }
        }
        if (!moved){
            for(int i=0;i<27;i++){
                char temp;
                if (board[i] !='O' && board[i]!='X'){
                    temp = board[i];
                    board[i]='X';             // place x on the board and check win condition
                    if (Over(board)==1){
                            board[i]='O';
                            moved=true;
                            cout<<"computer moved into "<<i+1<<endl;
                            break;
                }else{
                    board[i]=temp; //remove the X
                }
            }
            }
        }
        //else randomly move into an available slot
        if (!moved){
            int move = rand()%26;
            while (board[move]=='X' || board[move]=='O'){
                move = rand()%26;
            }
            board[move]='O'; 
            cout<<"Computer moved into "<<move+1<<endl;
        }
        }