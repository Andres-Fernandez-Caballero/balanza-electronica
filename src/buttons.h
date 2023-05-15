const char CLEAR = 'A';
const char ADD = 'B';
const char SUB = 'C';
const char GET_TOTAL = 'D';
const char DOT = '#';
const char FUNCTION = '*';

bool keyIsNumber(char key){
  return key != CLEAR 
  && key != ADD 
  && key != SUB 
  && key != GET_TOTAL 
  && key != DOT 
  && key != FUNCTION;
}