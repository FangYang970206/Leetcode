# 问题描述

编写一个 SQL 查询，获取 Employee 表中第 n 高的薪水（Salary）。

```bash
+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
```

例如上述 Employee 表，n = 2 时，应返回第二高的薪水 200。如果不存在第 n 高的薪水，那么查询应返回 null。

```bash
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+
```

# 方法

这一题与上一题类似，不过需要对输入的N进行判断，如果小于0，需要都是LIMIT和OFFSET都为0