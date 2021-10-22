CC = g++
tinyImage: Source.o source.h conv2d.h maxpool2d.h dense.h dequantize.h quantize_biases.h quantize_weights.h quantize_input.h
	$(CC) -o source Source.o

Source.o: Source.cpp source.h conv2d.h maxpool2d.h dense.h dequantize.h quantize_biases.h quantize_weights.h quantize_input.h
