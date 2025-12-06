# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -I/opt/homebrew/include
LDFLAGS := -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Target binary
TARGET := myapp

# Source files (all .cpp files in current dir and subdirectories)
SRCS := $(shell find . -name '*.cpp')

# Object files (replace .cpp with .o)
OBJS := $(SRCS:.cpp=.o)

# Build rules
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

