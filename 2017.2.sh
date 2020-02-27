i=0
j=0
if [ $# -lt 2 ]
then
	echo Plase give me two args
else
	echo `ls $1 | grep $2`
fi
#for j in "${num[@]} ${files[@]}"
#do
#	echo  $j
#done
