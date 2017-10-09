SOURCES=addressbook.c addressbook_list.c addressbook_array.c commands.c helpers.c
HEADERS=addressbook.h addressbook_list.h addressbook_array.h commands.h helpers.h
PROGRAM=addressbook
FLAGS=-ansi -pedantic -Wall

all:
	gcc $(FLAGS) -o $(PROGRAM) $(SOURCES)

addressbook: addressbook.o addressbook_array.o addressbook_list.o commands.o helpers.o
			gcc -o addressbook addressbook.o addressbook_array.o addressbook_list.o commands.o helpers.o

addressbook.o: addressbook.c addressbook.h
				gcc -c addressbook.c

addressbook_array.o: addressbook_array.c addressbook_array.h
				gcc -c addressbook_array.c

addressbook_list.o: addressbook_list.c addressbook_list.h
				gcc -c addressbook_list.c

commands.o: commands.c commands.h
				gcc -c commands.c

helpers.o: helpers.c helpers.h
			gcc -c helpers.c

clean:
	rm $(PROGRAM)

archive:
	zip $(USER)-a2 $(SOURCES) $(HEADERS) Makefile
