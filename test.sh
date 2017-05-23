TESTSCOMPLEJO=7
TESTSVECTOR=8
TABBCOM=10
nombreBase="tad"
extension=".cpp"
zero="0"

echo "Autocorrector Cuadernillo 1 PED"
echo "1. Test TComplejo"
echo "2. Test TVectorCom"
echo "3. Test TABBCom"
echo "4. Todos"
echo 'Opcion: '
read Opcion
if (( $Opcion == 1 || $Opcion == 4 )); then
	
	echo "//////////////////////////////////////////////////////////////////"
	echo "///////////////////////Pruebas TComplejo//////////////////////////"
	cp src/tcomplejo/*.cpp src/
	for (( i = 1; i <= $TESTSCOMPLEJO; i++ )); do
		
		if (($i >= 10)); then
			nombre=$nombreBase$i$extension 
		else
			nombre=$nombreBase$zero$i$extension 
		fi
		echo $nombre
		mv src/$nombre src/tad.cpp
		make > basura.txt
		./tad > $i.txt
		diff -b $i.txt salidas/tcomplejo/$nombre.sal
		mv src/tad.cpp src/$nombre
		rm ./tad
		rm ./basura.txt
		rm $i.txt
		
	done
	rm src/*.cpp
fi
if (( $Opcion == 2 || $Opcion == 4 )); then

	echo "//////////////////////////////////////////////////////////////////"
	echo "//////////////////////Pruebas TVectorCom/////////////////////////"
	cp src/tvectorcom/*.cpp src/
	for (( i = 1; i <= $TESTSVECTOR; i++ )); do
		
		if (($i >= 10)); then
			nombre=$nombreBase$i$extension 
		else
			nombre=$nombreBase$zero$i$extension 
		fi
		echo $nombre
		mv src/$nombre src/tad.cpp
		make > basura.txt
		./tad > $i.txt
		diff -b $i.txt salidas/tvectorcom/$nombre.sal
		mv src/tad.cpp src/$nombre
		rm ./tad
		rm ./basura.txt
		rm $i.txt
		
	done
	rm src/*.cpp
fi
if (( $Opcion == 3 || $Opcion == 4 )); then
	echo "//////////////////////////////////////////////////////////////////"
	echo "///////////////////////Pruebas TABBCom/////////////////////////"
	cp src/tabbcom/*.cpp src/
	for (( i = 1; i <= $TABBCOM; i++ )); do
		
		if (($i >= 10)); then
			nombre=$nombreBase$i$extension 
		else
			nombre=$nombreBase$zero$i$extension 
		fi
		echo $nombre
		mv src/$nombre src/tad.cpp
		make > basura.txt
		./tad > $i.txt
		diff -b $i.txt salidas/tabbcom/$nombre.sal
		mv src/tad.cpp src/$nombre
		rm ./tad
		rm ./basura.txt
		rm $i.txt
		
	done
	rm src/*.cpp
fi