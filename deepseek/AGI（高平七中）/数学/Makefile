SHELL:= bash
DIR:=../../../
LATEX=xelatex --shell-escape
PANDOC := pandoc
MD := $(wildcard *.md)
TEX := $(wildcard *.tex)
PDF_MD := $(MD:.md=.pdf)
PDF_TEX := $(TEX:.tex=.pdf)
PANDOC := pandoc 
PANDOC_FLAGS := -s -f markdown \
  -V author="丁保华（致慧星空工作室）" \
  -V numbersections \
  -V secnumdepth=4 \
  --wrap=none \
  --listings \
  --pdf-engine=xelatex \
  --template=$(DIR)styles/upandoc.tex

.PHONY:all clean c

all: $(PDF_TEX) $(PDF_MD)
	make clean

%.pdf:%.md
	$(PANDOC) $(PANDOC_FLAGS) -t pdf $< -o $@

%.pdf:%.tex
	$(LATEX) $<

clean: 
	@rm -f $(PDF) $(DOCX)
	@rm -f *.aux
	@rm -f *.fdb*
	@rm -f *.fls
	@rm -f *.gz
	@rm -f *.log
	@rm -f *.nav
	@rm -f *.out
	@rm -f *.snm
	@rm -f *.toc
	@rm -f *.vrb
	@rm -f *.xdv
	@rm -rf _minted*

c:clean

