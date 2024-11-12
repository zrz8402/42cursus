
# process and zombies 
: << END_COMMENT 
Zombies only exists while child has returned and parent has not. As soon as parent returned,
child is adopted by the 'init' process (pid 1), collecting its status and removing it from process table.
We can find zombie with : 
	-> ps -e (or a|u|x) looking for <defunct> or Z+ in stat column
	-> top -bn1 looking for zombie nb on the second line, or Z in stat
we'll use second line of top. First check the nb, do the test, recheck the nb before pipex returned : if increased then pipex creates zombie
we need to get one child returned and not pipex so lets have a ./pipex sleep 3 sleep 1 and we be checking if sleep 1 became a z
about killing : seems like singint doesnot kill children of specified process, sigterm and sigkill do kill children
sigkill output on stdout, sigterm and singint dont
$! refers to the pid of the last pipeline launched in bg
END_COMMENT

echo -e "${BLU_BG}Zombies (children process not waited by pipex):${END}"
rm -rf *top_result zombies_test*


echo -ne "Test 1 : ./pipex Makefile \"sleep 3\" \"sleep 1\" outf \t\t\t--> "
start_Z_nb=$(top -bn1 | head -n2 | egrep -o "[0-9]* zombie$" | egrep -o "[0-9]*")
./pipex Makefile "sleep 3" "sleep 1" outf &
sleep 1
exec_Z_nb=$(top -bn1 | head -n2 | egrep -o "[0-9]* zombie$" | egrep -o "[0-9]*")
ps -aux | grep Z | grep -vi grep > zombie_test1
kill -s SIGTERM $! > /dev/null 2>&1 || kill -s SIGKILL $! > /dev/null 2>&1
[[ $(( $exec_Z_nb - $start_Z_nb )) -eq 0 ]] && echo -e "${GREEN}OK (sleep 1 did not became a zombie)${END}" && rm -f zombie_test1
[[ $(( $exec_Z_nb - $start_Z_nb )) -gt 0 ]] && echo -e "${YEL}KO: $(( $exec_Z_nb - $start_Z_nb )) process became zombie before pipex returned (most probably sleep 1, please check 'zombie_test1')${END}"
rm -f outf

echo -ne "Test 2 : ./pipex Makefile \"sleep 1\" \"sleep 3\" outf \t\t\t--> "
start_Z_nb=$(top -bn1 | head -n2 | egrep -o "[0-9]* zombie$" | egrep -o "[0-9]*")
./pipex Makefile "sleep 1" "sleep 3" outf &
sleep 1 
exec_Z_nb=$(top -bn1 | head -n2 | egrep -o "[0-9]* zombie$" | egrep -o "[0-9]*")
ps -aux | grep Z | grep -vi grep > zombie_test2
kill -s SIGTERM $! > /dev/null 2>&1 || kill -s SIGKILL $! > /dev/null 2>&1
[[ $(( $exec_Z_nb - $start_Z_nb )) -eq 0 ]] && echo -e "${GREEN}OK (sleep 1 did not became a zombie)${END}" && rm -f zombie_test2
[[ $(( $exec_Z_nb - $start_Z_nb )) -gt 0 ]] && echo -e "${YEL}KO: $(( $exec_Z_nb - $start_Z_nb )) process became a zombie before pipex returned (most probably sleep 1, please check 'zombie_test2')${END}"
rm -f outf

echo -ne "Test 3 : ./pipex bad_infile ls \"sleep 2\" outf \t\t\t\t--> "
start_Z_nb=$(top -bn1 | head -n2 | egrep -o "[0-9]* zombie$" | egrep -o "[0-9]*")
./pipex bad_infile ls "sleep 2" outf > /dev/null 2>&1 &
sleep 1
exec_Z_nb=$(top -bn1 | head -n2 | egrep -o "[0-9]* zombie$" | egrep -o "[0-9]*")
ps -aux | grep Z | grep -vi grep > zombie_test3
kill -s SIGTERM $! > /dev/null 2>&1 || kill -s SIGKILL $! > /dev/null 2>&1
[[ $(( $exec_Z_nb - $start_Z_nb )) -eq 0 ]] && echo -e "${GREEN}OK (ls did not became a zombie)${END}" && rm -f zombie_test3
[[ $(( $exec_Z_nb - $start_Z_nb )) -gt 0 ]] && echo -e "${YEL}KO: $(( $exec_Z_nb - $start_Z_nb )) process became a zombie before pipex returned (most probably ls, please check 'zombie_test3')${END}"
rm -f outf

echo -ne "Test 4 : ./pipex Makefile bad_cmd \"sleep 1\" outf \t\t\t--> "
start_Z_nb=$(top -bn1 | head -n2 | egrep -o "[0-9]* zombie$" | egrep -o "[0-9]*")
./pipex Makefile bad_cmd "sleep 1" outf > /dev/null 2>&1 & 
exec_Z_nb=$(top -bn1 | head -n2 | egrep -o "[0-9]* zombie$" | egrep -o "[0-9]*")
ps -aux | grep Z | grep -vi grep > zombie_test4
kill -s SIGTERM $! > /dev/null 2>&1 || kill -s SIGKILL $! > /dev/null 2>&1
[[ $(( $exec_Z_nb - $start_Z_nb )) -eq 0 ]] && echo -e "${GREEN}OK (bad_cmd did not became a zombie)${END}" && rm -f zombie_test4
[[ $(( $exec_Z_nb - $start_Z_nb )) -gt 0 ]] && echo -e "${YEL}KO: $(( $exec_Z_nb - $start_Z_nb )) process became a zombie before pipex returned (most probably bad_cmd, please check 'zombie_test4')${END}"
rm -f outf

