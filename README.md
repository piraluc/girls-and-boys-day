# girls-and-boys-day

## Prerequisites

-	[Install Git](https://github.com/git-guides/install-git)
-	[Install Visual Studio Code](https://code.visualstudio.com/download)
-	[Install Docker](https://docs.docker.com/get-docker/)

## Get Started
1. Open a terminal or the command line
2. Clone the repo

```
> git clone https://github.com/piraluc/girls-and-boys-day.git
```
3. Open Visual Studio Code
4. Open the folder `girls-and-boys-day` in Visual Studio Code
5. Start the dev container
6. (Optional) Open Terminal in Visual Studio Code `View -> Terminal`

## Compile the program
```
> gcc -o hello_world hello_world.c
```
## Execute the program
```
> ./hello_world
> Hello World
````
## Take a look behind the scenes
```
objdump -M intel -D hello_world | grep -A20 main.: > hello_world.s
```