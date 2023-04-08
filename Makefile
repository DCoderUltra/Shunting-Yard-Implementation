PROG = sya
FILES = main.c f_create.c str_prep.c queue.c tok_functions.c alg_sya.c stack.c functions.c rpn_calc.c action.c
COMP = cc
FLAGS= -lm

${PROG} : ${FILES}
	  ${COMP} -o ${PROG} ${FILES} ${FLAGS}
debug:
	  ${COMP} -o ${PROG} ${FILES} ${FLAGS} -g
	  gdb ./${PROG}
