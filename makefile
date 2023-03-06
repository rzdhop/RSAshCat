# Usage : make ReleaseName="<NomdAppli>"
#		  make key bit=64

CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11

PY=py
GEN_SCRIPT=modules/genRSA.py

SRC_DIR=src
OBJ_DIR=obj
BUILD_DIR=build

SRC=$(wildcard $(SRC_DIR)/*.c)
OBJ=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

EXECUTABLE=$(BUILD_DIR)/$(ReleaseName).exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

key: $(GEN_SCRIPT) 
	$(PY) $^ $(bit)

clean:
	rm -f $(OBJ) $(EXECUTABLE)
