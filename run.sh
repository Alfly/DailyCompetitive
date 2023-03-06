set -e

cur_dir=$(pwd)
input_file='input'
if [ $# -eq 2 ];then
	input_file=$2
fi

g++ -o ${cur_dir}/$1 ${cur_dir}/$1.cpp -std=c++17 -O3
${cur_dir}/$1 < ${cur_dir}/${input_file}.txt
