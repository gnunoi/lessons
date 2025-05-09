SHELL=bash
LATEX=xelatex --shell-escape
LATEXMK=latexmk -xelatex --shell-escape
#LATEXMK=latexmk -silent -xelatex --shell-escape
TEX=$(wildcard *.tex)
PDF=$(TEX:.tex=.pdf)
MAIN=速算方法
MAIN2=速算方法打印版

.PHONY:all clean distclean c d

#all:$(PDF)
all:$(MAIN).pdf $(MAIN2).pdf
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

