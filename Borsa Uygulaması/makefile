derlecalistir:derle calistir
calistir:
	./bin/test
derle: satirsay program emirparser hisseparser portfoyparser banka emir hisse portfoy
	gcc ./lib/SatirSayici.o ./lib/Test.o ./lib/Emirparser.o ./lib/HisseParser.o ./lib/PortfoyParser.o ./lib/Banka.o ./lib/Emir.o ./lib/Hisse.o ./lib/Portfoy.o -o ./bin/test
satirsay: 
	gcc -c ./src/SatirSayici.c -o ./lib/SatirSayici.o
program: 
	gcc -c ./src/Test.c -o ./lib/Test.o
emirparser: 
	gcc -c ./src/Emirparser.c -o ./lib/Emirparser.o
hisseparser: 
	gcc -c ./src/HisseParser.c -o ./lib/HisseParser.o	
portfoyparser: 
	gcc -c ./src/PortfoyParser.c -o ./lib/PortfoyParser.o	
banka:
	gcc -c ./src/Banka.c -o ./lib/Banka.o
emir:
	gcc -c ./src/Emir.c -o ./lib/Emir.o
hisse:
	gcc -c ./src/Hisse.c -o ./lib/Hisse.o
portfoy:
	gcc -c ./src/Portfoy.c -o ./lib/Portfoy.o	