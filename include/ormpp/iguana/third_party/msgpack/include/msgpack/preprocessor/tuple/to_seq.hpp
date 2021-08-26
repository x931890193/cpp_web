# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002-2011.                             *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */

#

# /* See http://www.boost.org for most recent version. */

#

# ifndef MSGPACK_PREPROCESSOR_TUPLE_TO_SEQ_HPP
# define MSGPACK_PREPROCESSOR_TUPLE_TO_SEQ_HPP
#


# include <msgpack/preprocessor/cat.hpp>
# include <msgpack/preprocessor/config/config.hpp>
# include <msgpack/preprocessor/facilities/overload.hpp>
# include <msgpack/preprocessor/tuple/size.hpp>
# include <msgpack/preprocessor/variadic/size.hpp>

#

# /* MSGPACK_PP_TUPLE_TO_SEQ */

#

# if MSGPACK_PP_VARIADICS
#    if MSGPACK_PP_VARIADICS_MSVC
#        define MSGPACK_PP_TUPLE_TO_SEQ(...) MSGPACK_PP_TUPLE_TO_SEQ_I(MSGPACK_PP_OVERLOAD(MSGPACK_PP_TUPLE_TO_SEQ_O_, __VA_ARGS__), (__VA_ARGS__))
#        define MSGPACK_PP_TUPLE_TO_SEQ_I(m, args) MSGPACK_PP_TUPLE_TO_SEQ_II(m, args)
#        define MSGPACK_PP_TUPLE_TO_SEQ_II(m, args) MSGPACK_PP_CAT(m ## args,)
#    	 define MSGPACK_PP_TUPLE_TO_SEQ_O_1(tuple) MSGPACK_PP_CAT(MSGPACK_PP_TUPLE_TO_SEQ_, MSGPACK_PP_TUPLE_SIZE(tuple)) tuple
#    else
#        define MSGPACK_PP_TUPLE_TO_SEQ(...) MSGPACK_PP_OVERLOAD(MSGPACK_PP_TUPLE_TO_SEQ_O_, __VA_ARGS__)(__VA_ARGS__)
#    	 define MSGPACK_PP_TUPLE_TO_SEQ_O_1(tuple) MSGPACK_PP_CAT(MSGPACK_PP_TUPLE_TO_SEQ_, MSGPACK_PP_VARIADIC_SIZE tuple) tuple
#    endif
#    define MSGPACK_PP_TUPLE_TO_SEQ_O_2(size, tuple) MSGPACK_PP_TUPLE_TO_SEQ_O_1(tuple)
# else
#    if ~MSGPACK_PP_CONFIG_FLAGS() & MSGPACK_PP_CONFIG_MWCC()
#        define MSGPACK_PP_TUPLE_TO_SEQ(size, tuple) MSGPACK_PP_TUPLE_TO_SEQ_I(size, tuple)
#        if ~MSGPACK_PP_CONFIG_FLAGS() & MSGPACK_PP_CONFIG_MSVC()
#            define MSGPACK_PP_TUPLE_TO_SEQ_I(s, t) MSGPACK_PP_TUPLE_TO_SEQ_ ## s t
#        else
#            define MSGPACK_PP_TUPLE_TO_SEQ_I(s, t) MSGPACK_PP_TUPLE_TO_SEQ_II(MSGPACK_PP_TUPLE_TO_SEQ_ ## s t)
#            define MSGPACK_PP_TUPLE_TO_SEQ_II(res) res
#        endif
#    else
#        define MSGPACK_PP_TUPLE_TO_SEQ(size, tuple) MSGPACK_PP_TUPLE_TO_SEQ_OO((size, tuple))
#        define MSGPACK_PP_TUPLE_TO_SEQ_OO(par) MSGPACK_PP_TUPLE_TO_SEQ_I ## par
#        define MSGPACK_PP_TUPLE_TO_SEQ_I(s, t) MSGPACK_PP_TUPLE_TO_SEQ_ ## s ## t
#    endif
# endif
#
/* An empty array can be passed */
# define MSGPACK_PP_TUPLE_TO_SEQ_0() ()
#

