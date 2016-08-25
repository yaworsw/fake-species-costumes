#ifndef DEBUG
#define pp(str)   ;
#define ppln(str) ;

#endif //DEBUG

#ifdef DEBUG
#define pp(str)   Serial.print(str)
#define ppln(str) Serial.println(str)

#endif //DEBUG
