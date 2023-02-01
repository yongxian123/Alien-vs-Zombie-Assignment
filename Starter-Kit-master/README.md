# Alien vs. Zombie

Alien vs. Zombie is a puzzle game that consist of an Alien, which is the player, and Zombies which are the Alien's enemies.
The goal of the game is to defeat all the Zombies by interacting with different game objects that appear on the game board.

You may add one signature screenshot of your program here or above the title. Check out [this tutorial](https://www.digitalocean.com/community/tutorials/markdown-markdown-images) to learn how to do it.

Please provide the YouTube link to your [Video Demo](https://youtube.com).

## Compilation Instructions

Make sure the file directory is correct.

To compile the program, run in terminal:

```
g++ pf\*.cpp main.cpp
```

And to start the program, type for example:

```
.\a
```

## User Manual

Here are the components in the program:

Game Settings - type 'y' to update board dimensions and zombie count.
                type 'n' to proceed with default settings as displayed.
                
Game Board Objects - The numbers on the left and the bottom of the board represents the no. of rows and columns.
                   - 'A' represents Alien, which is the player's character.
                   - Numbers on the board represents the Zombies. '1' being Zombie 1 and '2' being Zombie 2.
                   - 'p' represents pod. Attacks nearest zombie on the board with 10 damage.
                   - 'h' represents health pad, heals Alien by 20 if Alien is not in full health.
                   - 'r' represents rock, reveals a random pickable game object ('p', 'h', '<', '>', 'v', '^')
                   - '<' or '>' or 'v' or '^' represent arrows. Alien will continuously move towards the direction of
                     the arrow until stopped by border or hits an alien. If another arrow is interacted along the way,
                     changes direction according to the arrow. Each arrow adds Alien's attack by 20 and this can be
                     stacked. If an alien is hit along the way, deals the accumulated damage towards zombie. Every
                     movement leaves a trail object on the previous position of the Alien.
                   - '.' represents trail. Turns into random pickable game object after Alien's turn.
                     
Commands - When in 'command>' displays, type 'help' to view available commands.
         - Commands include: 'up', 'down', 'left', 'right', 'arrow', 'save', 'load', 'quit'
        
Game Flow - The game will continue as long as the Alien is still alive or the Zombies are still alive.
          - If the Alien dies, it is game over. If all Zombies die, it is a victory for the player.
          - The game can be restarted after the end.

## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

-Liew Yong Xian
-Lee Zheng Wei


