CC = gcc
CPPFLAGS =
CFLAGS = -Wall -Wextra -Werror -std=c11 -g -O0 
DEPFLAGS = -MMD -MP
TARGET = evacuacion
OBJS = parser.o capacity.o priority.o report.o main.o
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS) ../tests/*.out ../tests/*.err ../tests/*.diff

-include $(DEPS)

.PHONY: all clean
