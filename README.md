<h1 align="center">so_long</h1>
<p align="center">Graphic project from 42 school</p>

## WELCOME!
> Hi, Hope you are doing great!
This is my first graphic project in the 42's common core!
The main proposal of this project is to create a 2D game using the MinilibX, witch is a graphic library from 42.
So. To create this little game, witch by the way, was my dream when I was a kid, I have to study and understand how to deal with C structs
and some functions that is avaliable in the MinilibX library.

## Usage:
First you need to clone this rep.
Paste the command bellow in your terminal:
```Shell
git clone https://github.com/PradoAllan/so_long.git <directory_name>
```

Now, enter the directory:
```Shell
cd <directory_name>
```

To use it, first you have to type "make" to compile all the files and create the executable named "so_long".
So, just type "make" in your terminal:
```Shell
make
```

To use it, you have to input the path from the map you want to play. Input example:

> "maps/map.ber".

So the command to start the game should be like that:
```Shell
./so_long maps/map.ber
```
After this, a little window should open for you to play.
Understanding the map:
> The little cone is the walls;`\n`
The red car, witch is a porsche by the way, is the player;\n
The gallon is the collectable that you have to collect;\n
The checkerd flag is the exit (but you can only finish the map when you collect all the gallons).

<h2 align="center">Creating a new map</h2>

The maps are locaated at "maps" file.
To create a new map, first of all, you need to understand how the map works:
	1 = wall;
	0 = floor;
	E = exit;
	C = collectables;
	P = player.

For example:
	111111
	1000E1
	1C0011
	1000P1
	111111

When you create your map, you have to be aware that there are some rules to run the map.
	The map can only have this 5 characters;
	The map must be rectangle. width != height;
	The map must be winnable. All the collectables and the exit should be able for the player to get/go.
	The map must be surrounded by walls, like the example.

Hope this little guide can help you to have fun playing my little 2D game. Feel welcome to get in touch with me on my social medias. I'll be happy to help you with some code!

#BYE!
