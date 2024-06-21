### 问题 1. 表达式

#### 背景

在这个问题中，我们处理代表算术表达式的树。首先，我们只考虑由数字（常量）、一元运算符+和-以及二元运算符+、-、*和/组成的表达式。这些表达式可以用一种树结构来表示，这种树结构称为表达式树或抽象语法树（AST）。例如，表达式 (2 + 5) * 3 / (-6) 的树表示如下：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>scss</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-scss">    (/)
   /   \
  (*)   -6
 /  \
2    5
</code></div></div></pre>

这种树很有用，因为它包含了所有子表达式的结构。我们可以递归地对树进行一些操作，比如打印、求值、转换成某种特殊形式等。现在你的任务是构建一个类层次结构来表示这些不同类型的节点。将表达式解析成AST的过程超出了本课程的范围。

#### 基本结构

我们从以下基本结构开始：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">class ExprNode {
public:
    // FIXME: 下面的一些函数应该是虚函数或纯虚函数。
    ExprNode() = default;
    double evaluate() const;
    std::string toString() const;
    virtual ~ExprNode() = default;
};

class Constant : public ExprNode {
    double mValue;
public:
    explicit Constant(double value) : mValue{value} {}
    // TODO: evaluate() 和 toString() ...
};

enum class UnaryOpKind {
    UOK_Plus, UOK_Minus
};

class UnaryOperator : public ExprNode {
    UnaryOpKind mOpKind;
    std::shared_ptr<ExprNode> mOperand;
public:
    UnaryOperator(UnaryOpKind op, std::shared_ptr<ExprNode> operand)
        : mOpKind{op}, mOperand{std::move(operand)} {}
    // TODO: evaluate() 和 toString() ...
};

enum class BinaryOpKind {
    BOK_Plus, BOK_Minus, BOK_Mul, BOK_Div
};

class BinaryOperator : public ExprNode {
    BinaryOpKind mOpKind;
    std::shared_ptr<ExprNode> mLeft;
    std::shared_ptr<ExprNode> mRight;
public:
    BinaryOperator(BinaryOpKind op, std::shared_ptr<ExprNode> left, std::shared_ptr<ExprNode> right)
        : mOpKind{op}, mLeft{std::move(left)}, mRight{std::move(right)} {}
    // TODO: evaluate() 和 toString() ...
};
</code></div></div></pre>

用户创建节点的代码可能如下：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">BinaryOperator bo1(BinaryOpKind::BOK_Plus, std::make_shared<Constant>(3), std::make_shared<Constant>(4));
auto bo2 = std::make_shared<BinaryOperator>(BinaryOpKind::BOK_Plus, std::make_shared<Constant>(3), std::make_shared<Constant>(4));
</code></div></div></pre>

这涉及到手动创建 `shared_ptr`。这种方式既丑陋又不方便。

#### 一个间接层次

这里有一个所谓的“软件工程基本定理”：

> 我们可以通过引入一个额外的间接层次来解决任何问题。

我们的问题是用户仍然必须进行内存管理（即使使用了智能指针）。理想情况下，内存管理应该是我们的实现细节的一部分。用户只需关心树的结构。例如，我们希望用户能够以以下方式创建一个节点：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">Expr bo('+', Expr(3), Expr(4));
auto bo = Expr(3) + Expr(4);
</code></div></div></pre>

显然，只要支持前一种方式，就可以通过简单的重载运算符来支持后一种方式。

考虑定义 `Expr` 类，它作为用户和特定节点类之间的间接层次。`Expr` 类应该封装一个 `std::shared_ptr<ExprNode>` 并隐藏与内存管理相关的所有内容。此外，`Expr` 还应该提供类似 `evaluate()` 和 `toString()` 的接口。

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">class Expr {
    std::shared_ptr<ExprNode> mNode;
    Expr(std::shared_ptr<ExprNode> ptr) : mNode{std::move(ptr)} {}
public:
    // 使得可以使用 `Expr(3)`。
    Expr(double value) : mNode{std::make_shared<Constant>(value)} {}
    auto toString() const { return mNode->toString(); }
    auto evaluate() const { return mNode->evaluate(); }
    // 可能需要一些友元声明...
};

