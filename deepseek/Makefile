SHELL=bash
LATEX=xelatex --shell-escape
LATEXMK=latexmk -xelatex --shell-escape
#LATEXMK=latexmk -quiet -xelatex --shell-escape
TEX=$(wildcard *.tex)
PDF=$(TEX:.tex=.pdf)
MAIN=deepseek

.PHONY:all clean distclean c d

#all:$(MAIN).pdf
all:$(PDF)
	make clean

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
	@rm -f *.pdf

c:clean

d:distclean

