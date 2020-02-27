i=0
x=1
args=$(($# % 2))
if [ $args -eq 1 ]
then
        echo Plase give me pair of two args
else
	for i in $*
	do
        	f=$2
		d=$x
		if [ ! -d $d ]
        	then
        	        mkdir $d
        	fi

		if [ -e $f ]
		then
			cp $f $d
		else
			touch $f
			cp $f $d
		fi
	done
fi
