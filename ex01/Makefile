# **************************************************************************** #
#    VARIABLES
# **************************************************************************** #

NAME 		:=	phonebook
FILETYPE	:=	.cpp
BUILDLOG	:=	build.log

SRCSDIR		:=	.
OBJSDIR		:=	build
DEPSDIR		:=	.deps

# **************************************************************************** #
#    COMMANDS
# **************************************************************************** #

RM			:=	rm -rf
CL			:=	printf "\033c"

# **************************************************************************** #
#    COMPILATION
# **************************************************************************** #

CC			:=	c++
CFLAGS		:=	-Wall -Werror -Wextra
DBGFLAGS	=	-g -fsanitize=address
DEPFLAGS	=	-c -MT $$@ -MMD -MP -MF $(DEPSDIR)/$$*.d

# **************************************************************************** #
#    SOURCES
# **************************************************************************** #

SOURCES		:= main \
			   PhoneBook \
			   Contact

SOURCES 	:= $(addsuffix $(FILETYPE), $(SOURCES))

# **************************************************************************** #
#    TARGETS
# **************************************************************************** #

SRCS	:= $(foreach src, $(SOURCES), $(shell find $(SRCSDIR) -name $(src)))
OBJS	:= $(patsubst $(SRCSDIR)/%$(FILETYPE), $(SRCSDIR)/$(OBJSDIR)/%.o, $(SRCS))
DEPS	:= $(patsubst $(SRCSDIR)/%$(FILETYPE), $(SRCSDIR)/$(DEPSDIR)/%.d, $(SRCS))

vpath %$(FILETYPE) $(SRCSDIR)

# **************************************************************************** #
#    RULES
# **************************************************************************** #

all: $(NAME)

re: fclean all

debug: CFLAGS += $(DBGFLAGS)
debug: re

run: all
	$(CL) && $(SRCSDIR)/$(NAME)

.PHONY: all re
.PHONY: debug
.PHONY: run

# **************************************************************************** #
#    BUILD
# **************************************************************************** #

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "$(C)$(B)Finish:$(T)$(V) $@"

define build_cmd
$1/%.o: %$(FILETYPE) | $(OBJSDIR) $(DEPSDIR)
	@if ! $(CC) $(CFLAGS) $(DEPFLAGS) $$< -o $$@ 2> $(BUILDLOG); then \
		printf "$(R)$(B)\nERROR!\n$(F)$(T)\n"; \
		printf "$(V)Unable to create object file:$(T)\n\n"; \
		printf "$(R)$(B)$$@$(T)\n"; \
		printf "$(Y)\n"; sed '$$d' $(BUILDLOG); \
		printf "$(R)$(B)\n$(F)\nExiting...$(T)\n"; exit 1 ; \
	else \
		printf "$(C)$(B)Build:$(T)$(V) $$<$\
		$(Y) [$(CC) $(CFLAGS)]\
		$(R)->$(G) $$@ $(T)\n"; \
	fi
endef

# **************************************************************************** #
#    CLEAN
# **************************************************************************** #

clean:
	@printf "$(C)$(B)Delete: $(T)$(V)$(OBJSDIR) $(DEPSDIR) $(BUILDLOG)$(T)\n"
	@$(RM) $(OBJSDIR) $(DEPSDIR) $(BUILDLOG)

fclean: clean
	@printf "$(C)$(B)Delete: $(T)$(V)$(NAME)$(T)\n"
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
