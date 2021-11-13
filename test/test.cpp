/**
 * Copyright (c) 2011-2021 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <boost/test/unit_test.hpp>

#include "test.hpp"

// ----------------------------------------------------------------------------
// decode_base16: derived from libbitcoin::system

constexpr size_t byte_bits = 8;
constexpr size_t octet_width = 2;

inline bool is_between(uint8_t value, uint8_t low, uint8_t high)
{
    return low <= value && value <= high;
}

static uint8_t from_base16_characters(char high, char low)
{
    const auto from_base16_digit = [](char character)
    {
        if (is_between(character, 'A', 'F'))
            return character - 'A' + '\xA';

        if (is_between(character, 'a', 'f'))
            return character - 'a' + '\xa';

        return character - '0' + '\x0';
    };

    return (from_base16_digit(high) << (byte_bits / 2)) |
        from_base16_digit(low);
}

static bool is_base16(char character)
{
    return
        (is_between(character, '0', '9')) ||
        (is_between(character, 'a', 'f')) ||
        (is_between(character, 'A', 'F'));
}

bool decode_base16(data_chunk& out, const std::string& in)
{
    if (in.size() % 2 != 0)
        return false;

    if (!std::all_of(in.begin(), in.end(), is_base16))
        return false;

    out.resize(in.size() / 2);
    auto data = out.begin();

    for (auto digit = in.begin(); digit != in.end();)
    {
        const auto hi = *digit++;
        const auto lo = *digit++;
        *data++ = from_base16_characters(hi, lo);
    }

    return true;
}

// ----------------------------------------------------------------------------
// mnemonic_to_data: derived from libbitcoin::system::chain

inline void ascii_lower_case(std::string& text)
{
    std::transform(text.begin(), text.end(), text.begin(),
        [](unsigned char character)
        {
            return std::tolower(character);
        });
}

inline bool is_ascii_numeric(const std::string& text)
{
    if (text.empty())
        return true;

    const auto negative = (text.front() == '-');
    const auto start = std::next(text.begin(), negative ? 1 : 0);
    return std::all_of(start, text.end(), [](char character)
    {
        return '0' <= character && character <= '9';
    });
}

// domain-specific no-dependency splitter
static std::vector<std::string> split(const std::string& mnemonic,
    char delimiter, bool trail=false)
{
    std::istringstream stream(mnemonic);
    std::vector<std::string> stack;
    std::string token;

    while (true)
    {
        stream >> std::ws;
        if (!std::getline(stream, token, delimiter))
        {
            // Handle case of trailing delimiter.
            if (trail && stack.size() == 1 &&
                mnemonic.find(delimiter) != std::string::npos)
                stack.push_back("");

            return stack;
        }

        stack.push_back(token);
    }
}

inline size_t floored_log2(uint64_t value)
{
    if (value < 1)
        return 0;

    size_t exponent = 0;
    while (((value >>= 1)) > 0) { ++exponent; };
    return exponent;
}

inline size_t bit_width(uint64_t value)
{
    return floored_log2(value) + 1;
}

constexpr size_t ceilinged_divide(size_t dividend, uint8_t divisor)
{
    return (dividend / divisor) + 1;
}

inline size_t byte_width(uint64_t value)
{
    return ceilinged_divide(bit_width(value), byte_bits);
}

static void to_little_endian(data_chunk& out, size_t value) noexcept
{
    for (auto& byte: out)
    {
        byte = static_cast<uint8_t>(value);
        value >>= byte_bits;
    }
}

enum class opcode: uint8_t
{
    //-------------------------------------------------------------------------
    // is_relaxed_push, is_push (excluding reserved_80)

    push_size_0 = 0,        // is_version (pushes [] to the stack, not 0)
    push_size_1 = 1,
    push_size_2 = 2,
    push_size_3 = 3,
    push_size_4 = 4,
    push_size_5 = 5,
    push_size_6 = 6,
    push_size_7 = 7,
    push_size_8 = 8,
    push_size_9 = 9,
    push_size_10 = 10,
    push_size_11 = 11,
    push_size_12 = 12,
    push_size_13 = 13,
    push_size_14 = 14,
    push_size_15 = 15,
    push_size_16 = 16,
    push_size_17 = 17,
    push_size_18 = 18,
    push_size_19 = 19,
    push_size_20 = 20,
    push_size_21 = 21,
    push_size_22 = 22,
    push_size_23 = 23,
    push_size_24 = 24,
    push_size_25 = 25,
    push_size_26 = 26,
    push_size_27 = 27,
    push_size_28 = 28,
    push_size_29 = 29,
    push_size_30 = 30,
    push_size_31 = 31,
    push_size_32 = 32,
    push_size_33 = 33,
    push_size_34 = 34,
    push_size_35 = 35,
    push_size_36 = 36,
    push_size_37 = 37,
    push_size_38 = 38,
    push_size_39 = 39,
    push_size_40 = 40,
    push_size_41 = 41,
    push_size_42 = 42,
    push_size_43 = 43,
    push_size_44 = 44,
    push_size_45 = 45,
    push_size_46 = 46,
    push_size_47 = 47,
    push_size_48 = 48,
    push_size_49 = 49,
    push_size_50 = 50,
    push_size_51 = 51,
    push_size_52 = 52,
    push_size_53 = 53,
    push_size_54 = 54,
    push_size_55 = 55,
    push_size_56 = 56,
    push_size_57 = 57,
    push_size_58 = 58,
    push_size_59 = 59,
    push_size_60 = 60,
    push_size_61 = 61,
    push_size_62 = 62,
    push_size_63 = 63,
    push_size_64 = 64,
    push_size_65 = 65,
    push_size_66 = 66,
    push_size_67 = 67,
    push_size_68 = 68,
    push_size_69 = 69,
    push_size_70 = 70,
    push_size_71 = 71,
    push_size_72 = 72,
    push_size_73 = 73,
    push_size_74 = 74,
    push_size_75 = 75,
    push_one_size = 76,
    push_two_size = 77,
    push_four_size = 78,
    push_negative_1 = 79,   // is_numeric
    reserved_80 = 80,       // is_reserved [op_reserved]
    push_positive_1 = 81,   // is_numeric, is_positive, is_version
    push_positive_2 = 82,   // is_numeric, is_positive, is_version
    push_positive_3 = 83,   // is_numeric, is_positive, is_version
    push_positive_4 = 84,   // is_numeric, is_positive, is_version
    push_positive_5 = 85,   // is_numeric, is_positive, is_version
    push_positive_6 = 86,   // is_numeric, is_positive, is_version
    push_positive_7 = 87,   // is_numeric, is_positive, is_version
    push_positive_8 = 88,   // is_numeric, is_positive, is_version
    push_positive_9 = 89,   // is_numeric, is_positive, is_version
    push_positive_10 = 90,  // is_numeric, is_positive, is_version
    push_positive_11 = 91,  // is_numeric, is_positive, is_version
    push_positive_12 = 92,  // is_numeric, is_positive, is_version
    push_positive_13 = 93,  // is_numeric, is_positive, is_version
    push_positive_14 = 94,  // is_numeric, is_positive, is_version
    push_positive_15 = 95,  // is_numeric, is_positive, is_version
    push_positive_16 = 96,  // is_numeric, is_positive, is_version

    //-------------------------------------------------------------------------
    // is_counted [notice that reserved_80 is not counted]

    nop = 97,
    op_ver = 98,            // is_reserved [disabled in 0.3.6]
    if_ = 99,               // is_conditional
    notif = 100,            // is_conditional
    op_verif = 101,         // is_invalid [disabled in 0.3.6]
    op_vernotif = 102,      // is_invalid [disabled in 0.3.6]
    else_ = 103,            // is_conditional
    endif = 104,            // is_conditional
    verify = 105,
    op_return = 106,        // is_reserved [disabled in 0.3.6]
    toaltstack = 107,
    fromaltstack = 108,
    drop2 = 109,
    dup2 = 110,
    dup3 = 111,
    over2 = 112,
    rot2 = 113,
    swap2 = 114,
    ifdup = 115,
    depth = 116,
    drop = 117,
    dup = 118,
    nip = 119,
    over = 120,
    pick = 121,
    roll = 122,
    rot = 123,
    swap = 124,
    tuck = 125,
    op_cat = 126,           // is_invalid [disabled in 0.3.10]
    op_substr = 127,        // is_invalid [disabled in 0.3.10]
    op_left = 128,          // is_invalid [disabled in 0.3.10]
    op_right = 129,         // is_invalid [disabled in 0.3.10]
    size = 130,
    op_invert = 131,        // is_invalid [disabled in 0.3.10]
    op_and = 132,           // is_invalid [disabled in 0.3.10]
    op_or = 133,            // is_invalid [disabled in 0.3.10]
    op_xor = 134,           // is_invalid [disabled in 0.3.10]
    equal = 135,
    equalverify = 136,
    reserved_137 = 137,     // is_reserved [op_reserved1]
    reserved_138 = 138,     // is_reserved [op_reserved2]
    add1 = 139,
    sub1 = 140,
    op_mul2 = 141,          // is_invalid [disabled in 0.3.10]
    op_div2 = 142,          // is_invalid [disabled in 0.3.10]
    negate = 143,
    abs = 144,
    not_ = 145,
    nonzero = 146,
    add = 147,
    sub = 148,
    op_mul = 149,           // is_invalid [disabled in 0.3.10]
    op_div = 150,           // is_invalid [disabled in 0.3.10]
    op_mod = 151,           // is_invalid [disabled in 0.3.10]
    op_lshift = 152,        // is_invalid [disabled in 0.3.10]
    op_rshift = 153,        // is_invalid [disabled in 0.3.10]
    booland = 154,
    boolor = 155,
    numequal = 156,
    numequalverify = 157,
    numnotequal = 158,
    lessthan = 159,
    greaterthan = 160,
    lessthanorequal = 161,
    greaterthanorequal = 162,
    min = 163,
    max = 164,
    within = 165,
    ripemd160 = 166,
    sha1 = 167,
    sha256 = 168,
    hash160 = 169,
    hash256 = 170,
    codeseparator = 171,
    checksig = 172,
    checksigverify = 173,
    checkmultisig = 174,
    checkmultisigverify = 175,

    //-------------------------------------------------------------------------
    // Promoted from reserved to nop by [0.3.6] hard fork.

    nop1 = 176,
    nop2 = 177,
    checklocktimeverify = nop2,
    nop3 = 178,
    checksequenceverify = nop3,
    nop4 = 179,
    nop5 = 180,
    nop6 = 181,
    nop7 = 182,
    nop8 = 183,
    nop9 = 184,
    nop10 = 185,

    //-------------------------------------------------------------------------
    // These are enumerated to provide explicit deserialization of byte opcode.
    // is_reserved [unnamed]

    reserved_186 = 186,     // To be subsumed by bip342 (tapscript).
    reserved_187 = 187,
    reserved_188 = 188,
    reserved_189 = 189,
    reserved_190 = 190,
    reserved_191 = 191,
    reserved_192 = 192,
    reserved_193 = 193,
    reserved_194 = 194,
    reserved_195 = 195,
    reserved_196 = 196,
    reserved_197 = 197,
    reserved_198 = 198,
    reserved_199 = 199,
    reserved_200 = 200,
    reserved_201 = 201,
    reserved_202 = 202,
    reserved_203 = 203,
    reserved_204 = 204,
    reserved_205 = 205,
    reserved_206 = 206,
    reserved_207 = 207,
    reserved_208 = 208,
    reserved_209 = 209,
    reserved_210 = 210,
    reserved_211 = 211,
    reserved_212 = 212,
    reserved_213 = 213,
    reserved_214 = 214,
    reserved_215 = 215,
    reserved_216 = 216,
    reserved_217 = 217,
    reserved_218 = 218,
    reserved_219 = 219,
    reserved_220 = 220,
    reserved_221 = 221,
    reserved_222 = 222,
    reserved_223 = 223,
    reserved_224 = 224,
    reserved_225 = 225,
    reserved_226 = 226,
    reserved_227 = 227,
    reserved_228 = 228,
    reserved_229 = 229,
    reserved_230 = 230,
    reserved_231 = 231,
    reserved_232 = 232,
    reserved_233 = 233,
    reserved_234 = 234,
    reserved_235 = 235,
    reserved_236 = 236,
    reserved_237 = 237,
    reserved_238 = 238,
    reserved_239 = 239,
    reserved_240 = 240,
    reserved_241 = 241,
    reserved_242 = 242,
    reserved_243 = 243,
    reserved_244 = 244,
    reserved_245 = 245,
    reserved_246 = 246,
    reserved_247 = 247,
    reserved_248 = 248,
    reserved_249 = 249,
    reserved_250 = 250,
    reserved_251 = 251,
    reserved_252 = 252,
    reserved_253 = 253,
    reserved_254 = 254,
    reserved_255 = 255
};

static bool opcode_from_hexadecimal(opcode& out_code, const std::string& value)
{
    if (value.size() != 4 || value[0] != '0' || value[1] != 'x')
        return false;

    data_chunk out;
    if (!decode_base16(out, { std::next(value.begin(), octet_width), value.end() }))
        return false;

    out_code = static_cast<opcode>(out.front());
    return true;
}

static bool opcode_from_mnemonic(opcode& out_code, std::string value)
{
#define RETURN_IF_OPCODE(text, code) \
if (value == text) { out_code = opcode::code; return true; }

#define RETURN_IF_OPCODE_OR_ALIAS(text, alias, code) \
if (value == text || value == alias) { out_code = opcode::code; return true; }

    ascii_lower_case(value);

    RETURN_IF_OPCODE("zero", push_size_0);
    RETURN_IF_OPCODE("push_0", push_size_0);
    RETURN_IF_OPCODE("push_1", push_size_1);
    RETURN_IF_OPCODE("push_2", push_size_2);
    RETURN_IF_OPCODE("push_3", push_size_3);
    RETURN_IF_OPCODE("push_4", push_size_4);
    RETURN_IF_OPCODE("push_5", push_size_5);
    RETURN_IF_OPCODE("push_6", push_size_6);
    RETURN_IF_OPCODE("push_7", push_size_7);
    RETURN_IF_OPCODE("push_8", push_size_8);
    RETURN_IF_OPCODE("push_9", push_size_9);
    RETURN_IF_OPCODE("push_10", push_size_10);
    RETURN_IF_OPCODE("push_11", push_size_11);
    RETURN_IF_OPCODE("push_12", push_size_12);
    RETURN_IF_OPCODE("push_13", push_size_13);
    RETURN_IF_OPCODE("push_14", push_size_14);
    RETURN_IF_OPCODE("push_15", push_size_15);
    RETURN_IF_OPCODE("push_16", push_size_16);
    RETURN_IF_OPCODE("push_17", push_size_17);
    RETURN_IF_OPCODE("push_18", push_size_18);
    RETURN_IF_OPCODE("push_19", push_size_19);
    RETURN_IF_OPCODE("push_20", push_size_20);
    RETURN_IF_OPCODE("push_21", push_size_21);
    RETURN_IF_OPCODE("push_22", push_size_22);
    RETURN_IF_OPCODE("push_23", push_size_23);
    RETURN_IF_OPCODE("push_24", push_size_24);
    RETURN_IF_OPCODE("push_25", push_size_25);
    RETURN_IF_OPCODE("push_26", push_size_26);
    RETURN_IF_OPCODE("push_27", push_size_27);
    RETURN_IF_OPCODE("push_28", push_size_28);
    RETURN_IF_OPCODE("push_29", push_size_29);
    RETURN_IF_OPCODE("push_30", push_size_30);
    RETURN_IF_OPCODE("push_31", push_size_31);
    RETURN_IF_OPCODE("push_32", push_size_32);
    RETURN_IF_OPCODE("push_33", push_size_33);
    RETURN_IF_OPCODE("push_34", push_size_34);
    RETURN_IF_OPCODE("push_35", push_size_35);
    RETURN_IF_OPCODE("push_36", push_size_36);
    RETURN_IF_OPCODE("push_37", push_size_37);
    RETURN_IF_OPCODE("push_38", push_size_38);
    RETURN_IF_OPCODE("push_39", push_size_39);
    RETURN_IF_OPCODE("push_40", push_size_40);
    RETURN_IF_OPCODE("push_41", push_size_41);
    RETURN_IF_OPCODE("push_42", push_size_42);
    RETURN_IF_OPCODE("push_43", push_size_43);
    RETURN_IF_OPCODE("push_44", push_size_44);
    RETURN_IF_OPCODE("push_45", push_size_45);
    RETURN_IF_OPCODE("push_46", push_size_46);
    RETURN_IF_OPCODE("push_47", push_size_47);
    RETURN_IF_OPCODE("push_48", push_size_48);
    RETURN_IF_OPCODE("push_49", push_size_49);
    RETURN_IF_OPCODE("push_50", push_size_50);
    RETURN_IF_OPCODE("push_51", push_size_51);
    RETURN_IF_OPCODE("push_52", push_size_52);
    RETURN_IF_OPCODE("push_53", push_size_53);
    RETURN_IF_OPCODE("push_54", push_size_54);
    RETURN_IF_OPCODE("push_55", push_size_55);
    RETURN_IF_OPCODE("push_56", push_size_56);
    RETURN_IF_OPCODE("push_57", push_size_57);
    RETURN_IF_OPCODE("push_58", push_size_58);
    RETURN_IF_OPCODE("push_59", push_size_59);
    RETURN_IF_OPCODE("push_60", push_size_60);
    RETURN_IF_OPCODE("push_61", push_size_61);
    RETURN_IF_OPCODE("push_62", push_size_62);
    RETURN_IF_OPCODE("push_63", push_size_63);
    RETURN_IF_OPCODE("push_64", push_size_64);
    RETURN_IF_OPCODE("push_65", push_size_65);
    RETURN_IF_OPCODE("push_66", push_size_66);
    RETURN_IF_OPCODE("push_67", push_size_67);
    RETURN_IF_OPCODE("push_68", push_size_68);
    RETURN_IF_OPCODE("push_69", push_size_69);
    RETURN_IF_OPCODE("push_70", push_size_70);
    RETURN_IF_OPCODE("push_71", push_size_71);
    RETURN_IF_OPCODE("push_72", push_size_72);
    RETURN_IF_OPCODE("push_73", push_size_73);
    RETURN_IF_OPCODE("push_74", push_size_74);
    RETURN_IF_OPCODE("push_75", push_size_75);
    RETURN_IF_OPCODE_OR_ALIAS("push_one", "pushdata1", push_one_size);
    RETURN_IF_OPCODE_OR_ALIAS("push_two", "pushdata2", push_two_size);
    RETURN_IF_OPCODE_OR_ALIAS("push_four", "pushdata4", push_four_size);
    RETURN_IF_OPCODE("-1", push_negative_1);
    RETURN_IF_OPCODE_OR_ALIAS("reserved_80", "reserved", reserved_80);
    RETURN_IF_OPCODE("0", push_size_0);
    RETURN_IF_OPCODE("1", push_positive_1);
    RETURN_IF_OPCODE("2", push_positive_2);
    RETURN_IF_OPCODE("3", push_positive_3);
    RETURN_IF_OPCODE("4", push_positive_4);
    RETURN_IF_OPCODE("5", push_positive_5);
    RETURN_IF_OPCODE("6", push_positive_6);
    RETURN_IF_OPCODE("7", push_positive_7);
    RETURN_IF_OPCODE("8", push_positive_8);
    RETURN_IF_OPCODE("9", push_positive_9);
    RETURN_IF_OPCODE("10", push_positive_10);
    RETURN_IF_OPCODE("11", push_positive_11);
    RETURN_IF_OPCODE("12", push_positive_12);
    RETURN_IF_OPCODE("13", push_positive_13);
    RETURN_IF_OPCODE("14", push_positive_14);
    RETURN_IF_OPCODE("15", push_positive_15);
    RETURN_IF_OPCODE("16", push_positive_16);
    RETURN_IF_OPCODE("nop", nop);
    RETURN_IF_OPCODE_OR_ALIAS("op_ver", "ver", op_ver);
    RETURN_IF_OPCODE("if", if_);
    RETURN_IF_OPCODE("notif", notif);
    RETURN_IF_OPCODE_OR_ALIAS("op_verif", "verif", op_verif);
    RETURN_IF_OPCODE_OR_ALIAS("op_vernotif", "vernotif", op_vernotif);
    RETURN_IF_OPCODE("else", else_);
    RETURN_IF_OPCODE("endif", endif);
    RETURN_IF_OPCODE("verify", verify);
    RETURN_IF_OPCODE("return", op_return);
    RETURN_IF_OPCODE("toaltstack", toaltstack);
    RETURN_IF_OPCODE("fromaltstack", fromaltstack);
    RETURN_IF_OPCODE_OR_ALIAS("drop2", "2drop", drop2);
    RETURN_IF_OPCODE_OR_ALIAS("dup2", "2dup", dup2);
    RETURN_IF_OPCODE_OR_ALIAS("dup3", "3dup", dup3);
    RETURN_IF_OPCODE_OR_ALIAS("over2", "2over", over2);
    RETURN_IF_OPCODE_OR_ALIAS("rot2", "2rot", rot2);
    RETURN_IF_OPCODE_OR_ALIAS("swap2", "2swap", swap2);
    RETURN_IF_OPCODE("ifdup", ifdup);
    RETURN_IF_OPCODE("depth", depth);
    RETURN_IF_OPCODE("drop", drop);
    RETURN_IF_OPCODE("dup", dup);
    RETURN_IF_OPCODE("nip", nip);
    RETURN_IF_OPCODE("over", over);
    RETURN_IF_OPCODE("pick", pick);
    RETURN_IF_OPCODE("roll", roll);
    RETURN_IF_OPCODE("rot", rot);
    RETURN_IF_OPCODE("swap", swap);
    RETURN_IF_OPCODE("tuck", tuck);
    RETURN_IF_OPCODE("cat", op_cat);
    RETURN_IF_OPCODE("substr", op_substr);
    RETURN_IF_OPCODE("left", op_left);
    RETURN_IF_OPCODE("right", op_right);
    RETURN_IF_OPCODE("size", size);
    RETURN_IF_OPCODE("invert", op_invert);
    RETURN_IF_OPCODE("and", op_and);
    RETURN_IF_OPCODE("or", op_or);
    RETURN_IF_OPCODE("xor", op_xor);
    RETURN_IF_OPCODE("equal", equal);
    RETURN_IF_OPCODE("equalverify", equalverify);
    RETURN_IF_OPCODE_OR_ALIAS("reserved_137", "reserved1", reserved_137);
    RETURN_IF_OPCODE_OR_ALIAS("reserved_138", "reserved2", reserved_138);
    RETURN_IF_OPCODE_OR_ALIAS("add1", "1add", add1);
    RETURN_IF_OPCODE_OR_ALIAS("sub1", "1sub", sub1);
    RETURN_IF_OPCODE_OR_ALIAS("mul2", "2mul", op_mul2);
    RETURN_IF_OPCODE_OR_ALIAS("div2", "2div", op_div2);
    RETURN_IF_OPCODE("negate", negate);
    RETURN_IF_OPCODE("abs", abs);
    RETURN_IF_OPCODE("not", not_);
    RETURN_IF_OPCODE_OR_ALIAS("nonzero", "0notequal", nonzero);
    RETURN_IF_OPCODE("add", add);
    RETURN_IF_OPCODE("sub", sub);
    RETURN_IF_OPCODE("mul", op_mul);
    RETURN_IF_OPCODE("div", op_div);
    RETURN_IF_OPCODE("mod", op_mod);
    RETURN_IF_OPCODE("lshift", op_lshift);
    RETURN_IF_OPCODE("rshift", op_rshift);
    RETURN_IF_OPCODE("booland", booland);
    RETURN_IF_OPCODE("boolor", boolor);
    RETURN_IF_OPCODE("numequal", numequal);
    RETURN_IF_OPCODE("numequalverify", numequalverify);
    RETURN_IF_OPCODE("numnotequal", numnotequal);
    RETURN_IF_OPCODE("lessthan", lessthan);
    RETURN_IF_OPCODE("greaterthan", greaterthan);
    RETURN_IF_OPCODE("lessthanorequal", lessthanorequal);
    RETURN_IF_OPCODE("greaterthanorequal", greaterthanorequal);
    RETURN_IF_OPCODE("min", min);
    RETURN_IF_OPCODE("max", max);
    RETURN_IF_OPCODE("within", within);
    RETURN_IF_OPCODE("ripemd160", ripemd160);
    RETURN_IF_OPCODE("sha1", sha1);
    RETURN_IF_OPCODE("sha256", sha256);
    RETURN_IF_OPCODE("hash160", hash160);
    RETURN_IF_OPCODE("hash256", hash256);
    RETURN_IF_OPCODE("codeseparator", codeseparator);
    RETURN_IF_OPCODE("checksig", checksig);
    RETURN_IF_OPCODE("checksigverify", checksigverify);
    RETURN_IF_OPCODE("checkmultisig", checkmultisig);
    RETURN_IF_OPCODE("checkmultisigverify", checkmultisigverify);
    RETURN_IF_OPCODE("nop1", nop1);
    RETURN_IF_OPCODE_OR_ALIAS("checklocktimeverify", "nop2", checklocktimeverify);
    RETURN_IF_OPCODE_OR_ALIAS("checksequenceverify", "nop3", checksequenceverify);
    RETURN_IF_OPCODE("nop4", nop4);
    RETURN_IF_OPCODE("nop5", nop5);
    RETURN_IF_OPCODE("nop6", nop6);
    RETURN_IF_OPCODE("nop7", nop7);
    RETURN_IF_OPCODE("nop8", nop8);
    RETURN_IF_OPCODE("nop9", nop9);
    RETURN_IF_OPCODE("nop10", nop10);
    RETURN_IF_OPCODE("reserved_186", reserved_186);
    RETURN_IF_OPCODE("reserved_187", reserved_187);
    RETURN_IF_OPCODE("reserved_188", reserved_188);
    RETURN_IF_OPCODE("reserved_189", reserved_189);
    RETURN_IF_OPCODE("reserved_190", reserved_190);
    RETURN_IF_OPCODE("reserved_191", reserved_191);
    RETURN_IF_OPCODE("reserved_192", reserved_192);
    RETURN_IF_OPCODE("reserved_193", reserved_193);
    RETURN_IF_OPCODE("reserved_194", reserved_194);
    RETURN_IF_OPCODE("reserved_195", reserved_195);
    RETURN_IF_OPCODE("reserved_196", reserved_196);
    RETURN_IF_OPCODE("reserved_197", reserved_197);
    RETURN_IF_OPCODE("reserved_198", reserved_198);
    RETURN_IF_OPCODE("reserved_199", reserved_199);
    RETURN_IF_OPCODE("reserved_200", reserved_200);
    RETURN_IF_OPCODE("reserved_201", reserved_201);
    RETURN_IF_OPCODE("reserved_202", reserved_202);
    RETURN_IF_OPCODE("reserved_203", reserved_203);
    RETURN_IF_OPCODE("reserved_204", reserved_204);
    RETURN_IF_OPCODE("reserved_205", reserved_205);
    RETURN_IF_OPCODE("reserved_206", reserved_206);
    RETURN_IF_OPCODE("reserved_207", reserved_207);
    RETURN_IF_OPCODE("reserved_208", reserved_208);
    RETURN_IF_OPCODE("reserved_209", reserved_209);
    RETURN_IF_OPCODE("reserved_210", reserved_210);
    RETURN_IF_OPCODE("reserved_211", reserved_211);
    RETURN_IF_OPCODE("reserved_212", reserved_212);
    RETURN_IF_OPCODE("reserved_213", reserved_213);
    RETURN_IF_OPCODE("reserved_214", reserved_214);
    RETURN_IF_OPCODE("reserved_215", reserved_215);
    RETURN_IF_OPCODE("reserved_216", reserved_216);
    RETURN_IF_OPCODE("reserved_217", reserved_217);
    RETURN_IF_OPCODE("reserved_218", reserved_218);
    RETURN_IF_OPCODE("reserved_219", reserved_219);
    RETURN_IF_OPCODE("reserved_220", reserved_220);
    RETURN_IF_OPCODE("reserved_221", reserved_221);
    RETURN_IF_OPCODE("reserved_222", reserved_222);
    RETURN_IF_OPCODE("reserved_223", reserved_223);
    RETURN_IF_OPCODE("reserved_224", reserved_224);
    RETURN_IF_OPCODE("reserved_225", reserved_225);
    RETURN_IF_OPCODE("reserved_226", reserved_226);
    RETURN_IF_OPCODE("reserved_227", reserved_227);
    RETURN_IF_OPCODE("reserved_228", reserved_228);
    RETURN_IF_OPCODE("reserved_229", reserved_229);
    RETURN_IF_OPCODE("reserved_230", reserved_230);
    RETURN_IF_OPCODE("reserved_231", reserved_231);
    RETURN_IF_OPCODE("reserved_232", reserved_232);
    RETURN_IF_OPCODE("reserved_233", reserved_233);
    RETURN_IF_OPCODE("reserved_234", reserved_234);
    RETURN_IF_OPCODE("reserved_235", reserved_235);
    RETURN_IF_OPCODE("reserved_236", reserved_236);
    RETURN_IF_OPCODE("reserved_237", reserved_237);
    RETURN_IF_OPCODE("reserved_238", reserved_238);
    RETURN_IF_OPCODE("reserved_239", reserved_239);
    RETURN_IF_OPCODE("reserved_240", reserved_240);
    RETURN_IF_OPCODE("reserved_241", reserved_241);
    RETURN_IF_OPCODE("reserved_242", reserved_242);
    RETURN_IF_OPCODE("reserved_243", reserved_243);
    RETURN_IF_OPCODE("reserved_244", reserved_244);
    RETURN_IF_OPCODE("reserved_245", reserved_245);
    RETURN_IF_OPCODE("reserved_246", reserved_246);
    RETURN_IF_OPCODE("reserved_247", reserved_247);
    RETURN_IF_OPCODE("reserved_248", reserved_248);
    RETURN_IF_OPCODE("reserved_249", reserved_249);
    RETURN_IF_OPCODE("reserved_250", reserved_250);
    RETURN_IF_OPCODE("reserved_251", reserved_251);
    RETURN_IF_OPCODE("reserved_252", reserved_252);
    RETURN_IF_OPCODE("reserved_253", reserved_253);
    RETURN_IF_OPCODE("reserved_254", reserved_254);
    RETURN_IF_OPCODE("reserved_255", reserved_255);

    // Any hexadecimal byte will parse (hex prefix not lowered).
    return opcode_from_hexadecimal(out_code, value);
}

class operation
{
public:
    operation(const std::string& mnemonic, bool valid=true)
    {
        // Failure of opcode deserialization is caught here.
        BOOST_REQUIRE_MESSAGE(from_string(mnemonic) == valid, mnemonic);
    }

    data_chunk to_data() const
    {
        data_chunk out;
        out.push_back(static_cast<uint8_t>(code_));

        switch (code_)
        {
            case opcode::push_one_size:
            {
                out.push_back(static_cast<uint8_t>(data_.size()));
                break;
            }
            case opcode::push_two_size:
            {
                data_chunk two(sizeof(uint16_t));
                to_little_endian(two, data_.size());
                out.push_back(two[0]);
                out.push_back(two[1]);
                break;
            }
            case opcode::push_four_size:
            {
                data_chunk four(sizeof(uint32_t));
                to_little_endian(four, data_.size());
                out.push_back(four[0]);
                out.push_back(four[1]);
                out.push_back(four[2]);
                out.push_back(four[3]);
                break;
            }
            default:
                break;
        }

        for (const auto byte: data_)
            out.push_back(byte);

        return out;
    }

private:
    static opcode opcode_from_size(size_t size)
    {
        constexpr auto op_75 = static_cast<uint8_t>(opcode::push_size_75);

        if (size <= op_75)
            return static_cast<opcode>(size);
        else if (size <= std::numeric_limits<uint8_t>::max())
            return opcode::push_one_size;
        else if (size <= std::numeric_limits<uint16_t>::max())
            return opcode::push_two_size;
        else
            return opcode::push_four_size;
    }

    static opcode nominal_opcode_from_data(const data_chunk& data)
    {
        return opcode_from_size(data.size());
    }

    static bool opcode_from_data_prefix(opcode& out_code,
        const std::string& prefix, const data_chunk& data)
    {
        constexpr auto op_75 = static_cast<uint8_t>(opcode::push_size_75);
        const auto size = data.size();
        out_code = opcode_from_size(size);

        if (prefix == "0")
        {
            return size <= op_75;
        }
        else if (prefix == "1")
        {
            out_code = opcode::push_one_size;
            return size <= std::numeric_limits<uint8_t>::max();
        }
        else if (prefix == "2")
        {
            out_code = opcode::push_two_size;
            return size <= std::numeric_limits<uint16_t>::max();
        }
        else if (prefix == "4")
        {
            out_code = opcode::push_four_size;
            return size <= std::numeric_limits<uint32_t>::max();
        }

        return false;
    }

    static data_chunk number_data(int64_t value)
    {
        constexpr uint8_t positive_0 = 0x00;
        constexpr uint8_t negative_sign = 0x80;

        if (value == 0)
            return {};

        const auto negative = value < 0;
        const uint64_t absolute = negative ? -value : value;
        data_chunk data(byte_width(absolute));
        to_little_endian(data, absolute);
        const auto negative_bit_set = (data.back() & 0x80) != 0;

        if (negative_bit_set && negative)
            data.push_back(negative_sign);
        else if (negative_bit_set)
            data.push_back(positive_0);
        else if (negative)
            data.back() |= 0x80;

        return data;
    }

    static bool data_from_decimal(data_chunk& out_data,
        const std::string& token)
    {
        if (!is_ascii_numeric(token))
            return false;

        int64_t value;
        std::istringstream istream(token);
        istream >> value;
        if (istream.fail())
            return false;

        out_data = number_data(value);
        return true;
    }

    inline bool is_push_token(const std::string& token)
    {
        return token.size() > 1 && token.front() == '[' && token.back() == ']';
    }

    inline bool is_text_token(const std::string& token)
    {
        return token.size() > 1 && token.front() == '\'' && token.back() == '\'';
    }

    inline std::string remove_token_delimiters(const std::string& token)
    {
        return std::string(std::next(token.begin()), std::prev(token.end()));
    }

    inline std::vector<std::string> split_push_token(const std::string& token)
    {
        return split(remove_token_delimiters(token), '.', true);
    }

    bool from_string(const std::string& mnemonic)
    {
        if (is_push_token(mnemonic))
        {
            // Data encoding uses single token with one or two parts.
            const auto parts = split_push_token(mnemonic);

            if (parts.size() == 1)
            {
                if (!decode_base16(data_, parts.front()))
                    return false;

                // Extract operation using nominal data size encoding.
                code_ = nominal_opcode_from_data(data_);
                return true;
            }
            else if (parts.size() == 2)
            {
                // Extract operation using minimal data size encoding.
                return decode_base16(data_, parts[1]) &&
                    opcode_from_data_prefix(code_, parts[0], data_);
            }
            else
            {
                return false;
            }
        }
        else if (is_text_token(mnemonic))
        {
            // Extract operation using nominal data size encoding.
            const auto text = remove_token_delimiters(mnemonic);
            data_ = data_chunk{ text.begin(), text.end() };
            code_ = nominal_opcode_from_data(data_);
            return true;
        }
        else if (opcode_from_mnemonic(code_, mnemonic))
        {
            // Any push code may have empty data, so this is presumed here.
            // No data is obtained here from a push opcode (use push/text tokens).
            return true;
        }
        else if (data_from_decimal(data_, mnemonic))
        {
            // opcode_from_mnemonic captures [-1, 0, 1..16] integers, others here.
            code_ = nominal_opcode_from_data(data_);
            return true;
        }
    }

    bool valid_;
    opcode code_;
    data_chunk data_;
};

typedef std::vector<operation> operations;

static operations operations_from_mnemonic(const std::string& mnemonic,
    bool valid=true)
{
    operations ops;
    for (const auto& token: split(mnemonic, ' '))
        ops.push_back(operation(token, valid));

    return ops;
}

static data_chunk operations_to_data(const operations& ops)
{
    data_chunk bytes;
    for (const auto& op: ops)
        for (const auto byte: op.to_data())
            bytes.push_back(byte);

    return bytes;
}

data_chunk mnemonic_to_data(const std::string& mnemonic, bool valid)
{
    return operations_to_data(operations_from_mnemonic(mnemonic, valid));
}
