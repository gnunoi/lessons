# Pandoc语法高亮

可以结合 **自定义LaTeX模板** 统一设置代码高亮、行号及其他样式，避免每次手动添加YAML元数据。以下是完整操作步骤：

---

### 步骤 1：创建自定义LaTeX模板
1. **生成默认模板**（作为修改基础）：
   ```bash
   pandoc -D latex > custom-template.tex
   ```
2. **修改模板**（以 `custom-template.tex` 为例）：
   - **添加全局代码样式设置**（如行号、高亮主题）  
   - **插入必要的LaTeX包**（如 `listings` 或 `minted`）

---

### 方法一：使用 `listings` 包的模板配置
在 `custom-template.tex` 的 **头部区域**（`\begin{document}` 之前）添加以下内容：
```latex
% 添加listings包及样式配置
\usepackage{listings}
\usepackage{xcolor} % 可选：支持颜色

% 全局代码块样式设置
\lstset{
    numbers=left,           % 行号在左侧
    numberstyle=\tiny\color{gray}, % 行号字体和颜色
    stepnumber=1,           % 每行显示行号
    numbersep=5pt,          % 行号与代码间距
    backgroundcolor=\color{white}, % 背景色
    showspaces=false,       % 不显示空格
    showstringspaces=false,
    basicstyle=\ttfamily\small, % 基础字体
    keywordstyle=\color{blue},  % 关键词颜色
    commentstyle=\color{green!60!black}, % 注释颜色
    stringstyle=\color{red},    % 字符串颜色
    frame=single,            % 边框样式
    breaklines=true,         % 自动换行
    breakatwhitespace=true,
    tabsize=4
}
```

---

### 方法二：使用 `minted` 包的模板配置
在 `custom-template.tex` 中添加以下内容：
```latex
% 添加minted包及样式配置
\usepackage{minted}
\usepackage{xcolor} % 可选：支持颜色

% 全局代码块样式设置
\setminted{
    linenos=true,          % 启用行号
    numbersep=5mm,         % 行号与代码间距
    bgcolor=white,         % 背景色
    fontsize=\small,       % 字体大小
    breaklines=true,       % 自动换行
    frame=lines,           % 边框样式
    framesep=2mm,
    rulecolor=\color{gray!30}
}

% 设置不同语言的高亮风格（可选）
\setmintedinline{python}{bgcolor=white}
```

---

### 步骤 2：使用模板生成PDF
1. **通过命令行调用模板**：
   ```bash
   # 方法一：使用listings模板
   pandoc input.md -o output.pdf --template=custom-template.tex --listings --pdf-engine=xelatex
   
   # 方法二：使用minted模板（需提前安装pygments和minted）
   pandoc input.md -o output.pdf --template=custom-template.tex --pdf-engine=xelatex --pdf-engine-opt=-shell-escape --highlight-style=pygments
   ```

---

### 高级技巧：模板变量控制
在模板中可通过 **变量** 动态控制样式，例如：
1. **在模板中添加条件判断**：
   ```latex
   \usepackage{iftex}
   \ifdefined\codedark
       \setminted{bgcolor=black!5} % 暗色背景
   \else
       \setminted{bgcolor=white}  % 默认白色背景
   \fi
   ```
2. **通过命令行传递变量**：
   ```bash
   pandoc input.md -o output.pdf --template=custom-template.tex -V codedark
   ```

---

