SRC = ft_ssl.c
SRC += common.c
SRC += md5.c
SRC += parsing.c
SRC += print.c
SRC += sha256.c
SRC += utils.c

NAME = ft_ssl

SRCDIR = srcs/
OBJDIR = objs/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

LIB = libft/libft.a
FLAG = -Wall -Werror -Wextra
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m
INC = -I ./includes/

all: start lib $(NAME)

lib:
	-@make -C libft nohd
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(FLAG) $(INC) $(LIB);
	@echo "\033[K$(CY)[FT_SSL] :$(CE) $(CG)Compiling ft_ssl$(CE)";


start:
	@echo "\n";
	@echo "			$(CG)      :::::::::: :::::::::::           ::::::::   ::::::::  :::   $(CE)";
	@echo "			$(CG)     :+:            :+:              :+:    :+: :+:    :+: :+:    $(CE)";
	@echo "			$(CG)    +:+            +:+              +:+        +:+        +:+     $(CE)";
	@echo "			$(CG)   :#::+::#       +#+              +#++:++#++ +#++:++#++ +#+      $(CE)";
	@echo "			$(CG)  +#+            +#+                     +#+        +#+ +#+       $(CE)";
	@echo "			$(CG) #+#            #+#              #+#    #+# #+#    #+# #+#        $(CE)";
	@echo "			$(CG)###            ###    ########## ########   ########  ##########  $(CE)";
	@echo "\n";

$(OBJ): $(OBJDIR)%.o: $(SRCDIR)%.c
	@echo "\033[K$(CY)[FT_SSL] :$(CE) $(CG)Compiling $<$(CE)";
	@gcc $(FLAG) -c $< -o $@ $(INC)

clean: start
	@echo "$(CY)[FT_SSL] :$(CE) $(CG)Cleaning ft_ssl objects$(CE)";
	-@make -C libft nohdclean;
	@/bin/rm -rf $(OBJ);

fclean: start clean
	@echo "\033[K$(CY)[FT_SSL] :$(CE) $(CG)Cleaning binairies ...$(CE)";
	-@make -C libft nohdfclean;
	@/bin/rm -f $(NAME);

re: fclean all

.PHONY: all clean fclean re
