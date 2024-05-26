#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include "ArtDigits.hpp"
#include "utils.hpp"

#include <cassert>

inline constexpr auto MSPerTick = 50;

namespace detail {

template <std::size_t Height, std::size_t Width>
static void printBlock(const char (&object)[Height][Width], int baseRow,
                       int baseCol) {
  for (int row = 0; row != Height; ++row) {
    move_cursor(baseRow + row, baseCol);
    std::cout << object[row];
  }
  std::cout << std::flush;
}

} // namespace detail

// DigitPad 类：表示一个数码牌，记录位置和当前数字，并负责显示和动画功能。
class DigitPad {                    
  const TextColor mColor;
  const int mBaseRow;
  const int mBaseCol;
  int mCurrentDigit;

public:
  DigitPad(TextColor color, int baseRow, int baseCol)
    : mColor{color}, mBaseRow{baseRow}, mBaseCol{baseCol}, mCurrentDigit{0} {}

  int getBaseRow() const { return mBaseRow; }

  int getBaseCol() const { return mBaseCol; }

  int getDigit() const { return mCurrentDigit; }

  TextColor getColor() const { return mColor; }

  void print() const {
    // 根据 mColor 设置颜色
    std::cout << mColor;

    // 打印边框
    detail::printBlock(Frame, mBaseRow, mBaseCol);

    // 打印数字到边框中间
    int digitRow = mBaseRow + (FrameHeight - DigitHeight) / 2;
    int digitCol = mBaseCol + (FrameWidth - DigitWidth) / 2;
    detail::printBlock(ArtDigit[mCurrentDigit], digitRow, digitCol);

    // 恢复正常颜色
    std::cout << TextColor::Normal;
  }


  enum class ScrollDirection { Up, Down };

  void updateAndScroll(int newDigit, ScrollDirection scrollDir){
    // 获取当前数字和新的数字
    int oldDigit = mCurrentDigit;
    
    // 决定滚动方向
    int topDigit = scrollDir == ScrollDirection::Up ? oldDigit : newDigit;
    int bottomDigit = oldDigit + newDigit - topDigit;
    
    // 计算数字在边框中的位置
    int digitRow = mBaseRow + (FrameHeight - DigitHeight) / 2;
    int digitCol = mBaseCol + (FrameWidth - DigitWidth) / 2;

    // 执行滚动动画
    for (int tick = 0; tick != DigitHeight + 1; ++tick) {
      int mid = scrollDir == ScrollDirection::Up ? tick : DigitHeight - tick;
      int row = digitRow;

      std::cout << mColor; // 设置颜色
      for (int i = mid; i != DigitHeight; ++i) {
        move_cursor(row++, digitCol);
        std::cout << ArtDigit[topDigit][i];
      }
      for (int i = 0; i != mid; ++ i) {
        move_cursor(row++, digitCol);
        std::cout << ArtDigit[bottomDigit][i];
      }
      std::cout << std::flush;
      sleep_ms(MSPerTick);
    }

    // 更新当前数字并重新打印
    mCurrentDigit = newDigit;
    print();
  }
};

// Player 类：表示一个对战方，管理名字和分数信息，并创建和管理两个数码牌。提供更新分数的接口，调用数码牌上的相关函数。
class Player {
public:
  enum class Side { Left, Right };

private:
  std::string mName;
  DigitPad mTensPlace;
  DigitPad mOnesPlace;
  int mScore;
  Side mSide;


public:
  Player(std::string name, Side side)
      : mName{std::move(name)},
        mTensPlace{ColorOfSide(side), 0, BaseColOfSide(side)},
        mOnesPlace{ColorOfSide(side), 0, BaseColOfSide(side) + FrameWidth},
        mScore{0},
        mSide{side} { print(); }

  int getScore() const { return mScore; }
  std::string getName() const { return mName; }

  void print() const {
    mTensPlace.print();
    mOnesPlace.print();
  };

  void updateScore(int delta) {
    int newScore = mScore + delta;
    assert(newScore >= 0 && newScore < 100);

    PrinterGuard printerGuard;
    ColorGuard withColor(mTensPlace.getColor());

    auto dir = delta > 0 ? DigitPad::ScrollDirection::Up : DigitPad::ScrollDirection::Down;

    int oldTens = mScore / 10;
    int oldOnes = mScore % 10;
    int newTens = newScore / 10;
    int newOnes = newScore % 10;

    if (oldOnes != newOnes) {
      mOnesPlace.updateAndScroll(newOnes, dir);
    }
    if (oldTens != newTens) {
      mTensPlace.updateAndScroll(newTens, dir);
    }

    mScore = newScore;
  }

private:
  static TextColor ColorOfSide(Side side){
    return side == Side::Left ? TextColor::Red : TextColor::Blue;
  }

  static int BaseColOfSide(Side side){
    return side == Side::Left ? 0 : FrameWidth * 2 + ColonWidth;
  }
};

// ScoreBoard 类：包含两个 Player 实例，每个 Player 管理自己的数码牌和名字显示。
class ScoreBoard {
  Player mLeft;
  Player mRight;

public:
  ScoreBoard(std::string leftName, std::string rightName)
      : mLeft{std::move(leftName), Player::Side::Left},
        mRight{std::move(rightName), Player::Side::Right} {
    clear_screen();
    PrinterGuard printerGuard; //隐藏光标和输⼊

    mLeft.print();
    mRight.print();

    // 恢复正常颜色
    std::cout << TextColor::Normal;

    // 打印冒号
    detail::printBlock(Colon, 0, FrameWidth * 2);
    
    // 打印玩家名字
    move_cursor(FrameHeight, FrameWidth - mLeft.getName().size() / 2);
    std::cout << mLeft.getName();
    move_cursor(FrameHeight, 3 * FrameWidth + ColonWidth - mRight.getName().size() / 2);
    std::cout << mRight.getName();

    std::cout << std::flush;
  }

  void leftInc(int delta = 1) { mLeft.updateScore(delta); }
  void rightInc(int delta = 1) { mRight.updateScore(delta); }
  void leftDec(int delta = 1) { mLeft.updateScore(-delta); }
  void rightDec(int delta = 1) { mRight.updateScore(-delta); }

  ~ScoreBoard() {
    for (int row = FrameHeight; row >= 0; --row) {
      move_cursor(row, 0);
      clear_to_eol();
      sleep_ms(MSPerTick);
    }
  }
};

#endif // SCOREBOARD_HPP