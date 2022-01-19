#ifndef DISP35_DEFS_H
#define DISP35_DEFS_H

/*
 * SEGMENT POSITION DEFINITIONS
 */

#define X_MARG            2
#define Y_MARG            0
#define SEG_LEN           10
#define DIGIT_OFFSET(D)   (D)*16
#define DP_LEN            2
#define DP_OFFSET_PAX     4
#define DP_OFFSET_PDY     (-3)

///////////// SEGMENT A
#define PAX(D)            (DIGIT_OFFSET(D) + X_MARG)
#define PAY               Y_MARG
#define PA(D)             PAX(D), PAY, SEG_LEN
///////////// SEGMENT F
#define PF(D)             PA(D)
///////////// SEGMENT B
#define PBX(D)            (PAX(D) + SEG_LEN)
#define PBY               PAY
#define PB(D)             PBX(D), PBY, SEG_LEN
///////////// SEGMENT C
#define PCX(D)            PBX(D)
#define PCY               (PBY + SEG_LEN)
#define PC(D)             PCX(D), PCY, SEG_LEN
///////////// SEGMENT E
#define PEX(D)            PAX(D)
#define PEY               (PAY + SEG_LEN)
#define PE(D)             PEX(D), PEY, SEG_LEN
///////////// SEGMENT G
#define PG(D)             PE(D)
///////////// SEGMENT D
#define PDX(D)            PAX(D)
#define PDY               (PEY + SEG_LEN)
#define PD(D)             PDX(D), PDY, SEG_LEN
///////////// DP
#define PDPX(D)           (PAX(D) + DP_OFFSET_PAX)
#define PDPY              (PDY + DP_OFFSET_PDY)
#define PDP(D)            PDPX(D), PDPY, DP_LEN
#define PDP2(D)           (PDPX(D) + 1), PDPY, DP_LEN

#endif
