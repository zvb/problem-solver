g++ gen.cpp -o gen
g++ Source.cpp -o Source
g++ testFactOddSmall.cpp -o test
while true; do
	./gen > in.txt
	./test < in.txt > out1.txt
	./Source < in.txt > out2.txt
	if diff out1.txt out2.txt > /dev/null; then
		echo ok
	else
		echo error
		break
	fi
done
