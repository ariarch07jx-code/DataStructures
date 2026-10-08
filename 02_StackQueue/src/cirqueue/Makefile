CC     = gcc
CFLAGS = -Wall -Wextra -fsanitize=address,undefined -g -std=c11
BUILD  = build

# 链接两个 .o 生成可执行文件
$(BUILD)/cirqueue: $(BUILD)/cirqueue.o $(BUILD)/test_cirqueue.o
	$(CC) $(CFLAGS) $(BUILD)/cirqueue.o $(BUILD)/test_cirqueue.o -o $(BUILD)/cirqueue

# 编译 .c → .o（依赖 .h，改头文件也会重编）
$(BUILD)/cirqueue.o: cirqueue.c cirqueue.h
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c cirqueue.c -o $(BUILD)/cirqueue.o

$(BUILD)/test_cirqueue.o: test_cirqueue.c cirqueue.h
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c test_cirqueue.c -o $(BUILD)/test_cirqueue.o

clean:
	rm -rf $(BUILD)

.PHONY: clean
