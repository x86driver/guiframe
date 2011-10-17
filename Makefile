TARGET = gui
CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(addprefix ,$(notdir $(CPP_FILES:.cpp=.o)))

CFLAGS = -Wall -Wextra -g
CFLAGS += -Weffc++

all: $(TARGET)

%.o:%.cpp %.h
	g++ $(CFLAGS) -c -o $@ $<

gui:$(OBJ_FILES)
	g++ $(CFLAGS) -o $@ $^

clean:
	rm -rf $(TARGET) *.o
