# so_long
A simple 2D game.
The player's goal is to gather every collectible from the map. An exit path will show up when this objective is accomplished.
Use WASD or arrow keys to move around.

## Cloning the repo
This repo has a submodule so you'll need to clone it with the command `git clone --recurse-submodules https://github.com/silvatom/so_long.git`.

If you already clone it and the directory `minilibx` is empty, run this command.
`git submodule update --init `.

## Compiling and Running
After cloning the repo, compile everything with `make`. After that, you will have two ways of running the game. Second one is easier than the first.

1. `./so_long <maps/map_name.ber>.` Try `./so_long maps/valid_map1.ber` as an example.
2. use `makefile` targets to easily compile everything up.
    * `make run` easily run the game.
    * `make run_bonus` will run a bit more animated version.