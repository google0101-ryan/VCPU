CC := g++
CFILES := src/memory.cpp \
src/CPU.cpp \
src/main.cpp
OBJFILES := $(CFILES:.cpp=.o)

all: VCPU

VCPU: $(OBJFILES)
	$(CC) -o $@ $^
	rm -r $(OBJFILES)

run:
	./VCPU

clean:
	rm -r $(OBJFILES) VCPU