PHP_ARG_ENABLE(widiuid, whether to enable widiuid support,
[  --enable-widiuid          Enable widiuid support], no)

if test "$PHP_WIDIUID" != "no"; then
  AC_DEFINE(HAVE_WIDIUID, 1, [ Have widiuid support ])
  PHP_NEW_EXTENSION(widiuid, widiuid.c, $ext_shared)
fi
