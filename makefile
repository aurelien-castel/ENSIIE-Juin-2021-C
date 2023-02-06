# pour faire marcher:
# make all
# puis: ./bin/main
# pour nettoyer:
# make clean

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
HEA_DIR := headers

EXE := $(BIN_DIR)/main
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS := -Wall -Wextra -std=c99
CC := gcc

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEA_DIR)

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)

print:
	echo SRC_DIR 
	echo $(wildcard $(SRC_DIR)/*.c)
	echo OBJ_DIR 
	echo $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)