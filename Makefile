# Project name
TARGET = calculator  

# List all input source files
SRC = src/main.cpp src/calculatorFrameWork_functions.cpp 

# Header file directories 
INCLUDE = include

# List all header files
HEADERS = $(wildcard include/*.h)  

# Get object files from sources
OBJS = ${SRC:.cpp=.o}

# Compiler flags
CXXFLAGS += -std=c++11 -Wall -g

# Linker flags 
#LDFLAGS += -lstdc++ 

# Linker flags 
LDFLAGS += -lc++

# Target
all: ${TARGET}

# Build target executable
${TARGET}: ${OBJS} 
	g++ ${OBJS} -o ${TARGET} ${LDFLAGS}

# Compile source
%.o: %.cpp ${HEADERS}
	g++ -c $< ${CXXFLAGS} -I${INCLUDE} -o $@

# Clean build files
clean:
	${RM} ${TARGET} ${OBJS}