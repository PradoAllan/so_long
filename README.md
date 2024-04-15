<h1 align="center">so_long</h1>
<p align="center">Graphic project from 42 school</p>

![image](https://github.com/PradoAllan/so_long/blob/main/prints/Captura%20de%20Tela%202024-04-15%20%C3%A0s%2008.59.52.png)

## WELCOME!
> Hi, Hope you are doing great!
This is my first graphic project in the 42's common core!
The main proposal of this project is to create a 2D game using the MinilibX, witch is a graphic library from 42.
So. To create this little game, witch by the way, was my dream when I was a kid, I have to study and understand how to deal with C structs
and some functions that is avaliable in the MinilibX library.

## IMPORTANT!!!
The game only work in UNIX systems.<br />
So, you can play in Linux and in MacOS.
In MacOS:<br />
	W = UP<br />
 	S = DOWN<br />
  	A = LEFT<br />
   	D = RIGHT<br />
In Linux:<br />
	UP_ARROW = UP<br />
 	DOWN_ARROW = DOWN<br />
  	LEFT_ARROW = LEFT<br />
   	RIGHT_ARROW = RIGHT<br />

## Usage:
First you need to clone this rep.<br />
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
> The little cone is the walls;<br />
The red car, witch is a porsche by the way, is the player;<br />
The gallon is the collectable that you have to collect;<br />
The checkerd flag is the exit (but you can only finish the map when you collect all the gallons).

<h2 align="center">Creating a new map</h2>

## MAPS:
The maps are locaated at "maps" file.<br />
To create a new map, first of all, you need to understand how the map works:<br />
	1 = wall;<br />
	0 = floor;<br />
	E = exit;<br />
	C = collectables;<br />
	P = player.

When you create your map, you have to be aware that there are some rules to run the map.<br />
	The map can only have this 5 characters;<br />
	The map must be rectangle. width != height;<br />
	The map must be winnable. All the collectables and the exit should be able for the player to get/go.<br />
	The map must be surrounded by walls, like the example.<br />

Hope this little guide can help you to have fun playing my little 2D game. Feel welcome to get in touch with me on my social medias. I'll be happy to help you with some code!

#BYE!
