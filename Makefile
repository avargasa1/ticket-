CC = gcc
CPPFLAGS =
CFLAGS = -Wall -Wextra -Werror -std=c11 -g -O0
DEPFLAGS = -MMD -MP
TARGET = resumen_taller
OBJS = main.o leer_taller.o calcular_taller.o imprimir_taller.o
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) -c -o $@ $<

test: $(TARGET)
	../scripts/tests-run.sh ./$(TARGET) ../tests

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS) ../tests/*.out ../tests/*.err ../tests/*.diff

-include $(DEPS)

.PHONY: all clean test
