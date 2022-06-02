SRCS	= get_next_line.c get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror -c

BUF		= -D BUFFER_SIZE=28

AR		= ar rc

O		= -o

NAME	= libget_next_line.a

all:		${NAME}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

.c.o:		${SRCS}
			${GCC} ${FLAGS} ${BUF} $< ${O} $(<:.c=.o)
