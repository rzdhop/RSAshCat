# Usage : make ReleaseName="<NomdAppli>"
#		  make key bit=64
#		  make GPU

CUDACC=nvcc
CUDAFLAGS=--expt-relaxed-constexpr -lcrypto
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -lcrypto

PY=sudo python3
GEN_SCRIPT=modules/genRSA.py

SRC_DIR_CUDA=src/Cuda

SRC_DIR=src/noCuda
OBJ_DIR=obj
BUILD_DIR=build

SRC=$(wildcard $(SRC_DIR)/*.c)
OBJ=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

SRC_CUDA=$(wildcard $(SRC_DIR_CUDA)/*.c)

EXECUTABLE=$(BUILD_DIR)/$(ReleaseName).exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -lm

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

key: $(GEN_SCRIPT) 
	$(PY) $^ $(bit)

GPU: $(SRC_CUDA)
	$(CUDACC) $(CUDAFLAGS) $^ -o $(EXECUTABLE)
