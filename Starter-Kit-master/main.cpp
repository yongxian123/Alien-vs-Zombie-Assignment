// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T14L
// Names: LIEW YONG XIAN | LEE ZHENG WEI
// IDs: 1201103349 | 1201103467
// Emails: 1201103349@student.mmu.edu.my | 1201103467@student.mmu.edu.my
// Phones: 0163871550 | 0124742932
// *********************************************************

#include "pf/helper.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string commands[9] = {"up", "down", "left", "right", "arrow", "help", "save", "load", "quit"};



class Alien
{
    private:
        int health = 100;
        int atk = 0;
        bool turn = false;
    public:
        void changeTurn();
        void attributes();
        void showAttributes();
        void changeHealth(int currhp);
        void changeAttack(int curratk);
        int getHealth();
        int getAttack();
        

};

class Zombie
{
    private:
        int health, atk, range, num, row, col;
        bool turn = false;
    public:
        void checkAlive();
        void changeHealth(int currhp);
        void changeTurn();
        void getCoordinates(int zombieNum);
        void attributes(int noOfZombie);
        void showAttributes();
        bool move(int zombieNum);
        void attack(int zombieNum, Alien &alien);
        int getHealth();
        int getAttack();
};

class Game
{
private:
    bool arrowMove = false;
    char arrowObj;
public:
    
    bool arrow(char& obj, Alien& alien, Zombie zombies[]);
    void displaySettings();
    bool updateSettings();
    void refreshBoard(Alien alien, Zombie zombies[]);
    void checkObject(char obj, Alien& alien, Zombie zombies[]);
    void help();
    bool command(Alien& alien, Zombie zombies[]);
};


void Alien::changeHealth(int currhp)
{
    health = currhp;
}


void Alien::changeAttack(int curratk)
{
    atk = curratk;
}


int Alien::getHealth()
{
    return health;
}

int Alien::getAttack()
{
    return atk;
}


void Alien::changeTurn()
{
    if(turn == false)
    {
        turn = true;
    }
    else
    {
        turn = false;
    }
}

void Alien::showAttributes()
{
    if(turn == true)
    {
        cout << " ->";
    }
    else
    {
        cout << "   ";
    }
    cout << "Alien     : ";
    cout << "Life ";
    cout.width(3);
    cout << health << ", " << "Attack ";
    cout.width(2);
    cout << atk << endl;
    
}

void Alien::attributes()
{

}

void Zombie::checkAlive()
{
    if(health <= 0)
    {
        cout << "Zombie " << num << " died from the attack!" << endl << endl;
        pf::deleteEntity(row, col);
    }
    else
    {
        cout << "Zombie " << num << " survived the attack!" << endl << endl; 
    }
}

void Zombie::changeHealth(int currhp)
{
    health = currhp;
}

int Zombie::getHealth()
{
    return health;
}

int Zombie::getAttack()
{
    return atk;
}

void Zombie::getCoordinates(int zombieNum)
{
    pf::SetCoordinates(row, col, zombieNum);
}

bool Zombie::move(int ZombieNum)
{
    int zombieMove = rand() % 4;  // Generate a random number between 0 and 3
    char success;
    switch (zombieMove) {
        case 0: // move up
            cout << "Zombie " << ZombieNum + 1 << " moves up." << endl << endl;
            success = pf::Up(row, col, 1, false);
            break;
        case 1: // move down
            cout << "Zombie " << ZombieNum + 1 << " moves down." << endl << endl;
            success = pf::Down(row, col, 1, false);
            break;
        case 2: // move left
            cout << "Zombie " << ZombieNum + 1 << " moves left." << endl << endl;
            success = pf::Left(row, col, 1, false);
            break;
        case 3: // move right
            cout << "Zombie " << ZombieNum + 1 << " moves right." << endl << endl;
            success = pf::Right(row, col, 1, false);
            break;
    }

    if (success == 'c')
    {
        //cout << "Zombie " << ZombieNum + 1 << " finds an empty space." << endl;
        return true;
    }
    else if (success == 'd')
    {
        move(ZombieNum);
        return false;
    }

    return true;

}

