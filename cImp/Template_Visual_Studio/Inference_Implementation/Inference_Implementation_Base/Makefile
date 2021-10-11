CC = g++
tinyImage: Source.o source.h conv2d.h maxpool2d.h dense.h
	$(CC) -pthread -o source Source.o

Source.o: Source.cpp source.h conv2d.h maxpool2d.h dense.h
