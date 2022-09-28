#!/bin/bash

rm result.txt
IFS="
"

i=0
while read line
do
	if [ ${i} -ge 2 ]; then
		ft[i]=${line:29:9}
	fi
	i=$((i+1))
done < result_ft.txt

i=0
while read line
do
	if [ ${i} -eq 1 ]; then
		echo $line >> result.txt
	elif [ ${i} -ge 2 ]; then
		echo -n ${line:0:30} >> result.txt
		std[i]=${line:29:9}
		echo -n ${ft[i]} "/" ${std[i]} "= " >> result.txt
		bc <<< "scale=4; ${ft[i]}/${std[i]}" >> result.txt
	fi
	i=$((i+1))
done < result_std.txt
