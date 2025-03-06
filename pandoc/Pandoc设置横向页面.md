# Pandoc设置横向页面

使用Pandoc将Markdown转换为横向排列的PDF时，可以通过调整LaTeX的页面设置实现。以下是详细步骤：

---

## **方法1：通过命令行参数设置**

直接在Pandoc命令中指定页面方向为横向：
```bash
pandoc input.md -o output.pdf -V geometry:landscape
```
- **关键参数**：`-V geometry:landscape`  
  - `geometry` 是LaTeX的页面布局包，`landscape` 表示横向模式。
- **调整边距（可选）**：  
  如果横向后边距不合适，可追加参数（如 `-V geometry:margin=1in`）：
  ```bash
  pandoc input.md -o output.pdf -V geometry:landscape,margin=1in
  ```

---

## **方法2：在Markdown文件中添加YAML元数据**

在Markdown文件头部插入以下YAML配置：
```yaml
---
geometry: landscape
---
```
或同时调整边距：
```yaml
---
geometry: "landscape, margin=1in"
---
```

---

## **方法3：自定义LaTeX设置（高级）**

通过LaTeX代码直接控制布局：
1. 在Markdown文件中添加YAML头：
```yaml
---
header-includes: |
  \usepackage{lscape}
  \usepackage{pdflscape}
---
```
2. 在需要横向的页面内容前插入：
```latex
\begin{landscape}
```
3. 内容结束后插入：
```latex
\end{landscape}
```
- **适用场景**：仅部分页面需要横向时。

---

## **常见问题**

1. **依赖缺失**：  
   确保已安装完整LaTeX环境（如[TeX Live](https://www.tug.org/texlive/)），否则Pandoc无法生成PDF。
2. **边距异常**：  
   横向模式下默认边距较大，建议通过 `geometry:margin=参数` 调整。
3. **内容溢出**：  
   横向后若内容仍超出页面，尝试调整字体大小（如 `-V fontsize=12pt`）或换用 `geometry` 的其他参数。

---

## **完整示例**

```bash
# 命令行设置横向+A4纸+窄边距
pandoc input.md -o output.pdf \
  -V geometry:a4paper,landscape,margin=1cm
```

通过以上方法，可轻松实现Markdown转PDF时的横向布局。