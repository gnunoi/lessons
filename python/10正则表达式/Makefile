SHELL=bash
LATEX=xelatex --shell-escape
LATEXMK=latexmk -xelatex --shell-escape
TEX=$(wildcard *.tex)
PANDOC := pandoc
PANDOC_FLAGS := -s -f markdown \
  -V author="丁保华（致慧星空工作室）" \
  -V numbersections \
  -V secnumdepth=4 \
  --wrap=none \
  --listings \
  --pdf-engine=xelatex \
  --template=../../styles/upandoc.tex

MD := $(wildcard *.md)
DOCX := $(MD:.md=.docx)
PDF := $(MD:.md=.pdf)
PDF += $(TEX:.tex=.pdf)
MAIN=变量与类型

.PHONY:all clean c
all:$(PDF)

%.pdf:%.md
	$(PANDOC) $(PANDOC_FLAGS) -t pdf $< -o $@

%.docx:%.md
	$(PANDOC) -t docx $< -o $@

%.pdf:%.tex
	$(LATEXMK) $<

clean: 
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

distclean : clean
	@rm -f *.pdf *.docx

c:clean

d:distclean

