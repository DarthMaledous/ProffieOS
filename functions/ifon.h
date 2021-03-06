#ifndef FUNCTIONS_IFON_H
#define FUNCTIONS_IFON_H

// Usage: Ifon<A, B>
// Returns A if saber is on, B otherwise.
// A, B: INTEGER
// return value: INTEGER

// TODO: optimize when the A & B is the same for all LEDs.

class BladeBase;

template<class IFON, class IFOFF>
class Ifon {
public:
  void run(BladeBase* blade) {
    ifon_.run(blade);
    ifoff_.run(blade);
    on_ = blade->is_on();
  }
  int getInteger(int led) {
    return on_ ? ifon_.getInteger(led) : ifoff_.getInteger(led);
  }

private:
  IFON ifon_;
  IFOFF ifoff_;
  bool on_;
};

// InOutFunc<OUT_MILLIS, IN_MILLIS>
// IN_MILLIS, OUT_MILLIS: a number
// RETURN VALUE: FUNCTION
// 0 when off, 32768 when on, takes OUT_MILLIS to go from 0 to 32768
// takes IN_MILLIS to go from 32768 to 0.
template<int OUT_MILLIS, int IN_MILLIS>
class InOutFunc {
public:
  void run(BladeBase* blade) {
    uint32_t now = micros();
    uint32_t delta = now - last_micros_;
    last_micros_ = now;
    if (blade->is_on()) {
      if (extension == 0.0) {
         // We might have been off for a while, so delta might
         // be insanely high.
         extension = 0.00001;
      } else {
         extension += delta / (OUT_MILLIS * 1000.0);
         extension = min(extension, 1.0f);
      }
    } else {
      extension -= delta / (IN_MILLIS * 1000.0);
      extension = max(extension, 0.0f);
    }
    ret_ = extension * 32768.0;
  }
  int getInteger(int led) { return ret_; }

private:
  float extension = 0.0;
  uint32_t last_micros_;
  int ret_;
};

#endif
