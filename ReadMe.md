# Minishell tests

Here are some tests for the minishell project of school 42 cursus. It's not exaustive, so don't limit yourself with this tests.
These tests are not all mines. Credits to vgoldman, mashar, and jecaudal.

tmarx
# Tests

- [b] echo bonjour ; |
- [x] echo bonjour | |
- [x] |
- [x] echo bonjour |;
- [x] echo bonjour \; ls
- [x] echo bonjour > test\ 1 [leaks]
- [x] cd $HOME/Documents
- [x] echo "\s" & echo "\\s"
- [x] echo \>
- [x] echo -n -n -nnnn -nnnnm
- [x] cat /dev/random | head -n 1 | cat -e
- [x] unset var1 # with undefined var1
- [!!]  export "" et unset ""
- [!!] echo test > file test1 [+leaks]
- [x] $
- [x] not_cmd bonjour > salut
- [x] env puis export puis env # vars aren't sorted
- [!!] cat Makefile | grep pr | head -n 5 | cd test # check status code
- [x] cat Makefile | grep pr | head -n 5 | cat test (bin) # check status code
- [x] cat Makefile | grep pr | head -n 5 | hello (NA) # check status code
- [x] echo bonjour >>> test
- [x] echo bonjour > > out
- [x] echo 2 >> out1 > out2
- [x] echo 2 > out1 >> out2
- [x] cat < test # with non-existent test
- [x] export var; export var=test
- [x] echo bonjour > $test # with test not defined
- [x] file_name_in_current_dir
- [x] cd ../../../../../.. ; pwd
- [x] ctrl-C . 130 sur bin(ex : sleep 10)&line vide
- [x] ctrl-\ .131 sur bin
- [x] echo "bip | bip ; coyotte > < \" "
- [x] cat | cat | cat | ls # check outputs order
- [x] $bla # with bla not defined
- [x] export var ="cat Makefile | grep >"
- [x] export "test=ici"=coucou
- [x] c$var Makefile # with var=at
- [x] $LESS$VAR
- [x] /bin/echo bonjour
- [x] not_cmd
- [x] sleep 5 | exit
- [!!] echo bonjour > $test w/ t
- [x] "exit retour a la ligne"
- [ ] minishell # binary not in path without "./" before
- [x] cat diufosgid # check exit code
- [!!] exit # should return the last exit code value [FIXED]
- [x] exit -10
- [x] exit +10
- [b] ;
- [b] echo coucou | ;
- [x] echo "$HOME"
- [x] echo '$HOME'
- [b] export ; env # display is different for both commands
- [x] echo \$HOME
- [x] > log echo coucou
- [x] echo hudifg d | | hugdfihd
- [x] echo
- [x] echo simple
- [x] echo -n simple
- [x] echo '\'
- [x] echo "\"
- [x] echo "\\"
- [x] echo "\n \n \n"
- [x] echo "\n \\n \\\n"
- [b] echo ;;
- [b] echo hi";" hihi
- [b] echo hi "   ;   " hihi
- [x] cd
- [x] cd .
- [x] cd ~
- [x] cd /
- [x] cd no_file
- [x] cd a b c d
- [x] pwd a
- [x] pwd a b c d
- [x] export LOL=lala ROR=rara
- [x] unset LOL ROR
- [x] export "HI= hi"
- [x] export "HI =hi"
- [x] /bin/ls
- [x] # write something then press ctrl+c
- [x] # write something then press ctrl+d
- [x] # write something then press ctrl+\
- [x] echo $?
- [x] l^Ds
- [x] echo |
- [x] | echo
- [x] sort | ls # check output order
- [x] cat < >
- [x] cat < <
- [x] cat > >
- [!!] > a ls > b < Makefile
- [!!] echo > a Hello World!
- [!!] > a echo Hello World!
- [!!] cat < Makefile | grep gcc > output
- [x] exit 0 | exit 1
- [x] exit 1 | exit 0
