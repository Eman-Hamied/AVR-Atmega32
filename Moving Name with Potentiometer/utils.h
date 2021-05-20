
#ifndef UTILS_H_
#define UTILS_H_

//Functions Like Macro
#define set_bit(reg,bitn) reg |=(1<<bitn)
#define clr_bit(reg,bitn) reg &=(~(1<<bitn))
#define get_bit(reg,bitn) ((reg&(1<<bitn))>>bitn)
#define toggle_bit(reg,bitn) reg^=(1<<bitn)
#define set_byte(reg,value) reg = value


#endif /* UTILS_H_ */
