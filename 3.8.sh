
for f in $*; do
    if [ -d "$f" ]; then
        mkdir newcatalog
	#for i in `ls $1`
	#do
	#	mv $i newcatalog
	#done
    else
	echo Doesnt exist
    fi
done
