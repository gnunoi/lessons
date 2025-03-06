SHELL:= bash
PANDOC := pandoc
MD := $(wildcard *.md)
PDF := $(MD:.md=.pdf)
DOCX := $(MD:.md=.docx)
MAIN := C++程序设计第二讲
PANDOC := pandoc 
PANDOC_FLAGS := -s -f markdown \
  -V author="丁保华（致慧星空工作室）" \
  -V numbersections \
  -V secnumdepth:3 \
  --pdf-engine=xelatex --pdf-engine-opt=-shell-escape \
  --template=../../styles/upandoc.tex

.PHONY:all clean c

#all:$(MAIN).pdf
all:$(PDF) $(DOCX)

%.pdf:%.md
	$(PANDOC) $(PANDOC_FLAGS) -t pdf $< -o $@

%.docx:%.md
	$(PANDOC) -t docx $< -o $@

clean: 
	@rm -f $(PDF) $(DOCX)

c:clean

