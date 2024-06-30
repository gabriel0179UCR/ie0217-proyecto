# Flags
CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -lstdc++fs

# Directorios
SRC_DIR = src
SRC_DIR2 = src/Scripts
BIN_DIR = src

# Archivos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR2)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR2)/%.cpp=$(BIN_DIR)/%.exe)
EXECUTABLE = $(BIN_DIR)/main.exe

# Target que se encarga de eliminar los binarios
.PHONY: clean
clean:
	del $(BIN_DIR)\*.exe

# Target que se encarga de compilar el programa 
.PHONY: build
build: $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS) -IC:\sqlite -LC:\sqlite -lsqlite3

$(BIN_DIR)/%.exe: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -IC:\sqlite -LC:\sqlite -lsqlite3

$(BIN_DIR)/%.exe: $(SRC_DIR2)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -IC:\sqlite -LC:\sqlite -lsqlite3

# Target que se encarga de correr el programa
.PHONY: run
run: $(EXECUTABLE)
	$(EXECUTABLE)

# Target que se encarga de compilar y correr el programa
.PHONY: all
all: build run
	build
	run
