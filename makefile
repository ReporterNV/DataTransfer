all: test.c
	gcc test.c -o xr
test: xr 1.txt 2.txt 
	./xr 1.txt 2.txt out.txt
	./xr out.txt 1.txt 22.txt
	./xr out.txt 2.txt 11.txt
view: 11.txt 1.txt 2.txt 22.txt
	cat 1.txt
	cat 11.txt
	echo
	cat 2.txt
	cat 22.txt
rm: 
	rm 11.txt 22.txt ./xr out.txt
indent: *.c
	indent -nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce -ci4 -cli0 -d0 -di1 -nfc1 -i8 -ip0 -l80 -lp -npcs -nprs -npsl -sai -saf -saw -ncs -nsc -sob -nfca -cp33 -ss -ts8 -il1 *.c