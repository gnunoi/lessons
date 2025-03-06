SHELL=bash
PANDOC=pandoc
MD=$(wildcard *.md)
PDF=$(MD:.md=.pdf)
MAIN=C++程序设计第二讲
PANDOC=pandoc -s -f markdown -t pdf \
  -V author="丁保华（致慧星空工作室）" \
  -V numbersections \
  -V secnumdepth:3 \
  --pdf-engine=xelatex --pdf-engine-opt=-shell-escape \
  --template=upandoc.tex

.PHONY:all clean distclean c d

#all:$(MAIN).pdf
all:$(PDF)

%.pdf:%.md
	$(PANDOC) $< -o $@

clean: 
	@rm -f *.pdf

distclean : clean
	@rm -f *.pdf

c:clean

d:distclean

