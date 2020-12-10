cd ../../../Downloads
x=$(ls -Art | tail -n 2)
#echo $x
file1=`echo $x | cut -d' ' -f1`
file2=`echo $x | cut -d' ' -f2`
if [ $file1 == "in" -o $file1 == "out" ]
then
    x=1 # echo already changed
else
    mv $file1 in
    mv $file2 out
#    echo renamed
fi
