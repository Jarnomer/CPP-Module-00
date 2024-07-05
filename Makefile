# **************************************************************************** #
#    VARIABLES
# **************************************************************************** #

NAME 		:= ex00
FILETYPE	:= .cpp
BUILDLOG	:= buildlog.txt
ROOOTDIR	:= .

OBJSDIR		:= build
INCSDIR		:= includes
SRCSDIR		:= sources
DEPSDIR		:= .deps

# **************************************************************************** #
#    COMMANDS
# **************************************************************************** #

RM		:= rm -rf

# **************************************************************************** #
#    COMPILATION
# **************************************************************************** #

CC		:=	c++
CFLAGS		:=	-Wall -Werror -Wextra
DBGFLAGS	=	-g -fsanitize=address
DEPFLAGS	=	-c -MT $$@ -MMD -MP -MF $(DEPSDIR)/$$*.d

# **************************************************************************** #
#    SOURCES
# **************************************************************************** #

SOURCES		:= megaphone

SOURCES 	:= $(addsuffix $(FILETYPE), $(SOURCES))

# **************************************************************************** #
#    TARGETS
# **************************************************************************** #

SOURCEDIR	:= $(addprefix $(ROOTDIR)/, $(SRCSDIR))
BUILDDIR	:= $(addprefix $(ROOTDIR)/, $(OBJSDIR))
DEPENDDIR	:= $(addprefix $(ROOTDIR)/, $(DEPSDIR))

SRCS	:= $(foreach src, $(SOURCES), $(shell find $(SOURCEDIR) -name $(src)))
OBJS	:= $(patsubst $(SRCSDIR)/%.c, $(OBJSDIR)/%.o, $(SRCS))
DEPS	:= $(patsubst $(OBJSDIR)/%.o, $(DEPSDIR)/%.d, $(OBJS))

INCS	:= $(foreach hdr, $(ROOTDIR)/$(INCSDIR), -I $(hdr))

# **************************************************************************** #
#    RULES
# **************************************************************************** #

all: $(NAME)

re: fclean all

debug: CFLAGS += $(DBGFLAGS)
debug: re

run: re
	./$(NAME)

.PHONY: all re
.PHONY: debug run

# **************************************************************************** #
#    BUILD
# **************************************************************************** #

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCS) $^ -o $@

define build_cmd
$1/%.o: %.c | $(OBJSDIR) $(DEPSDIR)
	@if ! $(CC) $(CFLAGS) $(INCS) $(DEPFLAGS) $$< -o $$@ 2> $(BUILDLOG); then \
		printf "$(R)$(B)\nERROR!\n$(F)$(T)\n"; \
		printf "$(V)Unable to create object file:$(T)\n\n"; \
		printf "$(R)$(B)$$@$(T)\n"; \
		printf "$(Y)\n"; sed '$$d' $(BUILDLOG); \
		printf "$(R)$(B)\n$(F)\nExiting...$(T)\n"; exit 1 ; \
	else \
		printf "$(C)$(B)☑$(T)$(V) $(CC) $(CFLAGS) $$<$ \n  $(C)⮑  $(G)$(B)$$@$(T)\n"; \
	fi
endef

# **************************************************************************** #
#    CLEAN
# **************************************************************************** #

clean:
	@printf "$(C)$(B)Removed $(T)$(V)$(OBJSDIR) $(DEPSDIR) $(BUILDLOG)$(T)\n"
	@$(RM) $(OBJSDIR) $(DEPSDIR) $(BUILDLOG)

fclean: clean
	@printf "$(C)$(B)Removed $(T)$(V)$(NAME)$(T)\n"
	@$(RM) $(NAME)

.PHONY: clean fclean

# **************************************************************************** #
#    FORMAT
# **************************************************************************** #

F	=	=================================
B	=	\033[1m
T	=	\033[0m
G	=	\033[32m
V	=	\033[35m
C	=	\033[36m
R	=	\033[31m
Y	=	\033[33m

# **************************************************************************** #
#    UTILS
# **************************************************************************** #

$(OBJSDIR) $(DEPSDIR):
	@mkdir -p $@

$(DEPS):
	include $(wildcard $(DEPS))

$(foreach build, $(OBJSDIR), $(eval $(call build_cmd, $(build))))
