#include <iostream>

#include <cstdlib>

#include <ctime>

using namespace std;
// Studies Problem Solving with C++ (Course Book)
// Some online C++ books for example: Chegg (computer science learning materials)

bool checkAndDisplay(char **board,int height,int width,int x,int y);

int main() {

               srand(time(NULL));

               char **board; // board

               // length and height of the board

               int width,height;

               int bomb; // number of bombs

               int x,y;

               // inputs

               cout<<" Please Select board width : ";

               cin>>width;

               cout<<" Please Select board height : ";

               cin>>height;

               cout<<" Please Select number of bombs :";

               cin>>bomb;

               // create the board

               board = new char*[height];

               for(int i=0;i<height;i++)

                              board[i] = new char[width];

               for(int i=0;i<height;i++)

               {

                              for(int j=0;j<width;j++)

                                             board[i][j]='.';

               }

               // place the bombs

               for(int i=0;i<bomb;i++)

               {

                              x=rand()%height;

                              y = rand()%width;

                              if(board[x][y] == '.')

                                             board[x][y] = 'X';

                              else if(board[x][y] != '.')

                                             i--;

               }

               // display the initial board

               for(int i=0;i<width;i++)

                              cout<<i<<" ";

               cout<<endl;

               for(int i=0;i<height;i++)

               {              cout<<i<<" ";

                              for(int j=0;j<width;j++)

                                             cout<<". ";

                              cout<<endl;

               }

               bool playEnd=false;

               // loop continues till a bomb is found

               do{

                              cout<<"Please Enter the x-coordinate (0.."<<(height-1)<<") : ";

                              cin>>x;

                              while(x < 0 || x>=height)

                              {

                                             cout<<" Invalid input. Enter the x-coordinate (0.."<<(height-1)<<") : ";

                                             cin>>x;

                              }

                              cout<<" Please Enter the y-coordinate (0.."<<(width-1)<<") : ";

                              cin>>y;

                              while(y < 0 || y>=width)

                              {

                                             cout<<" Invalid input. Enter the x-coordinate (0.."<<(width-1)<<" ): ";

                                             cin>>y;

                              }

                              playEnd = checkAndDisplay(board,height,width,x,y);

                              if(playEnd)

                                             cout<<"!!!! YOU ARE DEAD !!!!"<<endl;

               }while(!playEnd);

               return 0;

}

// function to display the board after each turn and check if a bomb was found at the input coordinate or not

bool checkAndDisplay(char **board,int height,int width,int x,int y)

{

               for(int i=0;i<width;i++)

                              cout<<i<<" ";

               cout<<endl;

               if(board[x][y] == 'X')

               {

                              board[x][y] = '@';

                              for(int i=0;i<height;i++)

                              {              cout<<i<<" ";

                                             for(int j=0;j<width;j++)

                                                            cout<<board[i][j]<<" ";

                                             cout<<endl;

                              }

                              return true;

               }

               board[x][y] = 'N';

               for(int i=0;i<height;i++)

               {

                              cout<<i<<" ";

                              for(int j=0;j<width;j++)

                              {

                                             if(board[i][j] == 'N')

                                                            cout<<board[i][j]<<" ";

                                             else

                                                            cout<<". ";

                              }

                              cout<<endl;

               }

               return false;

}