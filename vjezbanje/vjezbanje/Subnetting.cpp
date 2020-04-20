#include "pch.h"

/*

	network address == mrezna adresa;
	broadcast address == emisiona adresa;
	subnet address == podmrezna adresa;





						IP:	11.0.0.7/10		2 bita za podmreze

	network				00001011.00000000.00000000.00000111
	subnet mask			11111111.11000000.00000000.00000000

	subnet part			00001011.00
	host part	                   000000.00000000.00000111

	subnet ID			00001011.00000000.00000000.00000000  (11.0.0.0)
	host ID				00001011.00111111.11111111.11111111  (11.63.255.255)

	range:				11.0.0.1 - 11.63.255.254 (prva i zadnja su reserved)
	2 bita odvajamo za podmreze

	subnet 				00001011.00000000.00000000.00000000 / 12 (ranije je bilo 10, ali odvojili smo 2 bita)
	4 + 8 + 8 = 20 host bitova, 2 ^ 20 = 1048576, buduci da je host part, rezervisemo pocetak i kraj,
	tako da na kraju imamo 1048674 mogucih hostova

	1 podmreza			00001011.00000000.00000000.00000000 / 12  (11.0.0.0)
	2 podmreza			00001011.00010000.00000000.00000000 / 12  (11.16.0.0)
	3 podmreza			00001011.00100000.00000000.00000000 / 12  (11.32.0.0)
	4 podmreza			00001011.00110000.00000000.00000000 / 12  (11.48.0.0)









						IP: 11.67.6.4/10

	network				00001011.01000011.00000110.00000100
	subnet mask			11111111.11000000.00000000.00000000

	subnet part			00001011.01
	host part 	                   000011.00000110.00000100

	subnet ID			00001011.01000000.00000000.00000000  (11.64.0.0)
	host ID				00001011.01111111.11111111.11111111  (11.127.255.255)

	range				11.64.0.1 - 11.127.255.254









						IP: 131.1.0.0/16		10 bita za podmreze

	network				10000011.00000001.00000000.00000000
	subnet mask			11111111.11111111.00000000.00000000

	subnet part			10000011.00000001
	host part	                          00000000.00000000

	subnet ID			10000011.00000001.00000000.00000000  (131.1.0.0)
	host ID				10000011.00000001.11111111.11111111  (131.1.255.255)

	range				131.1.0.1 - 131.1.255.254

	/16 je subnet maska, trebamo 10 bita odvojiti za podmreze, dakle kod njih ce biti /26 subnet maska


	Sa 10 bita mozemo napraviti 2^10 podmrezi. Ovih 10 bita se nalaze na 2 razlicita okteta, tj cijeli treci i 2 bita cetvrtog

				10000011.00000001.00000000.00000000  (131.1.0.0)
				10000011.00000001.00000000.01000000  (131.1.64.0)
				10000011.00000001.00000000.10000000  (131.1.128.0)
				10000011.00000001.00000000.11000000  (131.1.192.0)
	Iznad su napisane sve kombinacije za 131.1.X.0 adresu

	Ispod su kombinacije za 131.2.X.0 adresu:
				10000011.00000010.00000000.00000000  (131.2.0.0)
				10000011.00000010.00000000.01000000  (131.2.64.0)
				10000011.00000010.00000000.10000000  (131.2.128.0)
				10000011.00000010.00000000.11000000  (131.2.192.0)

	I ovo cemo nastaviti raditi za sve moguce kombinacije treceg okteta. Prva i druga su vec napisane, mozemo nastaviti do 255
	sto je na kraju 2^10 tj 1024 moguce kombinacije.














*/