class UnaryOperator : public ExprNode {
    UnaryOpKind mOpKind;
    Expr mOperand;
public:
    UnaryOperator(UnaryOpKind op, Expr operand)
        : mOpKind{op}, mOperand{std::move(operand)} {}
    // TODO: evaluate() 和 toString() ...
};

Expr operator-(const Expr &arg) {
    return {std::make_shared<UnaryOperator>(UnaryOpKind::UOK_Minus, arg)};
}

Expr operator+(const Expr &arg) {
    return {std::make_shared<UnaryOperator>(UnaryOpKind::UOK_Plus, arg)};
}

auto neg3 = -Expr(3);
</code></div></div></pre>

#### 更多功能

在了解了我们的类层次结构的基本知识后，你将添加对更多功能的支持：

* 新类型的节点 `Variable`，表示变量 `x`。支持后，我们的AST可以用来表示一元函数，而不仅仅是包含常量的算术表达式。
* 在某一点上对函数进行求值。
* 在某一点上对函数的导数进行求值。

这些操作在基类中声明如下：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">class ExprNode {
public:
    // FIXME: 如有必要，使这些函数虚拟或纯虚拟。
    ExprNode() = default;
    double evaluate(double x) const;   // 对 f(x) 求值
    double derivative(double x) const; // 对 df(x)/dx 求值
    std::string toString() const;      // 返回函数的括号表示
    virtual ~ExprNode() = default;
};
</code></div></div></pre>

之前的部分中，我们只使用了一个类 `BinaryOperator` 来表示四种不同的二元运算符。这种设计在现在可能不太方便，因为不同运算符的求值和求导方式差异更大。因此，我们将它们分成四个类：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">class BinaryOperator : public ExprNode {
protected:
    Expr mLeft;
    Expr mRight;
public:
    BinaryOperator(Expr left, Expr right)
        : mLeft{std::move(left)}, mRight{std::move(right)} {}
};

class PlusOperator : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    // TODO: evaluate()、derivative() 和 toString() ...
};

class MinusOperator : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    // TODO: evaluate()、derivative() 和 toString() ...
};

class MultiplyOperator : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    // TODO: evaluate()、derivative() 和 toString() ...
};

class DivideOperator : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    // TODO: evaluate()、derivative() 和 toString() ...
};

class Variable : public ExprNode {
public:
    // TODO: evaluate()、derivative() 和 toString() ...
};
</code></div></div></pre>

定义一个静态的 `Expr` 数据成员：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">class Expr {
    std::shared_ptr<ExprNode> mNode;
    Expr(std::shared_ptr<ExprNode> ptr) : mNode{std::move(ptr)} {}
public:
    Expr(double value);
    static const Expr x;
    // 其他成员...
};

const Expr Expr::x{std::make_shared<Variable>()};
Expr::Expr(double value) : mNode{std::make_shared<Constant>(value)} {}
</code></div></div></pre>

最终结构如下：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">class ExprNode {
public:
    virtual double evaluate(double x) const = 0;
    virtual double derivative(double x) const = 0;
    virtual std::string toString() const = 0;
    virtual ~ExprNode() = default;
};

class Constant : public ExprNode {
    double mValue;
public:
    explicit Constant(double value) : mValue{value} {}
    double evaluate(double x) const override { return mValue; }
    double derivative(double x) const override { return 0; }
    std::string toString() const override { return std::to_string(mValue); }
};

class Variable : public ExprNode {
public:
    double evaluate(double x) const override { return x; }
    double derivative(double x) const override { return 1; }
    std::string toString() const override { return "x"; }
};

class BinaryOperator : public ExprNode {
protected:
    Expr mLeft;
    Expr mRight;
public:
    BinaryOperator(Expr left, Expr right)
        : mLeft{std::move(left)}, mRight{std::move(right)} {}
};

class PlusOperator : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    double evaluate(double x) const override { return mLeft.evaluate(x) + mRight.evaluate(x); }
    double derivative(double x) const override { return mLeft.derivative(x) + mRight.derivative(x); }
    std::string toString() const override { return "(" + mLeft.toString() + " + " + mRight.toString() + ")"; }
};

class MinusOperator : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    double evaluate(double x) const override { return mLeft.evaluate(x) - mRight.evaluate(x); }
    double derivative(double x) const override { return mLeft.derivative(x) - mRight.derivative(x); }
    std::string toString() const override { return "(" + mLeft.toString() + " - " + mRight.toString() + ")"; }
};

