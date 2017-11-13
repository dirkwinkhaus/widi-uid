/* widiuid extension for PHP */

#ifndef PHP_WIDIUID_H
# define PHP_WIDIUID_H

extern zend_module_entry widiuid_module_entry;
# define phpext_widiuid_ptr &widiuid_module_entry

# define PHP_WIDIUID_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_WIDIUID)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_WIDIUID_H */
