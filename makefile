compile: main.c
	gcc main.c -o lab1

test: lab1 text out test
	./lab1 -f text -o out -t c
	./lab1 -f out -o test -t d
	cat test text
	
view:
	cat text
	cat out
	cat test

rm: 
	rm lab1 out test
indent: *.c *.h
	indent -nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce -ci4 -cli0 -d0 -di1 -nfc1 -i8 -ip0 -l80 -lp -npcs -nprs -npsl -sai -saf -saw -ncs -nsc -sob -nfca -cp33 -ss -ts8 -il1 *.c *.h
