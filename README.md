 <p align="center">
<h1> Simple Shell </h1></p>

 <p>In this second project we created a Shell based on the Bourne shell (sh) shell command line interpreter for computer operating systems.</p>

<h3>Description<h3> 

<p>A Unix shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.</p>


<h3> Instructions🚀 <h3>

<p>To download the SHELL and run it first they should follow these steps:</p>

<p>1. Install vagrant, wsl, visual studio code or a virtual machine.</p>

```
sudo apt-get install vagrant
```

<p>2. Install a text editor like emacs, vi or sublime text.</p>

```
sudo apt-get install emacs
```

<p>3. Install the Ubuntu 20.04 LTS compiler.</p>

```
sudo apt-get install gcc
```

<p>4. Clone the repository.</p>

```
git clone https://github.com/Julian-Carlosama/simple_shell.git
```

<p>5. All files must be compiled with.</p>

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

<h3>The most beautiful part of the program 📑 <h3>

<p>When the .c files are compiled with the gcc program, they are redirected to an executable file called hsh.</p>

```
hsh
```
<p>Interactive mode: must be run as follows to enter the shell and see the prompt ready to receive commands.</p> 

```
./hsh
$
```
<p>Non-interactive mode: The shell is entered, the commands are executed and the shell is exited.</p>

```
echo "ls" | ./hsh
```

<h3> Interactive mode examples <h3>

<p>If the following commands are executed, the following results will be obtained</p>

```
$ ls
Execve.c  GetPath.c  MetodosShell.c  README.md  free.c  holberton.h  hsh  initPrompt.c  main.c  man_1_simple_shell  printEnv.c  signal.c  tokens.c  write.c
$
```

```
$ pwd
/home/jessie/simple_shell
$
```

<h3> Non Interactive mode examples <h3>

<p>To execute the commands in non-interactive mode you must use the command "echo" followed by "" and within these double quotes the desired command, then use a pipe "|" to pass the instruction to the file that must execute the command in this case ./hsh</p>

```
$ echo "ls" | ./hsh
Execve.c  GetPath.c  MetodosShell.c  README.md  free.c  holberton.h  hsh  initPrompt.c  main.c  man_1_simple_shell  printEnv.c  signal.c  tokens.c  write.c
```

```
$ echo "pwd" | ./hsh
/home/jessie/simple_shell
```


<h3> Files <h3>

| FILES | DESCRIPCION1 |
| ----- | ------------ |
| Execve.c | Contain that excecute the command| 
| GetPath.c | Get, init, count and copy the path | 
| MetodosShell.c | Interact with the strings | 
| free.c | Free all variables allocated | 
| initPrompt.c | Function that initializes the promtp |
| main.c | Principal function | 
| printEnv.c | Print the environment variables | 
| signal.c | Handle Ctrl+C: shell should not quit when the user inputs ^C | 
| tokens.c | Tokenized the arguments | 
| write.c | Error messages |
| man_1_simple_shell  | Description to each function and comand | 
| holberton.h | Library that we used to call the functions | 
| README.md | Description to the proyect | 


<h3> Flowchart <h3>

<li><a href="https://drive.google.com/file/d/1DK2C1q0z_HP52qrHGh80zFD4yX-uLGiz/view?usp=sharing">Flowchart</a></li>


<h3> Authors <h3>

<p>Dairo Julian Carlosama 3392@holbertonschool.com</p>
<p>Jessica Julieth Sanabria 3476@holbertonschool.com</p>