void Zombie::attack(int ZombieNum, Alien &alien)
{
 
    if (abs(row - pf::alienRow) <= range && abs(col - pf::alienCol) <= range) 
    {
        int currAlienHealth = alien.getHealth() - atk;
        alien.changeHealth(currAlienHealth);
        cout << "Zombie " << num << " attacked Alien with " << atk << " damage!" << endl << endl;
    }
    else
    {
        cout << "Zombie " << num << " could not reach the Alien!" << endl << endl;
    }
}



void Zombie::changeTurn()
{
    if(turn == false)
    {
        turn = true;
    }
    else
    {
        turn = false;
    }
}

void Zombie::showAttributes()
{
    if(turn == true)
    {
        cout << " ->";
    }
    else
    {
        cout << "   ";
    }
    cout << "Zombie ";
    cout.width(2);
    cout << num << " : " << "Life ";
    cout.width(3);
    cout << health << ", " << "Attack ";
    cout.width(2);
    cout << atk << ", " << "Range " << range << endl;
}

void Zombie::attributes(int noOfZombie)
{
    num = noOfZombie;

    int rand_health = rand() % 4 + 1;
    int rand_atk = rand() % 3 + 1;
    int rand_range = rand() % 2 + 1;

    if(rand_health == 1)
    {
        health = 50;
    }
    else if(rand_health == 2)
    {
        health = 100;
    }
    else if(rand_health == 3)
    {
        health = 150;
    }
    else if(rand_health == 4)
    {
        health = 200;
    }
    else
    {
        health = 250;
    }

    if(rand_atk == 1)
    {
        atk = 5;
    }
    else if(rand_atk == 2)
    {
        atk = 10;
    }
    else
    {
        atk = 15;
    }

    if(rand_range == 1)
    {
        range = 1;
    }
    else if(rand_range == 2)
    {
        range = 2;
    }
    else
    {
        range = 3;
    }

}

void Game::help()
{
    cout << "Commands" << endl;
    cout << "1. up      - Move up." << endl;
    cout << "2. down    - Move down." << endl;
    cout << "3. left    - Move left." << endl;
    cout << "4. right   - Move right." << endl;
    cout << "5. arrow   - Change the direction of an arrow." << endl;
    cout << "6. help    - Display these user commands." << endl;
    cout << "7. save    - Save the game." << endl;
    cout << "8. load    - Load a game." << endl;
    cout << "9. quit    - Quit the game." << endl;
}

void Game::refreshBoard(Alien alien, Zombie zombies[])
{
    pf::ClearScreen();
    pf::ShowGameBoard();
    alien.showAttributes();
    for(int i = 0; i < pf::kZombies; ++i)
    {
        zombies[i].showAttributes();
    }
    cout << endl;
}

