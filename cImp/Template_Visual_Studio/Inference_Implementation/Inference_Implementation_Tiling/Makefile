CC = g++
tinyImage: Source.o source.h conv2d.h maxpool2d.h dense.h
	$(CC) -O3  --param=loop-block-tile-size=8 -floop-block --with-cloog=/usr/bin/ --with-ppl=/usr/bin/   -o source Source.o 

Source.o: Source.cpp source.h conv2d.h maxpool2d.h dense.h