Y=0
X=0
if [ $# -eq 0 ]
then
	echo Please give me arguments
else
for f in `ls $1`
do
    if [ -f "$f" ]
    then
	X=$(($X + 1))
    else
        Y=$(($Y + 1))
    fi
done
echo I found $X files and $Y directories
fi

