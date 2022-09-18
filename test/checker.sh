#!/bin/bash/

LIMIT="700"
PARAMETERS="100"

############

COUNT=0
_MAX=`expr $PARAMETERS - 1`;
for (( ; ; ))
do
if [ $COUNT -ge $LIMIT ]
then
  break;
else
	ARG=$(ruby -e "puts (0..$_MAX).to_a.shuffle.join(' ')")
	echo $ARG > arg.log
	./push_swap $ARG > log.log
	COUNT=$(cat log.log | wc -l)
	echo $COUNT
fi
done