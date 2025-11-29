/***************************************************************************
 * Dr. Evil's Insidious Bomb, Version 1.1
 * Copyright 2011, Dr. Evil Incorporated. All rights reserved.
 *
 * LICENSE:
 *
 * Dr. Evil Incorporated (the PERPETRATOR) hereby grants you (the
 * VICTIM) explicit permission to use this bomb (the BOMB).  This is a
 * time limited license, which expires on the death of the VICTIM.
 * The PERPETRATOR takes no responsibility for damage, frustration,
 * insanity, bug-eyes, carpal-tunnel syndrome, loss of sleep, or other
 * harm to the VICTIM.  Unless the PERPETRATOR wants to take credit,
 * that is.  The VICTIM may not distribute this bomb source code to
 * any enemies of the PERPETRATOR.  No VICTIM may debug,
 * reverse-engineer, run "strings" on, decompile, decrypt, or use any
 * other technique to gain knowledge of and defuse the BOMB.  BOMB
 * proof clothing may not be worn when handling this program.  The
 * PERPETRATOR will not apologize for the PERPETRATOR's poor sense of
 * humor.  This license is null and void where the BOMB is prohibited
 * by law.
 ***************************************************************************/
/***************************************************************************
 * 邪恶博士的阴险炸弹，版本 1.1
 * 版权所有 2011，邪恶博士公司。保留所有权利。
 *
 * 许可证：
 *
 * 邪恶博士公司（行凶者）特此授予你（受害者）明确的许可来使用此炸弹（炸弹）。
 * 这是一个有时限的许可证，在受害者死亡时过期。
 * 行凶者不对受害者的损害、挫折、精神错乱、突眼、腕管综合症、失眠或其他伤害承担任何责任。
 * 除非行凶者想要邀功，那就是另一回事了。
 * 受害者不得将此炸弹源代码分发给行凶者的任何敌人。
 * 任何受害者不得调试、反向工程、运行“strings”、反编译、解密或使用任何其他技术
 * 来获取有关炸弹的知识并拆除炸弹。
 * 处理此程序时不得穿防爆服。
 * 行凶者不会为行凶者糟糕的幽默感道歉。
 * 在法律禁止炸弹的地方，此许可证无效。
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "phases.h"

/*
 * Note to self: Remember to erase this file so my victims will have no
 * idea what is going on, and so they will all blow up in a
 * spectaculary fiendish explosion. -- Dr. Evil
 */
/*
 * 给自己的笔记：记得删掉这个文件，这样我的受害者就不知道发生了什么，
 * 然后他们就会在壮观的恶魔爆炸中全部炸飞。 -- 邪恶博士
 */

FILE *infile;

int main(int argc, char *argv[])
{
    char *input;

    /* Note to self: remember to port this bomb to Windows and put a
     * fantastic GUI on it. */
    /* 给自己的笔记：记得把这个炸弹移植到 Windows 上，并给它做一个很棒的 GUI。 */

    /* When run with no arguments, the bomb reads its input lines
     * from standard input. */
    /* 当不带参数运行时，炸弹从标准输入读取输入行。 */
    if (argc == 1)
    {
        infile = stdin;
    }

    /* When run with one argument <file>, the bomb reads from <file>
     * until EOF, and then switches to standard input. Thus, as you
     * defuse each phase, you can add its defusing string to <file> and
     * avoid having to retype it. */
    /* 当带有一个参数 <file> 运行时，炸弹从 <file> 读取直到 EOF，
     * 然后切换到标准输入。因此，当你拆除每个阶段时，你可以将其拆除字符串添加到 <file> 中，
     * 避免重新输入。 */
    else if (argc == 2)
    {
        if (!(infile = fopen(argv[1], "r")))
        {
            printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
            exit(8);
        }
    }

    /* You can't call the bomb with more than 1 command line argument. */
    /* 你不能用超过 1 个命令行参数调用炸弹。 */
    else
    {
        printf("Usage: %s [<input_file>]\n", argv[0]);
        exit(8);
    }

    /* Do all sorts of secret stuff that makes the bomb harder to defuse. */
    /* 做各种秘密的事情，让炸弹更难拆除。 */
    initialize_bomb();

    printf("Welcome to my fiendish little bomb. You have 6 phases with\n");
    printf("which to blow yourself up. Have a nice day!\n");
    /* 欢迎来到我邪恶的小炸弹。你有 6 个阶段可以用来炸死自己。祝你愉快！ */

    /* Hmm...  Six phases must be more secure than one phase! */
    /* 嗯... 六个阶段肯定比一个阶段更安全！ */
    input = read_line();                                   /* Get input                   */
    phase_1(input);                                       /* Run the phase               */
    phase_defused();                                      /* Drat!  They figured it out!
                                                           * Let me know how they did it. */
                                                          /* 该死！他们居然解出来了！让我看看他们是怎么做到的。 */
    printf("Phase 1 defused. (Interesting key, huh?)\n"); /* 阶段 1 已拆除。（有趣的密钥，是吧？） */

    /* The second phase is harder.  No one will ever figure out
     * how to defuse this... */
    /* 第二阶段更难。没人能弄清楚如何拆除这个... */
    input = read_line();
    phase_2(input);
    phase_defused();
    printf("That's number 2.\n"); /* 这是第 2 个。 */

    /* I guess this is too easy so far.  Some more complex code will
     * confuse people. */
    /* 我猜到目前为止太容易了。一些更复杂的代码会让人困惑。 */
    input = read_line();
    phase_3(input);
    phase_defused();
    printf("Halfway there!\n"); /* 完成一半了！ */

    /* Oh yeah?  Well, how good is your math?  Try on this saucy problem! */
    /* 噢是吗？好吧，你的数学怎么样？试试这个棘手的问题！ */
    printf("Ancient monks moved sacred disks between poles...\n"); /* 古代僧侣在柱子之间移动神圣的圆盘... */
    input = read_line();
    phase_4(input);
    phase_defused();
    printf("So you got that one.  Try this one.\n"); /* 既然你搞定了那个。试试这个。 */

    /* Round and 'round in memory we go, where we stop, the bomb blows! */
    /* 在内存中转啊转，停在哪里，炸弹就炸在哪里！ */
    input = read_line();
    phase_5(input);
    phase_defused();
    printf("Good work!  On to the next...\n"); /* 干得好！继续下一个... */

    /* This phase will never be used, since no one will get past the
     * earlier ones.  But just in case, make this one extra hard. */
    /* 这个阶段永远不会被用到，因为没人能通过前面的阶段。但以防万一，把这个做得特别难。 */
    input = read_line();
    phase_6(input);
    phase_defused();

    /* Wow, they got it!  But isn't something... missing?  Perhaps
     * something they overlooked?  Mua ha ha ha ha! */
    /* 哇，他们做到了！但是不是少了点什么...？也许是他们忽略了什么？哇哈哈哈哈哈！ */

    return 0;
}
