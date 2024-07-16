NAME 		:=	megaphone
BUILDLOG	:=	build.log
BUILDDIR	:=	build
DEPENDDIR	:=	.deps

RM			:=	rm -rf
SCREENCLEAR	:=	printf "\033c"

CC			:=	c++
CFLAGS		:=	-Wall -Werror -Wextra
DBGFLAGS	=	-g -fsanitize=address
DEPFLAGS	=	-c -MT $$@ -MMD -MP -MF \
				$(DEPENDDIR)/$$*.d

SOURCES		:= megaphone.cpp

SRCS	:= $(foreach s, $(SOURCES), $(shell find . -name $(s)))
OBJS	:= $(patsubst ./%.cpp, ./$(BUILDDIR)/%.o, $(SRCS))
DEPS	:= $(patsubst ./%.cpp, ./$(DEPENDDIR)/%.d, $(SRCS))

vpath %.cpp .

all: $(NAME)

re: fclean all

debug: CFLAGS += $(DBGFLAGS)
debug: re

run: all
	@$(SCREENCLEAR)
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)

clean:
	@printf "$(R)$(B)Delete: $(T)$(Y)$(DEPENDDIR) $(BUILDDIR) $(BUILDLOG)$(T)\n"
	@$(RM) $(DEPENDDIR) $(BUILDDIR)  $(BUILDLOG)

fclean: clean
	@printf "$(R)$(B)Delete: $(T)$(Y)$(NAME)$(T)\n"
	@$(RM) $(NAME)

.PHONY: all re
.PHONY: clean fclean
.PHONY: debug run

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "$(C)$(B)Binary:$(T)$(Y) $@\n"

define build_cmd
$1/%.o: %.cpp | $(BUILDDIR) $(DEPENDDIR)
	@if ! $(CC) $(CFLAGS) $(DEPFLAGS) $$< -o $$@ 2> $(BUILDLOG); then \
		printf "$(R)$(B)\nError: \
		$(V)Unable to create object file: \
		$(R)$(B)$$@$(Y)\n\n"; \
		sed '$$d' $(BUILDLOG); exit 1 ; \
	else \
		printf "$(C)$(B)Object:$(T)$(V) $$<$ $(R) ->$(G)$(B) $$@ $(T)\n"; \
	fi

T	=	\033[0m
B	=	\033[1m
G	=	\033[32m
V	=	\033[35m
C	=	\033[36m
Y	=	\033[33m
R	=	\033[31m

$(BUILDDIR) $(DEPENDDIR):
	@mkdir -p $@

$(DEPS):
	include $(wildcard $(DEPS))

$(foreach build, $(BUILDDIR), $(eval $(call build_cmd, $(build))))
