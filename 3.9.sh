d=$1
sd=$d/new
if [ -d $d ]
then
	mkdir $sd
	for i in `ls $1`
	do
		if [ -f $i ]
		then
			cp $i $sd
		fi
	done
else
	echo Need args
fi
