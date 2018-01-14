#Name:Bailey Payne  ID:brp7vh  Lab:Tuesdays 9:30am
#!/bin/bash
#Get User Input
echo "Enter a dictionary file: "
read dict
echo "Enter a grid file: "
read grid
#Run the Program 5 Times
TIME1=`./a.out $dict $grid | tail -1`
TIME2=`./a.out $dict $grid | tail -1`
TIME3=`./a.out $dict $grid | tail -1`
TIME4=`./a.out $dict $grid | tail -1`
TIME5=`./a.out $dict $grid | tail -1`
#Get Average of the 5 Returned Times
num=$((TIME1 + TIME2 + TIME3 + TIME4 + TIME5))
TOTAL=$((num / 5))
echo "The average time is $TOTAL milliseconds"
exit 4

