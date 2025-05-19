# Compilador
CXX := g++
CXXFLAGS := -Wall -Iinclude -Iinclude/SDL2

# Diretórios
SRC_DIR := src
OBJ_DIR := build
BIN := $(OBJ_DIR)/DoomNUMBERTWO.exe
LIB_DIR := lib

# Bibliotecas
LDFLAGS := -L$(LIB_DIR) -lSDL2 -lmingw32 -lSDL2main

# Lista todos os .cpp recursivamente
SOURCES := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp)
# Converte os .cpp para .o na pasta build/
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Regra padrão
all: $(BIN)

# Linkagem final
$(BIN): $(OBJECTS)
	@echo Linking...
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compilação individual
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo Compiling $<
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	@echo Cleaning...
	rm -rf $(OBJ_DIR)

.PHONY: all clean
