echoserver
==========

This is a sample project for an echo server interview project.  The project
will serve as a simple task to be completed as part of the interview process.
The instructions are given below.

1. Create an open source project on github.  Add a README to the repository
containing:
    * A summary of the problem you are trying to solve
    * A description of your solution to the problem

2. Add a hello world program written in C to the project. The program should
compile with GCC on a Linux system, it will be compiled with the following
flags:

    gcc -std=c99 -pedantic -Wall -Werror -Wextra -O0 -g -ggdb hello.c -o hello

The program will be executed on a Debian GNU/Linux system.

3. Create an echo server.  It should be accessible via TCP on 127.0.0.1:7777.
The application will be compiled on Debian GNU/Linux using GCC with the
following command:

    gcc -std=c99 -pedantic -Wall -Werror -Wextra -O0 -g -ggdb echo.c -o echo

and will be tested with:

    telnet 127.0.0.1 7777

The application should read up to 1 packet worth of data, write that data back
to the client over the stablished connection, and then close the connection.
The server does not need to support concurrent connections, however it should
support multiple connections in serial.

4. Extra Credit: Modify the echo server program to log to standard error the IP
address and port that the client has connected from.
