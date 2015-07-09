clear
set -e

rm -f ex18
make ex18

echo  
echo === TEST: BEGIN ===
echo ./ex18 4 1 7 3 2 0 8
echo
./ex18 4 1 7 3 2 0 8

echo === TEST: END ===
echo

