#!/bin/bash

valgrind --tool=cachegrind --I1=1,1, ./a.out 100 10 50
