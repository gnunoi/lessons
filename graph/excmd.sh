#!/bin/bash

# 提供帮助信息
function show_help {
    echo "Usage: $0 <source_directory> <destination_directory>"
    echo "  <source_directory>    Directory to search for .tex files."
    echo "  <destination_directory> Directory to save processed .tex files."
}

# 检查参数数量
if [ "$#" -ne 2 ]; then
    show_help
    exit 1
fi

source_dir=$1
dest_dir=$2

# 检查源目录是否存在
if [ ! -d "$source_dir" ]; then
    echo "Error: Source directory '$source_dir' does not exist."
    exit 1
fi

# 检查目标目录是否存在
if [ ! -d "$dest_dir" ]; then
    echo "Error: Destination directory '$dest_dir' does not exist."
    exit 1
fi

# 遍历源目录下的所有.tex文件
find "$source_dir" -type f -name "*.tex" | while read file; do
    # 计算目标文件的路径
    filename=$(basename "$file")
    dest_file="$dest_dir/$filename"

    # 使用sed命令提取 \begin{tikzpicture} 和 \end{tikzpicture} 之间的内容
    # 删除行首空白字符和空白行
    sed -n '/\\begin{tikzpicture}/, /\\end{tikzpicture}/ {
        /\\begin{tikzpicture}/d
        /\\end{tikzpicture}/d
        s/^[[:space:]]*//
        /^$/d
        p
    }' "$file" > "$dest_file"

    echo "Processed file: $file -> $dest_file"
done

