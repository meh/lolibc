{
    echo "#ifndef _LOLIBC_FEATURES_H"
    echo "#define _LOLIBC_FEATURES_H"
    echo ""

    if [ $1 == "x86" ]; then
        echo "#define _LOLIBC_X86"
    fi

    echo ""
    cat <<LOL
#ifdef __cplusplus
#   define  __BEGIN_NAMESPACE(name) namespace ## name {
#   define  __END_NAMESPACE }
#
#   define PUBLIC extern "C"
#else
#   define __BEGIN_NAMESPACE(name)
#   define __END_NAMESPACE
#
#   define PUBLIC extern
#endif
LOL

    echo ""
    echo "#endif"
} > include/features.h
