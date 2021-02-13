CC := g++
CFILES := memory.cpp \
CPU.cpp \
main.cpp
OBJFILES := $(CFILES:.cpp=.o)

all: VCPU

VCPU: $(OBJFILES)
	$(CC) -o $@ $^

run:
	./VCPU