class MultiplyOperator : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    double evaluate(double x) const override { return mLeft.evaluate(x) * mRight.evaluate(x); }
    double derivative(double x) const override { return mLeft.evaluate(x) * mRight.derivative(x) + mLeft.derivative(x) * mRight.evaluate(x); }
    std::string toString() const override { return "(" + mLeft.toString() + " * " + mRight.toString() + ")"; }
};

class DivideOperator : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    double evaluate(double x) const override { return mLeft.evaluate(x) / mRight.evaluate(x); }
    double derivative(double x) const override { return (mLeft.derivative(x) * mRight.evaluate(x) - mLeft.evaluate(x) * mRight.derivative(x)) / (mRight.evaluate(x) * mRight.evaluate(x)); }
    std::string toString() const override { return "(" + mLeft.toString() + " / " + mRight.toString() + ")"; }
};
</code></div></div></pre>

通过定义这些类和重载运算符（你的任务），我们可以非常方便地创建函数：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">auto &x = Expr::x;
auto f = x * x + 2 * x + 1; // x^2 + 2x + 1
std::cout << f.toString() << std::endl;
std::cout << f.evaluate(3) << std::endl;
std::cout << f.derivative(3) << std::endl;
auto g = f / (-x * x + x - 1); // (x^2 + 2x + 1)/(-x^2 + x - 1)
std::cout << g.evaluate(3) << std::endl;
std::cout << g.derivative(3) << std::endl;
</code></div></div></pre>

输出应该是：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>scss</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-scss">(((x) * (x)) + ((2.000000) * (x))) + (1.000000)
16
8
-2.28571
0.489796
</code></div></div></pre>

#### toString() 方法的要求

注意：这是一种非常简单和朴素的将表达式转换为字符串的方法，因为我们不希望在这部分设置障碍。你可以搜索一些算法使表达式尽可能简化，但这可能无法通过 OJ 测试。

一元运算符（+、-）或二元运算符（+、-、*、/）的任何操作数都应被括号括起来。正确的例子：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">Expr e(-2);
std::cout << e.toString() << std::endl; // 输出应该是 -2.000000 而不是 -(2.000000)
</code></div></div></pre>

应在每个二元运算符前后添加一个空格，例如 `(expr1) + (expr2)` 而不是 `(expr1)+(expr2)`。

将浮点数转换为 `std::string`，只需使用 `std::to_string`，这样你就不会因为精度和浮点误差而烦恼。

example.cpp 包含这些简单的测试。

#### Expr 的要求

从用户的角度来看，只有 `Expr` 和它的算术运算符是接口。代码中的其他任何东西都是实现细节，用户代码不会依赖这些细节。换句话说，只要 `Expr` 的接口满足我们的要求，你可以以任何方式实现这些东西。

* `Expr` 是可复制构造的、可复制赋值的、可移动构造的、可移动赋值的和可销毁的。这些操作只需对成员 `mNode` 执行相应的操作，并让 `std::shared_ptr` 的相应函数处理一切。移动操作应是 `noexcept` 的。
* `Expr` 可从 `double` 值构造，并且这个构造函数不是 `explicit` 的。

让 `e` 是类型为 `const Expr`，`x0` 是类型为 `double`，那么以 `e` 为根的子树表示一个函数。

* `e.evaluate(x0)` 返回该函数在 `x0` 处的值。
* `e.derivative(x0)` 返回该函数在 `x0` 处的导数值。
* `e.toString()` 返回表示该函数的 `std::string`。

让 `e1` 和 `e2` 是两个类型为 `const Expr` 的对象，以下表达式返回一个类型为 `Expr` 的对象，该对象创建了一个对应运算符的新节点。

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">-e1
+e1
e1 + e2
e1 - e2
e1 * e2
e1 / e2
</code></div></div></pre>

`Expr::x` 是一个类型为 `const Expr` 的对象，表示变量 `x`。

使用 compile_test.cpp 检查你的代码是否编译。有关静态断言失败的说明，请参阅附录。

#### 提交

提交 `expr.hpp` 或其内容到 OJ。

#### 思考

为什么我们使用 `std::shared_ptr` 而不是 `std::unique_ptr`？

