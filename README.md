# girls-and-boys-day

## Prerequisites

-	[Install Git](https://github.com/git-guides/install-git)
-	[Install Visual Studio Code](https://code.visualstudio.com/download)
-	[Install Docker](https://docs.docker.com/get-docker/)

## Get Started
1. Open a terminal or the command line
2. Clone the repo

```bash
git clone https://github.com/piraluc/girls-and-boys-day.git
```
3. Open Visual Studio Code
4. Open the folder `girls-and-boys-day` in Visual Studio Code
5. Start the dev container
6. (Optional) Open Terminal in Visual Studio Code `View -> Terminal`

## Compile the program
```bash
gcc -o hello_world hello_world.c
```
## Execute the program
```bash
./hello_world
Hello World
```
## Take a look behind the scenes
```bash
objdump -M intel -D hello_world | grep -A20 main.: > hello_world.s
```

A similar result should be visible in the file `hello_world.s`
```asm
0000000000001149 <main>:
    1149:	f3 0f 1e fa          	endbr64 
    114d:	55                   	push   rbp
    114e:	48 89 e5             	mov    rbp,rsp
    1151:	48 8d 3d ac 0e 00 00 	lea    rdi,[rip+0xeac]        # 2004 <_IO_stdin_used+0x4>
    1158:	e8 f3 fe ff ff       	call   1050 <puts@plt>
    115d:	b8 00 00 00 00       	mov    eax,0x0
    1162:	5d                   	pop    rbp
    1163:	c3                   	ret    
    1164:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
    116b:	00 00 00 
    116e:	66 90                	xchg   ax,ax

0000000000001170 <__libc_csu_init>:
    1170:	f3 0f 1e fa          	endbr64 
    1174:	41 57                	push   r15
    1176:	4c 8d 3d 3b 2c 00 00 	lea    r15,[rip+0x2c3b]        # 3db8 <__frame_dummy_init_array_entry>
    117d:	41 56                	push   r14
    117f:	49 89 d6             	mov    r14,rdx
    1182:	41 55                	push   r13
    1184:	49 89 f5             	mov    r13,rsi
```

## Can you calculate 3+5?
```bash
gcc -o calc calc.c
./calc
Result is 8
```
Where is the add operation exactly?
```C
int a = 3, b = 5;
int c = a + b;
```
Print the machine code

```bash
objdump -M intel -D calc | grep -A20 main.: > calc.s
```

Take a look at the lines that starts with `1155:` and `115c:` in `calc.s`. There at the end we can find the two numbers `0x3` and `0x5` aka 3 and 5. And in line `1169` we see the `add` operation that means "+". In `117f:` the `printf` function is called.

```asm
0000000000001149 <main>:
    1149:	f3 0f 1e fa          	endbr64 
    114d:	55                   	push   rbp
    114e:	48 89 e5             	mov    rbp,rsp
    1151:	48 83 ec 10          	sub    rsp,0x10
    1155:	c7 45 f4 03 00 00 00 	mov    DWORD PTR [rbp-0xc],0x3
    115c:	c7 45 f8 05 00 00 00 	mov    DWORD PTR [rbp-0x8],0x5
    1163:	8b 55 f4             	mov    edx,DWORD PTR [rbp-0xc]
    1166:	8b 45 f8             	mov    eax,DWORD PTR [rbp-0x8]
    1169:	01 d0                	add    eax,edx
    116b:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax
    116e:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
    1171:	89 c6                	mov    esi,eax
    1173:	48 8d 3d 8a 0e 00 00 	lea    rdi,[rip+0xe8a]        # 2004 <_IO_stdin_used+0x4>
    117a:	b8 00 00 00 00       	mov    eax,0x0
    117f:	e8 cc fe ff ff       	call   1050 <printf@plt>
    1184:	b8 00 00 00 00       	mov    eax,0x0
    1189:	c9                   	leave
    118a:	c3                   	ret
    118b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
```
