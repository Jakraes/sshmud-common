CC := gcc
AR := ar
RANLIB := ranlib

SRCDIR := src
INCDIR := include
BIN_DIR := bin
OBJDIR := build

LIBNAME := libsshmud.a

SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

CFLAGS := -std=c11 -O2 -Wall -Wextra -Werror -fPIC
CPPFLAGS := -I$(INCDIR)

.PHONY: all clean install dirs

all: dirs $(BIN_DIR)/$(LIBNAME)

dirs:
	mkdir -p $(BIN_DIR) $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/$(LIBNAME): $(OBJS)
	$(AR) rcs $@ $(OBJS)
	$(RANLIB) $@

clean:
	rm -rf $(OBJDIR) $(BIN_DIR)/$(LIBNAME) $(BIN_DIR)/$(INCDIR)

install: all
	@mkdir -p $(BIN_DIR)
	cp -a $(INCDIR) $(BIN_DIR)/
	@echo "Built $(BIN_DIR)/$(LIBNAME) and copied headers to $(BIN_DIR)/$(INCDIR)"