bool Game::arrow(char& obj, Alien& alien, Zombie zombies[])
{

    if(arrowObj == '<' || arrowObj == '>' || arrowObj == '^' || arrowObj == 'v')
    {
        obj = arrowObj;
    }

    if(obj == '^')
    {
        arrowObj = pf::Up(pf::alienRow, pf::alienCol, 0, true);

        if(arrowObj == 'b')
        {
            cout << "A border is blocking the way!" << endl << endl;
            cout << "Trails are randomized into random objects." << endl << endl;
            pf::Pause();
            return true;
        }
        else if(arrowObj == 'a')
        {
            cout << "Alien finds an empty space." << endl << endl;
            pf::Pause();
        }
        else if(arrowObj == '1' || arrowObj == '2' || arrowObj == '3' || arrowObj == '4' || arrowObj == '5')
        {
            int numOfZombie = arrowObj - '0';
            int currhp = zombies[numOfZombie - 1].getHealth() - alien.getAttack();
            zombies[numOfZombie - 1].changeHealth(currhp);
            cout << "Alien attacked Zombie " << numOfZombie << " with " << alien.getAttack() << " damage!" << endl;
            zombies[numOfZombie - 1].checkAlive();
            
            pf::Pause();
            return true;
        }
        else if(arrowObj == 'r')
        {
            checkObject(arrowObj, alien, zombies);
            pf::Pause();
            return true;
        }
        else
        {
            checkObject(arrowObj, alien, zombies);
            pf::Pause();
        }

        refreshBoard(alien, zombies);
        arrow(obj, alien, zombies);
        return false;
    }
    else if(obj == 'v')
    {
        arrowObj = pf::Down(pf::alienRow, pf::alienCol, 0, true);

        if(arrowObj == 'b')
        {
            cout << "A border is blocking the way!" << endl << endl;
            cout << "Trails are randomized into random objects." << endl << endl;
            pf::Pause();
            return false;
        }
        else if(arrowObj == 'a')
        {
            cout << "Alien finds an empty space." << endl << endl;
            pf::Pause();
        }
        else if(arrowObj == 'c')
        {
            pf::Pause();
        }
        else if(arrowObj == '1' || arrowObj == '2' || arrowObj == '3' || arrowObj == '4' || arrowObj == '5')
        {
            int numOfZombie = arrowObj - '0';
            int currhp = zombies[numOfZombie - 1].getHealth() - alien.getAttack();
            zombies[numOfZombie - 1].changeHealth(currhp);
            cout << "Alien attacked Zombie " << numOfZombie << " with " << alien.getAttack() << " damage!" << endl;
            zombies[numOfZombie - 1].checkAlive();
            
            pf::Pause();
            return true;
        }
        else if(arrowObj == 'r')
        {
            checkObject(arrowObj, alien, zombies);
            pf::Pause();
            return true;
        }
        else
        {
            checkObject(arrowObj, alien, zombies);
            pf::Pause();
        }

        refreshBoard(alien, zombies);
        arrow(obj, alien, zombies);
        return false;
    }
    else if(obj == '<')
    {
        arrowObj = pf::Left(pf::alienRow, pf::alienCol, 0, true);

        if(arrowObj == 'b')
        {
            cout << "A border is blocking the way!" << endl << endl;
            cout << "Trails are randomized into random objects." << endl << endl;
            pf::Pause();
            return false;
        }
        else if(arrowObj == 'a')
        {
            cout << "Alien finds an empty space." << endl << endl;
            pf::Pause();
        }
        else if(arrowObj == 'c')
        {
            pf::Pause();
        }
        else if(arrowObj == '1' || arrowObj == '2' || arrowObj == '3' || arrowObj == '4' || arrowObj == '5')
        {
            int numOfZombie = arrowObj - '0';
            int currhp = zombies[numOfZombie - 1].getHealth() - alien.getAttack();
            zombies[numOfZombie - 1].changeHealth(currhp);
            cout << "Alien attacked Zombie " << numOfZombie << " with " << alien.getAttack() << " damage!" << endl;
            zombies[numOfZombie - 1].checkAlive();
            
            pf::Pause();
            return true;
        }
        else if(arrowObj == 'r')
        {
            checkObject(arrowObj, alien, zombies);
            pf::Pause();
            return true;
        }
        else
        {
            checkObject(arrowObj, alien, zombies);
            pf::Pause();
        }

        refreshBoard(alien, zombies);
        arrow(obj, alien, zombies);
        return false;
    }
    else if(obj == '>')
    {
        arrowObj = pf::Right(pf::alienRow, pf::alienCol, 0, true);

        if(arrowObj == 'b')
        {
            cout << "A border is blocking the way!" << endl << endl;
            cout << "Trails are randomized into random objects." << endl << endl;
            pf::Pause();
            return false;
        }
        else if(arrowObj == 'a')
        {
            cout << "Alien finds an empty space." << endl << endl;
            pf::Pause();
        }
        else if(arrowObj == 'c')
        {
            pf::Pause();
        }
        else if(arrowObj == '1' || arrowObj == '2' || arrowObj == '3' || arrowObj == '4' || arrowObj == '5')
        {
            int numOfZombie = arrowObj - '0';
            int currhp = zombies[numOfZombie - 1].getHealth() - alien.getAttack();
            zombies[numOfZombie - 1].changeHealth(currhp);
            cout << "Alien attacked Zombie " << numOfZombie << " with " << alien.getAttack() << " damage!" << endl;
            zombies[numOfZombie - 1].checkAlive();
            
            pf::Pause();
            return true;
        }
        else if(arrowObj == 'r')
        {
            checkObject(arrowObj, alien, zombies);
            pf::Pause();
            return true;
        }
        else
        {
            checkObject(arrowObj, alien, zombies);
            pf::Pause();
        }

        refreshBoard(alien, zombies);
        arrow(obj, alien, zombies);
        return false;
    }

    return true;
}

