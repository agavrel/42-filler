# Filler Project

## Project Overview
Filler is a 42 Project to learn about AI and also a joint collaboration between <a href="http://www.github.com/BenjaminSouchet">Ben</a> and I on the UI. 
The goal is to be the last player to put a piece, that can have any size and shape, sent by the Virtual Machine.
To put a piece it needs to overlap ONE player's cell and only ONE and not overlap any of the challengers cells. 

<img align="center" src="https://github.com/agavrel/42-Projects/blob/master/filler/filler.gif" width="100%" />

## Strategy
* Strategy is to check relative position compared to challenger.
* Then get close enough from challenger, surround it while maintaining enough distance.
* Once surrounded put pieces the closer we can.

## Features
* Original VM has been slightly modified in order to send the challenger's name to display it on the UI.
* Colors of the board gradually change from green to blue for player 1 and from red to purple for its challenger.
* inside the squares of player 1 we get the color of player 2.
* [not yet implemented] we can see previous state

## Credits
* Many Thanks to my dear friend <a href="http://www.github.com/BenjaminSouchet">Ben</a> for all the hard work on the User Interface.
Please take 5mn to play its awesome <a href="https://github.com/BenjaminSouchet/Wolf3D">Wolf3d project</a>  ;)

## Installation
```
$> make
```

## Usage
```
./filler_vm -f MAP -p1 ./P1_NAME -p2 P2_NAME -v
We can add -q to prevent display in the terminal
Example:
$> ./filler_vm -f maps/map01 -p1 ./angavrel.filler -p2 players/hcao.filler -v -q
```
## Contact & contribute
To contact me and helping me to (fix bugs || improve) FDF, feel free to e-mail me at **angavrel at student dot 42 dot fr**
