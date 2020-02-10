#!/bin/bash
input="./omega1_P.txt"
output_file="output.txt"
echo "" > $output_file
while IFS= read -r line
do
    p="curl -H \"Content-Type: application/json\" --request POST --data '{\"teamname\":\"Sherlocked\",\"password\":\"9ed6d0d0a21f329deee082d56fc58b40\", \"plaintext\":\""
    q="\"}' -s -k "
    r="https://172.27.26.181:9997/des"
    a=$(printf "%s%s%s%s" "$p" "$line" "$q" "$r")
    echo $(eval "$a") >> $output_file
done < "$input"
a=$(cut -c 17-32 output.txt)
echo $a > $output_file
# sed 's/ /\n/g' output.txt > out.txt
 