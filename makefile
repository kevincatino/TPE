COMPILER=gcc
FLAGS=-pedantic -std=c99 -Wall -fsanitize=address
all: VAN BUE

VAN: OUTPUT_FILE=arbolesADTVAN
VAN: mainVAN.c
	$(COMPILER) -o $(OUTPUT_FILE) mainVAN.c arbolesADT.c fileManagement.c $(FLAGS)
	@echo Compilation success!

BUE: OUTPUT_FILE=arbolesADTBUE
BUE: mainBUE.c
	$(COMPILER) -o $(OUTPUT_FILE) mainBUE.c arbolesADT.c fileManagement.c $(FLAGS)
	@echo Compilation success!

clean:
	rm -r finalVAN finalBUE
	@echo Clean success!
