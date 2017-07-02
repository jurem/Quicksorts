CC = gcc
CFLAGS = -I. -O3 -std=c99

OUT = ../bin
LIB = libs


all: $(OUT) $(OUT)/genseq $(OUT)/runalg $(OUT)/bench


$(OUT):
	@mkdir -p $(OUT)


# ***** linking

$(OUT)/genseq: $(OUT)/genseq.o $(OUT)/seq.o


$(OUT)/runalg: $(OUT)/seq.o $(OUT)/timer.o $(OUT)/stat.o $(OUT)/algs.o


$(OUT)/bench: $(OUT)/bench.o $(OUT)/seq.o $(OUT)/timer.o $(OUT)/stat.o $(OUT)/algs.o


# ***** compiling

# executables
$(OUT)/%.o: %.c common.h
	$(CC) $(CFLAGS)	-c $<	-o $@

# libraries
$(OUT)/%.o: $(LIB)/%.c $(LIB)/%.h $(LIB)/common.h
	$(CC) $(CFLAGS)	-c $<	-o $@

# algorithms
$(OUT)/algs.o: algs/*.h


# ***** other

clean:
	@rm -rf bin


@PHONY: all $(OUT) clean
