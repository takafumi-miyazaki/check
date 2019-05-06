#!/bin/bash


# valgrind massif
valgrind --tool=massif --stack=yes --trace-children=yes ./*.exe
ms_print massif* | less

#

