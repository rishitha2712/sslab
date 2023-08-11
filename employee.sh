#!/bin/bash
while(true)
do
echo "Menu:"
echo "1.Create Employee Record"
echo "2.Delete Employee Record"
echo "3.Search Employee Record"
echo "4.Display Employee Details"
echo "5.Sort Records"
echo "6.List All Records"
echo "7.Exit"
echo -n  "Enter your choice (1-7):"

read choice

case $choice in 
	1)
		echo -n "Enter Employee Name:"
		read ename
		echo -n "Enter Employee Number:"
		read eno
		echo -n "Enter Phone Number:"
		read ph
		if grep -q "^.* $eno .*$" employee.txt; then
			echo "Employee Number already exists can't create duplicates"
		else		
			echo "$ename" "$eno" "$ph" >>employee.txt
			echo "Employee Record Created"
		fi
		;;

	2)
		echo "Enter Employee Number to Delete:"
		read eno
		grep -v "^.* $eno .*$" employee.txt > temp.txt
	        mv temp.txt employee.txt
		echo "Employee  Record Deleted"
		;;

	3)
		echo "Enter Employee Number to search:"
		read eno
		if grep -q "^.* $eno .*$" employee.txt; then
			grep  "^.* $eno .*$" employee.txt
		else
			echo "No employee found"
		fi
		;;

		
	4)
		echo "Enter Employee Number to display details:"
                read eno
                if grep -q "^.* $eno .*$" employee.txt; then
                        grep  "^.* $eno .*$" employee.txt
                else
                        echo "No employee found"
                fi
                ;;

	5)
		sort -t ' ' -k2n employee.txt > temp.txt
                mv temp.txt employee.txt
    		echo "Records Sorted"
		;;
	
	6)
		cat employee.txt
		;;


	7)
		exit 0
		;;
	*)
		echo "Invalid Choice"
		;;
		
	esac
done
