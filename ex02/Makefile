NAME = NoYouNeedForm28bNot28c

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRCS = src/main.cpp src/Bureaucrat.cpp src/AForm.cpp src/RobotomyRequestForm.cpp \
	src/PresidentialPardonForm.cpp src/ShrubberyCreationForm.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: fclean all