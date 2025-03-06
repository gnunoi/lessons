## LaTeX的geometry包

LaTeX 的 `geometry` 包用于调整页面布局参数（如边距、纸张大小、方向等）。以下是其常用参数分类及说明：

---

### **1. 页面尺寸与方向**

- **`paper=<name>`**  
  设置纸张类型，例如：`a4`, `letter`, `legal`, `a5` 等。  
  示例：`paper=a4paper`

- **`landscape`**  
  将页面方向设置为横向（默认是纵向 `portrait`）。

---

### **2. 边距调整**
- **`left`, `right`, `top`, `bottom`**  
  设置左、右、上、下边距。  
  示例：`left=3cm, right=2cm, top=2.5cm, bottom=3cm`

- **`margin=<length>`**  
  统一设置所有边距（上下左右相同）。  
  示例：`margin=2cm`

- **`hcentering` 或 `centering`**  
  水平居中内容区域（自动平衡左右边距）。

---

### **3. 内容区域尺寸**
- **`textwidth`, `textheight`**  
  直接指定内容区域的宽度和高度。  
  示例：`textwidth=15cm, textheight=23cm`

- **`lines=<number>`**  
  根据行数自动计算内容高度（需配合 `\baselineskip`）。

---

### **4. 页眉与页脚**
- **`headheight`, `headsep`, `footskip`**  
  - `headheight`: 页眉高度  
  - `headsep`: 页眉与正文的间距  
  - `footskip`: 页脚基准线到页面底部的距离  
  示例：`headheight=15pt, headsep=0.4in`

- **`includehead`, `includefoot`**  
  将页眉/页脚包含在内容区域内（默认不包含）。

---

### **5. 装订与多页布局**
- **`bindingoffset=<length>`**  
  设置装订线额外边距（常用于书籍）。  
  示例：`bindingoffset=1cm`

- **`twoside`**  
  启用双页模式（奇偶页边距对称）。

- **`asymmetric`**  
  双页模式下允许不对称边距（需配合 `twoside`）。

---

### **6. 其他参数**
- **`showframe`**  
  显示页面框架（调试布局时使用）。

- **`heightrounded`**  
  自动调整内容高度为整数倍行高。

- **`ignoreall`**  
  忽略文档类的默认布局参数。

- **`scale=<factor>`**  
  按比例缩放页面（如 `scale=0.8` 缩小到 80%）。

---

### **综合示例**
```latex
\usepackage[%
    a4paper,
    left=3cm,
    right=2cm,
    top=2.5cm,
    bottom=3cm,
    headheight=15pt,
    headsep=0.4in,
    footskip=30pt,
    twoside,
    bindingoffset=5mm,
    includehead,
    includefoot,
    heightrounded,
]{geometry}
```

---

### **注意事项**
1. `geometry` 通常在文档类之后加载（如 `\documentclass{article}` 后）。
2. 多个参数用逗号分隔，避免重复定义。
3. 若需覆盖默认值，需确保参数组合合理（例如双页模式需考虑装订边距）。

通过灵活组合这些参数，可以精确控制页面布局以适应不同排版需求。