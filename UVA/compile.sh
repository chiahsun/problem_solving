# http://askubuntu.com/questions/444082/how-to-check-if-1-and-2-are-null
if [ -z "$1" ]; then 
    for a in *.cc;
    do
        name=${a%%.*}
        echo "[Compile] $name.cc -> $name.out"
        g++ -std=c++11 $name.cc -o $name.out
    done
else
    a=$1
    name=${a%%.*}
    echo "[Compile] $name.cc -> $name.out"
    g++ -std=c++11 $name.cc -o $name.out
fi
