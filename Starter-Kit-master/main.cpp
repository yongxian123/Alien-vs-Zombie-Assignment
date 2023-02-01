// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TxxL
// Names: LIEW YONG XIAN | LEE ZHENG WEI
// IDs: 1201103349 | 1201103467
// Emails: 1201103349@student.mmu.edu.my | 1201103467@student.mmu.edu.my
// Phones: 0163871550 | MEMBER_PHONE_2
// *********************************************************

// TODO: Fill in the missing information above and delete this line.

#include "pf/helper.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string commands[9] = {"up", "down", "left", "right", "arrow", "help", "save", "load", "quit"};

class Game
{ 
public:
    void displaySettings();
    bool updateSettings();
    void refreshBoard(Alien alien, Zombie zombies[]);
    void checkObject(char obj, Alien alien);
    void help();
    bool command(Alien alien);
};

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
        void addHealth();
        void addAttack();
        int getHealth();
        int getAttack();
        

};

class Zombie
{
    private:
        int health, atk, range, num, row, col;
        bool turn = false;
    public:
        void changeTurn();
        void getCoordinates();
        void attributes(int noOfZombie);
        void showAttributes();
        void move();
};

void Alien::addHealth()
{
    health += 20;
}

void Alien::addAttack()
{
    atk += 20;
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

void Zombie::getCoordinates()
{
    pf::SetCoordinates(row, col);
}

void Zombie::move()
{

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

void Game::checkObject(char obj, Alien alien)
{
    if(obj == '<' || obj == '>' || obj == '^' || obj == 'v')
    {
        cout << "Alien finds an arrow." << endl;
        alien.addAttack();
        cout << "Alien's attack is increased by 20." << endl << endl;
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
            alien.addHealth();
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
        cout << "(WIP)" << endl << endl;
    }
}

bool Game::command(Alien alien)
{
    string comm_input;
    cout << "command> ";
    cin >> comm_input;
    cout << endl;

    //CHECKING COMMAND INPUT:
    if (comm_input == "up")
    {
        char success = pf::Up(pf::alienRow, pf::alienCol, 0);
        if(success == 'b')
        {
            cout << "A border is blocking the way!" << endl << endl;
            command(alien);
            return false;
        }
        else if(success == 'a')
        {
            cout << "Alien finds an empty space." << endl << endl;
            pf::Pause();
        }
        else if(success == 'c')
        {
            pf::Pause();
        }
        else
        {
            checkObject(success);
            pf::Pause();
        }
    }
    else if (comm_input == "down")
    {
        char success = pf::Down(pf::alienRow, pf::alienCol, 0);
        if(success == 'b')
        {
            cout << "A border is blocking the way!" << endl << endl;
            command(alien);
            return false;
        }
        else if(success == 'a')
        {
            cout << "Alien finds an empty space." << endl << endl;
            pf::Pause();
        }
        else if(success == 'c')
        {
            pf::Pause();
        }
        else
        {
            checkObject(success, alien);
            pf::Pause();
        }
    }
    else if (comm_input == "left")
    {
        char success = pf::Left(pf::alienRow, pf::alienCol, 0);
        if(success == 'b')
        {
            cout << "A border is blocking the way!" << endl << endl;
            command(alien);
            return false;
        }
        else if(success == 'a')
        {
            cout << "Alien finds an empty space." << endl << endl;
            pf::Pause();
        }
        else if(success == 'c')
        {
            pf::Pause();
        }
        else
        {
            checkObject(success);
            pf::Pause();
        }
    }
    else if (comm_input == "right")
    {
        char success = pf::Right(pf::alienRow, pf::alienCol, 0);
        if(success == 'b')
        {
            cout << "A border is blocking the way!" << endl << endl;
            command(alien);
            return false;
        }
        else if(success == 'a')
        {
            cout << "Alien finds an empty space." << endl << endl;
            pf::Pause();
        }
        else if(success == 'c')
        {
            pf::Pause();
        }
        else
        {
            checkObject(success);
            pf::Pause();
        }
    }
    else if (comm_input == "arrow")
    {
    }
    else if (comm_input == "help")
    {
       help();
       pf::Pause();
    }
    else if (comm_input == "save")
    {
        cout << "Feature is not added to the game yet." << endl << endl;
        command(alien);
        return false;
    }
    else if (comm_input == "load")
    {
        cout << "Feature is not added to the game yet." << endl << endl;
        command(alien);
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
            command(alien);
            return false;
        }
        else
        {
            cout << "Command does not exist! Type 'help' to view available commands." << endl << endl;
            command(alien);
            return false;
        }
    }
    else
    {
        cout << "Command does not exist! Type 'help' to view available commands." << endl << endl;
        command(alien);
        return false;
    }

    return true;
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
    alien.showAttributes();
    for(int i = 0; i < pf::kZombies; ++i)
    {
        zombies[i].getCoordinates();
        zombies[i].attributes(i + 1);
        zombies[i].showAttributes();
    }
    cout << endl;
    
    //GAME TURNS LOOPING UNTIL WIN OR LOSE:
    
    while(true)
    {   
        alien.changeTurn();
        game.refreshBoard(alien, zombies);
        alien.changeTurn();
        game.command(alien);
        
        for(int i = 0; i < pf::kZombies; ++i)
        {
            zombies[i].changeTurn();
            game.refreshBoard(alien, zombies);
            zombies[i].changeTurn();
            pf::Pause();
        }
    }
}