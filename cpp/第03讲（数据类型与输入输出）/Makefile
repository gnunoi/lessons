SHELL=bash
PANDOC=pandoc
MD=$(wildcard *.md)
PDF=$(MD:.md=.pdf)
MAIN=C++程序设计第二讲
PANDOC=pandoc -s -f markdown -t pdf --pdf-engine=xelatex \
  --highlight-style tango \
  --number-sections \
  -V minted=true \
  -V documentclass=ctexart \
  -V geometry="top=2cm, bottom=2cm, left=2cm, right=2cm" \
  -V mainfont="Times New Roman" \
  -V sansfont=Arial \
  -V monofont="Courier New" \
  -V CJKmainfont="Songti SC" \
  -V CJKsansfont="PingFang SC" \
  -V CJKmonofont=FangSong \
  --template=template.tex

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

