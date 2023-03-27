COMPILER=cc
PROG=main
FUNC=input.c tok_functions.c stack.c queue.c sya.c rpn_calc.c replace.c action.c
D_FLAG=-g
FLAGS =-lm
DEBUGER=gdb


a.out: ${PROG}.c ${FUNC}
	${COMPILER} ${PROG}.c ${FUNC} ${FLAGS}

debug:
	${COMPILER} ${PROG}.c ${FUNC} ${FLAGS} ${D_FLAG}
	${DEBUGER} ./a.out
clean:
	rm a.out