### 模板示例文件
一个集成代码样式、标题页和页眉页脚的模板示例：[custom-template.tex](https://gist.github.com/example)（需根据实际需求修改）。

---

### 注意事项
1. **模板路径问题**：若模板不在当前目录，需用 `--template=/path/to/custom-template.tex` 指定完整路径。
2. **依赖包冲突**：确保模板中引用的LaTeX包（如 `xcolor`, `minted`）已安装。
3. **调试建议**：若生成PDF失败，尝试先编译纯LaTeX文件定位问题。

通过自定义模板，你可以实现 **代码样式、页面布局、字体等全局统一设置**，无需在每个Markdown文件中重复配置。



以下是 LaTeX `listings` 包的 **`lstset` 参数全集**及其简要说明，按功能分类整理：

---

### **基础参数**
| 参数                | 类型   | 说明                       | 示例值                                                      |
| ------------------- | ------ | -------------------------- | ----------------------------------------------------------- |
| `language`          | 字符串 | 设置默认代码语言           | `language=Python`                                           |
| `basicstyle`        | 命令   | 基础字体样式               | `basicstyle=\ttfamily\small`                                |
| `showspaces`        | 布尔   | 显示空格符号               | `showspaces=true`                                           |
| `showtabs`          | 布尔   | 显示制表符符号             | `showtabs=true`                                             |
| `showstringspaces`  | 布尔   | 显示字符串中的空格         | `showstringspaces=false`                                    |
| `tabsize`           | 整数   | 制表符等效空格数           | `tabsize=4`                                                 |
| `breaklines`        | 布尔   | 允许自动换行               | `breaklines=true`                                           |
| `breakatwhitespace` | 布尔   | 仅在空格处换行             | `breakatwhitespace=true`                                    |
| `postbreak`         | 符号   | 换行后插入的符号（如箭头） | `postbreak=\mbox{\textcolor{red}{$\hookrightarrow$}\space}` |

---

### **行号配置**
| 参数          | 类型        | 说明                      | 示例值                                                    |
| ------------- | ----------- | ------------------------- | --------------------------------------------------------- |
| `numbers`     | 字符串      | 行号位置                  | `numbers=left`（左）/`numbers=none`（无）                 |
| `numberstyle` | 命令        | 行号字体样式              | `numberstyle=\tiny\color{gray}`                           |
| `stepnumber`  | 整数        | 行号步长（每n行显示一次） | `stepnumber=1`（每行显示）                                |
| `numbersep`   | 长度        | 行号与代码间距            | `numbersep=10pt`                                          |
| `firstnumber` | 整数/`last` | 起始行号                  | `firstnumber=100` 或 `firstnumber=last`（接续上一代码块） |

---

### **颜色与高亮**
| 参数              | 类型 | 说明                        | 示例值                                        |
| ----------------- | ---- | --------------------------- | --------------------------------------------- |
| `backgroundcolor` | 颜色 | 代码块背景色                | `backgroundcolor=\color{yellow!20}`           |
| `keywordstyle`    | 命令 | 关键词颜色/样式             | `keywordstyle=\color{blue}\bfseries`          |
| `commentstyle`    | 命令 | 注释颜色/样式               | `commentstyle=\color{green!50!black}\itshape` |
| `stringstyle`     | 命令 | 字符串颜色/样式             | `stringstyle=\color{red}`                     |
| `identifierstyle` | 命令 | 标识符（变量名）样式        | `identifierstyle=\color{magenta}`             |
| `rulecolor`       | 颜色 | 边框颜色（配合`frame`使用） | `rulecolor=\color{black!30}`                  |

---

### **边框与布局**
| 参数               | 类型       | 说明                               | 示例值                                               |
| ------------------ | ---------- | ---------------------------------- | ---------------------------------------------------- |
| `frame`            | 字符串     | 边框样式                           | `frame=single`（单线框）/`frame=shadowbox`（阴影框） |
| `framesep`         | 长度       | 边框与代码间距                     | `framesep=5pt`                                       |
| `framerule`        | 长度       | 边框线宽度                         | `framerule=1pt`                                      |
| `framexleftmargin` | 长度       | 左侧边框额外留空                   | `framexleftmargin=10pt`                              |
| `fillcolor`        | 颜色       | 边框内填充色（需`frameround`启用） | `fillcolor=\color{blue!10}`                          |
| `frameshape`       | 自定义函数 | 自定义边框形状（高级）             | 需定义 `\newcommand{\myframe}{...}`                  |

---

### **代码块标题**
| 参数               | 类型   | 说明         | 示例值                                        |
| ------------------ | ------ | ------------ | --------------------------------------------- |
| `caption`          | 字符串 | 代码块标题   | `caption={My Code}`                           |
| `captionpos`       | 字符串 | 标题位置     | `captionpos=b`（底部）/`captionpos=t`（顶部） |
| `abovecaptionskip` | 长度   | 标题上方间距 | `abovecaptionskip=10pt`                       |
| `belowcaptionskip` | 长度   | 标题下方间距 | `belowcaptionskip=10pt`                       |

---

### **高级参数**
| 参数             | 类型     | 说明                         | 示例值                                                     |
| ---------------- | -------- | ---------------------------- | ---------------------------------------------------------- |
| `escapeinside`   | 字符串   | 允许在代码中插入 LaTeX 命令  | `escapeinside={\%*}{*)`（用 `%*...*)` 包裹 LaTeX 片段）    |
| `morekeywords`   | 列表     | 添加自定义关键词             | `morekeywords={let, each, yield}`                          |
| `deletekeywords` | 列表     | 删除默认关键词               | `deletekeywords={for}`                                     |
| `literate`       | 符号替换 | 自定义符号渲染（如数学符号） | `literate={→}{$\rightarrow$}1`（将 `→` 替换为 LaTeX 箭头） |
| `xleftmargin`    | 长度     | 代码块整体左缩进             | `xleftmargin=20pt`                                         |

---

### **完整示例**
```latex
\lstset{
    language=Python,
    numbers=left,
    numberstyle=\tiny\color{gray},
    stepnumber=1,
    numbersep=10pt,
    basicstyle=\ttfamily\small,
    keywordstyle=\color{blue}\bfseries,
    commentstyle=\color{green!50!black}\itshape,
    stringstyle=\color{red},
    backgroundcolor=\color{yellow!10},
    frame=single,
    framesep=5pt,
    framerule=1pt,
    rulecolor=\color{black!30},
    breaklines=true,
    postbreak=\mbox{\textcolor{red}{$\hookrightarrow$}\space},
    captionpos=b,
    escapeinside={\%*}{*)}
}
```

---

### **注意事项**
1. **依赖包**：部分参数（如颜色）需加载 `xcolor` 包：
   ```latex
   \usepackage{xcolor}
   ```
2. **冲突解决**：若与其他包（如 `minted`）冲突，需调整加载顺序或使用 `\PassOptionsToPackage`。
3. **调试建议**：逐步添加参数测试效果，避免一次性配置过多。

通过合理组合这些参数，可以实现高度定制化的代码块样式。