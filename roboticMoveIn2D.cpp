#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define LOG cout<<'\n'<<
#define GET cin>>
#define Repeat(n)  for(int i = 0 ; i < n ; i++)

string rankpost(int n){
    n %= 10;
    string postfix{ " " };
    switch(n){

    default: postfix = "th";
        break;
    case(1): postfix = "st";
        break;
    case(2): postfix = "nd";
        break;
    case(3): postfix = "rd";
        break;
                                }

    return postfix;
                                     }



// Function to find  final position of
// robot after the complete movement

int  finalPositionX (int x , int y , string move){
    if (move == "R" || move == "r") x++;
    if (move == "L" || move == "l") x--;
    if (move == "U" || move == "u") y++;
    if (move == "D" || move == "d") y--;

    return x;

                                                      }


int  finalPositionY (int x, int y, string move){

    if (move == "R" || move == "r") x++;
    if (move == "L" || move == "l") x--;
    if (move == "U" || move == "u") y++;
    if (move == "D" || move == "d") y--;

    return y;

                                                                  }


bool  gridBoundControl(int Lx, int Ux, int Ly, int Uy, int Xf, int Yf){

    if((Xf > Ux) || (Xf < Lx) || (Yf > Uy) || (Yf < Ly))
        return false;
    else
        return true;


}


bool obstControl (int* arr , int n, int Xf, int Yf){
 // n : capacity of array
    for(short i = 0; i < n; i += 2){

        if((arr[i] == Xf) && (arr[i+1] == Yf))
            return false;
                                                        }

    return true;
                                                                }



int main(){

    system("color 1E");

    /********************** Grid Dimension control module *********************************/
    int Lx{}, Ux{}, Ly{}, Uy{}, Ox{} , Oy{}, ObsN{}, Xf{}, Yf{} , distance {};
    double displacement{};

// displacement : جابه جایی
    // distance : مسافت طی شده

     do{
    LOG " Lx: "; GET Lx;
    LOG " Ux: "; GET Ux;
    LOG " Ly: "; GET Ly;
    LOG " Uy: "; GET Uy;

    if((Ly > Uy) || (Lx > Ux)){
        LOG "Error in entering bonds values .";
        LOG " Please enter again.";
                                                   }

                                                        }
     while ((Ly > Uy) || (Lx > Ux));

     /********************* Start point value control module**********************/

     do{

         LOG " Ox: "; GET Ox;
         LOG " Oy: "; GET Oy;

         if((Ox < Lx) || (Ox > Ux) || (Oy < Ly) || (Oy > Uy)){
             LOG " Error in entering start point co-ordination.";
             LOG " Please enter again.";
                                                                         }




                                                                                }

     while((Ox < Lx) || (Ox > Ux) || (Oy < Ly) || (Oy > Uy));

     /**********************   Obstacles number and co-ordination **********************************/

     LOG " How many obstacles exist? ";
     GET ObsN;

     int* obstaclesOrdination = new int [2*ObsN] {};
 int obstacleIndex = 1;
     Repeat(ObsN*2){

         LOG "Enter the" << (obstacleIndex) << rankpost(obstacleIndex) << " Obstacle X : ";
         GET obstaclesOrdination[i];
         i++;
         LOG "Enter the" << (obstacleIndex) << rankpost(obstacleIndex) << " Obstacle Y : ";
         GET obstaclesOrdination[i];
         obstacleIndex++;
                                                                                                       }

     /********************************* Moving commands module ***************************************/

     LOG "**************** Start move commands with (begin) and exit with (end) ***************** ";
     LOG "****** Please enter (L : Left), (R: Right), (U:Up), (D:Down) for move instructions and then press enter for entering next command.";
     LOG " ************ press X key to end the commands **************";
     cout << '\n';

     string command{ " "};

     Xf = Ox;
     Yf = Oy;

     while(command != "x" || command != "X"){

         cin >> command;
         if(command == "X" || command == "x")
            break;

         Xf = finalPositionX (Xf, Yf ,command) ;
         Yf = finalPositionY (Xf, Yf, command);

 if(gridBoundControl(Lx, Ux, Ly, Uy, Xf, Yf) == false)  LOG "Out of grid bounderies Error ! ";
         if(obstControl(obstaclesOrdination, 2*ObsN, Xf, Yf) == false)  LOG " Collision with barrier error.";

         if(gridBoundControl(Lx, Ux, Ly, Uy, Xf, Yf) == true && obstControl(obstaclesOrdination, 2 * ObsN, Xf, Yf) == true)
         cout << "Current position = (" << Xf << ", " << Yf << ")";


         if(gridBoundControl(Lx, Ux, Ly, Uy, Xf, Yf) == true)
             distance ++ ;


         cout << '\n';
                                                                                               }

     displacement = sqrt(pow(Ox - Xf, 2) + pow(Oy - Yf, 2));


     LOG " Displacemnt = " << displacement;
     LOG " Distance = " << distance;


    return 0;

                                                                                                             }

