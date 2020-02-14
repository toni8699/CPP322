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
    void displayBoard(char charboard[]){
        int board [] { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
        for (int i = 0; i<28;i++){
           if ( board[i] %3 ==0)
           {    
               if ( charboard[i]=='X'|| charboard[i]=='O')     
               {
                    if (i <=8){cout <<charboard[i]<<"  "; }else{
                 cout <<charboard[i]<<" "<<"  ";}
               }else
               {
                cout <<board[i]<<"  ";
               }
               if (board[i] == 21 || board[i]==24)
               {
                   cout <<endl;
                  cout<<"-----" <<"  "<<"--------"<<"  "<<"--------"<<endl;
               }
               if (board[i]==21){
                   i=2;
              }else if (board[i]==24){
                   i=5;
               }
               else{
                   i +=6;
               }
           }else
           {
                if ( charboard[i]=='X'|| charboard[i]=='O')
                {
                     if (i <=8){cout <<charboard[i]<<"|"; }else{
                 cout <<charboard[i]<<" "<<"|";}

                }else
                {
                     cout <<board[i]<<"|";
                }
                
           }
           
          
       }
       }
       /*

       if the number entered is out of bound or if it's occupy then prompt user to re enter
        */
       bool checkIfLegal(int CellNbre, char charboard[])
       {

           if ( charboard[CellNbre-1] =='O' || charboard[CellNbre-1]=='X' || CellNbre-1 >26||CellNbre-1<0)
           {
            cout <<endl<<"Il legal move bro try again plx "<<endl;
               return false;
           }
           return true;

       }
       /* 
       call a helper function Over()to check for state of game. 
       */
       bool ChecWinner(char charboard[]){
           if (Over(charboard) ==1){
               cout<<"You Won !"<<endl;
               return true;
             //  exit(0);
           }
           if (Over(charboard)==2){
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
       int Over(char charboard[]){
        int who=0;
        bool end=0;
      //  check horizontal
       if(end==0){
           int i=0;
        while(i<27){
            if (charboard[i]==charboard[i+1] && charboard[i+1] == charboard[i+2]){
                end =true;
                if(charboard[i]=='X'){
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
                if(charboard[i]==charboard[i+3]&&charboard[i+3]==charboard[i+6]){
                end =true;
                if (charboard[i]=='X'){who=1;}else{who=2;}
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
            if(charboard[i]==charboard[i+4]&&charboard[i+4]==charboard[i+8]){
                end = true;
                if (charboard[i]=='X'){who=1;}else{who=2;}
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
            if((charboard[i+2]==charboard[i+4]&&charboard[i+4]==charboard[i+6])){
                end = true;
                if (charboard[i+2]=='X'){who=1;}else{who=2;}
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
            if((charboard[i]==charboard[i+12]&&charboard[i+12]==charboard[i+24])){
                end = true;
                if (charboard[i]=='X'){who=1;}else{who=2;}
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
            if((charboard[i]==charboard[i+9]&&charboard[i+9]==charboard[i+18])){
                end = true;
                if (charboard[i]=='X'){who=1;}else{who=2;}
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
            if((charboard[i]==charboard[i+6]&&charboard[i+6]==charboard[i+12])){
                end = true;
                if (charboard[i]=='X'){who=1;}else{who=2;}
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
            if((charboard[i]==charboard[i+10]&&charboard[i+10]==charboard[i+20])){
                end = true;
                if (charboard[i]=='X'){who=1;}else{who=2;}
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
            if((charboard[i+2]==charboard[i+10]&&charboard[i+10]==charboard[i+18])){
                end = true;
                if (charboard[i]=='X'){who=1;}else{who=2;}
                break;
            }else{
               i+=3;
            }
            }
            }
       
       // 4 diags cross board
       if (end ==0){
           if(charboard[0]==charboard[13]&&charboard[13]==charboard[26]){
               end =true;
               if(charboard[0]=='X'){who=1;}else{who=2;}
               }
           if (charboard[2]==charboard[13]&&charboard[13]==charboard[24]){
               end =true;
               if(charboard[2]=='X'){who=1;}else{who=2;}
               }
           if( charboard[8]==charboard[13]&&charboard[13]==charboard[18]){
               end =true;
               if(charboard[8]=='X'){who=1;}else{who=2;}
               }
           if(charboard[6]==charboard[13]&&charboard[13]==charboard[20]){
               end =true;
               if(charboard[6]=='X'){who=1;}else{who=2;}
               }
       }

        return who;
       }
       /*
       play an X or O on all possible slots, if it's a winning move for player then replace it with O
       if
       
        */
       void ComputerMove(char charboard[]){
           bool moved;
        if (!moved){
            for (int i=0;i<27;i++){
                char tmp;
                if (charboard[i] !='O' && charboard[i]!='X'){
                    tmp = charboard[i];
                    charboard[i]='O';       //place an O if win then move there, if not then remove the O
                    if (Over(charboard)){
                        moved=true;
                        cout<<"Computer moving to "<<i+1<<endl;
                        break;
                    }else{
                        charboard[i]=tmp;
                    }
                }
            }
        }
        if (!moved){
            for(int i=0;i<27;i++){
                char temp;
                if (charboard[i] !='O' && charboard[i]!='X'){
                    temp = charboard[i];
                    charboard[i]='X';             // place x on the board and check win condition
                    if (Over(charboard)==1){
                            charboard[i]='O';
                            moved=true;
                            cout<<"computer moved into "<<i+1<<endl;
                            break;
                }else{
                    charboard[i]=temp; //remove the X
                }
            }
            }
        }
        //else randomly move into an available slot
        if (!moved){
            int move = rand()%26;
            while (charboard[move]=='X' || charboard[move]=='O'){
                move = rand()%26;
            }
            charboard[move]='O'; 
            cout<<"Computer moved into "<<move+1<<endl;
        }
        }