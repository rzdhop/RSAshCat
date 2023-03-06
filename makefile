# Usage : make ReleaseName="<NomdAppli>"
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11

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

clean:
	rm -f $(OBJ) $(EXECUTABLE)
