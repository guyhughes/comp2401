2016-01-12
==============
Basic language features in c

operators
------------------

 - arithmetic `+ - * / % ++ --`
 - relational `== != < > <= >=`
 - bitwise `~ & | ^ >> <<`
 - logical `&& || !`
 - conditional `?:`
 - assignment `= += -+ *= /= %=`

operator characteristics
----------------------------
 - arity (unary,binary, ternary)
 - precedence
 - associativity: order in which orperators of the same predecence execute

expressions, statements, blocks
------------
 - expression: sequence of operators that resolves to a single value
 - statement: expression terminated by a semi-colon
 - block: sequence of statements between a pair of matches braces { }
 - scope: part of the program where a variable can be used:
    - local: inside a block
    - global: outside blocks

control structures, data structures:
---------
- conditional - if/else
- selective - switch statement
- iterative - for, while, do-while (segfaults often)
- jump - break, continue



2016-01-19
================
commenting
--------------
- you need to document sideeffects of a function: unintended/unexpected
- do not document every line of code or i will CHRISTINE you

section 2:  data representation
----------------------
- 2.1. primitives DTs
- 2.2. compound DTs
- 2.3. pointers

s. 2.1.1 Bit models
-------------------------------
- bit: (0|1)
- byte: 8 consecutive bits
- nibble: 4 consecutive bits; maps to one hexadecimal digit

- base conversion:
    - binary base 2
    - octal base 8
    - hexadecimal base 16

magnitude-only bit model
--------------------------------------------------
    - unsigned non-negative whole numbers
    - each bit represents non-negative integer power of 2
    - 8 bits → 2^8 ⇒ 256 max val
    - least significant bits → lowest powers of 2 ("lower order bits")
    - most significant bits → highest powers of 2 ("higher order bits")
    1. unsigned char is 1 byte
    2. unsigned int is 4 bytes (on 32bit arch)
    3. unsigned short int is 2 bytess

- in c **{int, char} is always signed int**

two's complement
--------------------------------------------------
    - positive integers and zero - use magnitude-only bit model
    - negative integers: write bits for positive number; invert; add 1


- fixed point: NOT USED ANYMORE
    - number of digits in fraction are fixed
    - inefficient use of avialable bits
    - fine for fraction powers of 2 but imprecise for powers of 10

- floating point:
    - format: +/- 1.f x 2^e



2016-01-21
===============================

- two's complement: only applies when you put in a negative number
    - to reverse, run the procedure again

floating point
----------------------
float
- 4 bytes

double
- 8 bytes

bitwise operations
-----------------------
- why? store data that is only one bit long; modify
- smallest c data type is 8 bits, so if we have single-bit data, we waste 7 bits
- bitwise ops allow using those 7 bits
- can use bitwise ops on literals and vars
- bit-shift operators are not 'circular'
    - `<< 3` left shift by 3 (adding zeros to end)
    - `>> 2` right shift by 2
      - (if twos complement, adding sign bit to beginning)
      - (if otherwise, adding zeros to begninng )



2016-02-04
===================================

THESE ARE THE ONLY MEMORY ALLOCATION FUNCTIONS YOU MAY USE FOR THIS COURSE. OR ELSE I WILL CRY. IAMPROF.

malloc
-------------
- `void \*malloc(size_t size)` where size is a number of bytes (duh)
- returns the start memory address reserved
- if you don't store this pointer, how in the hell ya gonna free the memory, honey?
- in stdlib.h

calloc
-------------
- clears memory first, allocs a number of elements
- mallocs
- in stdlib.h

void
-------------
- both malloc and calloc return the pointer to void
- void means: no datatype || any data type

typecasting
------------
- outside scope of course
- usually used on pointers
- can be used on non-pointer vars



2016-03-15
========================================

Header files
-------------------
- never contains function implementations
- never includes .c files

gcc
------------------
- preprocessor
- compile
- link

- gcc -c : we will use -c from now on
- gcc *.o -o bin

why separate compiling and linking?
-------------------------------------
- different programming languages
- compilation may be slow


how to use a library?
--------------------------
1. include the header file
2. link in the object file
0. remember: libc.a is always linked in by default

static linking v. dynamic linking
-----------------------------------
- dynamic - default - runtime as needed - smaller exe but slower execution time
- static - library code is copied into exe - larger exe but faster exe time



2016-03-17 Concurrent
===============================================


