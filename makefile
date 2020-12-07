COMPILER=gcc
FLAGS=-pedantic -std=c99 -Wall -fsanitize=address
COMMON=arbolesADT.c fileManagement.c Q1ADT.c
all: VAN BUE

VAN: OUTPUT_FILE=arbolesADTVAN
VAN: mainVAN.c
	$(COMPILER) -o $(OUTPUT_FILE) mainVAN.c $(COMMON) $(FLAGS)
	@echo Compilation success!

BUE: OUTPUT_FILE=arbolesADTBUE
BUE: mainBUE.c
	$(COMPILER) -o $(OUTPUT_FILE) mainBUE.c $(COMMON) $(FLAGS)
	@echo Compilation success!

clean:
	rm -r arbolesADTVAN arbolesADTBUE
	@echo Clean success!
