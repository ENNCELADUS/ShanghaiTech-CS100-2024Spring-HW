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

  void print() const {      // TODO: Edge should be printed.
    detail::printBlock(ArtDigit[mCurrentDigit], mBaseRow, mBaseCol);
  }

  enum class ScrollDirection { Up, Down };

  void updateAndScroll(int newDigit, ScrollDirection scrollDir){
    // 获取当前数字和新的数字
    int oldDigit = mCurrentDigit;
    
    // 决定滚动方向
    int topDigit = scrollDir == ScrollDirection::Up ? oldDigit : newDigit;
    int bottomDigit = oldDigit + newDigit - topDigit;

    // 执行滚动动画
    for (int tick = 0; tick != DigitHeight + 1; ++tick) {
      int mid = scrollDir == ScrollDirection::Up ? tick : DigitHeight - tick;
      int row = mBaseRow;
      for (int i = mid; i != DigitHeight; ++i) {
        move_cursor(row++, mBaseCol);
        std::cout << ArtDigit[topDigit][i];
      }
      for (int i = 0; i != mid; ++i) {
        move_cursor(row++, mBaseCol);
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
  std::string mName;
  DigitPad mTensPlace;
  DigitPad mOnesPlace;
  int mScore;

public:
  enum class Side { Left, Right };

  Player(std::string name, Side side)
      : mName{std::move(name)},
        mTensPlace{ColorOfSide(side), 0, BaseColOfSide(side)},
        mOnesPlace{ColorOfSide(side), 0, BaseColOfSide(side) + FrameWidth},
        mScore{0} { print(); }

  int getScore() const { return mScore; }

  void print() const {        // TODO: Names should be printed.
    mTensPlace.print();
    mOnesPlace.print();
  };

  void updateScore(int delta) {
    int newScore = mScore + delta;
    assert(newScore >= 0 && newScore < 100);

    PrinterGuard printerGuard;
    ColorGuard withColor(mTensPlace.getColor()); // Assuming DigitPad has getColor method

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
        mRight{std::move(rightName), Player::Side::Right} {        // TODO: Initial condition print should be printed correctly. Including color, ':', clearScreen.
    clear_screen();
    PrinterGuard printerGuard; //隐藏光标和输⼊

    mLeft.print();
    mRight.print();
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