void Game::checkObject(char obj, Alien& alien, Zombie zombies[])
{
    if(obj == '<' || obj == '>' || obj == '^' || obj == 'v')
    {
        arrowMove = true;
        arrowObj = obj;

        cout << "Alien finds an arrow." << endl;
        int curratk = alien.getAttack() + 20;
        alien.changeAttack(curratk);
        cout << "Alien's attack has increased by 20!" << endl << endl;
    }
    else if(obj == 'h')
    {
        cout << "Alien finds a health pad." << endl;

        if(alien.getHealth() == 100)
        {
            cout << "Alien's health is already full." << endl << endl;
        }
        else
        {
            int newHealth = alien.getHealth() + 20;
            alien.changeHealth(newHealth);
            cout << "Alien's life is increased by 20." << endl << endl;
        }
         
        
    }
    else if(obj == 'p')
    {
        cout << "Alien finds a pod." << endl;
        cout << "(WIP)" << endl << endl;
    }
    else if(obj == 'r')
    {
        cout << "Alien stumbles upon a rock." << endl;
        
        int rand_object = rand() % 6;
        int chosen_object;
        string nameOfObject;
        switch(rand_object){
            case 0:
                chosen_object = 'h';
                break;
            case 1:
                chosen_object = 'p';
                break;
            case 2:
                chosen_object = '<';
                break;
            case 3:
                chosen_object = '>';
                break;
            case 4:
                chosen_object = 'v';
                break;
            case 5:
                chosen_object = '^';
                break;
        }
        pf::rock(chosen_object);
        
        if(chosen_object == 'h')
        {
            nameOfObject = "health pad";
        }
        else if(chosen_object == 'p')
        {
            nameOfObject = "attack pod";
        }
        else if(chosen_object == '<' || chosen_object == 'v' || chosen_object == '<' || chosen_object == '>')
        {
            nameOfObject = "arrow";
        }

        cout << "A " << nameOfObject << " was under the rock." << endl << endl;

    }
    
}

