CC=gcc
UNAME_S := $(shell uname -s)
# CSTATICFLAGS=-static -static-libgcc 
# OSX_CSTATICFLAGS=-Bstatic -v
LFLAGS=-lmicrohttpd
CFLAGS=-O3 -pipe -Wall -Wextra

ifeq ($(DEBUG), 1)
	TARGET_FLAGS=-DDEBUG
else
	TARGET_FLAGS=-DRELEASE
endif

#ifeq ($(UNAME_S),Linux)
	# CFLAGS=-O3 -pipe -Wall -Wextra $(CSTATICFLAGS) -lmicrohttpd
#	CFLAGS=-O3 -pipe -Wall -Wextra -lmicrohttpd
#endif	
#ifeq ($(UNAME_S),Darwin)
	# CFLAGS=-O3 -pipe -Wall -Wextra $(OSX_CSTATICFLAGS)
#	CFLAGS=-O3 -pipe -Wall -Wextra -lmicrohttpd 
#endif

BIN_DIR=bin
BIN=white-rabbit
OBJ_DIR=obj
OBJ=$(OBJ_DIR)/$(BIN).o $(OBJ_DIR)/utils.o $(OBJ_DIR)/logger.o

# Create directories if not exists
$(shell mkdir -p $(BIN_DIR))
$(shell mkdir -p $(OBJ_DIR))

all: $(BIN_DIR)/$(BIN)

$(BIN_DIR)/$(BIN): $(OBJ)
		$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c
		$(CC) $(TARGET_FLAGS) $< -c -o $@

$(OBJ_DIR)/$(BIN).o: main.c
		$(CC) $(TARGET_FLAGS) $< -c -o $@


.PHONY: clean
clean:
		rm -f $(OBJ) $(BIN_DIR)/$(BIN)
		rm -rf $(OBJ_DIR) $(BIN_DIR)

print-%  : ; @echo $* = $($*)
