# nom de la bibliotheque qui sera créée
NAME = libft.a

# compilateur utilisé
CC = cc

# flags de compilation 
CFLAGS = -Wall -Wextra -Werror

# commande pour créer une archive (bibliotheque)
AR = ar rcs

# commande pour supprimer des fichiers 
RM = rm -f

# tous les fichiers sources obligatoires presents dans le repertoire courant 
SRCS = $(filter-out %_bonus.c, $(wildcard *.c))

#tous les fichiers bonus presents dans le repertoire courant.
BONUS = $(wildcard *_bonus.c)


# conversion des fichiers .c en fichiers objets .o 
OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUS:.c=.o)
OBJS_ALL = $(OBJS) $(BOBJS) # Définir OBJS_ALL qui contient tous les objets


# regle principale : creation de la bibliotheque 
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) # creation de la bibliotheque libft.a avec tous les fichiers objets 

# regle all : Compile la bibliotheque 
all: $(NAME)

# regle bonus : complie les fichiers bonus et les ajoutes a la bibliotheque 
bonus: $(OBJS) $(BOBJS)  
	$(AR) $(NAME) $(OBJS) $(BOBJS) #compilation avec tous les fichiers objets.

# regle clean : supprime tous les fichiers objets .o 
clean:
	$(RM) $(OBJS) $(BOBJS)

# regle fclean : supprime tous les fichiers objets et la bibliotheque 
fclean: clean
	$(RM) $(NAME)

# regle re : supprime tout et recommence la compilation 
re: fclean all

# generation des fichiers objets (.o) depuis les fichiers sources (.c)
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# .PHONY evite les conflits entre les noms des fichiers et les noms des regles
.PHONY: all clean fclean re bonus
