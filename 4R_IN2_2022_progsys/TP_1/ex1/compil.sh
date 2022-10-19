#! /bin/sh
rm output.file 
rm output.svg
cc -Wall -g -o hierarchie hierarchie.c

var=$(./hierarchie)
echo "graph {" >> output.file
echo "${var}" >> output.file
echo " } " >> output.file
dot -Tsvg output.file > output.svg
