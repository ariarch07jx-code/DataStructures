# 02 栈和队列 (Stack & Queue)

栈和队列都是**操作受限的线性表**——在普通线性表上限制了插入、删除的位置。

## 一、栈 vs 队列

| | 栈 Stack | 队列 Queue |
|---|---|---|
| 操作位置 | 只在栈顶一端 | 队尾插入、队头删除 |
| 规则 | 后进先出 **LIFO** | 先进先出 **FIFO** |
| 术语 | push / pop / getTop | 入队 / 出队 / getHead |
| 典型应用 | 括号匹配、递归、DFS | 排队、BFS、缓冲区 |

## 二、存储实现一览

| 结构 | 顺序 | 链式 | 循环 |
|---|---|---|---|
| 栈 | `SeqStack.c`（数组 + top） | `LinkedStack.c`（表头作栈顶） | — |
| 队列 | `SeqQueue.c`（数组 + front/rear，有假溢出） | `LinkedQueue.c`（头结点 + front/rear） | `CirQueue.c`（取模循环，牺牲 1 单元） |

## 三、复杂度速查

| 操作 | 栈（顺序 / 链式） | 队列（顺序 / 链式 / 循环） |
|---|---|---|
| 入栈 / 入队 | O(1) | O(1)* |
| 出栈 / 出队 | O(1) | O(1) |
| 取栈顶 / 队头 | O(1) | O(1) |
| 判空 | O(1) | O(1) |

\* 顺序队列入队平均 O(1)，但触发 `queueFull` 搬数据时是 O(n)。

## 四、本章目录

- [1.1 栈](1.1_Stack.md)
- [1.2 队列](1.2_Queue.md)

代码在 [`code/`](code/) 目录下（教学版）：`SeqStack.c`、`LinkedStack.c`（栈）；`SeqQueue.c`、`LinkedQueue.c`、`CirQueue.c`（队列）。

工程版（`.h/.c` 分离 + `const` + 测试 + Makefile）在 [`src/`](src/) 目录下，目前已完成循环队列 [`src/cirqueue/`](src/cirqueue/)，作为后续结构的样板。
