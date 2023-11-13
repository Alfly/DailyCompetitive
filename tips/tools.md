# 算法题小工具

## Python

计算器 万能编程

```python
~ > python3
Python 3.11.5 (main, Sep 11 2023, 08:31:25) [Clang 14.0.6 ] on darwin
Type "help", "copyright", "credits" or "license" for more information.
>>> 2**32
4294967296
# 是否溢出 int
>>> (10 * 100 * 32768 * 47 * 40) / (2**31 - 1)
28.686523450858203
>>>
```

## time

按时掐断

```bash
time ls
time sleep 1
time ./a.out

timeout 1 ./a.out
```

## diff

文件对比
```bash
#!/bin/bash

g++ bad.cpp -o bad.exe
g++ ok.cpp -o ok.exe

for T in $(seq 1 100)
do
    echo Testcase $T
    # ./gen
    echo "100 200" > in.txt

    diff -q \
        <(timeout 1 ./ok.exe < in.txt) \
        <(timeout 1 ./bad.exe < in.txt)
    if [[ $? != 0 ]]
    then
        echo 'Error!'
        cp in.txt error-$T.txt
    fi
done
```


## 统计代码行数

```bash
find . | grep \.cpp$ | xargs cat | wc -l

cat $(find . | grep \.cpp$) | wc -l
```