#include "instructions.h"

InstructionInfo VCPU_INSTRUCTIONS[] = {
    { 0010000, 0017777, "mov"   , (void*) instr_mov , VCPU_INSTR_TYPE_DOUBLE_OPERAND },
    { 0110000, 0117777, "movb"  , (void*) instr_movb, VCPU_INSTR_TYPE_DOUBLE_OPERAND },
    { 0020000, 0027777, "cmp"   , (void*) instr_cmp , VCPU_INSTR_TYPE_DOUBLE_OPERAND },
    { 0120000, 0127777, "cmpb"  , (void*) instr_cmpb, VCPU_INSTR_TYPE_DOUBLE_OPERAND },
    { 0030000, 0037777, "bit"   , (void*) instr_bit , VCPU_INSTR_TYPE_DOUBLE_OPERAND },
    { 0130000, 0137777, "bitb"  , (void*) instr_bitb, VCPU_INSTR_TYPE_DOUBLE_OPERAND },
    { 0040000, 0047777, "bic"   , (void*) instr_bic , VCPU_INSTR_TYPE_DOUBLE_OPERAND },
    { 0140000, 0147777, "bicb"  , (void*) instr_bicb, VCPU_INSTR_TYPE_DOUBLE_OPERAND },
    { 0050000, 0057777, "bis"   , (void*) instr_bis , VCPU_INSTR_TYPE_DOUBLE_OPERAND },
    { 0150000, 0157777, "bisb"  , (void*) instr_bisb, VCPU_INSTR_TYPE_DOUBLE_OPERAND },
    { 0060000, 0067777, "add"   , (void*) instr_add , VCPU_INSTR_TYPE_DOUBLE_OPERAND },
    { 0160000, 0167777, "sub"   , (void*) instr_sub , VCPU_INSTR_TYPE_DOUBLE_OPERAND },

    { 0070000, 0070777, "mul"   , (void*) instr_mul , VCPU_INSTR_TYPE_OPERAND_REGISTER },
    { 0071000, 0071777, "div"   , (void*) instr_div , VCPU_INSTR_TYPE_OPERAND_REGISTER },
    { 0072000, 0072777, "ash"   , (void*) instr_ash , VCPU_INSTR_TYPE_OPERAND_REGISTER },
    { 0073000, 0073777, "ashc"  , (void*) instr_ashc, VCPU_INSTR_TYPE_OPERAND_REGISTER },
    { 0074000, 0074777, "xor"   , (void*) instr_xor , VCPU_INSTR_TYPE_OPERAND_REGISTER },

    { 0000300, 0000377, "swab"  , (void*) instr_swab, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0005000, 0005077, "clr"   , (void*) instr_clr , VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0105000, 0105077, "clrb"  , (void*) instr_clrb, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0005100, 0005177, "com"   , (void*) instr_com , VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0105100, 0105177, "comb"  , (void*) instr_comb, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0005200, 0005277, "inc"   , (void*) instr_inc , VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0105200, 0105277, "incb"  , (void*) instr_incb, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0005300, 0005377, "dec"   , (void*) instr_dec , VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0105300, 0105377, "decb"  , (void*) instr_decb, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0005400, 0005477, "neg"   , (void*) instr_neg , VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0105400, 0105477, "negb"  , (void*) instr_negb, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0005500, 0005577, "adc"   , (void*) instr_adc , VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0105500, 0105577, "adcb"  , (void*) instr_adcb, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0005600, 0005677, "sbc"   , (void*) instr_sbc , VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0105600, 0105677, "sbcb"  , (void*) instr_sbcb, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0005700, 0005777, "tst"   , (void*) instr_tst , VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0105700, 0105777, "tstb"  , (void*) instr_tstb, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0006000, 0006077, "ror"   , (void*) instr_ror , VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0106000, 0106077, "rorb"  , (void*) instr_rorb, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0006100, 0006177, "rol"   , (void*) instr_rol , VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0106100, 0106177, "rolb"  , (void*) instr_rolb, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0006200, 0006277, "asr"   , (void*) instr_asr , VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0106200, 0106277, "asrb"  , (void*) instr_asrb, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0006300, 0006377, "asl"   , (void*) instr_asl , VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0106300, 0106377, "aslb"  , (void*) instr_aslb, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0006700, 0006777, "sxt"   , (void*) instr_sxt , VCPU_INSTR_TYPE_SINGLE_OPERAND },

    { 0000400, 0000777, "br"  , (void*) instr_br  , VCPU_INSTR_TYPE_BRANCH },
    { 0001000, 0001377, "bne" , (void*) instr_bne , VCPU_INSTR_TYPE_BRANCH },
    { 0001400, 0001777, "beq" , (void*) instr_beq , VCPU_INSTR_TYPE_BRANCH },
    { 0002000, 0002377, "bge" , (void*) instr_bge , VCPU_INSTR_TYPE_BRANCH },
    { 0002400, 0002777, "blt" , (void*) instr_blt , VCPU_INSTR_TYPE_BRANCH },
    { 0003000, 0003377, "bgt" , (void*) instr_bgt , VCPU_INSTR_TYPE_BRANCH },
    { 0003400, 0003777, "ble" , (void*) instr_ble , VCPU_INSTR_TYPE_BRANCH },
    { 0100000, 0100377, "bpl" , (void*) instr_bpl , VCPU_INSTR_TYPE_BRANCH },
    { 0100400, 0100777, "bmi" , (void*) instr_bmi , VCPU_INSTR_TYPE_BRANCH },
    { 0101000, 0101377, "bhi" , (void*) instr_bhi , VCPU_INSTR_TYPE_BRANCH },
    { 0101400, 0101777, "blos", (void*) instr_blos, VCPU_INSTR_TYPE_BRANCH },
    { 0102000, 0102377, "bvc" , (void*) instr_bvc , VCPU_INSTR_TYPE_BRANCH },
    { 0102400, 0102777, "bvs" , (void*) instr_bvs , VCPU_INSTR_TYPE_BRANCH },
    { 0103000, 0103377, "bcc/bhis", (void*) instr_bcc, VCPU_INSTR_TYPE_BRANCH },
    { 0103400, 0103777, "bcs/blo" , (void*) instr_bcs, VCPU_INSTR_TYPE_BRANCH },

    // subroutine
    { 0000100, 0000177, "jmp" , NULL, VCPU_INSTR_TYPE_SINGLE_OPERAND }, // TODO: implement all
    { 0004000, 0004777, "jsr" , NULL, VCPU_INSTR_TYPE_OPERAND_REGISTER  },
    { 0000200, 0000207, "rts" , NULL, VCPU_INSTR_TYPE_REGISTER  },
    { 0006400, 0006477, "mark", NULL, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0077000, 0077777, "sob" , NULL, VCPU_INSTR_TYPE_OPERAND_REGISTER },

    // interrupts
    { 0000002, 0000002, "rti", NULL, VCPU_INSTR_TYPE_WITHOUT_PARAMETERS },
    { 0000006, 0000006, "rtt", NULL, VCPU_INSTR_TYPE_WITHOUT_PARAMETERS },

    // other
    { 0000000, 0000000, "halt" , NULL, VCPU_INSTR_TYPE_WITHOUT_PARAMETERS },
    { 0000001, 0000001, "wait" , NULL, VCPU_INSTR_TYPE_WITHOUT_PARAMETERS },
    { 0000005, 0000005, "reset", NULL, VCPU_INSTR_TYPE_WITHOUT_PARAMETERS },

    { 0000240, 0000277, "condition code operations", NULL, VCPU_INSTR_TYPE_NOT_IMPLEMENTED },

    // Not implemented:
    { 0104000, 0104377, "unimplemented: emp" , NULL, VCPU_INSTR_TYPE_NOT_IMPLEMENTED },
    { 0104400, 0104777, "unimplemented: trap", NULL, VCPU_INSTR_TYPE_NOT_IMPLEMENTED },
    { 0000003, 0000003, "unimplemented: bpt" , NULL, VCPU_INSTR_TYPE_NOT_IMPLEMENTED },
    { 0000004, 0000004, "unimplemented: iot" , NULL, VCPU_INSTR_TYPE_NOT_IMPLEMENTED },

    { 0075000, 0075777, "floating-point operations (1)", NULL, VCPU_INSTR_TYPE_NOT_IMPLEMENTED },
    { 0170000, 0177777, "floating-point operations (2)", NULL, VCPU_INSTR_TYPE_NOT_IMPLEMENTED },
    { 0076000, 0076777, "system instructions"          , NULL, VCPU_INSTR_TYPE_NOT_IMPLEMENTED },

    { 0000007, 0000007, "mfpt"  , NULL, VCPU_INSTR_TYPE_NOT_IMPLEMENTED },
    { 0000230, 0000237, "spl"   , NULL, VCPU_INSTR_TYPE_NOT_IMPLEMENTED },
    { 0106700, 0106777, "mfps"  , NULL, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0106400, 0106477, "mtps"  , NULL, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0006500, 0006577, "mfpi"  , NULL, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0106500, 0106577, "mfpd"  , NULL, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0006600, 0006677, "mtpi"  , NULL, VCPU_INSTR_TYPE_SINGLE_OPERAND },
    { 0106600, 0106677, "mtpd"  , NULL, VCPU_INSTR_TYPE_SINGLE_OPERAND },

    { 0000010, 0000077, "", NULL, VCPU_INSTR_TYPE_INVALID_OPCODE },
    { 0000210, 0000227, "", NULL, VCPU_INSTR_TYPE_INVALID_OPCODE },
    { 0007000, 0007777, "", NULL, VCPU_INSTR_TYPE_INVALID_OPCODE },
    { 0107000, 0107777, "", NULL, VCPU_INSTR_TYPE_INVALID_OPCODE },
};

int VCPU_NUM_INSTRUCTIONS_IN_TABLE = sizeof (VCPU_INSTRUCTIONS) / sizeof(InstructionInfo);
