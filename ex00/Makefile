# **************************************************************************** #
#    VARIABLES
# **************************************************************************** #

NAME 		:=	megaphone
FILETYPE	:=	.cpp
BUILDLOG	:=	buildlog.txt
ROOTDIR		:=	.

OBJSDIR		:=	build
INCSDIR		:=	includes
SRCSDIR		:=	sources
DEPSDIR		:=	.deps

# **************************************************************************** #
#    COMMANDS
# **************************************************************************** #

RM			:=	rm -rf
CLR			:=	printf "\033c"

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

SOURCES		:= megaphone

SOURCES 	:= $(addsuffix $(FILETYPE), $(SOURCES))

# **************************************************************************** #
#    TARGETS
# **************************************************************************** #

SOURCEDIR	:= $(addprefix $(ROOTDIR)/, $(SRCSDIR))
BUILDDIR	:= $(addprefix $(ROOTDIR)/, $(OBJSDIR))
DEPENDDIR	:= $(addprefix $(ROOTDIR)/, $(DEPSDIR))

SRCS	:= $(foreach src, $(SOURCES), $(shell find $(SOURCEDIR) -name $(src)))
OBJS	:= $(patsubst $(SOURCEDIR)/%$(FILETYPE), $(BUILDDIR)/%.o, $(SRCS))
DEPS	:= $(patsubst $(SOURCEDIR)/%$(FILETYPE), $(DEPENDDIR)/%.d, $(SRCS))

INCS	:= $(foreach hdr, $(ROOTDIR)/$(INCSDIR), -I $(hdr))

vpath %$(FILETYPE) $(SOURCEDIR)

# **************************************************************************** #
#    RULES
# **************************************************************************** #

all: $(NAME)

re: fclean all

debug: CFLAGS += $(DBGFLAGS)
debug: re

test: re
	$(CLR)
	$(ROOTDIR)/$(NAME) "shhhhh... I think the students are asleep..."
	$(ROOTDIR)/$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	$(ROOTDIR)/$(NAME)

.PHONY: all re
.PHONY: debug
.PHONY: test

# **************************************************************************** #
#    BUILD
# **************************************************************************** #

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCS) $^ -o $@

define build_cmd
$1/%.o: %$(FILETYPE) | $(BUILDDIR) $(DEPENDDIR)
	@if ! $(CC) $(CFLAGS) $(INCS) $(DEPFLAGS) $$< -o $$@ 2> $(BUILDLOG); then \
		printf "$(R)$(B)\nERROR!\n$(F)$(T)\n"; \
		printf "$(V)Unable to create object file:$(T)\n\n"; \
		printf "$(R)$(B)$$@$(T)\n"; \
		printf "$(Y)\n"; sed '$$d' $(BUILDLOG); \
		printf "$(R)$(B)\n$(F)\nExiting...$(T)\n"; exit 1 ; \
	else \
		printf "$(C)$(B)Source:$(T)$(V) $$<$ $(T)\n"; \
		printf "$(C)$(B)Flags:$(T)$(Y) $(CC) $(CFLAGS) $(T)\n"; \
		printf "$(C)$(B)Build:$(T)$(G) $(B)$$@ $(T)\n"; \
	fi
endef

# **************************************************************************** #
#    CLEAN
# **************************************************************************** #

clean:
	@printf "$(C)$(B)Removed: $(T)$(V)$(BUILDDIR) $(DEPENDDIR) $(BUILDLOG)$(T)\n"
	@$(RM) $(BUILDDIR) $(DEPENDDIR) $(BUILDLOG)

fclean: clean
	@printf "$(C)$(B)Removed: $(T)$(V)$(NAME)$(T)\n"
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

$(BUILDDIR) $(DEPENDDIR):
	@mkdir -p $@

$(DEPS):
	include $(wildcard $(DEPS))

$(foreach build, $(BUILDDIR), $(eval $(call build_cmd, $(build))))
