define colorecho
      @tput setaf 2
      @echo $1
      @tput sgr0
endef
CFLAGS   = -Wall -Wextra -no-pie -mtune=native
PCRE_CFLAGS := $(CFLAGS) `pkg-config --cflags libpcre2-8`
LDFLAGS  = -lm
PCRE_LDFLAGS := $(LDFLAGS) `pkg-config --libs libpcre2-8`
TARGETS = posix_re read_file pcre2 pcre2demo

.PHONY: all
all: $(TARGETS)

posix_re: posix_re.c 
	@cc $(CFLAGS) -o $@ $< $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

pcre2: pcre2.c 
	@cc $(PCRE_CFLAGS) -o $@ $< $(PCRE_LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

pcre2demo: pcre2demo.c 
	@cc $(PCRE_CFLAGS) -o $@ $< $(PCRE_LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

read_file:   read_file.c
	@cc $(CFLAGS) -o $@ $+ $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

.PHONY: clean
clean:
	@rm $(TARGETS) 2>/dev/null || true
	$(call colorecho,"It is clean now.")