concurrency :: doing > 1 thing at a time
--------------------------------------------------

concurrent computing ::
--------------------------------------------------
- a program with more than one control flow
- a large system can be: 
  - multithreaded
  - multiprocess
  - distributed

thread :: one control flow
--------------------------------------------------
- !== processes
- share resources with process tree

distributed system :: 
--------------------------------------------------
- execution over multiple physical host
- each host has different resources (fs, processor...)
- hosts msust be networked togeter in order to commnicate
  - either by intranet or internet
- why?
  - users are in different physical locations
  - server hosts are in different physical locatoins
  - single host has insufficient resources/processor power


process :: running exe
--------------------------------------------------

multiprocess ::
--------------------------------------------------
- can be DIFFERENT exe *OR* MULTIPLE instance of same exe
- why?
  - system has different tasks to perform
  - tasks are independent
  - tasks use different resources

multithreaded ::
--------------------------------------------------
- process with multiple control flows
- share the process (virtual memeory, address space, resources)
- different threads may need to synchronize
- why?
  - different things to do within a process
  - tasks ~dependent upon each other
  - example: one thread blocks and waits for user input

process management ::
--------------------------------------------------
- launching, killing, signals

process
--------------------------------------------------
- process id (PID)
- parent process id - PID of process that started this process
- usually managed by OS; can be: shell, program
- `ps -ef`

forking
--------------------------------------------------
- clone of itself
- new process is the child
- child gets an instantaneous copy of the parent's address space 

exec
--------------------------------------------------
- morphing itself
- char \*args = {processname,arg1,arg2};
- execvp(buffer, args); 

fork bomb
--------------------------------------------------
- OS keeps process table
- all tables have finite capacity

wait()
--------------------------------------------------
- wait until any of the children terminator
- or wait until a specific process terminates

system()
--------------------------------------------------
- fork-exec the stupid way

signals
--------------------------------------------------
- just an integer
- USR1, USR2
- typically used for errors
- procesess

2016-03-31 Code Organization
========================================
types of storage classes
--------------------------------------------------
- auto(matic): stored on stack, incl. params, local vars
- static: retains value until program termination, only visible in block
- extern: global and declared in another file
- register: stored in CPU register rather than in memory; may be ignored
  - good compiler will perform this optimization anyway
- mutable: allows parent's const status to change (i.e. struct/c++ class)
- see http://www.csegeek.com/csegeek/view/tutorials/cpp_lang/cpp_storage_class.php


block scope
--------------------------------------------------
- automatic variable disappear at the closing brace

file scope === "global scope"
--------------------------------------------------
- != global memory

function parameter scope
--------------------------------------------------
- a paramter name specificed within a function prototype is useable only in that prototype
- the name is not binding wihtin the implementation of hte function

function scope
--------------------------------------------------
- this is really → labels! 
- do not use these unless you're forced to and you want Christine to Christine you!


2016-03-31 Libraries
==================================================
- (these notes are not comprehensive for this course.)
- libraries are in `/usr/include` - duh. honestly this is first-year/highschool material. what is this curriculum?
- Hot tip from the prof. Don't try to grep through `*.o` in `/usr/lib` it's object code. yawn. why am i here?

how do i use a library? (most first year material)
--------------------------------------------------
- include the header files
    - specify additonal location with `gcc -I`
- linking `-lpthread -lm`
    - specify additional location with `gcc -L`

how to make a library
--------------------------------------------------
- create object files, package them
- supply header `*.h` files and archive `*.a` files to 
- where is my `libc.a`? → this is cool `gcc --print-file-name=libc.a` 
- include a library → `#include <yomammagotsalib.h>`

2016-03-31 Shell Scripts
==================================================
- ( really? can i just get a 90% on the exam for writing every answer as a portable sh script without bashisms? )
- ( cause he's got a big ego. he talks like dis cuz he can back it up. )
- ( who needs twitter when you can read my course notes. )
- ( My dream is that we would cover POSIX-defined constructs instead of backticks. )
- not on the exam -_-


2016-04-21 Supplementary: Memory Areas of a Program
==================================================
1. *Data Segment / Global Segment*
    - static vars, global vars
2. *Text Segment / Code Segment*:
    - program instructions 
3. *Function Call Stack*:
    - automatic vars, parameters
4. *Heap*
    - dynamically allocated with malloc, calloc, c++ new
