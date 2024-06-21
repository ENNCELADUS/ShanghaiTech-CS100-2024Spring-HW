#ifndef EXPR_HPP
#define EXPR_HPP

#include <memory>
#include <string>

/**
 * @brief Base class for all expression nodes in the abstract syntax tree (AST).
 */
class ExprNode {
public:
  // FIXED: Make any of these functions virtual, or pure virtual, if necessary.
  ExprNode() = default;

  virtual double evaluate(double x) const = 0;    // Evaluate f(x)

  virtual double derivative(double x) const = 0;  // Evaluate df(x)/dx

  virtual std::string toString() const = 0;       // Returns the parenthesized representation of the function.
  
  virtual ~ExprNode() = default;
};

/**
 * @brief Wrapper class to manage ExprNode objects and provide a convenient interface for users to interact with expression trees.
 */
class Expr {
  std::shared_ptr<ExprNode> mNode;

  Expr(std::shared_ptr<ExprNode> ptr) : mNode{std::move(ptr)} {}

public:
  /**
   * @brief Construct a new Expr object
   * 
   * @param value 
   */
  Expr(double value);

  /**
   * @brief Default constructor
   * 
   * @param other 
   */
  Expr(const Expr& other) = default;
  Expr& operator=(const Expr& other) = default;
  Expr(Expr&& other) noexcept = default;
  Expr& operator=(Expr&& other) noexcept = default;
  ~Expr() = default;

  static const Expr x;

  double evaluate(double x) const { return mNode->evaluate(x); }
  double derivative(double x) const { return mNode->derivative(x); }
  std::string toString() const { return mNode->toString(); }

  friend Expr operator-(const Expr &arg);
  friend Expr operator+(const Expr &arg);
  friend Expr operator+(const Expr &lhs, const Expr &rhs);
  friend Expr operator-(const Expr &lhs, const Expr &rhs);
  friend Expr operator*(const Expr &lhs, const Expr &rhs);
  friend Expr operator/(const Expr &lhs, const Expr &rhs);
};

/**
 * @brief Represents the variable x in the expression tree.
 * 
 */
class Variable : public ExprNode {
public:
  // DONE: evaluate, derivative and toString ...
  double evaluate(double x) const override { return x; }
  double derivative(double ) const override { return 1.0; }
  std::string toString() const override { return "x"; }
};

const Expr Expr::x{std::make_shared<Variable>()};

class Constant : public ExprNode {
  double mValue;

public:
  explicit Constant(double value) : mValue{value} {}

  // DONE: evaluate, derivative and toString ...
  double evaluate(double) const override { return mValue; }
  double derivative(double) const override { return 0.0; }
  std::string toString() const override { return std::to_string(mValue); }
};

Expr::Expr(double value) : mNode{std::make_shared<Constant>(value)} {}

/**
 * @brief Enum for unary operator kinds.
 * 
 */
enum class UnaryOpKind {
  UOK_Plus, /**Unary plus operator */
  UOK_Minus /** Unary minus operator */
};

/**
 * @brief Represents a unary operator in the expression tree.
 */
class UnaryOperator : public ExprNode {
  UnaryOpKind mOpKind;
  Expr mOperand;

public:
  UnaryOperator(UnaryOpKind op, Expr operand) : mOpKind{op}, mOperand{std::move(operand)} {}

  // DONE: evaluate, derivative and toString ...
  double evaluate(double x) const override {
    double value = mOperand.evaluate(x);
    return mOpKind == UnaryOpKind::UOK_Minus ? -value : value;
  }

  double derivative(double x) const override {
    double value = mOperand.derivative(x);
    return mOpKind == UnaryOpKind::UOK_Minus ? -value : value;
  }

  std::string toString() const override {
    return mOpKind == UnaryOpKind::UOK_Minus ? "-(" + mOperand.toString() + ")" : mOperand.toString();
  }
};

/**
 * @brief Base class for all binary operators in the expression tree.
 * 
 */
class BinaryOperator : public ExprNode {
protected:
  Expr mLeft;
  Expr mRight;

public:
  BinaryOperator(Expr left, Expr right)
      : mLeft{std::move(left)}, mRight{std::move(right)} {}
};

class PlusOp : public BinaryOperator {
public:
  using BinaryOperator::BinaryOperator;

  // DONE: evaluate, derivative and toString ...
  double evaluate(double x) const override {
    return mLeft.evaluate(x) + mRight.evaluate(x);
  }

  double derivative(double x) const override {
    return mLeft.derivative(x) + mRight.derivative(x);
  }

  std::string toString() const override {
    return "(" + mLeft.toString() + ")" +  " + " + "(" + mRight.toString() + ")";
  }
};

class MinusOp : public BinaryOperator {
public:
  using BinaryOperator::BinaryOperator;

  // DONE: evaluate, derivative and toString ...
  double evaluate(double x) const override {
    return mLeft.evaluate(x) - mRight.evaluate(x);
  }

  double derivative(double x) const override {
    return mLeft.derivative(x) - mRight.derivative(x);
  }

  std::string toString() const override {
    return "(" + mLeft.toString() + ")" +  " - " + "(" + mRight.toString() + ")";
  }
};

class MultiplyOp : public BinaryOperator {
public:
  using BinaryOperator::BinaryOperator;

  // DONE: evaluate, derivative and toString ...
  double evaluate(double x) const override {
    return mLeft.evaluate(x) * mRight.evaluate(x);
  }

  double derivative(double x) const override {
    return mLeft.derivative(x) * mRight.evaluate(x) + mLeft.evaluate(x) * mRight.derivative(x);
  }

  std::string toString() const override {
    return "(" + mLeft.toString() + ")" +  " * " + "(" + mRight.toString() + ")";
  }
};

class DivideOp : public BinaryOperator {
public:
  using BinaryOperator::BinaryOperator;

  // DONE: evaluate, derivative and toString ...
  double evaluate(double x) const override {
    return mLeft.evaluate(x) / mRight.evaluate(x);
  }

  double derivative(double x) const override {
    double f = mLeft.evaluate(x);
    double g = mRight.evaluate(x);
    double df = mLeft.derivative(x);
    double dg = mRight.derivative(x);
    return (df * g - f * dg) / (g * g);
  }

  std::string toString() const override {
    return "(" + mLeft.toString() + ")" +  " / " + "(" + mRight.toString() + ")";
  }
};

// DONE: Add functions if necessary.
Expr operator-(const Expr &arg) {
  return {std::make_shared<UnaryOperator>(UnaryOpKind::UOK_Minus, arg)};
}

Expr operator+(const Expr &arg) {
  return {std::make_shared<UnaryOperator>(UnaryOpKind::UOK_Plus, arg)};
}

Expr operator+(const Expr &lhs, const Expr &rhs) {
  return {std::make_shared<PlusOp>(lhs, rhs)};
}

Expr operator-(const Expr &lhs, const Expr &rhs) {
  return {std::make_shared<MinusOp>(lhs, rhs)};
}

Expr operator*(const Expr &lhs, const Expr &rhs) {
  return {std::make_shared<MultiplyOp>(lhs, rhs)};
}

Expr operator/(const Expr &lhs, const Expr &rhs) {
  return {std::make_shared<DivideOp>(lhs, rhs)};
}

#endif // EXPR_HPP