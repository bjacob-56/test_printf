# test_printf

To use this test, clone it in your repo, compile with your libftprintf.a

Default test : `gcc -Wall -Wextra test.c -g3 libftprintf.a && ./a.out`

exemple all test : `gcc -Wall -Wextra test.c -g3 libftprintf.a && ./a.out a`

to check differents option run with whose differents av[1] 

- `./a.out a` for all tests
- `./a.out d` for %d
- `./a.out s` for %s
- `./a.out c` for %c
- `./a.out p` for %p
- `./a.out x` for %x
- `./a.out X` for %X
- `./a.out u` for %u
- `./a.out o` for %%
- `./a.out m` fot mixed tests

you can also check your unittest with solotest.c, just modify between |...| and add some args

**42/Lyon tclaudel**


# test_test_printf

To test the results printed by the test above, paste your 'libftprintf.h' file in this repo and run the command below.

- Create and parse the text printed by the test
`gcc -Wall -Wextra test_bis.c -g3 libftprintf.a && ./a.out all > results`

- Check for each line if the results with printf and ft_printf are the same
`gcc -Wall -Wextra -Werror check_test.c split_test.c && ./a.out`


**42/Lyon bjacob**
