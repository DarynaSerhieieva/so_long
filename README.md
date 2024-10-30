# So Long - A 2D Game with MiniLibX
## Game Objective
Your character starts at a designated position on a maze-like map. The goal is:

1. Collect All Collectibles: Pick up all items (collectibles) scattered around the map.
2. Find the Exit: Once all collectibles are collected, reach the exit to win the game.
## Installation
1. Clone this repository:
  ```sh
  git clone https://github.com/DarynaSerhieieva/so_long.git
  ```
2. Enter the folder
  ```sh
  cd so_long
  ```
3. Compile the project using make:
   ```sh
   make all
   ```
4. You should see an executable called so_long
## Usage
To start the game, run:
```sh
./so_long ./maps/map1.ber
```
I have included several valid maps in folder ./maps named map1.ber, map2.ber, ..., map5.ber. You can also create your own custom map by following the map format guidelines.

Additionally, I have provided some maps with intentional errors to demonstrate error handling; these maps are named err1.ber, err2.ber, ..., err7.ber.
## Controls
- **W** - Move Up
- **A** - Move Left
- **S** - Move Down
- **D** - Move Right
- **ESC** - Exit the Game
## Map Format
Maps must have a .ber extension and follow these rules:

- Walls are represented by 1
- Empty spaces are represented by 0
- Collectibles are represented by C
- Player starting position is represented by P
- Exit is represented by E
  Example map:
  ```
  111111
  1P0C01
  101001
  1C0E11
  111111
  ```
## Map Rules
- The map must be surrounded by walls (1) on all edges.
- There should be exactly one player start position (P) and one exit (E).
- There must be at least one collectible (C) on the map.
- The map must be rectangular.
## How to change size
I have included two folders, img_50 and img_100, to allow you to adjust the game’s size. By default, the game uses images with a size of 100 pixels, but you can switch to 50 pixels if preferred.

To change the game size to 50:

- Open ./includes/so_long.h and go to line 21. Change the line '# define SIZE_IMG 100' to '# define SIZE_IMG 50'.
-  Next, go to the ../src folder and open the ft_utils.c file. In the render_img function, update each line that references "./img_100/..." to "./img_50/...", simply replacing 100 with 50 for each image path.
- After saving these changes, recompile and run the program, and it will display at the smaller size.
