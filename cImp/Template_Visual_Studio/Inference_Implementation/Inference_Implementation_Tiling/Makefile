CC = g++
tinyImage: Source.o Source.cpp source.h conv2d.h maxpool2d.h dense.h
	$(CC)  -O3 --param=loop-block-tile-size=2 -floop-block -o source Source.o

Source.o: Source.cpp source.h conv2d.h maxpool2d.h dense.h
