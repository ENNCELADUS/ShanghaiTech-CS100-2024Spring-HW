# Snake

贪吃蛇是一个简单有趣的小游戏。如果你没玩过，可以用 Google 搜索贪吃蛇，跳出来的那个在线小游戏就是。

*[Surprise](https://pippinbarr.com/SNAKISMS/)*

这次作业中，你将要用 C 语言实现一个**命令行** (command-line) 的 Snake 游戏。作为参考，你可以在 `demo` 文件夹下找到我们实现好的版本。

Snake 的规则非常简单
：局面上有一个蛇 (Snake) 和若干食物 (Food) 。玩家需要移动蛇（用 w/a/s/d 键控制），让蛇吃到食物。每吃到一个食物，蛇的长度会增加一节。游戏的目标是尽可能长时间地存活并吃到更多的食物。

具体规则如下：

- 每吃到一个食物，分数增加 1
- 如果蛇撞到墙壁或自己的身体，游戏结束。
- 当得到10分时游戏胜利

注意，你可以自行决定蛇的移动速度、食物的个数，地图的大小等，但需要有一个明确的、合理的策略。
通过改变 `snake.h`里面的

```c
#define MAX_FOODS 3
#define SEC_PER_SNAKE_MOVE 0.5
#define NUM_ROWS 15
#define NUM_COLS 15
#define INIT_SNAKE_LEN 3
```

即可

## 运行参考程序

我们提供 Linux, Mac OS, Windows 三种平台上的参考程序可执行文件，它们都位于 `demo` 文件夹下。为了方便描述，假设这个可执行文件的名称是 `snake`

Windows用 `./snake.exe`，MacOS用 `./snake_macos`，Linux用 `./snake_linux`

> 实际上 Windows 的 PowerShell 是完全可以支持正斜线 / 的，可以忘记反斜线这回事了

对于 Mac OS ，你需要先 `chmod +x snake_macos` 为 `snake` 赋予执行权限。

## 代码文件

代码分为三个文件，分别是 `utils.h` ,`snake.h`和 `snake.c` ，其中前两者被 `snake.c` `#include` 。

`utils.h` 包含各种和系统有关的函数，例如隐藏光标、移动光标、清屏、控制输出颜色、获取键盘动作。你不需要改动这里的内容，但如果实在想改也是可以的，比如你可能想用一些别的颜色？

`snake.c` 是主文件，包含了整个游戏的实现。稍后我们会仔细介绍其中的内容和你要完成的部分。

## 交互

我们采用**实时交互**的方式。每隔一定的时间，程序就会检测一下是否有键盘的动作，并作出相应的反应（相关函数为 `runGame` 和 `getSnakeMovement` ）。检测键盘是否有键被按下的函数是 `kbhit()` ，读取被按下的键的函数是 `getch()` 。

在 `printInitialGame` 之后，屏幕上的内容将会不断地被**更新**。 `move_cursor(row, col)` 函数可以将光标移动到第 `row` 行、第 `col` 列，这里的行号和列号从 `0` 开始。

由于常用的字符在命令行的宽高比是1:2,在玩贪吃蛇的时候会有横纵方向切换时手感不好的影响，于是我们引入宽字符 `wchar`，这种字符在显示的时候宽高比为1:1，但是只占据正常命令行的一格，于是我们在这题里们打印字符的命令是 `wprint(L"■ ");`表示打印宽字符(注意■后面有一个空格)，以便一个宽字符占位两格，此处的 `L`是字面值 `wchar*`的前缀

于是我们在用 `move_cursor`时候要注意因为每一个宽字符都是占位两格，需要用 `move_cursor(row, 2*col)`来保证显示的位置在你预料之中

注意，这种交互方式对效率是有要求的。移动一个物品应该只涉及到一两个字符的更新，更新一个字符只需将光标移动到相应的位置并输出新的字符。**每一帧都清屏并重新输出全部内容的做法是不可接受的**。

## 总体要求

本题采用和 TA 面对面 check 的方式来评分， OJ 上不设测试，**但是你需要提交你的代码**（见[提交方式](#提交方式)）。你和 TA 当面 check 的代码应当是你在 OJ 上的最后一次提交。

在游戏的实现上，我们允许你有较多的自由。你可以自行决定很多东西，例如你可以自行决定蛇的移动速度、食物的个数，地图的大小等，但你需要有一个明确的、合理的决定，并正确地实现出来。

你甚至也**可以改动函数参数，改动函数名**，我们不严格要求你一定按照我们的框架，但是需要合理正确的实现出来。

代码本身的质量也是评分项，而非仅仅是“能跑就行”，因为追求高质量的代码也是编程学习中十分重要的一环。你的代码需要是格式化的，并且经过了良好的组织，不随意使用全局变量，变量在即将被使用的时候才被声明，遵守一致的命名规范，避免大段的雷同，避免内存泄漏，在 GCC 的 `-Wall -Wpedantic -Wextra` 编译选项之下没有 warning 等。特别地，对于 `struct` 对象的初始化和赋值应尽可能多用 initializer-list （包括 designators）、 compound literals 等语法，它们比罗列一条一条的赋值语句更简洁、更清晰。

阅读代码的能力也在本题的考查范围之内。你需要读懂 `snake.c` 中的每一个部分，包括我们已经实现好的功能，这当然也是有助于你正确地实现你的部分的。我们会在 check 时问及其中的一些细节。

另外，我们在代码中以注释的形式给出了很多的提示，在你实现了相关函数之后这些注释应该被删除或作相应的调整。特别地， `FIXME:` 和 `TODO:` 是代码项目中常见的标注，现代编辑器一般都可以将其高亮显示（例如 VSCode 的 `TODO Highlight` 插件），它们通常表示某个功能的实现有问题、需要更正或者完善。在相应的问题被解决之后，你应该将 `FIXME:` 或 `TODO:` 改为 `DONE:` ，或直接将那条注释删去。

## 提交方式

将 `utils.h` ,`snake.h`和 `snake.c` 打包为一个 zip 文件提交到 OJ 。如果你还增加了其它文件，也需一并打包提交。

## 具体要求

注意，以下是你需要完成的部分，但并不意味着你只需要阅读这几个部分的代码。你要做的是“让游戏跑起来”，而不是“完成一个函数”。诸如“某个函数需不需要做某件事”这样的问题，你应该根据题目描述和代码前后的逻辑自行得出答案，**我们不会再回答**。

### 1. 实现 `createSnake`

在我们提供的框架中，snake是通过链表实现的，链表节点对应的结构体为 `SnakeNode`。如果你对链表这一数据结构不够熟悉，请阅读附件中的[linkedList.md](./linkedList.md)。

函数 `SnakeNode *createSnake(Game *pGame)` 创建一个长度为 `INIT_SNAKE_LEN` 的 snake，并返回 snake 的头节点。

- snakehead应该在整个游戏的中央（可自定义）
- 初始方向是向上（也可自定义）
- 确保 snake 的每个节点都正确连接

### 2. 实现 `getSnakeMovement`

函数 `void getSnakeMovement(Game *pGame)` 会进行一次按键检测，`kbhit()`会检查有没有键盘输入，即stdin里面是否有字符，而 `getch()`会读取stdin里面的第一个字符，即按顺序读取键盘输入的字符

- 你需要实现不同方向键按下时，改变下一步蛇头的移动方向
- 你**可以不考虑**按下相反方向键后，检测到穿身导致游戏结束的问题
  - 例如蛇当前向上移动，按下s后蛇头撞击自己身体导致游戏结束
  - 线下check将不会检查这种case

### 3. 实现 `createNewSnakeHead`

函数 `SnakeNode *createNewSnakeHead(const Game *pGame)` 将 snake 按照当前方向移动一步，并返回新的蛇头节点。

这个函数的目的：在蛇移动下一步**之前**生成一个不可见的**虚拟蛇头**，然后就可以用 `snakeHitWall``snakeHitSelf``snakeEatFood`等函数去检测下一步会不会撞墙，穿身，和吃到食物

- 根据当前方向（例如向上、向下、向左、向右）计算新的蛇头位置。
- 创建一个新的 `SnakeNode` 作为新的蛇头，**可自行选择**是否将其连接到原来的蛇头。

提示：你可以使用 `malloc` 函数为新的蛇头节点分配内存，并确保在游戏结束时正确释放这些内存。

### 4. 实现 `snakeHitWall`

函数 `bool snakeHitWall(Game *pGame, SnakeNode *pNewHead)` 检查蛇是否撞墙。

- 如果新的蛇头位置超出了地图的边界，返回 `true` 。
- 否则，返回 `false` 。

### 5. 实现 `snakeHitSelf`

函数 `bool snakeHitSelf(Game *pGame, SnakeNode *pNewHead)` 检查蛇是否撞到自己。

- 遍历蛇的每一个节点，检查新的蛇头位置是否与蛇的某个节点重合。
- 如果新的蛇头位置与蛇的某个节点重合，返回 `true` 。
- 否则，返回 `false` 。

### 6. 实现 `snakeDie`

函数 `bool snakeDie(const Game *pGame, SnakeNode *pNewHead)`检查蛇是否撞到墙或撞到自己。当至少发生其中之一时，使游戏判负。

### 7. 实现 `snakeEatFood`

函数 `bool snakeEatFood(Game *pGame, SnakeNode *pNewHead)` 检查蛇是否吃到食物。

- 如果新的蛇头位置与食物的位置重合，返回 `true` 。
  - 用 `move_cursor`和 `wprintf(HEAD);`将新蛇头显示出来打印，并保留蛇的尾部；
  - 生成新的食物，并将新的蛇头显示出来。
  - 增加分数。
- 否则，返回 `false` 。

### 8. 实现 `isFoodOnSnake`

函数 `bool isFoodOnSnake(const SnakeNode *pSnakeHead, const Food food)` 检查食物是否在蛇的身体上。这个函数应当在生成新的食物时被调用，以确保食物不会出现在蛇的身体上。

- 遍历蛇的每一个节点，检查食物的位置是否与蛇的某个节点重合。
- 如果食物在蛇的身体上，返回 `true` 。
- 否则，返回 `false` 。

### 9. 实现 `snakeMoveNormal`

函数 `void snakeMoveNormal(Game *pGame, SnakeNode *pNewHead)` 将 snake 移动一步。

- 如果蛇没有撞墙、撞到自己或吃到食物，则会调用该函数：将新的蛇头节点添加到链表的头部，并移除尾部节点以保持蛇的长度不变。
- 用 `move_cursor`和 `wprintf(HEAD);`将新蛇头显示出来打印，移除蛇的尾部以保持蛇的长度不变，并用 `move_cursor`和 `wprintf(AIR);`隐藏已经被移除的蛇尾。
- 记得释放被移除尾部节点的内存，并把倒数第二个节点指向的指针置为NULL
- 禁止move时打印整条蛇

提示：你可以使用 `free` 函数释放被移除的尾部节点的内存

### 10. 实现 `destroySnake`

函数 `void destroySnake(SnakeNode *pHead)` 负责销毁 snake 的链表结构并释放所有相关的内存。你需要确保在游戏结束时正确地释放 snake 所占用的所有内存。

- 从链表的头节点开始，逐个释放每一个节点。
- 确保没有内存泄漏。

提示：你可以使用一个循环遍历链表，并在每次迭代中释放当前节点，然后移动到下一个节点。

### 11. 实现 `destroyGame`

函数 `void destroyGame(Game *pGame)` 结束游戏并释放所有资源。你需要确保在 `Game`这个对象被销毁前时正确地释放该结构体里面所有**动态分配**的内存
