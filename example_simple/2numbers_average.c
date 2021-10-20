/*calcul de la moyenne arithmétique de deux entiers */
/*@
ensures \result == ( x + y ) / 2;
 */
int average(int x, int y) {
  if (x >= 0 && y >= 0) {
    if (y >= x)
      return x + (y - x) / 2;
    else
      return y + (x - y) / 2;
  } else if (x >= 0 && y < 0) {
    return (x+y) / 2;
  } else if (x < 0 && y >= 0) {
    return (x+y) / 2;
  } else {
    if (y >= x)
      return y + (x - y) / 2;
    else
      return x + (y - x) / 2; 
  }
}

