#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;


void greetAndInstruct();
void displayBoard(char board1[]);
bool checkIfLegal(int number,char board[]);
bool Over(char board2[]);
void ComputerMove(char charboard111[]);

//  int board[] = {1,2,3,   10,11,12,   19,20,21,
//                 4,5,6,   13,14,15,   22,23,24,
//                 7,8,9,   16,17,18,   25,26,27};
char boardchar[] = {'a','b','d', 
                    'd','e','f',   
                    'g','h','i',  

                                'j','k','l',
                                'm','n','o',   
                                'p','q','r',

                                            's','t','u',    
                                            'v','w','x',   
                                            'y','z','$'};
char boardchar2[27];



int main()
{
    // greetAndInstruct();
    // displayBoard();
    // for ( int i =0;i<28;i++){
    //     cout << boardchar[i] <<endl;
    // }
    greetAndInstruct();
    displayBoard(boardchar);
   for (int i = 0;i<1000;i++){
    cout<<"enter a number plx: "<<endl;
    int input;
    cin >> input;
    if (checkIfLegal(input,boardchar))
        {
        boardchar[input-1] ='X';
        }
          else{
            checkIfLegal(input,boardchar);
        }
        ComputerMove(boardchar);
        displayBoard(boardchar);   
    //displayBoard(boardchar);
        
    }
    
    }


    


    

    
    void greetAndInstruct(){
        // int board[] = {1,2,3,   10,11,12,   19,20,21,
        //                 4,5,6,   13,14,15,   22,23,24,
        //                 7,8,9,   16,17,18,   25,26,27};
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
       cout<<"  Play? (y/n)"<<endl;
       char input;
       cin>>input;
       if (input ='n'){exit;}else{

       }



    }
    /* 
    
    
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
                   //cout<<"----------" <<"    "<<"-----------"<<"     "<<"-------------"<<endl;
                   cout<<endl;
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
       bool checkIfLegal(int CellNbre, char charboard[])
       {

           if ( charboard[CellNbre-1] =='O' || charboard[CellNbre-1]=='X' || CellNbre-1 >26||CellNbre<0)
           {
               cout <<"Il legal move bro try again plx"<<endl;
               return false;
           }
           return true;

       }
       bool Over(char charboard[]){
           int who=0;
           
        int i =0;
        //check horizontal
        while(i<27){
            if (!(charboard[i]==charboard[i+1] && charboard[i+1] == charboard[i+2])){
                 i+=3;
                 }else{if(charboard[i]=='X'){cout<<"You Win";}
                     return true;}    
        }
        // check vertical
        i=0;
        while (i<27){ 
            if(!(charboard[i]==charboard[i+3]&&charboard[i+3]==charboard[i+6])){
                i+=1;
            }else{ if(charboard[i]=='X'){cout<<"You Win";}return true;}
        }
        //left to right diag
        i = 0;
        while (i<27){
            if(!(charboard[i]==charboard[i+4]&&charboard[i+4]==charboard[i+8])){
                i+=9;
            }else{
                if(charboard[i]=='X'){cout<<"You Win";}return true;}
        }
        //right to left diag
        i=0;
        while (i<27){
            if(!(charboard[i+2]==charboard[i+4]&&charboard[i+4]==charboard[i+6])){
                i+=11;
            }else{if(charboard[i]=='X'){cout<<"You Win";}return true;}
        }
        // x-z
        i=0;
        while (i<27){
            if(!(charboard[i]==charboard[i+12]&&charboard[i+12]==charboard[i+24])){
                i+=1;
            }else{if(charboard[i]=='X'){cout<<"You Win";}return true;}
            }
        i=0;
        while (i<27){
            if(!(charboard[i+6]==charboard[i+12]&&charboard[i+12]==charboard[i+18])){
                i+=1;
            }else{if(charboard[i+6]=='X'){cout<<"You Win";}return true;}
            }
        //y-z
        i=0;
        while (i<27){
            if(!(charboard[i]==charboard[i+10]&&charboard[i+10]==charboard[i+20])){
                i+=3;
            }else{if(charboard[i]=='X'){cout<<"You Win";}return true;}
       }
       i=0;
       while (i<27){
            if(!(charboard[i+2]==charboard[i+10]&&charboard[i+10]==charboard[i+18])){
                i+=3;
            }else{if(charboard[i+2]=='X'){cout<<"You Win";}return true;}
       }
       
       // diag1
           if(charboard[0]==charboard[13]&&charboard[13]==charboard[26]){if(charboard[0]=='X'){cout<<"You Win";}return true;}
           if (charboard[2]==charboard[13]&&charboard[13]==charboard[24]){if(charboard[2]=='X'){cout<<"You Win";}return true;}
           if( charboard[8]==charboard[13]&&charboard[13]==charboard[19]){if(charboard[8]=='X'){cout<<"You Win";}return true;}
           if(charboard[6]==charboard[13]&&charboard[13]==charboard[21]){if(charboard[6]=='X'){cout<<"You Win";}return true;}

        //  int board[] = {1,2,3,   10,11,12,   19,20,21,
//                         4,5,6,   13,14,15,   22,23,24,
//                         7,8,9,   16,17,18,   25,26,27};
        if (who ==1){
            cout<<who<<endl;
        }
       return false;
      
       }
       void ComputerMove(char charboard[]){
           int x=0;
           int o=0;
           int pos =0;
           bool winmove=false;
           int movehere;
          
        if(winmove ==false){
             int i =0;
           while (i<27){
               pos =i;
             //  cout<<"winmove is ?"<<winmove<<endl;
             //  cout<<"looping from j (post)" <<pos<<" to pos+3: "<<(pos+3)<<endl;
               for (int j = pos;j<pos+3;j++){
                  // cout<<"j is "<<j<<" now"<<endl;
                   if ( charboard[j]=='X')
                   {x++;
               //    cout<<"x is now "<<x<<endl;

                   }else{
                       if(charboard[j]=='O'){o++;
                       }
                   }
               }if ( x ==2 || o==2){
                //   cout<<"going into this if "<<endl;
                    for (int k = pos;k<pos+3;k++){
                        if ( charboard[k] != 'X'&&charboard[k]!='O'){
                       //     cout<<"charboard[k] is "<<k<<" "<<charboard[k]<<endl;
                         //   cout<<"there is a win move and it's "<<k<<endl;
                            movehere = k;
                            winmove = true;
                         }  
                     }
                     if (winmove){
                      //   cout<<"winmove is "<<winmove<<"and move here is "<<movehere<<endl;
                         i=0; x=0; o=0;
                       //  cout<<"resetting i,x and o, now i is "<<i<<endl;
                         break;
                     }else{
                        // cout<<"x=2 but no available move first row where i is "<<i<<endl;
                         winmove = false;
                         x=0;o=0;i+=3;
                       //  cout<<"resetting x to "<<x<<" and o to "<<o<<endl;
                     }
                 }else{
                    // cout<<"i is at position"<<i<<"and incrementing by 3 to get"<<i+3<<endl;
                     winmove = false;
                     x=0;o=0;
                     i+=3;
                 }
            }
            }
            if(winmove ==false){
                 int i =0;
             while (i<27){
               pos =i;
             //  cout<<"winmove is ?"<<winmove<<endl;
             //  cout<<"looping from j (post)" <<pos<<" to pos+6: "<<(pos+6)<<endl;
               for (int j = pos;j<pos+7;j+=3){
               //    cout<<"j is "<<j<<" now"<<endl;
                   if ( charboard[j]=='X')
                   {x++;
               //    cout<<"x is now "<<x<<endl;

                   }else{
                       if(charboard[j]=='O'){o++;
                       }
                   }
               }if ( x ==2 || o==2){
                //   cout<<"going into this if "<<endl;
                    for (int k = pos;k<pos+7;k+=3){
                        if ( charboard[k] != 'X'&&charboard[k]!='O'){
                    //        cout<<"charboard[k] is "<<k<<" "<<charboard[k]<<endl;
                     //      cout<<"there is a win move and it's "<<k<<endl;
                            movehere = k;
                            winmove = true;
                         }  
                     }
                     if (winmove){
                     //    cout<<"winmove is "<<winmove<<"and move here is "<<movehere<<endl;
                         i=0; x=0; o=0;
                      //   cout<<"resetting i,x and o, now i is "<<i<<endl;
                         break;
                     }else{
                     //    cout<<"x=2 but no available move first row where i is "<<i<<endl;
                         winmove = false;
                         x=0;o=0;i+=1;
                       //  cout<<"resetting x to "<<x<<" and o to "<<o<<endl;
                     }
                 }else{
                   //  cout<<"i is at position"<<i<<"and incrementing by 3 to get"<<i+3<<endl;
                     winmove = false;
                     x=0;o=0;
                     i+=1;
                 }
            }
            }
            









            
            if (winmove){
                cout<<"there's a win move so moving to position "<<movehere<<endl;
                charboard[movehere]='O';
            }else{
                cout<<"there's no win move"<<endl;
                movehere=rand()%26;
               while (charboard[movehere]=='X' || charboard[movehere]=='O'){
                   movehere=rand()%26;
               }
               charboard[movehere]='O';
           }
           }
        
           
// char boardchar[] = {'X','b','X', 
//                     'd','e','f',   
//                     'g','h','i',  

//                                 'j','k','l',
//                                 'm','n','o',   
//                                 'p','q','r',

//                                             's','t','u',    
//                                             'v','w','x',   
//                                             'y','z','$'};
       

    
