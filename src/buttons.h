const char CLEAR = 'A';
const char ADD = 'B';
const char SUB = 'C';
const char ENTER = 'D';
const char DOT = '#';
const char FUNCTION = '*';

bool keyIsNumber(char key){
  return key != CLEAR && key != ADD && key != SUB && key != ENTER && key != DOT && key != FUNCTION;
}