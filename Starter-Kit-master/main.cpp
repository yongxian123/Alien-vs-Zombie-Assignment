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

};

class Zombie
{
    private:
        int health, atk, range, num;
        bool turn = false;
    public:
        void changeTurn();
        void attributes(int noOfZombie);
        void showAttributes();
};

class Game
{
private:
    
public:
    void displaySettings();
    bool updateSettings();
    void refreshBoard(Alien alien, Zombie zombies[]);
    bool command();
};



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

void Game::refreshBoard(Alien alien, Zombie zombies[])
{
    pf::ClearScreen();
    pf::ShowGameBoard();
    alien.showAttributes();
    for(int i = 0; i < pf::kZombies; ++i)
    {
        zombies[i].showAttributes();
    }
}

bool Game::command()
{
    string comm_input;
    cout << endl << "command> ";
    cin >> comm_input;

    //CHECKING COMMAND INPUT:
    if (comm_input == "up")
    {
        pf::Up(pf::alienRow, pf::alienCol);
        pf::Pause();
    }
    else if (comm_input == "down")
    {
        pf::Down(pf::alienRow, pf::alienCol);
        pf::Pause();
    }
    else if (comm_input == "left")
    {
        pf::Left(pf::alienRow, pf::alienCol);
        pf::Pause();
    }
    else if (comm_input == "right")
    {
        pf::Right(pf::alienRow, pf::alienCol);
        pf::Pause();
    }
    else if (comm_input == "arrow")
    {
    }
    else if (comm_input == "help")
    {
    }
    else if (comm_input == "save")
    {
    }
    else if (comm_input == "load")
    {
    }
    else if (comm_input == "quit")
    {
    }
    else
    {
        cout << "*Command does not exist! Type 'help' to view available commands." << endl;
        command();
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
        zombies[i].attributes(i + 1);
        zombies[i].showAttributes();
    }
    
    //GAME TURNS LOOPING UNTIL WIN OR LOSE:
    
    while(true)
    {   
        alien.changeTurn();
        game.refreshBoard(alien, zombies);
        alien.changeTurn();
        game.command();
        
        for(int i = 0; i < pf::kZombies; ++i)
        {
            /*if(i > 0)
            {
                zombies[i - 1].changeTurn();
            }*/
            zombies[i].changeTurn();
            game.refreshBoard(alien, zombies);
            zombies[i].changeTurn();
            pf::Pause();
        }
    }
}