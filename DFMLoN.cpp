//chipotle anyone? moes is better nope yes, they have quaeso
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <stdlib.h>
#include <vector>
//#include "conio.h"

using namespace std;

int sizeX;
int sizeY;
std::random_device rd;
std::mt19937 gen(rd());

class hero{
    public:
        int pos_x;
        int pos_y;
        void fireArrow(){
            
        }
        void move(){
            char wasd;
        cin.get(wasd);
        cin.ignore();
        switch (wasd){
            case 'w':
                if (pos_y != 1)
                    pos_y--;
                break;
            case 'a':
                if (pos_x != 1)
                    pos_x--;
                break;
            case 's':
                if (pos_y != sizeY-2)
                    pos_y++;
                break;
            case 'd':
                if (pos_x != sizeX-2)
                    pos_x++;
                break;
        }
        }
    private:
    
    protected:
};

        std::uniform_int_distribution<> dis(1, 10);
        std::uniform_int_distribution<> dir(1, 4);  
class enemy{
    private:
      
    public:
        int pos_x, pos_y;
        char marker;
        bool move(int target_x, int target_y){
            int ran = dis(gen);
            if (ran > 5){
                int direction = dir(gen);
                switch (direction){
                    case 1:
                        if (pos_y != 1)
                            pos_y--;
                        break;
                    case 2:
                        if (pos_x != 1)
                            pos_x--;
                        break;
                    case 3:
                        if (pos_y != sizeY-2)
                            pos_y++;
                        break;
                    case 4:
                        if (pos_x != sizeX-2)
                            pos_x++;
                        break;
                }
            }
            else{
                int dir_x = target_x-pos_x;
                int dir_y = target_y-pos_y;
                if (dir_x>0){
                    pos_x++;
                }
                else if (dir_x<0){
                    pos_x--;
                }
                else if (dir_y>0){
                    pos_y++;
                }
                else if (dir_y<0){
                    pos_y--;
                }

            }
            if (target_y == pos_y && target_x == pos_x){
                return false;
           }
           return true;
        }
};


int main(){
    sizeX = 13;
    sizeY = 13;
    hero DrPepper;
    std::vector<enemy> currEnemys;
    enemy rat;
    rat.pos_x = 2;
    rat.pos_y = 2;
    rat.marker = 'r';
    currEnemys.push_back(rat);
    rat.pos_x = 3;
    rat.pos_y = 2;
    currEnemys.push_back(rat);
    DrPepper.pos_x = sizeX/2, DrPepper.pos_y=sizeY/2;
    
    string board[sizeX][sizeY];
    for (int i = 0; i < sizeX; i++){
        for (int j = 0; j < sizeY; j++){
            if ( i==0 || i==sizeX-1 || j==0 || j==sizeY-1){
                board[i][j] = "+";
            }
            else{
                board[i][j] = " ";
            }
        }
    }
    bool alive = true;
    while(alive){
        std::cout <<"[" <<  DrPepper.pos_x << "," << DrPepper.pos_y << "]" << std::endl;
        for (int i = 0; i < sizeX; i++){
            for (int j = 0; j < sizeY; j++){
                bool marked = false;
                for (enemy e : currEnemys){
                    if (i == e.pos_y && j == e.pos_x){
                        cout << setw(2) << left << e.marker;
                        marked = true;
                    }
                }
                if (i == DrPepper.pos_y && j == DrPepper.pos_x && !marked){
                    cout << setw(2) << left << "s";
                }
                else if (!marked){
                    cout << setw(2) << left << board[i][j];
                }
            }
            cout << endl;
        }
        DrPepper.move();

        for (int i = 0; i < currEnemys.size(); i++){
            alive = currEnemys[i].move(DrPepper.pos_x, DrPepper.pos_y);
            if (alive == false){
                break;
            }
        }

        for (int i = 0; i < 30; i++)
            cout << endl;
    }
            for (int i = 0; i < sizeX; i++){
            for (int j = 0; j < sizeY; j++){
                bool marked = false;
                for (enemy e : currEnemys){
                    if (i == e.pos_y && j == e.pos_x){
                        cout << setw(2) << left << e.marker;
                        marked = true;
                    }
                }
                if (i == DrPepper.pos_y && j == DrPepper.pos_x && !marked){
                    cout << setw(2) << left << "s";
                }
                else if (!marked){
                    cout << setw(2) << left << board[i][j];
                }
            }
            cout << endl;
        }
    cout << "GAME OVER!@#!@#!!!@\n You died of the dissentary.\n";
    return 0;
}
