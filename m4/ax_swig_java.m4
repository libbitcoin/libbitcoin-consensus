
AC_DEFUN([AX_SWIG_JAVA], [
    if test -n "$1" ; then
        JAVA_PACKAGE_NAME="$1"
        JAVA_PACKAGE_PATH=`echo "$1" | sed 's/\./\//g'`
        AC_SUBST([JAVA_PACKAGE_NAME])
        AC_SUBST([JAVA_PACKAGE_PATH])

        AC_PROG_MKDIR_P
        AX_PROG_JAVAC
        AX_PROG_JAVA
        AX_PROG_JAR
        AX_JNI_INCLUDE_DIR

        JNI_CFLAGS=
        JNI_LIBS=

        for JNI_INCLUDE_DIR in $JNI_INCLUDE_DIRS; do
          JNI_CFLAGS="$JNI_CFLAGS -I$JNI_INCLUDE_DIR"
        done

        AC_SUBST([JNI_CFLAGS])
        AC_SUBST([JNI_LIBS])
    else
        AC_MSG_ERROR(["Required java package name not provided."])
    fi
])
