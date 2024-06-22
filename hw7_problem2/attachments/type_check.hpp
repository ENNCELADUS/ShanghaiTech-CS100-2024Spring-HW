#ifndef EXPR_TYPE_CHECK_HPP
#define EXPR_TYPE_CHECK_HPP

#include "expr.hpp"

/**
 * @brief A visitor class for performing type checking on the abstract syntax tree (AST).
 * 
 */
class TypeCheckVisitor : public ExprNodeVisitor{
public:
    /**
     * @brief Visit a constant node.
     * 
     * @param node The constant node.
     */
    void visit(IntegerConstant &node) override {
        node.setType(ExprType::Integer);
    }

    void visit(FloatConstant &node) override {
        node.setType(ExprType::Float);
    }

    void visit(BooleanConstant &node) override {
        node.setType(ExprType::Boolean);
    }

    /**
     * @brief Visit a variable node.
     */
    void visit(Variable &) override {
        // The type of a variable is determined when it's created.
    }

    /**
     * @brief Visit a unary arithmetic operator node.
     * 
     * @param node The unary arithmetic operator node.
     */
    void visit(UnaryArithOp &node) override {
        node.getOperand().accept(*this);
        if (node.getOperand().getType() == ExprType::Integer || node.getOperand().getType() == ExprType::Float) {
            node.setType(node.getOperand().getType());
        } else {
            node.setType(ExprType::ErrorType);
        }
    }

    /**
     * @brief Visit a logical NOT operator node.
     * 
     * @param node The logical NOT operator node.
     */
    void visit(LogicalNotOp &node) override {
        node.getOperand().accept(*this);
        if (node.getOperand().getType() == ExprType::Boolean) {
            node.setType(ExprType::Boolean);
        } else {
            node.setType(ExprType::ErrorType);
        }
    }

    /**
     * @brief Visit a binary arithmetic operator node.
     * 
     * @param node The binary arithmetic operator node.
     */
    void visit(BinaryArithOp &node) override {
        node.getLHS().accept(*this);
        node.getRHS().accept(*this);
        if (node.getLHS().getType() == ExprType::Integer && node.getRHS().getType() == ExprType::Integer) {
            node.setType(ExprType::Integer);
        } else if ((node.getLHS().getType() == ExprType::Float || node.getLHS().getType() == ExprType::Integer) &&
                   (node.getRHS().getType() == ExprType::Float || node.getRHS().getType() == ExprType::Integer)) {
            node.setType(ExprType::Float);
        } else {
            node.setType(ExprType::ErrorType);
        }
    }

    /**
     * @brief Visit a binary logical operator node.
     * 
     * @param node The binary logical operator node.
     */
    void visit(BinaryLogicalOp &node) override {
        node.getLHS().accept(*this);
        node.getRHS().accept(*this);
        if (node.getLHS().getType() == ExprType::Boolean && node.getRHS().getType() == ExprType::Boolean) {
            node.setType(ExprType::Boolean);
        } else {
            node.setType(ExprType::ErrorType);
        }
    }

    /**
     * @brief Visit a relational operator node.
     * 
     * @param node The relational operator node.
     */
    void visit(RelationalOp &node) override {
        node.getLHS().accept(*this);
        node.getRHS().accept(*this);
        if ((node.getLHS().getType() == ExprType::Integer || node.getLHS().getType() == ExprType::Float) &&
            (node.getRHS().getType() == ExprType::Integer || node.getRHS().getType() == ExprType::Float)) {
            node.setType(ExprType::Boolean);
        } else {
            node.setType(ExprType::ErrorType);
        }
    }

    /**
     * @brief Visit an equality operator node.
     * 
     * @param node The equality operator node.
     */
    void visit(EqualityOp &node) override {
        node.getLHS().accept(*this);
        node.getRHS().accept(*this);
        if (node.getLHS().getType() == ExprType::ErrorType || node.getRHS().getType() == ExprType::ErrorType) {
            node.setType(ExprType::ErrorType);
        } else if (node.getLHS().getType() == node.getRHS().getType()) {
            node.setType(ExprType::Boolean);
        } else if ((node.getLHS().getType() == ExprType::Integer || node.getLHS().getType() == ExprType::Float) &&
            (node.getRHS().getType() == ExprType::Integer || node.getRHS().getType() == ExprType::Float)) {
            node.setType(ExprType::Boolean);
        } else {
            node.setType(ExprType::ErrorType);
        }
    }

    /**
     * @brief Visit a conditional operator node.
     * 
     * @param node The conditional operator node.
     */
    void visit(ConditionalOp &node) override {
        node.getCondition().accept(*this);
        node.getExprTrue().accept(*this);
        node.getExprFalse().accept(*this);
        if (node.getCondition().getType() == ExprType::ErrorType || node.getExprTrue().getType() == ExprType::ErrorType || node.getExprFalse().getType() == ExprType::ErrorType) {
            node.setType(ExprType::ErrorType);
        } else if (node.getCondition().getType() == ExprType::Boolean) {
            ExprType trueType = node.getExprTrue().getType();
            ExprType falseType = node.getExprFalse().getType();
            if (trueType == falseType) {
                node.setType(trueType);
            } else if ((trueType == ExprType::Integer || trueType == ExprType::Float) &&
                (falseType == ExprType::Integer || falseType == ExprType::Float)) {
                if (trueType == ExprType::Integer && falseType == ExprType::Integer) {
                    node.setType(ExprType::Integer);
                }
                else {
                    node.setType(ExprType::Float);
                }
            } else {
                node.setType(ExprType::ErrorType);
            }
        } else {
            node.setType(ExprType::ErrorType);
        }
    }
};

/// @brief Performs type checking on the expression @c expr, including all of
/// its subexpressions.
/// @param expr The expression, which is the root of the AST.
void typeCheck(Expr &expr){
    TypeCheckVisitor visitor;
    expr.accept(visitor);
}

#endif // EXPR_TYPE_CHECK_HPP
