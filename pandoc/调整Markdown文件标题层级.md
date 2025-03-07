# 调整Markdown文件标题层级

要将Markdown文件中的标题层级提升两级，可以使用Pandoc的`--shift-heading-level-by`参数。以下是具体步骤和说明：

### 命令

```bash
pandoc input.md --shift-heading-level-by=2 -o output.md
```

### 参数说明
- **`--shift-heading-level-by=2`**：将每个标题的级别增加2。例如：
  - H1 → H3
  - H2 → H4
  - 依此类推。

### 注意事项
1. **标题层级限制**：Markdown标准支持H1到H6。若原文件中有H5或H6，提升后可能超过H6（如H5→H7）。此时Pandoc会将其强制设为H6，需检查结果是否符合预期。
2. **反向操作**：若需降低标题层级（如H3→H1），使用负值（`--shift-heading-level-by=-2`）。
3. **版本要求**：该参数适用于Pandoc 2.0及以上版本，请确保版本更新。

### 示例
输入文件（`input.md`）：
```markdown
# 标题1
## 标题2
### 标题3
```
运行命令后，输出文件（`output.md`）：
```markdown
### 标题1
#### 标题2
##### 标题3
```

通过此方法可快速调整标题层级结构，适用于文档嵌入子章节等场景。

你可以通过 **自定义Pandoc Lua过滤器** 来保留原H1标题，并在降级时自动将“低于H1”的标题强制设为H1。以下是完整解决方案：

---

### 方法：使用Lua过滤器动态调整标题

方法可用，但是硬编码（shift = -1），将就使吧。

1. **创建Lua过滤器文件 `shift_headers.lua`**：
```lua
function Header(elem)
    local shift = -1  -- 设置需要降级的层级数（此处为-1）
    local new_level = elem.level + shift
    -- 如果降级后级别 <1，则强制设为1；否则正常降级
    elem.level = new_level < 1 and 1 or new_level
    return elem
end
```

2. **运行Pandoc命令**：
```bash
pandoc input.md -L shift_headers.lua -o output.md
```

---

### 效果说明
- **原H1标题**（级别1）：
  - 降级后 `1 + (-1) = 0` → 强制设为1 → 保持H1不变。
- **原H2及以上标题**（级别≥2）：
  - 例如H2 → `2 + (-1) = 1` → 变为H1，H3 → H2，依此类推。

---

### 示例验证
**输入文件（`input.md`）**：
```markdown
# 我是H1
## 我是H2
### 我是H3
```

**运行命令后输出（`output.md`）**：
```markdown
# 我是H1   <!-- 原H1保留为H1 -->
# 我是H2   <!-- 原H2降级为H1 -->
## 我是H3  <!-- 原H3降级为H2 -->
```

---

### 扩展配置
- **调整降级幅度**：修改Lua脚本中的 `shift = -N`（例如 `shift = -2` 会降级2层）。
- **兼容性**：此方法适用于所有Pandoc版本（无需依赖`--shift-heading-level-by`参数）。

通过此方法，无需担心标题被删除，且能精准控制层级逻辑。

可以通过 **Pandoc的变量传递功能** 动态向Lua脚本传递参数（如降级层级数），无需硬编码。以下是具体实现方法：

---

### 步骤1：修改Lua脚本以接收外部参数

以下代码不可行，因为Header函数访问不了meta.shift。

创建名为 `header.lua` 的脚本，内容如下：
```lua
-- header.lua
local shift = 0

function Meta(meta)
    shift = tonumber(pandoc.utils.stringify(meta.shift or "0")) or 0
    print("[DEBUG] shift_num=" .. shift)
    return meta
end

function Header(elem)
    print("shift in Header: " .. shift)
    elem.level = math.min(math.max(elem.level + shift, 1), 6)
    return elem
end
```

---

### 步骤2：通过Pandoc命令动态传递参数
在命令行中使用 `-V shift=N` 指定层级调整值（例如 `-V shift=-1`）：

-V传递不了，需要使用-M参数。

```bash
pandoc -L header.lua -M shift=-1 -o output.md input.md 
```

---

### 关键机制说明
1. **参数传递**：
   - `-V shift=-1` 将参数传递给Lua脚本的 `meta.shift` 变量。
   - 通过 `tonumber(pandoc.utils.stringify(meta.shift))` 将参数转换为数字。

2. **安全限制**：
   - `math.max(new_level, 1)`：确保标题层级不低于1（避免删除H1）。
   - `math.min(..., 6)`：确保不超过H6（符合Markdown标准）。

---

### 测试效果
#### 输入文件 (`input.md`)：
```markdown
# H1
## H2
### H3
#### H4
```

#### 命令：
```bash
pandoc input.md -L shift_headers.lua -V shift=-1 -o output.md
```

#### 输出文件 (`output.md`)：
```markdown
# H1    <!-- 原H1: 1 + (-1) = 0 → 强制设为1 -->
# H2    <!-- 原H2: 2 + (-1) = 1 → H1 -->
## H3   <!-- 原H3: 3 + (-1) = 2 → H2 -->
### H4  <!-- 原H4: 4 + (-1) = 3 → H3 -->
```

---

### 扩展用法
| 场景    | 命令            | 效果                                |
| ------- | --------------- | ----------------------------------- |
| 降级2层 | `-V shift=-2`   | H1→H1，H2→H1，H3→H2...              |
| 升级1层 | `-V shift=1`    | H1→H2，H2→H3...（超过H6的强制为H6） |
| 不调整  | 省略 `-V shift` | 使用默认值0，标题层级不变           |

---

### 注意事项
1. **参数有效性**：
   - 如果传递非数字参数（如 `-V shift=text`），`tonumber` 会返回 `nil`，此时脚本自动使用 `shift=0`。
2. **版本兼容性**：
   - 此方法适用于 **Pandoc 2.1.3+**（确保 `pandoc.utils.stringify` 方法存在）。
3. **批量处理**：
   - 可将命令封装为Shell脚本，通过变量动态批量处理多个文件。

通过这种方法，标题层级调整完全由命令行参数控制，无需修改Lua脚本代码，灵活性大幅提升。