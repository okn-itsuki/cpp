NAME := zombie

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

DBG_NAME = $(NAME)_debug
DBGFLAGS = -g3 -O0 -DDEBUG

DBG_CXXFLAGS = $(CXXFLAGS) $(DBGFLAGS)

SRCS := main.cpp  newZombie.cpp  randomChump.cpp  Zombie.cpp  Zombie.hpp
OBJS = $(SRCS:.cpp=.o)
DBG_OBJS = $(SRCS:.cpp=_debug.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

debug: $(DBG_NAME)

$(DBG_NAME): $(DBG_OBJS)
	$(CXX) $(DBG_CXXFLAGS) $(DBG_OBJS) -o $(DBG_NAME)

%_debug.o: %.cpp
	$(CXX) $(DBG_CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DBG_OBJS)

fclean: clean
	rm -f $(NAME) $(DBG_NAME)

re: fclean all

.PHONY: all debug clean fclean re