# define MSGPACK_PP_TUPLE_TO_SEQ_1(e0) (e0)
# define MSGPACK_PP_TUPLE_TO_SEQ_2(e0, e1) (e0)(e1)
# define MSGPACK_PP_TUPLE_TO_SEQ_3(e0, e1, e2) (e0)(e1)(e2)
# define MSGPACK_PP_TUPLE_TO_SEQ_4(e0, e1, e2, e3) (e0)(e1)(e2)(e3)
# define MSGPACK_PP_TUPLE_TO_SEQ_5(e0, e1, e2, e3, e4) (e0)(e1)(e2)(e3)(e4)
# define MSGPACK_PP_TUPLE_TO_SEQ_6(e0, e1, e2, e3, e4, e5) (e0)(e1)(e2)(e3)(e4)(e5)
# define MSGPACK_PP_TUPLE_TO_SEQ_7(e0, e1, e2, e3, e4, e5, e6) (e0)(e1)(e2)(e3)(e4)(e5)(e6)
# define MSGPACK_PP_TUPLE_TO_SEQ_8(e0, e1, e2, e3, e4, e5, e6, e7) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)
# define MSGPACK_PP_TUPLE_TO_SEQ_9(e0, e1, e2, e3, e4, e5, e6, e7, e8) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)
# define MSGPACK_PP_TUPLE_TO_SEQ_10(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)
# define MSGPACK_PP_TUPLE_TO_SEQ_11(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)
# define MSGPACK_PP_TUPLE_TO_SEQ_12(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)
# define MSGPACK_PP_TUPLE_TO_SEQ_13(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)
# define MSGPACK_PP_TUPLE_TO_SEQ_14(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)
# define MSGPACK_PP_TUPLE_TO_SEQ_15(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)
# define MSGPACK_PP_TUPLE_TO_SEQ_16(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)
# define MSGPACK_PP_TUPLE_TO_SEQ_17(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)
# define MSGPACK_PP_TUPLE_TO_SEQ_18(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)
# define MSGPACK_PP_TUPLE_TO_SEQ_19(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)
# define MSGPACK_PP_TUPLE_TO_SEQ_20(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)
# define MSGPACK_PP_TUPLE_TO_SEQ_21(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)
# define MSGPACK_PP_TUPLE_TO_SEQ_22(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)
# define MSGPACK_PP_TUPLE_TO_SEQ_23(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)
# define MSGPACK_PP_TUPLE_TO_SEQ_24(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)
# define MSGPACK_PP_TUPLE_TO_SEQ_25(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)
# define MSGPACK_PP_TUPLE_TO_SEQ_26(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)
# define MSGPACK_PP_TUPLE_TO_SEQ_27(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)
# define MSGPACK_PP_TUPLE_TO_SEQ_28(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)
# define MSGPACK_PP_TUPLE_TO_SEQ_29(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)
# define MSGPACK_PP_TUPLE_TO_SEQ_30(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)
# define MSGPACK_PP_TUPLE_TO_SEQ_31(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)
# define MSGPACK_PP_TUPLE_TO_SEQ_32(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)
# define MSGPACK_PP_TUPLE_TO_SEQ_33(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)
# define MSGPACK_PP_TUPLE_TO_SEQ_34(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)
# define MSGPACK_PP_TUPLE_TO_SEQ_35(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)
# define MSGPACK_PP_TUPLE_TO_SEQ_36(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)
# define MSGPACK_PP_TUPLE_TO_SEQ_37(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)
# define MSGPACK_PP_TUPLE_TO_SEQ_38(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)
# define MSGPACK_PP_TUPLE_TO_SEQ_39(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)
# define MSGPACK_PP_TUPLE_TO_SEQ_40(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)
# define MSGPACK_PP_TUPLE_TO_SEQ_41(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)
# define MSGPACK_PP_TUPLE_TO_SEQ_42(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)
# define MSGPACK_PP_TUPLE_TO_SEQ_43(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)
# define MSGPACK_PP_TUPLE_TO_SEQ_44(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)
# define MSGPACK_PP_TUPLE_TO_SEQ_45(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)
# define MSGPACK_PP_TUPLE_TO_SEQ_46(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)
# define MSGPACK_PP_TUPLE_TO_SEQ_47(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)
# define MSGPACK_PP_TUPLE_TO_SEQ_48(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)
# define MSGPACK_PP_TUPLE_TO_SEQ_49(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)
# define MSGPACK_PP_TUPLE_TO_SEQ_50(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)
# define MSGPACK_PP_TUPLE_TO_SEQ_51(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)
# define MSGPACK_PP_TUPLE_TO_SEQ_52(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)
# define MSGPACK_PP_TUPLE_TO_SEQ_53(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)
# define MSGPACK_PP_TUPLE_TO_SEQ_54(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)
# define MSGPACK_PP_TUPLE_TO_SEQ_55(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)
# define MSGPACK_PP_TUPLE_TO_SEQ_56(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)
# define MSGPACK_PP_TUPLE_TO_SEQ_57(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)
# define MSGPACK_PP_TUPLE_TO_SEQ_58(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)
# define MSGPACK_PP_TUPLE_TO_SEQ_59(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)(e58)
# define MSGPACK_PP_TUPLE_TO_SEQ_60(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)(e58)(e59)
# define MSGPACK_PP_TUPLE_TO_SEQ_61(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)(e58)(e59)(e60)
# define MSGPACK_PP_TUPLE_TO_SEQ_62(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)(e58)(e59)(e60)(e61)
# define MSGPACK_PP_TUPLE_TO_SEQ_63(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)(e58)(e59)(e60)(e61)(e62)
# define MSGPACK_PP_TUPLE_TO_SEQ_64(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)(e58)(e59)(e60)(e61)(e62)(e63)
#

# endif
