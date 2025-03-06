## Pandoc设置作者与页码

在Pandoc中设置PDF的页眉或页脚显示作者信息，需通过修改LaTeX模板或添加自定义页眉页脚配置实现。以下是分步说明：

---

### **方法一：通过YAML元数据 + `header-includes`（无需自定义模板）**

1. **设置YAML元数据**：在Markdown文件头部添加作者信息。
2. **使用`fancyhdr`包**：通过`header-includes`插入LaTeX代码，配置页眉/页脚。

```markdown
---
title: 文档标题
author: 作者姓名
header-includes:
  - \usepackage{fancyhdr}
  - \pagestyle{fancy}
  - \fancyhead[L]{\author}  # 页眉左侧显示作者
  - \fancyfoot[C]{\thepage} # 页脚中间显示页码
---
```

---

### **方法二：使用自定义LaTeX模板（推荐复用配置）**
1. **创建模板文件**（如`template.tex`），添加以下内容：
```latex
\usepackage{fancyhdr}
\pagestyle{fancy}
\fancyhead[CO,CE]{$author$}  % 奇偶页居中显示作者
\fancyfoot[LE,RO]{\thepage}  % 页脚显示页码
$if(title)$
\fancyhead[RE,LO]{$title$}   % 奇偶页另一侧显示标题
$endif$
```
2. **生成PDF时指定模板**：
```bash
pandoc input.md -o output.pdf --template=template.tex --pdf-engine=xelatex
```

---

### **关键说明**
- **位置调整**：`fancyhdr`中`\fancyhead`和`\fancyfoot`参数：
  - `L`（左）、`C`（中）、`R`（右）
  - `O`（奇数页）、`E`（偶数页），例如 `CO` 表示奇数页中间。
- **特殊字符转义**：若作者名含LaTeX特殊符号（如`_`, `&`），需用`\`转义，或启用`--pdf-engine=xelatex`自动处理。
- **多作者处理**：若作者有多个，Pandoc默认用`\and`分隔，需在模板中适当处理（如用`\author`直接显示）。

---

### **完整示例**
```markdown
---
title: 人工智能研究报告
author: 李四\and 王五（联合研究组）
header-includes:
  - \usepackage{fancyhdr}
  - \pagestyle{fancy}
  - \fancyhead[R]{\author}     # 页眉右侧显示作者
  - \fancyfoot[C]{\thepage}    # 页脚中间显示页码
---

# 正文内容
这里是文档内容...
```

生成命令：
```bash
pandoc input.md -o output.pdf --pdf-engine=xelatex
```

---

通过上述方法，作者信息将正确显示在PDF的页眉或页脚。如需更复杂布局，可进一步调整`fancyhdr`参数或自定义模板。