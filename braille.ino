//3 - 6
//4 - 7
//5 - 8 
#include <ctype.h>

int alpha[26][6] = {{1,0,0,0,0,0}, //a
                    {1,1,0,0,0,0}, //b
                    {1,0,0,1,0,0}, //c
                    {1,0,0,1,1,0}, //d
                    {1,0,0,0,1,0}, //e
                    {1,1,0,1,0,0}, //f
                    {1,1,0,1,1,0}, //g
                    {1,1,0,0,1,0}, //h
                    {0,1,0,1,0,0}, //i
                    {0,1,0,1,1,0}, //j
                    {1,0,1,0,0,0}, //k
                    {1,1,1,0,0,0}, //l
                    {1,0,1,1,0,0}, //m
                    {1,0,1,1,1,0}, //n
                    {1,0,1,0,1,0}, //o
                    {1,1,1,1,0,0}, //p
                    {1,1,1,1,1,0}, //q
                    {1,1,1,0,1,0}, //r
                    {0,1,1,1,0,0}, //s
                    {0,1,1,1,1,0}, //t
                    {1,0,1,0,0,1}, //u
                    {1,1,1,0,0,1}, //v
                    {0,1,0,1,1,1}, //w
                    {1,0,1,1,0,1}, //x
                    {1,0,1,1,1,1}, //y
                    {1,0,1,0,1,1}};//z
                   
// 'a' - 97
// alpha[ch - 97] --> alpha[0]

void print_letter(char ch) {
//  ch = tolower(ch);
//  if (ch < 97 || ch > 123) return;
  for (int i = 3; i < 9; i++) {
    digitalWrite(i, !(alpha[ch - 97][i-3] && 1));
  }
}

void reset_pos() {
  for (int i = 3; i < 9; i++) digitalWrite(i, HIGH);
}

void print_string(String str) {
  Serial.println("Received new word :" + str + ".");
  for (int i = 0; i < str.length(); i++) 
  {
    char tmp = str.charAt(i);
    print_letter(tmp);
    delay(1000);
  }
  for(int i = 3; i < 9; i++) digitalWrite(i, HIGH);
}

void setup() 
{
  for (int i = 3; i < 9; i++) {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
}

void loop() 
{ 
  reset_pos();  
  Serial.println("Enter a string to print: ");
  while (Serial.available() == 0);
  String inp = Serial.readStringUntil('\n');
  print_string(inp);  
}
