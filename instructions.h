#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "utils.h"
#include "memregion.h"
#include <string>

enum InstructionType
{
    VCPU_INSTR_TYPE_NOT_INITIALIZED,
    VCPU_INSTR_TYPE_NOT_IMPLEMENTED,
    VCPU_INSTR_TYPE_INVALID_OPCODE,
    VCPU_INSTR_TYPE_DOUBLE_OPERAND,
    VCPU_INSTR_TYPE_OPERAND_REGISTER,
    VCPU_INSTR_TYPE_SINGLE_OPERAND,
    VCPU_INSTR_TYPE_REGISTER,
    VCPU_INSTR_TYPE_WITHOUT_PARAMETERS,
    VCPU_INSTR_TYPE_BRANCH
};

struct InstructionInfo
{
    uint16_t begin;
    uint16_t end;
    std::string name;
    void* callback;
    InstructionType type;
};

extern InstructionInfo VCPU_INSTRUCTIONS[];
extern int VCPU_NUM_INSTRUCTIONS_IN_TABLE;

struct VcpuPSW
{
    bool n;
    bool z;
    bool v;
    bool c;
};

typedef bool vcpu_instr_double_operand_callback(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
typedef bool vcpu_instr_operand_register_callback(bool onereg, MemRegion& reg, MemRegion& reg2, MemRegion& src, VcpuPSW& psw);
typedef bool vcpu_instr_single_operand_callback(MemRegion& data, VcpuPSW& psw);
typedef bool vcpu_instr_without_parameters_callback(uint16_t instr, Vcpu& cpu);
typedef bool vcpu_instr_branch_callback(uint16_t& pc, int8_t offset, VcpuPSW& psw);

// VCPU_INSTR_TYPE_DOUBLE_OPERAND
bool instr_mov(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
bool instr_movb(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
bool instr_cmp(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
bool instr_cmpb(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
bool instr_bit(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
bool instr_bitb(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
bool instr_bic(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
bool instr_bicb(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
bool instr_bis(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
bool instr_bisb(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
bool instr_add(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
bool instr_addb(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
bool instr_sub(MemRegion& dst, MemRegion& src, VcpuPSW& psw);
bool instr_subb(MemRegion& dst, MemRegion& src, VcpuPSW& psw);

// VCPU_INSTR_TYPE_OPERAND_REGISTER
bool instr_mul(bool onereg, MemRegion& reg, MemRegion& reg2, MemRegion& src, VcpuPSW& psw);
bool instr_div(bool onereg, MemRegion& reg, MemRegion& reg2, MemRegion& src, VcpuPSW& psw);
bool instr_ash(bool onereg, MemRegion& reg, MemRegion& reg2, MemRegion& src, VcpuPSW& psw);
bool instr_ashc(bool onereg, MemRegion& reg, MemRegion& reg2, MemRegion& src, VcpuPSW& psw);
bool instr_xor(bool onereg, MemRegion& reg, MemRegion& reg2, MemRegion& src, VcpuPSW& psw);

// VCPU_INSTR_TYPE_SINGLE_OPERAND
bool instr_clr(MemRegion& data, VcpuPSW& psw);
bool instr_clrb(MemRegion& data, VcpuPSW& psw);
bool instr_com(MemRegion& data, VcpuPSW& psw);
bool instr_comb(MemRegion& data, VcpuPSW& psw);
bool instr_inc(MemRegion& data, VcpuPSW& psw);
bool instr_incb(MemRegion& data, VcpuPSW& psw);
bool instr_dec(MemRegion& data, VcpuPSW& psw);
bool instr_decb(MemRegion& data, VcpuPSW& psw);
bool instr_neg(MemRegion& data, VcpuPSW& psw);
bool instr_negb(MemRegion& data, VcpuPSW& psw);
bool instr_tst(MemRegion& data, VcpuPSW& psw);
bool instr_tstb(MemRegion& data, VcpuPSW& psw);
bool instr_asr(MemRegion& data, VcpuPSW& psw);
bool instr_asrb(MemRegion& data, VcpuPSW& psw);
bool instr_asl(MemRegion& data, VcpuPSW& psw);
bool instr_aslb(MemRegion& data, VcpuPSW& psw);
bool instr_ror(MemRegion& data, VcpuPSW& psw);
bool instr_rorb(MemRegion& data, VcpuPSW& psw);
bool instr_rol(MemRegion& data, VcpuPSW& psw);
bool instr_rolb(MemRegion& data, VcpuPSW& psw);
bool instr_swab(MemRegion& data, VcpuPSW& psw);
bool instr_adc(MemRegion& data, VcpuPSW& psw);
bool instr_adcb(MemRegion& data, VcpuPSW& psw);
bool instr_sbc(MemRegion& data, VcpuPSW& psw);
bool instr_sbcb(MemRegion& data, VcpuPSW& psw);
bool instr_sxt(MemRegion& data, VcpuPSW& psw);

// VCPU_INSTR_TYPE_BRANCH
bool instr_br(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_bne(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_beq(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_bpl(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_bmi(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_bvc(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_bvs(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_bcc(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_bcs(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_bge(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_blt(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_bgt(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_ble(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_bhi(uint16_t& pc, int8_t offset, VcpuPSW& psw);
bool instr_blos(uint16_t& pc, int8_t offset, VcpuPSW& psw);

// Other
bool instr_nop(uint16_t instr, Vcpu& cpu);
bool instr_condition_code_operation(uint16_t instr, Vcpu& cpu);
bool instr_halt(uint16_t instr, Vcpu& cpu);

#endif // INSTRUCTIONS_H
