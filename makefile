CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -g #-Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp2.exe # nome do executavel que sera gerado, nao troque
TMPOUT=tp2.testresult
BUILD=./build/
SRC=./src/
INCLUDE=./include/
BTPRO=BackPackProblem/

$(EXEC): $(BUILD)main.o $(BUILD)$(BTPRO)BackPackFactory.o $(BUILD)$(BTPRO)BackPackBTFactory.o $(BUILD)$(BTPRO)BackPackBBFactory.o $(BUILD)$(BTPRO)Item.o 
	$(CC) $(CFLAGS) -o $(EXEC) $(BUILD)main.o $(BUILD)$(BTPRO)*.o 

$(BUILD)main.o:	$(SRC)main.cpp $(BUILD)$(BTPRO)BackPackFactory.o $(BUILD)$(BTPRO)BackPackBTFactory.o $(BUILD)$(BTPRO)BackPackBBFactory.o $(BUILD)$(BTPRO)Item.o 
	$(CC) $(CFLAGS) -I $(INCLUDE)$(BTPRO) -c $(SRC)main.cpp -o $(BUILD)main.o

$(BUILD)$(BTPRO)BackPackFactory.o: $(SRC)$(BTPRO)BackPackFactory.cpp $(INCLUDE)$(BTPRO)BackPackFactory.hpp $(BUILD)$(BTPRO)BackPack.o
	$(CC) $(CFLAGS) -I $(INCLUDE)$(BTPRO) -c $(SRC)$(BTPRO)BackPackFactory.cpp -o $(BUILD)$(BTPRO)BackPackFactory.o

$(BUILD)$(BTPRO)BackPackBBFactory.o: $(SRC)$(BTPRO)BackPackBBFactory.cpp $(INCLUDE)$(BTPRO)BackPackBBFactory.hpp $(BUILD)$(BTPRO)BackPackFactory.o $(BUILD)$(BTPRO)BackPackBB.o $(BUILD)$(BTPRO)BackPack.o
	$(CC) $(CFLAGS) -I $(INCLUDE)$(BTPRO) -c $(SRC)$(BTPRO)BackPackBBFactory.cpp -o $(BUILD)$(BTPRO)BackPackBBFatory.o

$(BUILD)$(BTPRO)BackPackBTFactory.o: $(SRC)$(BTPRO)BackPackBTFactory.cpp $(INCLUDE)$(BTPRO)BackPackBTFactory.hpp $(BUILD)$(BTPRO)BackPackFactory.o $(BUILD)$(BTPRO)BackPackBT.o $(BUILD)$(BTPRO)BackPack.o
	$(CC) $(CFLAGS) -I $(INCLUDE)$(BTPRO) -c $(SRC)$(BTPRO)BackPackBTFactory.cpp -o $(BUILD)$(BTPRO)BackPackBTFatory.o

$(BUILD)$(BTPRO)BackPackBT.o: $(SRC)$(BTPRO)BackPackBT.cpp $(INCLUDE)$(BTPRO)BackPackBT.hpp $(BUILD)$(BTPRO)Item.o $(BUILD)$(BTPRO)BackPack.o
	$(CC) $(CFLAGS) -I $(INCLUDE)$(BTPRO) -c $(SRC)$(BTPRO)BackPackBT.cpp -o $(BUILD)$(BTPRO)BackPackBT.o

$(BUILD)$(BTPRO)BackPackBB.o: $(SRC)$(BTPRO)BackPackBB.cpp $(INCLUDE)$(BTPRO)BackPackBB.hpp $(BUILD)$(BTPRO)Item.o $(BUILD)$(BTPRO)BackPack.o $(BUILD)$(BTPRO)Node.o
	$(CC) $(CFLAGS) -I $(INCLUDE)$(BTPRO) -c $(SRC)$(BTPRO)BackPackBB.cpp -o $(BUILD)$(BTPRO)BackPackBB.o

$(BUILD)$(BTPRO)BackPack.o: $(SRC)$(BTPRO)BackPack.cpp $(INCLUDE)$(BTPRO)BackPack.hpp $(BUILD)$(BTPRO)Item.o
	$(CC) $(CFLAGS) -I $(INCLUDE)$(BTPRO) -c $(SRC)$(BTPRO)BackPack.cpp -o $(BUILD)$(BTPRO)BackPack.o

$(BUILD)$(BTPRO)Item.o: $(SRC)$(BTPRO)Item.cpp $(INCLUDE)$(BTPRO)Item.hpp
	$(CC) $(CFLAGS) -I $(INCLUDE)$(BTPRO) -c $(SRC)$(BTPRO)Item.cpp -o $(BUILD)$(BTPRO)Item.o

$(BUILD)$(BTPRO)Node.o: $(SRC)$(BTPRO)Node.cpp $(INCLUDE)$(BTPRO)Node.hpp
	$(CC) $(CFLAGS) -I $(INCLUDE)$(BTPRO) -c $(SRC)$(BTPRO)Node.cpp -o $(BUILD)$(BTPRO)Node.o

run_all_tests:	$(EXEC)
	$(EXEC) ./testcases/*

clean:
	rm -f $(BUILD)*/*.o

mem_check_testcases: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all $(EXEC) ./testcases/f1_l-d_kp_10_269