你能添加对更多功能的支持吗？例如，基本函数、指数表达式、更多变量？打印表达式？

### 附录

#### 返回一个大括号初始化列表

在下面的代码中：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">Expr operator-(const Expr &arg) {
    return {std::make_shared<UnaryOperator>(UnaryOpKind::UOK_Minus, arg)};
}
</code></div></div></pre>

return 语句相当于：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">return Expr{std::make_shared<UnaryOperator>(UnaryOpKind::UOK_Minus, arg)};
</code></div></div></pre>

但我们不想在 return 语句中重复返回类型。

这里我们使用大括号初始化列表 `{...}` 来初始化返回的对象（类型为 `Expr`）。由于 `Expr` 是非聚合类类型，并且没有接受 `std::initializer_list` 的构造函数，并且有一个非 `explicit` 的接受 `std::shared_ptr<ExprNode>` 的构造函数，所以大括号内写的任何内容都传递给了该构造函数。

关于列表初始化的详细规则可以在[这里](https://en.cppreference.com/w/cpp/language/list_initialization)找到。

#### 继承构造函数

给定以下 `BinaryOperator` 的定义：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">class BinaryOperator : public ExprNode {
protected:
    Expr mLeft;
    Expr mRight;
public:
    BinaryOperator(Expr left, Expr right)
        : mLeft{std::move(left)}, mRight{std::move(right)} {}
};
</code></div></div></pre>

具有接受两个 `Expr` 的构造函数，并分别用它们初始化 `mLeft` 和 `mRight`，派生类 `PlusOperator` 可以通过使用 `using` 声明继承构造函数，轻松获取一个执行相同操作的构造函数。

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">class PlusOperator : public BinaryOperator {
    using BinaryOperator::BinaryOperator;
};
</code></div></div></pre>

现在用户可以以下列方式创建一个 `PlusOperator` 对象（假设 `e1` 和 `e2` 是 `Expr` 类型）：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">PlusOperator po(e1, e2);
</code></div></div></pre>

注意，继承构造函数的访问级别始终与基类中继承的构造函数的访问级别相同，无论 `using` 声明的位置在哪里。

同样适用于 `MinusOperator`、`MultiplyOperator` 和 `DivideOperator`。

#### 关于静态断言失败的说明

compile_test.cpp 将测试 `Expr` 的要求是否满足，并使用 `static_assert` 报告错误。这也在 OJ 上使用。

如果任何要求未满足，将报告如下错误：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">compile_test.cpp:24:45: error: static assertion failed: Expect { e.evaluate(d) } -> double, with the setting (const Expr e, double d).
24 | static_assert(decltype(helper_##name(0))::value, \ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~
compile_test.cpp:31:1: note: in expansion of macro ‘EXPECT’
31 | EXPECT(evaluate, e.evaluate(d), double)
| ^~~~~~
</code></div></div></pre>

错误信息的关键部分是 `static assertion failed` 之后的内容：

它表示给定类型为 `const Expr` 的 `e` 和类型为 `double` 的 `d`，表达式 `e.evaluate(d)` 预计返回 `double`。此错误消息表明要么不支持 `e.evaluate(d)`，要么其返回类型不是 `double`。

#### 未使用的参数

如果在函数定义中声明了未使用的参数，编译器将生成警告，如果使用 `-Werror`，则变为错误。

如果确实想要声明未使用的参数（特别是在虚函数中），最常见的方法是简单地省略参数名：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">void foo(int /* unused */) {}
</code></div></div></pre>

注意我们之前见过这个：重载的后缀递增运算符 `++` 有一个未使用的参数。

另一种抑制未使用参数/变量警告的明显方法是使用 `[[maybe_unused]]` 属性。然而，我们不建议对明确未使用的内容使用此属性。只有当参数可能未使用时，才应将其标记为 `[[maybe_unused]]`：

<pre><div class="dark bg-gray-950 rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>cpp</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>复制代码</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">void skip([[maybe_unused]] const std::string &str, std::size_t &pos, [[maybe_unused]] char expect) {
    assert(str[pos] == expect);
    ++pos;
}
</code></div></div></pre>

当程序使用 `-DNDEBUG`（即定义了宏 `NDEBUG`）进行编译时，`assert` 将被移除，`str` 和 `expect` 将未使用。
