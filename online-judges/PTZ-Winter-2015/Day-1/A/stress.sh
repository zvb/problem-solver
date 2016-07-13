g++ gen.cpp -o gen
javac Main.java
g++ Source.cpp -o Source

while true; do
	./gen > in.txt
	java Main < in.txt > out1.txt
	./Source < in.txt > out2.txt
	if diff out1.txt out2.txt > /dev/null; then
		echo ok
	else
		echo error
		break
	fi
done
