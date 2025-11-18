# =============================================================================
#  sshmud – Static library + test suite
# =============================================================================

CC      := gcc
AR      := ar
RANLIB  := ranlib

# Directories
SRCDIR        := src
INCDIR        := include
BINDIR        := bin
OBJDIR        := build

TESTDIR       := test
TEST_OBJDIR   := $(TESTDIR)/build
TEST_BINDIR   := $(TESTDIR)/bin

# Library
LIBNAME := libsshmud.a
LIB     := $(BINDIR)/$(LIBNAME)

SRCS    := $(wildcard $(SRCDIR)/*.c)
OBJS    := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Tests
TEST_SRCS := $(wildcard $(TESTDIR)/*.c)
TEST_OBJS := $(TEST_SRCS:$(TESTDIR)/%.c=$(TEST_OBJDIR)/%.o)
TEST_EXES := $(TEST_SRCS:$(TESTDIR)/%.c=$(TEST_BINDIR)/%)

# Flags
CFLAGS       := -std=gnu99 -O2 -Wall -Wextra -Werror -fPIC
CPPFLAGS     := -I$(INCDIR)

TEST_CPPFLAGS := -I$(INCDIR)
TEST_LDFLAGS  := -L$(BINDIR)
TEST_LDLIBS   := -lsshmud
TEST_LIBS     := -pthread

# Default target
.PHONY: all clean install test test-run dirs
all: dirs $(LIB)

# -----------------------------------------------------------------------------
# Directory creation
# -----------------------------------------------------------------------------
dirs: | $(BINDIR) $(OBJDIR) $(TEST_OBJDIR) $(TEST_BINDIR)

$(BINDIR) $(OBJDIR) $(TEST_OBJDIR) $(TEST_BINDIR):
	@mkdir -p $@

# -----------------------------------------------------------------------------
# Library
# -----------------------------------------------------------------------------
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIB): $(OBJS) | $(BINDIR)
	$(AR) rcs $@ $^
	$(RANLIB) $@

# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------
$(TEST_OBJDIR)/%.o: $(TESTDIR)/%.c | $(LIB) dirs
	$(CC) $(TEST_CPPFLAGS) $(CFLAGS) -c $< -o $@

$(TEST_BINDIR)/%: $(TEST_OBJDIR)/%.o | $(LIB) dirs
	$(CC) $(CFLAGS) $< -o $@ $(TEST_LDFLAGS) $(TEST_LDLIBS) $(TEST_LIBS)

test: $(TEST_EXES)

test-run: test
	@echo "Running all tests..."
	@failed=0; \
	for t in $(TEST_EXES); do \
		echo "=== $$t ==="; \
		./$$t || { echo "FAIL: $$t"; failed=1; }; \
		echo; \
	done; \
	[ $$failed -eq 0 ] && echo "All tests PASSED!" || { echo "Some tests FAILED."; exit 1; }

# -----------------------------------------------------------------------------
# Install (copy library + headers)
# -----------------------------------------------------------------------------
install: all
	@cp -a $(INCDIR) $(BINDIR)/

# -----------------------------------------------------------------------------
# Clean
# -----------------------------------------------------------------------------
clean:
	rm -rf $(OBJDIR) $(BINDIR)/$(LIBNAME) $(BINDIR)/$(INCDIR)
	rm -rf $(TEST_OBJDIR) $(TEST_BINDIR)

# =============================================================================