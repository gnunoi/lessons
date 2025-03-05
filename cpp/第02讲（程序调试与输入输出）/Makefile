SHELL=bash
PANDOC=pandoc
MD=$(wildcard *.md)
PDF=$(MD:.md=.pdf)
MAIN=C++程序设计第二讲
PANDOC=pandoc -s -f markdown -t pdf --pdf-engine=xelatex \
	--template=template.tex

.PHONY:all clean distclean c d

#all:$(MAIN).pdf
all:$(PDF)
	make clean

%.pdf:%.md
	$(PANDOC) $< -o $@

clean: 

distclean : clean
	@rm -f *.pdf

c:clean

d:distclean

