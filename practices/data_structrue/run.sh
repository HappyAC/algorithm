args=($*)
len=${#args[*]}
g++ $1 && ./a.out ${args[*]:1:$len}