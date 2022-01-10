
# General Instructions for Assignments

## Build and test your code on the student machines.

Make sure that your program builds and runs correctly on the CSE student servers (student00.cse.nd.edu through student08.cse.nd.edu) which run the RHEL7 operating system. (Note that student04.cse.nd.edu should not be used for this class, since it's setup for another class.) The TAs will only test your program on those machines, and that's where your grade will be determined.

Of course, many of you want to build and test on your laptops, and that's something you should know how to do. However, our experience is that no two Linux (or Mac) machines are identical in any way: compilers, libraries, and other irrelevant things differ in subtle ways that will complicate the writing and running of your program. Code that compiles on your laptop may not compile at all on the student machines, or vice versa. If you do develop on your laptop, then leave extra time to test and debug your program when copied to the student machines.

## Use the standard C compiler /usr/bin/gcc with the options --std=c99 -Wall

Other classes may have asked you to change the compiler by adjusting your PATH, LD_LIBRARY_PATH or other settings. This class is using the default C compiler, which is /usr/bin/gcc. To check whether you have the right compiler, run the which gcc command. If it says anything other than /usr/bin/gcc, then you are using the wrong compiler. Please remove whatever changes you made to use a different compiler, and log in again.

## Use standard C99 (not C++) for this course.

Plain old C99 is the language used nearly-universally for implementing operating systems and other low-level kinds of code. It is a much simpler and smaller language than C++, with many fewer "gotchas" and surprises. If you aren't familiar with plain C, read the Kernighan and Ritchie book. Use the --std=c99 option to gcc to ensure conformance to this standard.

## Pay close attention to warnings, and eliminate them.

Use the -Wall option to gcc to turn on all warnings, and don't ignore them! The compiler is trying to tell you that there is something wrong with your code that (almost always) needs to be fixed. If the warning doesn't make sense to you, please ask, and we will try to point you in the right direction. (There are rare cases where a warning can be safely ignored, but don't start with this assumption.)

## Always check return codes and print error messages.

Systems programming is very different from application programming, in that runtime errors happen all the time. Get in the habit of writing error handling code right from the beginning. (It is tempting to skip it at first and add it later, but that just makes it harder to debug.) Any time that you open a file, create a process, or allocate some memory, check the result, and on failure, explain what failed and why, like this:

```
FILE * file = fopen(path,"r");
if(!file) {
    fprintf(stderr,"mycoolprogram: couldn't open %s: %s\n",path,strerror(errno));
    return -1;
}
```

## Use Standard Debugging Tools

Make good use of the tools you learned in prior classes:

- valgrind helps to find some pointer and malloc errors in C programs. (Unfortunately, it has a tendency to slow down multi-threaded prorgams dramatically.)
- gdb allows you to step through a program and display variables.
- strace shows the system calls your program performs. 

## Use good coding style and common sense.

Give variables reasonable names, put comments near tricky bits of code, and break up complex code into smaller functions. Use the indent command to make your code line up nicely.