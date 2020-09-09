d=$1
X=0
Y=0
foo()
{
	if [ -d $d ]
	then
		for i in `ls $d`
		do
			if [ -f $i ]
			then
				X=$(($X + 1))
			else
				d=$i
				foo
			fi
		done
		echo Found $X files and $Y directories in directory $d
	fi
}

foo
