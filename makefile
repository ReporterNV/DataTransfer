all: Lab1.c
	gcc Lab1.c -o xr
test: xr text out oy
	./xr text out 
	./xr out oy f
	cat text oy	
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
