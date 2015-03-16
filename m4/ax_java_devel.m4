# Java discovery wrapper, defines JAVA_CPPFLAGS.

AC_DEFUN([AX_JAVA_DEVEL], [

    AX_PROG_JAVAC
    AX_PROG_JAVA
    AX_PROG_JAR
    AX_JNI_INCLUDE_DIR
    AC_PROG_MKDIR_P
    
    JAVA_CPPFLAGS=
    for JNI_INCLUDE_DIR in $JNI_INCLUDE_DIRS; do
      JAVA_CPPFLAGS="$JAVA_CPPFLAGS -I$JNI_INCLUDE_DIR"
    done

    # Set CPP compile flags.
    AC_SUBST([JAVA_CPPFLAGS])

    # Install .class files to ${datadir}/java.
    AC_SUBST([javadir], [${datadir}/java])
    AC_SUBST([javaexecdir], [${javadir}])

    # Install .jar files to ${javadir} (also).
    AC_SUBST([jardir], [${javadir}])
    AC_SUBST([jarexecdir], [${jardir}])

    # Build .class files in hidden directory.
    AC_SUBST([java_builddir], [.class])
    $MKDIR_P $java_builddir

    # Build .jar files in hidden directory.
    AC_SUBST([jar_builddir], [.jar])
    $MKDIR_P $jar_builddir

    # Instruct automake to build .class files in ${java_builddir}.
    AC_SUBST([JAVAROOT], [${java_builddir}])
])
