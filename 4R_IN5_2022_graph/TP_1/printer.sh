rm output.file
var=$(./graphe $1)
echo "digraph A {" >> output.file
echo "$var" >> output.file
echo " } " >> output.file
dot -Tsvg output.file > output.svg
rm output.file
display output.svg

