all:
	g++ memory.cpp CPU.cpp main.cpp -o VCPU
	./VCPU