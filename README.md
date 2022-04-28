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
int c = a + b;
```
Print the machine code

```bash
objdump -M intel -D calc | grep -A20 main.: > calc.s
```

Take a look at the row that starts with `1170:` in `calc.s`

```bash
0000000000001149 <main>:
    1149:	f3 0f 1e fa          	endbr64 
    114d:	55                   	push   rbp
    114e:	48 89 e5             	mov    rbp,rsp
    1151:	48 83 ec 20          	sub    rsp,0x20
    1155:	89 7d ec             	mov    DWORD PTR [rbp-0x14],edi
    1158:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
    115c:	c7 45 f4 03 00 00 00 	mov    DWORD PTR [rbp-0xc],0x3
    1163:	c7 45 f8 05 00 00 00 	mov    DWORD PTR [rbp-0x8],0x5
    116a:	8b 55 f4             	mov    edx,DWORD PTR [rbp-0xc]
    116d:	8b 45 f8             	mov    eax,DWORD PTR [rbp-0x8]
    1170:	01 d0                	add    eax,edx
    1172:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax
    1175:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
    1178:	89 c6                	mov    esi,eax
    117a:	48 8d 3d 83 0e 00 00 	lea    rdi,[rip+0xe83]        # 2004 <_IO_stdin_used+0x4>
    1181:	b8 00 00 00 00       	mov    eax,0x0
    1186:	e8 c5 fe ff ff       	call   1050 <printf@plt>
    118b:	b8 00 00 00 00       	mov    eax,0x0
    1190:	c9                   	leave  
    1191:	c3                   	ret    

```