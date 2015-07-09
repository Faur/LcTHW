clear
set -e

rm -f ex17
rm db.dat
make ex17

echo  
echo === TEST: BEGIN ===
echo Create 3 entries
./ex17 db.dat c
./ex17 db.dat s 1 zed zed@zedshaw.com
./ex17 db.dat s 2 frank frank@zedshaw.com
./ex17 db.dat s 3 joe joe@zedshaw.com
./ex17 db.dat l

echo 
echo delete the 3rd
./ex17 db.dat d 3
./ex17 db.dat l

echo get entry 2
./ex17 db.dat g 2
echo === TEST: END ===
echo