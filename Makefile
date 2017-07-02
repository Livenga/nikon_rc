XC     = xc8
CHIP   = 16F648A
TARGET = nikon_rc
BIN    = bin
OBJDIR = objs

SRC    = $(shell find src/ -name \*.c)
OBJS   = $(addprefix $(OBJDIR)/, $(patsubst %.c, %.p1, $(SRC)))
BINDIR = $(dir $(OBJS))


default:
	[ -d  $(BIN)     ] || mkdir -v $(BIN)
	[ -d  $(OBJDIR)  ] || mkdir -v $(OBJDIR)
	[ -d "$(BINDIR)" ] || mkdir -pv $(BINDIR)
	make $(TARGET)

$(TARGET):$(OBJS)
	$(XC) --chip=$(CHIP) --outdir=$(BIN) -O$@ $^

$(OBJDIR)/%.p1:%.c
	$(XC) --pass1 --chip=$(CHIP) --outdir=$(dir $@) $<

clean:
	rm -r $(BIN)
	rm -r $(OBJDIR)

all:
	make clean
	make
