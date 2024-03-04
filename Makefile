# Define the root directory
rootdir := $(realpath .)

# Compiler and flags
CXX := g++ -std=c++11

# -I$(rootdir)/EC
CXXFLAGS := -Wall -F $(rootdir)/frameworks 
LDFLAGS := -F $(rootdir)/frameworks -Wl,-rpath,$(rootdir)/frameworks

# List of frameworks to link against
FRAMEWORKS := -framework SDL2 -framework SDL2_image -framework SDL2_ttf

# Define the name of the executable
TARGET := main

# List of source files
SRCS := $(wildcard src/*.cpp)
# SRCS += $(wildcard src/ECS/*.cpp)  # Add sub1 source files

# Generate object file names from source files
OBJS := $(SRCS:.cpp=.o)

# Define the build directory
BUILDDIR := build

# List of object files in the build directory
OBJS_BUILD := $(addprefix $(BUILDDIR)/, $(notdir $(OBJS)))

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS_BUILD)
	$(CXX) $^ -o $@ $(LDFLAGS) $(FRAMEWORKS)

# Rule to compile each source file
$(BUILDDIR)/%.o: src/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# $(BUILDDIR)/%.o: src/ECS/%.cpp | $(BUILDDIR)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Rule to clean up generated files
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Rule to clean up generated files
clean:
	rm -rf $(TARGET) $(BUILDDIR)

# Phony targets
.PHONY: all run clean

