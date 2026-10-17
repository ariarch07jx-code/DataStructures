#include <stdio.h>
#include <string.h>

#define MAXLEN 255

// 串：ch[0] 存长度，字符从下标 1 开始放（严蔚敏约定）
typedef struct {
    char ch[MAXLEN + 1];
} SString;

// 用 C 字符串构造 SString
void assign(SString *s, const char *str) {
    int len = (int)strlen(str);
    s->ch[0] = (char)len;
    for (int i = 0; i < len; i++) {
        s->ch[i + 1] = str[i];
    }
}

// BF 朴素匹配：返回 p 在 s 中从 pos 开始第一次出现的位置（从 1 计数），找不到返回 0
int Index_BF(SString s, SString p, int pos) {
    int i = pos, j = 1;
    while (i <= s.ch[0] && j <= p.ch[0]) {
        if (s.ch[i] == p.ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;  // 主串回退到本次比较起点的下一位置
            j = 1;          // 模式串回到开头
        }
    }
    if (j > p.ch[0]) return i - p.ch[0];
    return 0;
}

// 求 next 数组（next[1] = 0）
void getNext(SString p, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < p.ch[0]) {
        if (j == 0 || p.ch[i] == p.ch[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];  // 关键：用更短的相同前后缀继续试
        }
    }
}

// KMP 匹配：主串指针 i 不回溯
int Index_KMP(SString s, SString p, int pos) {
    int i = pos, j = 1;
    int next[MAXLEN + 1];
    getNext(p, next);

    while (i <= s.ch[0] && j <= p.ch[0]) {
        if (j == 0 || s.ch[i] == p.ch[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j > p.ch[0]) return i - p.ch[0];
    return 0;
}

int main(void) {
    SString s, p;
    assign(&s, "ababcabcacbab");
    assign(&p, "abcac");

    printf("BF  匹配位置: %d\n", Index_BF(s, p, 1));
    printf("KMP 匹配位置: %d\n", Index_KMP(s, p, 1));

    // 打印 next 数组，和笔记里的表对照
    SString p2;
    assign(&p2, "ababa");
    int next[MAXLEN + 1];
    getNext(p2, next);
    printf("\nP = \"ababa\" 的 next 数组:\n");
    printf("j     :");
    for (int j = 1; j <= p2.ch[0]; j++) printf(" %d", j);
    printf("\nnext  :");
    for (int j = 1; j <= p2.ch[0]; j++) printf(" %d", next[j]);
    printf("\n");

    // 找不到的情况
    SString p3;
    assign(&p3, "xyz");
    printf("\n找不到时的返回: %d\n", Index_KMP(s, p3, 1));

    return 0;
}
