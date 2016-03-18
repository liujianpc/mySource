# Vim的操作
## Vim的三种模式
**1.命令模式：**
***
* 1、**：**进入
* 2、**？**进入
* 3、**\**进入
* 4、** esc **退出

***
**2.正常模式：**
这是一个普通段落。

1.  Bird
1.  McHal

*   Lorem ipsum dolor sit amet, consectetuer adipiscing elit.
*		llllllllll
*		

\*literal asterisks\*

*    Aliquam hendrerit mi posuere lectus. Vestibulum enim wisi,
    viverra nec, fringilla in, laoreet vitae, risus.
*   Donec sit amet nisl. Aliquam semper ipsum sit amet velit.
    Suspendisse id sem consectetuer libero luctus adipiscing.
<table>
    <tr>
        <td>Foo</td>
        <td>doo</td>
    </tr>
</table>

> This text you see here is *actually* written in Markdown! To get a feel for Markdown's syntax, type some text into the left window and watch the results in the right.
        1.esc返回
    
        2.：切换进入命令模式
> hello.c javascript

``There is a literal backtick (`) here.``
    #include <stdio.h>
    #include <string.h>
    #define MAX_LEN		101
    
    typedef struct _bign{
        char buf[MAX_LEN];
    }bign;
    
    bign one = { { 1, { 0 } } };
    
    void add(bign* a1, bign* a2, bign* a3);
    void sub(bign* a1, bign* a2, bign* a3);
    void print_bign(bign* a);
    void minus(bign* a, bign* o);
    void create_bign(char* s, bign* n);
    
    int main()
    {
        bign a;
        bign b;
        bign c;
        char s1[MAX_LEN + 2], s2[MAX_LEN + 2];
        printf("请输入两个数字\n");
        scanf("%s%s", s1, s2);
        create_bign(s1, &a);
        create_bign(s2, &b);
        add(&a, &b, &c);
        printf("相加后结果为:\n");
        print_bign(&c);
        return 0;
    }
    
    void add(bign* a1, bign* a2, bign* a3)
    {
        int n = 0, k = 0;
        int i;
        for (i = 0; i < MAX_LEN; i++){
            int x = a1->buf[i] + a2->buf[i] + k;
            a3->buf[i] = x % 10;
            k = x / 10;
        }
    }
    
    void minus(bign* a, bign* o)
    {
        int i = MAX_LEN - 1;
        while (i >= 0){
            o->buf[i] = 9 - a->buf[i];
            i--;
        }
        add(o, &one, o);
    }
    
    void print_bign(bign* a)
    {
        if (a->buf[MAX_LEN - 1] == 9){
            int i = MAX_LEN - 1;
            while (a->buf[i] == 9){
                i--;
            }
            printf("-");
            while (i > 0){
                printf("%d", 9 - a->buf[i]);
                i--;
            }
            printf("%d", 9 - a->buf[0] + 1);
        }
        else{
            int i = MAX_LEN - 1;
            while (a->buf[i] == 0){
                i--;
            }
            if (i < 0){
                printf("0");
            }
            while (i >= 0){
                printf("%d", a->buf[i]);
                if (i % 4 == 0 && i != 0){
                    printf(",");
                }
                i--;
            }
        }
    }
    
    void create_bign(char* s, bign* n)
    {
        int flag = 0;
        int i, j = 0, k = 0;
        if (*s == '-'){
            s++;
            flag = 1;
        }
        int l = strlen(s);
        i = MAX_LEN - 1;
        while (i >= l){
            n->buf[i--] = 0;
        }
        while (i >= 0){
            if (s[i] == ','){
                i--;
                k++;
                continue;
            }
            n->buf[j] = s[i] - '0';
            i--;
            j++;
        }
        for (; k > 0; k--){
            n->buf[j + k - 1] = 0;
        }
        if (flag){
            minus(n, n);
        }
    } 
    
    
    
    
    
    
    