bool Game::command(Alien& alien, Zombie zombies[])
{
    char obj;
    string comm_input;
    cout << "command> ";
    cin >> comm_input;
    cout << endl;

    //CHECKING COMMAND INPUT:
    if (comm_input == "up")
    {
        obj = '^';
        char success = pf::Up(pf::alienRow, pf::alienCol, 0, false);
        if(success == 'b')
        {
            cout << "A border is blocking the way!" << endl << endl;
            command(alien, zombies);
            return false;
        }
        else if(success == 'a')
        {
            cout << "Alien finds an empty space." << endl << endl;
            pf::Pause();
        }
        else if(success == '1' || success == '2' || success == '3' || success == '4' || success == '5')
        {
            int numOfZombie = success - '0';
            int currhp = zombies[numOfZombie - 1].getHealth() - alien.getAttack();
            zombies[numOfZombie - 1].changeHealth(currhp);
            cout << "Alien attacked Zombie " << numOfZombie << " with " << alien.getAttack() << " damage!" << endl << endl;
            zombies[numOfZombie - 1].checkAlive();
            pf::Pause();
        }
        else
        {
            checkObject(success, alien, zombies);
            pf::Pause();
        }
    }
    else if (comm_input == "down")
    {
        obj = 'v';
        char success = pf::Down(pf::alienRow, pf::alienCol, 0, false);
        if(success == 'b')
        {
            cout << "A border is blocking the way!" << endl << endl;
            command(alien, zombies);
            return false;
        }
        else if(success == 'a')
        {
            cout << "Alien finds an empty space." << endl << endl;
            pf::Pause();
        }
        else if(success == '1' || success == '2' || success == '3' || success == '4' || success == '5')
        {
            int numOfZombie = success - '0';
            int currhp = zombies[numOfZombie - 1].getHealth() - alien.getAttack();
            zombies[numOfZombie - 1].changeHealth(currhp);
            cout << "Alien attacked Zombie " << numOfZombie << " with " << alien.getAttack() << " damage!" << endl << endl;
            zombies[numOfZombie - 1].checkAlive();
            pf::Pause();
        }
        else
        {
            checkObject(success, alien, zombies);
            pf::Pause();
        }
    }
    else if (comm_input == "left")
    {
        obj = '<';
        char success = pf::Left(pf::alienRow, pf::alienCol, 0, false);
        if(success == 'b')
        {
            cout << "A border is blocking the way!" << endl << endl;
            command(alien, zombies);
            return false;
        }
        else if(success == 'a')
        {
            cout << "Alien finds an empty space." << endl << endl;
            pf::Pause();
        }
        else if(success == '1' || success == '2' || success == '3' || success == '4' || success == '5')
        {
            int numOfZombie = success - '0';
            int currhp = zombies[numOfZombie - 1].getHealth() - alien.getAttack();
            zombies[numOfZombie - 1].changeHealth(currhp);
            cout << "Alien attacked Zombie " << numOfZombie << " with " << alien.getAttack() << " damage!" << endl << endl;
            zombies[numOfZombie - 1].checkAlive();
            pf::Pause();
        }
        else
        {
            checkObject(success, alien, zombies);
            pf::Pause();
        }
    }
    else if (comm_input == "right")
    {
        obj = '>';
        char success = pf::Right(pf::alienRow, pf::alienCol, 0, false);
        if(success == 'b')
        {
            cout << "A border is blocking the way!" << endl << endl;
            command(alien, zombies);
            return false;
        }
        else if(success == 'a')
        {
            cout << "Alien finds an empty space." << endl << endl;
            pf::Pause();
        }
        else if(success == '1' || success == '2' || success == '3' || success == '4' || success == '5')
        {
            int numOfZombie = success - '0';
            int currhp = zombies[numOfZombie - 1].getHealth() - alien.getAttack();
            zombies[numOfZombie - 1].changeHealth(currhp);
            cout << "Alien attacked Zombie " << numOfZombie << " with " << alien.getAttack() << " damage!" << endl << endl;
            zombies[numOfZombie - 1].checkAlive();
            pf::Pause();
        }
        else
        {
            checkObject(success, alien, zombies);
            pf::Pause();
        }
    }
    else if (comm_input == "arrow")
    {
        int newRow, newCol;
        string strDir;
        char newDir;
        cout << "Enter row, column, and direction: ";
        cin >> newRow;
        cin >> newCol;
        cin >> strDir;

        if (strDir == "up")
        {
            newDir = '^';
        }
        else if (strDir == "down")
        {
            newDir = 'v';
        }
        else if (strDir == "left")
        {
            newDir = '<';
        }
        else if (strDir == "right")
        {
            newDir = '>';
        }
        else
        {
            cout << "Invalid Direction! There is only up/down/left/right." << endl << endl;
            command(alien, zombies);
            return false;
        }

        bool insertArrow = pf::changeArrow(5 - newRow, newCol - 1, newDir);
        if (insertArrow == false)
        {
            cout << "The arrow in this row and column does not exist!" << endl << endl;
        }
    }
    else if (comm_input == "help")
    {
       help();
       command(alien, zombies);
       return false;
    }
    else if (comm_input == "save")
    {
        cout << "Feature is not added to the game yet." << endl << endl;
        command(alien, zombies);
        return false;
    }
    else if (comm_input == "load")
    {
        cout << "Feature is not added to the game yet." << endl << endl;
        command(alien, zombies);
        return false;
    }
    else if (comm_input == "quit")
    {
        char quit;
        cout << "Are you sure? (y/n): " << endl;
        cin >> quit;

        if (quit == 'y')
        {
            cout << endl;
            cout << "Goodbye!";
            return false;
        }
        else if (quit == 'n')
        {
            command(alien, zombies);
            return false;
        }
        else
        {
            cout << "Command does not exist! Type 'help' to view available commands." << endl << endl;
            command(alien, zombies);
            return false;
        }
    }
    else
    {
        cout << "Command does not exist! Type 'help' to view available commands." << endl << endl;
        command(alien, zombies);
        return false;
    }

    if(arrowMove)
    {
        alien.changeAttack(0);
        refreshBoard(alien, zombies);
        arrow(obj, alien, zombies);
        pf::resetTrail();
        arrowMove = false;
    }
    
    return false;
}

