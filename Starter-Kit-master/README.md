# Alien vs. Zombie

![Alt text](https://cdn.discordapp.com/attachments/952502284741410867/1070331791405224046/alien_vs_zombie.png)

Alien vs. Zombie is a puzzle game that consist of an Alien, which is the player, and Zombies which are the Alien's enemies.
The goal of the game is to defeat all the Zombies by interacting with different game objects that appear on the game board.

[Video Demo](https://youtu.be/g3EnqruzTTk).

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

Game Settings:

- type 'y' to update board dimensions and zombie count.
- type 'n' to proceed with default settings as displayed.
                
Game Board Objects:

- The numbers on the left and the bottom of the board represents the no. of rows and columns.
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
- 's' represents super cannon ball. Damages the nearest zombie with 100 damage. This objects seeks
to aid with clearing hordes of zombies.
- 'n' represents nuke. Players should try not to interact with this object as every entity on the 
board will lose their lives and this will end up with players losing the game.
                     
Commands:

- When in 'command>' displays, type 'help' to view available commands.
- Commands include: 'up', 'down', 'left', 'right', 'arrow', 'save', 'load', 'quit'

- Up - Alien moves up.
- Down - Alien moves down.
- Left - Alien moves left.
- Right - Alien moves right.
- Arrow - Select an arrow on the board based on row and column number and change its direction. (Eg. 4 5 left)
- Save - Saves current game with file named by player.
- Load - Able to save current game with file named by player and load file named by player.
- Quit - Quit the game.
        
Game Flow:

- The game will continue as long as the Alien is still alive or the Zombies are still alive.
- If the Alien dies, it is game over. If all Zombies die, it is a victory for the player.
- Players should not touch the nuke as it will result in an instant defeat.
- The game can be restarted after the end.

## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

1. Liew Yong Xian
2. Lee Zheng Wei


