#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
//declearing all the required global variables
enum  Direction{STOP = 0, LEFT, RIGHT,UP, DOWN}; // for direction 
Direction dir;
bool gameover;  // to store that game is over or not
const int height=20;/* For making board for the snake */
const int width=20;
int headX, headY, fruitX, fruitY, score=0;  // for the position of the snake and fruit.
int tail_len;
int tailx[100], taily[100];

//FUNCTIONS BEGINS
void setup();
void draw();
void input();
void logic();
int main(){
    char start;
     cout<<"\t---------------------------------------"<<endl;
     cout<<"\t\t :Snake Game :"<<endl;
     cout<<"\t---------------------------------------"<<endl;
     cout<<"Press 's' or 'S' to start :";
     cin>>start;
     if(start== 's' || start == 'S'){
         setup();
     while(!gameover){
           draw();
           input();
           logic();
           Sleep(30); // window function
           system("cls"); // To remove the previous function.
           
     }
     }
    return 0;
}
void setup(){
      gameover=false;
      dir=STOP;           //setup the initial conditions
      headX=width/2;
      headY=height/2;
      fruitX=rand()%width;
      fruitY=rand()%height;
      score =0;
}
void draw() {
    system("cls");
    cout << "\t\t";
    // Upper border
    for (int i = 0; i < width-8; i++) {
        cout << "||";
    }
    cout << endl;
    // In order to print snake, fruit, space, and side border;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Left border
            if (j == 0) {
                cout <<"\t\t||";
            }
            // Snake head
            if (i == headY && j == headX) {
                cout << "O";
            }
            // Fruit
            else if (i == fruitY && j == fruitX) {
                cout << "*";
            }
            // Space, snake tail;
            else {
                bool print = false;
                // Tail
                for (int k = 0; k < tail_len; k++) {
                    if (tailx[k] == j && taily[k] == i) {
                        cout << "o";
                        print = true;
                    }
                }
                // Space
                if (!print) {
                    cout << " ";
                }
            }
            // Right border
            if (j == width - 1) {
                cout << "||";
            }
        }
        cout << endl;
    }
    // Lower border
    cout << "\t\t";
    for (int i = 0; i < width-8; i++) {
        cout << "||";
    }
    cout << endl;
    cout << "\t\t\tScore: " << score << endl;
}

void input(){
    if(_kbhit()) // key board hit
  switch(getch()){
    case 'a':
    dir=LEFT;
     break;
    case 'd':
     dir=RIGHT;
     break;
    case 'w':
    dir=UP;
    break;
    case 's':
     dir=DOWN;
     break;
    default:
      break;
  }
}
void logic(){
    //tail logic
   int prevx=tailx[0];
   int prevy=taily[0];
   int prev2x, prev2y;
   tailx[0]=headX;
   taily[0]=headY;
   for(int i=1; i< tail_len ; i++){
    prev2x=tailx[i];
    prev2y=taily[i];
    tailx[i]= prevx;
    taily[i]= prevy;
    prevx=prev2x;
    prevy=prev2y;

   }
    // Direction logic;
    switch(dir){
        case LEFT:
        headX--;
        break;
        case RIGHT:
        headX++;
        break;
        case UP:
        headY--;
        break;
        case DOWN:
        headY++;
        break;
        default:
        break;
    }
    //Touching walls
    if(headX >= width){
        headX=0;
    }
    else if(headX < 0){
        headX=width-1;
    }
    else if(headY >= height){
        headY=0;
    }
    else if(headY < 0){
        headY=height-1;
    }
    // Snake bite itself
    for(int i=0; i<tail_len; i++){
        if(tailx[i]==headX && taily[i] == headY){
            gameover=true;
        }
    }
    // Snake eat fruit
    if(headX==fruitX && headY == fruitY){
        score +=10;
        fruitX = rand()%width;
        fruitY = rand()%height;
        tail_len++;
    }

}