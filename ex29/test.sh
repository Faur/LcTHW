# Compile the lib file
# You need -fPIC on some platforms, add IF you get an error
cc -c libex29.c -o libex29.o
cc -shared -o -fPIC libex29.so libex29.o
# compile the loader program
cc -Wall -g -DNDEBUG ex29.c -ldl -o ex29
	# On some platforms the ordering matters

echo
echo === Some tests that should work ===
#tests, should work
./ex29 ./libex29.so print_a_message "Hi world."
./ex29 ./libex29.so uppercase "Hi world."
./ex29 ./libex29.so lowercase "Hi world."
./ex29 ./libex29.so fail_on_purpose "Hi world."

echo
echo === Some tests that should fail ===
./ex29 ./libex29.so print_a_message
./ex29 ./libex29.so print_a_message Hi world
./ex29 ./libex29.so asdf asdf
./ex29 ./asdf.so print_a_message "Hi world."



