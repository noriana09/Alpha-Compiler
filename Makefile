all: phaseB

phaseB:
	bison --yacc --defines --output=parser.c parser.y -t
	flex --outfile=scanner.c scanner.l
	gcc -g -o calc scanner.c parser.c symtable.c 
	./calc a.txt
clean:
	rm calc quads.txt