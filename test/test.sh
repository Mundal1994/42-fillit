#!/bin/bash
MYPATH="/Users/molesen/Desktop/Hive/v_projects/fillit"
command -v $MYPATH/fillit >/dev/null 2>&1 || { printf "\nFillit not found!\n"; exit 1; }
LOCALPATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# nb of total valid test
nb=0

# colors
BOLD="\033[1m"
RED="\033[0;31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
PURPLE="\033[35m"
CYAN="\033[36m"
UNCOLOR="\033[0m"

# $1: i
function error_put()
{
	printf "\nfor the file tetri$1 (cat -e):\n"
	cat -e ${LOCALPATH}/notvalid/tetri$1
	printf "\nyour output is:"
}
function valid_put()
{
	printf "\nWHAT IS EXPECTED:\n"
	cat "${LOCALPATH}/solution/tetri$1"
	printf "\nYOUR OUTPUT:"
}

i=0
# $1: type test $2: pathfolder&name $3: number of test arg $4: var2 $5: 1 if var2 take i for arg, else 0 $6 fnctn error
function test()
{
	test_nb=0
	i=0
	printf "\n${PURPLE}${BOLD}$1 test${UNCOLOR}\n"
	while [ "$i" != $3 ]
	do
		printf "\n$1 test $i : \n"
		var=$((${MYPATH}/./fillit ${LOCALPATH}/$2$i) 2>&-)
		if [ "$5" == 1 ]
		then
			var2=$($4$i)
		else
			var2=$($4)
		fi
		# printf "\n$var2"
		if [ "$var" != "$var2" ]
		then
			printf "${RED}fail: ${UNCOLOR}\n"
			$6 $i
			printf "\n$var"
		else
			printf "$var\n"
			printf "		${GREEN}ok${UNCOLOR}\n"
			test_nb=$((test_nb+1))
		fi
		i=$((i+1))
	done
	if [ "$test_nb" != $3 ]
	then
		printf "\n${RED}$1 test failed, $test_nb / $3${UNCOLOR}\n"
	else
		printf "\n${GREEN}$1 test correct, $test_nb / $3${UNCOLOR}\n"
	fi
	nb=$((nb+test_nb))
}

function bonus()
{
	if [ "$nb" = 43 ]
	then
		printf "\n${PURPLE}${BOLD}BONUS ${UNCOLOR}\n"
		time ${MYPATH}/./fillit ${LOCALPATH}/valid/tetri1
		printf "\n"
		time ${MYPATH}/./fillit ${LOCALPATH}/valid/tetri2
		printf "\n"
		time ${MYPATH}/./fillit ${LOCALPATH}/valid/tetri23
		printf "\nNOTE: ${GREEN}43/43${UNCOLOR}"
	else
		printf "\nNOTE: ${RED}$nb / 43${UNCOLOR}"
	fi
}

function main()
{
	make re -C ${MYPATH}
	test invalid "notvalid/tetri" 20 "printf "error"" 0 error_put
	test valid "valid/tetri" 23 "cat ${LOCALPATH}/solution/tetri" 1 valid_put
	bonus
}

main
