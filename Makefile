all:
	g++ recdesc.cpp -o recdesc.out

test:
	./recdesc.out test1.txt