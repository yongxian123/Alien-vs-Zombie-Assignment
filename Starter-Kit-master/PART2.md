# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtu.be/g3EnqruzTTk).

## Minimum Requirements

### Completed

List all the features completed.

1. Game board
2. Character attributes (Alien & Zombies)
3. Movement and Attack
4. Multiple Zombies (At least 1 and up to 9 maximum)
5. Game Objects (Health, Pod, Rock, Arrow, Trail, Empty)
6. Game Controls (Up, Down, Left Right, Arrow, Save, Load, Quit)
7. Saving and Loading Game File
8. Game Flow

## Additional Features

1. Super Cannonball Object (Deals 100 damage to nearby zombie; works as a fast game test object) (s)
2. Nuke Object (Every character dies in the board but counts as the Alien's loss; players should not touch the nuke) (n)

## Contributions

List down the contribution of each group members.

### Liew Yong Xian

1. Randomly generate game board.
2. Character attributes.
3. Game controls.
4. Multiple zombies.
5. Arrow & Trail Object.
7. Save and Loading Game File.

### Lee Zheng Wei

1. Zombie movement and attack behaviour.
2. Attack pod.
3. Health pad.
5. Super Cannonball Object.
6. Nuke object.
7. Game Flow.

## Problems Encountered & Solutions

1. Program halting unexpectly at random times: We noticed that the cause of this was due to one Zombie taking over the position of another Zombie which caused their positions to be mixed and this greatly affected the behaviours of Zombies and their displayed attributes. This in turn had affected certain parts of the program to not run and be eventually put to a stop.

2. Unable to load the correct Alien position: This issue was resolved upon noticing missing data of the Alien class to be read. The issue was that the Alien did appear in the correct cell of the board when loaded as intended however the program did not keep track of the correct coordinates of the Alien in order to act towards game commands correctly.
