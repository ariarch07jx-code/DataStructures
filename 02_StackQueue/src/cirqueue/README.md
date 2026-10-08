# 循环队列（工程版样板）

教学版 `code/CirQueue.c` 的工程化重写，作为后续所有结构的「样板」。

## 相比教学版改了什么

- 拆成 `.h`（接口）+ `.c`（实现）+ 测试文件，接口与实现分离
- 只读参数加 `const`（`const CirQueue *q`），编译器帮你防止手滑
- 函数全部带 `cirqueue_` 前缀，避免和其他模块的 `enqueue`/`dequeue` 冲突
- 错误不再 `printf`，只靠 `bool` 返回值表达，打印交给调用方
- 补了教学版没有的 `cirqueue_is_full` 和 `cirqueue_size`

## 复杂度

| 操作 | 复杂度 |
|---|---|
| 入队 / 出队 | O(1) |
| 读队头 | O(1) |
| 判空 / 判满 | O(1) |
| 求长度 | O(1) |

## 为什么最多只能存 MAX-1 个元素

空和满都满足 `front == rear`，为了区分，约定「队尾再进一格就撞上队头」为满，
于是永远空着一格，所以容量是 `CIRQUEUE_MAX - 1`。

## 一道经典面试题

用循环队列实现「滑动窗口最大值」或「生产者-消费者」缓冲区。

## 编译运行

```bash
make                # 编译
./build/cirqueue    # 跑测试，应输出 "All tests passed."
make clean          # 清理
```
