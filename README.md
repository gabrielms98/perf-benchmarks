# PERF TEST

## To run the application:

First clone the repository

```console
$ git clone https://github.com/gabrielms98/perf-benchmarks
```

Enter a folder to see the premade results or generate others

```console
$ sudo su
$ cd <folder>
$ gcc *.c
$ chmod +x exec.sh
$ ./exec.sh
```

## Prerequisite:
To run the exec.sh you need gcc and perf

```console
$ apt install linux-common-tools
$ perf
Install the first linux tools that it shows
```

obs: perf won't install on windows bash since it need a linux kernel.

