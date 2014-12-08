#!/bin/sh

while [ 1 ]
do

php gencalc.php > tmp
strlen=`cat tmp | wc -m`
echo "" >> tmp
echo "calc..."
res1=`cat tmp |  ../calc "0123456789ABCDE" "()+-*/%" $strlen`
echo "bc..."
echo "ibase=F;obase=F" > new
cat tmp >> new
res2=`cat new | bc | tr -d '\n' | sed 's/\\\//g'`
echo ""
cat tmp
echo "calc: $res1"
echo "bc  : $res2"
if [ "$res1" != "$res2" ]
then
echo "/!\ ERROR"
exit
fi
echo $strlen
rm tmp
rm new

done
