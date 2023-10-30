#!/usr/bin/bash


echo -n "Enter filename: "
read filename

if [ -f $filename ]
then
	echo "File already exists"
else
	touch $filename
	echo "PRN		Name" >> $filename
	echo "File created successfully!"
fi


while [ 1 ]
do
	
	echo "------------------"
	echo "1. Add Data"
	echo "2. Delete Data"
	echo "3. Modify Data"
	echo "4. Display Data"
	echo "5. Exit"
	echo "------------------"	
	echo -n "Your choice: "
	read choice 
	
	echo ""
	echo ""	
		
	case $choice in
	
	1)
		echo -n "Enter PRN: "
		read PRN
		echo -n "Enter Name: "
		read name
		
		echo "$PRN	$name" >> $filename
		
	;;
	
	2)
		echo -n "Enter PRN to be deleted: "
		read del
		ndel=$(grep -c "$del" "$filename")
		if [ $ndel -eq 0 ]
		then
			echo "No PRN found!"
		else
			sed -i "/${del}/d" $filename
			echo "Record deleted successfully!"
		fi
	;;
	
	3)
		echo -n "Enter PRN to be modified: "
		read mod
		
		line_num=$(grep -n $mod $filename | cut -d : -f 1)
		nmod=$(grep -c "$mod" "$filename")
		n=$( wc -l < $filename )
		if [ $nmod -eq 0 ]
		then
			echo "No PRN found"
		else
			sed -i "/${mod}/d" $filename
			
			echo -n "Enter PRN: "
			read nPRN
			echo -n "Enter Name: "
			read nname
			newline="${nPRN}	${nname}"
			if [ $n -eq $line_num ]
			then
				echo "$nPRN	$nname" >> $filename
			else
				sed -i "${line_num} i\\${newline}" $filename
			fi
		fi
	;;
	
	4)
		n=$( wc -l < $filename )
		if [ $n -eq 1 ]
		then
			echo "No Records found!"
		else
			cat $filename
		fi
	;;
	
	5)
		exit
	;;
	
	*)
		echo "Invalid Input!"
	;;
	
	esac
	
	echo ""
	echo ""
	
done
