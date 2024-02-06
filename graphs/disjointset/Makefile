#---------------------------------------------------------------------#
# Makefile                                                            #
# Brief: Compiles disjointset.cpp and testdisjointset.cpp             #
# Author: Windsor Nguyen © 2024                                       #
#---------------------------------------------------------------------#

CXX := clang++
CXXFLAGS := -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -pedantic -std=c++20 -O2

# Project files
SOURCES := disjointset.cpp testdisjointset.cpp
OBJECTS := $(SOURCES:.cpp=.o)
DEPS := $(SOURCES:.cpp=.hpp)
TARGET := testdisjointset

# Compile and link the program
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to generate object files
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Utility commands
.PHONY: clean deepclean clobber all

# Clean: Remove object files
clean:
	rm -f $(OBJECTS)

# DeepClean: Remove object files and executable
deepclean: clean
	rm -f $(TARGET)

# Clobber: Remove all generated files and backup files
clobber: deepclean
	rm -f *~ \#*\#

# All: Compile and link the project
all: $(TARGET)

# Help: Display callable targets.
help:
	@echo "Supported targets:"
	@echo "  all        : Compile and link the project (default target)"
	@echo "  clean      : Remove object files"
	@echo "  deepclean  : Remove object files and executable"
	@echo "  clobber    : Remove all generated and backup files"
	@echo "  help       : Display this help"

# Default target
default: all
