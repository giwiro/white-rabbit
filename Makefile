CC=gcc
CFLAGS=-O3 -pipe -Wall -Wextra
BIN_DIR=bin
BIN=white-rabbit
OBJ_DIR=obj
OBJ=$(OBJ_DIR)/$(BIN).o $(OBJ_DIR)/utils.o $(OBJ_DIR)/logger.o

# Create directories if not exists
$(shell mkdir -p $(BIN_DIR))
$(shell mkdir -p $(OBJ_DIR))

all: $(BIN_DIR)/$(BIN)

$(BIN_DIR)/$(BIN): $(OBJ)
		$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c
		$(CC) $< -c -o $@

$(OBJ_DIR)/$(BIN).o: main.c
		$(CC) $< -c -o $@


.PHONY: clean
clean:
		rm -f $(OBJ) $(BIN_DIR)/$(BIN)
		rm -rf $(OBJ_DIR) $(BIN_DIR)
