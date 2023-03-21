set -e

cur_dir=$(pwd)
g++ -o ${cur_dir}/$1 ${cur_dir}/$1.cpp -std=c++17 -O3

if [ $# -eq 2 ]; then
	if [ "$2" = "none" ]; then
		${cur_dir}/$1
	else
		${cur_dir}/$1 < ${cur_dir}/$2.txt
	fi
else
	${cur_dir}/$1 < ${cur_dir}/input.txt
fi
