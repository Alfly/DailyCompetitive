set -e

function remove_cpp_extension() {
  local filename="$1"
  if [[ $filename == *.cpp ]]; then
    filename="${filename%.cpp}"
  fi
  if [[ $filename == *.txt ]]; then
    filename="${filename%.txt}"
  fi
  echo "$filename"
}

cur_dir=$(pwd)
code=$(remove_cpp_extension $1)
g++ -o ${cur_dir}/$code ${cur_dir}/$code.cpp -std=c++17 -O3

if [ $# -eq 2 ]; then
	data=$(remove_cpp_extension $2)
	if [ "$data" = "stdin" ]; then
		${cur_dir}/$code
	else
		${cur_dir}/$code < ${cur_dir}/$data.txt
	fi
else
	${cur_dir}/$code < ${cur_dir}/input.txt
fi
