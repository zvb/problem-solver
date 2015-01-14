g++ gen.cpp -o gen
g++ stupid.cpp -o stupid
g++ source.cpp -o source

while true; do
    ./gen > in.txt
    ./stupid < in.txt > out1.txt
    ./source < in.txt > out2.txt
    if diff out1.txt out2.txt > /dev/null; then
        echo ok
    else
        echo error
        break
    fi
done
