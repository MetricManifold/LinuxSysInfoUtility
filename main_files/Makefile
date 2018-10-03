CPP_VERSION_FLAGS=-std=c++17
RM=rm

OBJS_ALL=hostname.o hostname_main.o  \
	hostname.o hostname_main.o  \
	memory.o memory_main.o  \
	operatingsystem.o operatingsystem_main.o  \
	process.o processlist.o processlist_main.o  \
	network.o networklist.o networklist_main.o  \
	processor.o processor_main.o
SRC=$(shell ls *_main.cpp)
BIN=$(subst _main.cpp,,$(SRC))
OBJS=$(shell ls *.o)

RM=rm -f

all: hostname memory operatingsystem processlist networklist processor

# HostName
hostname: hostname.o hostname_main.o
	g++ $(CPP_VERSION_FLAGS) -o hostname hostname.o hostname_main.o

hostname.o: ../hostname.cpp ../hostname.h
	g++ $(CPP_VERSION_FLAGS) -c ../hostname.cpp


# Memory
memory: memory.o memory_main.o
	g++ $(CPP_VERSION_FLAGS) -o memory memory.o memory_main.o

memory.o: ../memory.cpp ../memory.h
	g++ $(CPP_VERSION_FLAGS) -c ../memory.cpp


# Operatin
operatingsystem: operatingsystem.o operatingsystem_main.o
	g++ $(CPP_VERSION_FLAGS) -o operatingsystem operatingsystem.o operatingsystem_main.o

operatingsystem.o: ../operatingsystem.cpp ../operatingsystem.h
	g++ $(CPP_VERSION_FLAGS) -c ../operatingsystem.cpp


# ProcessList
processlist: process.o processlist.o processlist_main.o
	g++ $(CPP_VERSION_FLAGS) -o processlist process.o processlist.o processlist_main.o

process.o: ../process.cpp ../process.h
	g++ $(CPP_VERSION_FLAGS) -c ../process.cpp

processlist.o: ../processlist.cpp ../processlist.h
	g++ $(CPP_VERSION_FLAGS) -c ../processlist.cpp


# NetworkList
networklist: network.o networklist.o networklist_main.o
	g++ $(CPP_VERSION_FLAGS) -o networklist network.o networklist.o networklist_main.o

network.o: ../network.cpp ../network.h
	g++ $(CPP_VERSION_FLAGS) -c ../network.cpp

networklist.o: ../networklist.cpp ../networklist.h
	g++ $(CPP_VERSION_FLAGS) -c ../networklist.cpp


# Processor
processor: processor.o processor_main.o
	g++ $(CPP_VERSION_FLAGS) -o processor processor.o processor_main.o

processor.o: ../processor.cpp ../processor.h
	g++ $(CPP_VERSION_FLAGS) -c ../processor.cpp

# Clean command
clean:
	$(RM) $(OBJS) $(BIN)




