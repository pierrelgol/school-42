NAME = webserv
CXX = clang++
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra -Werror=uninitialized -Werror=missing-field-initializers -g3 -fsanitize=undefined -fsanitize=null -fsanitize=address

SRCS := src/main.cpp                        \
        src/Utils.cpp                       \
        src/Parser.cpp                      \
        src/Server.cpp                      \
        src/Location.cpp                    \
        src/Request.cpp                     \
        src/Response.cpp                    \
        src/Webserv.cpp                     \
        src/WebservGet.cpp                  \
        src/WebservPost.cpp                 \
        src/WebservDelete.cpp               \
        src/WebservUtils.cpp                \
        src/Cgi.cpp                         \

INCS := ./include

OBJ_DIR := .obj
OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

NUM_CORES := $(shell nproc)

.PHONY: all re clean fclean build

all: $(NAME)

build:
	@$(MAKE) -j$(NUM_CORES) all || $(MAKE) all

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -ldl -o  $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCS) -c $< -o $@ -MMD -MP

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/src

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean build

-include $(DEPS)
