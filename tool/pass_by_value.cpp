#include <iostream>

using namespace std;

// Color
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[39m"

class Point {
 private:
  int _x;
  int _y;

 public:
  Point();
  Point(const Point &rhs);

  const int getX() const;
  const int getY() const;
  void setX(int x);
  void setY(int y);
};

Point::Point() : _x(2), _y(2) { cout << BLUE "Construcor" RESET << endl; }

Point::Point(const Point &rhs) {
  cout << MAGENTA "Copy-Construcor" RESET << endl;
}

const int Point::getX() const { return _x; }

const int Point::getY() const { return _y; }

void Point::setX(int x) { _x = x; }

void Point::setY(int y) { _y = y; }

std::ostream &operator<<(std::ostream &ost, const Point &rhs) {
  ost << "[x] " << rhs.getX() << endl << "[y] " << rhs.getY();
  return ost;
}

void toOrigin(Point point) {
  printf(YELLOW "-----Before:toOrigin-----\n" RESET);
  cout << point << endl;
  cout << &point << endl;
  point.setX(0);
  point.setY(0);
  printf(YELLOW "-----After :toOrigin-----\n" RESET);
  cout << point << endl;
  cout << &point << endl;
}

int main() {
  Point point;

  printf(GREEN "-----Before:Main-----\n" RESET);
  cout << point << endl;
  cout << &point << endl;
  toOrigin(point);
  printf(GREEN "-----After :Main-----\n" RESET);
  cout << point << endl;
  cout << &point << endl;
}
