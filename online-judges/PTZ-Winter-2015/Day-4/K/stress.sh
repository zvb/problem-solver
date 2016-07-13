g++ K.cpp -o K
g++ stupid.cpp -o stupid
g++ gen.cpp -o gen

while true ; do
    ./gen > in.txt
    ./K < in.txt > out2.txt
    ./stupid < in.txt > out1.txt
    if diff out1.txt out2.txt > /dev/null; then
        echo ok
    else
        echo error
        break
    fi
done