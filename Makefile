CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

SRC = src/main.cpp \
      src/persona.cpp \
      src/estudiante.cpp \
      src/curso.cpp \
      src/sistema.cpp

TARGET = sistema

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