bool Game::updateSettings()
{
    pf::ClearScreen();

    int tempRow, tempColumn, tempZombies;

    cout << "Board Settings" << endl;
    cout << "----------------" << endl;
    cout << "*Board dimensions must be in odd numbers." << endl
         << endl;
    cout << "Enter rows => ";
    cin >> tempRow;
    cout << endl;
    cout << "Enter columns => ";
    cin >> tempColumn;

    if (tempRow % 2 == 0 || tempColumn % 2 == 0)
    {
        cout << endl;
        cout << "Board dimensions must be in odd numbers!" << endl;
        pf::Pause();
        pf::ClearScreen();
        updateSettings();
        return false;
    }
    else
    {
        pf::kRows = tempRow;
        pf::kColumns = tempColumn;
    }
    cout << endl
         << endl;

    cout << "Zombie Settings" << endl;
    cout << "----------------" << endl;
    cout << "*Only 5 zombies maximum." << endl << endl;
    cout << "Enter number of zombies => ";
    cin >> tempZombies;

    if (tempZombies > 5)
    {
        cout << "*Only 5 zombies maximum are allowed!" << endl;
        pf::Pause();
        pf::ClearScreen();
        updateSettings();
        return false;
    }
    else
    {
        pf::kZombies = tempZombies;
        cout << endl << endl;
        cout << "Settings Updated." << endl;
    }

    return true;
}

void Game::displaySettings()
{
    char inputChar;

    cout << "Default Game Settings" << endl;
    cout << "-----------------------" << endl;
    cout << "Board Rows    : " << pf::kRows << endl;
    cout << "Board Columns : " << pf::kColumns << endl;
    cout << "Zombie Count  : " << pf::kZombies << endl;
    cout << endl
         << endl;
    cout << "Do you wish to change the game settings (y/n)? => ";
    cin >> inputChar;

    if (inputChar == 'y')
    {
        updateSettings();
    }
    else if (inputChar == 'n')
    {
    }
    else
    {
        pf::ClearScreen();
        displaySettings();
    }
}

void createGameBoard()
{
    pf::ClearScreen();
    pf::CreateGameBoard(pf::alienRow, pf::alienCol);
    pf::ShowGameBoard();
    
    //--YONG XIAN STOPPED AT ATTRIBUTES!
    
    
}

int main()
{
    pf::ClearScreen();
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    
    //TEMPORARY START SCREEN:
    Game game;
    game.displaySettings();
    pf::Pause();

    //BOARD DISPLAY, RANDOMIZE AND SHOW ATTRIBUTES:
    createGameBoard();

    Alien alien;
    Zombie zombies[pf::kZombies];

    cout << pf::kZombies << endl;
    alien.showAttributes();
    for(int i = 0; i < pf::kZombies; ++i)
    {
        cout << i << endl;
        zombies[i].getCoordinates(i);
        zombies[i].attributes(i + 1);
        zombies[i].showAttributes();
        cout << "attributes shown." << endl;
    }
    cout << endl;

    //GAME TURNS LOOPING UNTIL WIN OR LOSE:
    
    while(true)
    {   
        alien.changeTurn();
        game.refreshBoard(alien, zombies);
        alien.changeTurn();
        game.command(alien, zombies);
        
        for(int i = 0; i < pf::kZombies; ++i)
        {
            zombies[i].changeTurn();
            game.refreshBoard(alien, zombies);
            zombies[i].move(i);
            pf::Pause();
            game.refreshBoard(alien, zombies);
            zombies[i].attack(i, alien);
            zombies[i].changeTurn();
            pf::Pause();
        }
    }
}
