#!/bin/bash/

MAXIMUM_OF_INSTRUCTIONS="13"
NUMBERS_OF_NUMBERS="5"

############
_ARG=""
_COUNT=0
_NUMBERS=`expr $NUMBERS_OF_NUMBERS - 1`;
_SORTED=""
for (( ; ; )) do
if [ "$_SORTED" = "KO" ]
then
  break;
fi
if [ $_COUNT -ge $MAXIMUM_OF_INSTRUCTIONS ]
then
  break;
else
	_ARG=$(ruby -e "puts (0..$_NUMBERS).to_a.shuffle.join(' ')")
	./push_swap $_ARG > log.log
	_SORTED=$(cat log.log | ./test/checker_linux $_ARG)
	_COUNT=$(cat log.log | wc -l)
	echo $_ARG > arg.log
	echo $_SORTED $_COUNT
fi
done