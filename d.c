#include <stdio.h>
void func(const char *src)
{
    unsigned char all[256] = {0};    /* 字符 */
    int i;
    
    if (src == NULL)
        return;
    
    while (*src)
    {
        //++all[*src];
        //++src;
        all[*src]++;
        src++;
    }

    for (i = 0; i < 256; i++)
    {
        if (all[i] != 0)            /* 记录保存了的字符 */
        {
            printf("字符%c出现次数： %d\n", i, all[i]);
        }
    }

}
int main(void)
{
    char ss[100]="aaaabbbbbxxxxxxyxxxa123123##@$$return^^^!@@!uq";

    func(ss);

    return 0;
}