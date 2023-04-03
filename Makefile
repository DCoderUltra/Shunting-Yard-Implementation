PROG = main
FILES = f_create.c str_prep.c tok_functions.c sya.c stack.c queue.c functions.c rpn_calc.c action.c
COMP = cc
FLAGS= -lm

${PROG} : ${PROG}.c ${FILES}
	  ${COMP} ${PROG}.c -o ${PROG} ${FILES} ${FLAGS}
debug:
	  ${COMP} ${PROG}.c -o ${PROG} ${FILES} ${FLAGS} -g
	  gdb ./${PROG}
