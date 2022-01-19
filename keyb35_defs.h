#ifndef KEYB35_DEFS_H
#define KEYB35_DEFS_H

#define DY      20     // Max vertical offset from key center 
#define DX      30     // Max horizontal offset from key center 

#define RY      37     // 298px/8 rows = 37.25 
#define RX      48     // 240px/5 cols = 48   (Upper part of the keyboard)
#define RXL     60     // 240px/4 cols = 60   (Lower part of the keyboard)

#define R1      ( RY + 3 )       
#define R2      ( R1 + RY )     
#define R3      ( R2 + RY )     
#define R4      ( R3 + RY )    
#define R5      ( R4 + RY )   
#define R6      ( R5 + RY )   
#define R7      ( R6 + RY )      
#define R8      ( R7 + RY )     

#define C1      25
#define C2      ( C1 + RX )
#define C3      ( C2 + RX )
#define C4      ( C3 + RX )
#define C5      ( C4 + RX )
#define C1L     18
#define C2L     ( C1L + RXL )
#define C3L     ( C2L + 11 + RXL )    // Needed to be justified a bit
#define C4L     ( C3L + RXL )
#define CE      45                    // ENTER

#define KEY0 { C2L,R8 }, 36  //0
#define KEY1 { C2L,R7 }, 28  //1
#define KEY2 { C3L,R7 }, 27  //2
#define KEY3 { C4L,R7 }, 26  //3
#define KEY4 { C2L,R6 }, 20  //4
#define KEY5 { C3L,R6 }, 19  //5
#define KEY6 { C4L,R6 }, 18  //6
#define KEY7 { C2L,R5 }, 52  //7
#define KEY8 { C3L,R5 }, 51  //8
#define KEY9 { C4L,R5 }, 50  //9
#define KEY10 { C3L,R8 }, 35 //.
#define KEY11 { CE,R4 }, 62  //ENTER
#define KEY12 { C1L,R6 }, 22 //+
#define KEY13 { C1L,R5 }, 54 //-
#define KEY14 { C1L,R7 }, 30 //*
#define KEY15 { C1L,R8 }, 38 ///
#define KEY16 { C5,R4 }, 56  //CLX
#define KEY17 { C3,R4 }, 59  //CHS
#define KEY18 { C4,R4 }, 58  //EEX
#define KEY19 { C4L,R8 }, 34 //pi
#define KEY20 { C1,R1 }, 6   //x^y
#define KEY21 { C2,R1 }, 4   //LOG
#define KEY22 { C3,R1 }, 3   //LN
#define KEY23 { C4,R1 }, 2   //e^x
#define KEY24 { C5,R1 }, 0   //CLR
#define KEY25 { C1,R2 }, 46  //SQR
#define KEY26 { C2,R2 }, 44  //ARC
#define KEY27 { C3,R2 }, 43  //SIN
#define KEY28 { C4,R2 }, 42  //COS
#define KEY29 { C5,R2 }, 40  //TAN
#define KEY30 { C1,R3 }, 14  //1/x
#define KEY31 { C2,R3 }, 12  //x<>y
#define KEY32 { C3,R3 }, 11  //Rv
#define KEY33 { C4,R3 }, 10  //STO
#define KEY34 { C5,R3 }, 8   //RCL

/*
 * HP35 KEY CODES
      key = 6  //x^y
      key = 4  //LOG
      key = 3  //LN
      key = 2  //e^x
      key = 0  //CLR
      key = 46 //SQR
      key = 44 //ARC
      key = 43 //SIN
      key = 42 //COS
      key = 40 //TAN
      key = 14 //1/x
      key = 12 //x<>y
      key = 11 //Rv
      key = 10 //STO
      key = 8  //RCL
      key = 62 //ENTER
      key = 59 //CHS
      key = 58 //EEX
      key = 56 //CLX
      key = 54 //-
      key = 52 //7
      key = 51 //8
      key = 50 //9
      key = 22 //+
      key = 20 //4
      key = 19 //5
      key = 18 //6
      key = 30 //*
      key = 28 //1
      key = 27 //2
      key = 26 //3
      key = 38 ///
      key = 36 //0
      key = 35 //.
      key = 34 //pi
      
keyLookup[0-9]    0-9
keyLookup[10]     .
keyLookup[11]     ENTER
keyLookup[12]     +
keyLookup[13]     -
keyLookup[14]     *
keyLookup[15]     /
keyLookup[16]     CLX
keyLookup[17]     CHS
keyLookup[18]     EEX
keyLookup[19]     pi
keyLookup[20-34]  MATH KEYS + REG KEY (row by row)
*/

#endif
