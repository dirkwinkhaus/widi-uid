/* widiuid extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "php_widiuid.h"

/*
    {{{ void uid()
    This function does not require any arguments. it will generate a uid
    by involving the process id, the current time and an incrementer.
 */
PHP_FUNCTION(uid)
{
    zend_long process_id;
    char buffer[40];
    char result[40];
    int i;
    struct timespec moment;
    static zend_long incrementer = 0;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	if(clock_gettime(CLOCK_REALTIME, &moment) == -1) {
		return;
    }

    memset(buffer, 0, sizeof(buffer));
    memset(result, 0, sizeof(result));
    incrementer++;

    process_id = getpid();
	if (process_id < 0) {
		process_id = 0;
	}
    
    // insert
    sprintf(buffer, "%ld", incrementer);
    strcat(result, buffer);

    // insert time
    sprintf(buffer, "%ld", moment.tv_nsec);
    strcat(result, buffer);
    sprintf(buffer, "%ld", moment.tv_sec);
    strcat(result, buffer);

    // insert process id
    sprintf(buffer, "%ld", process_id);
    strcat(result, buffer);
    
    memset(buffer, 0, sizeof(buffer));
    
    // insert leading 0
    for (i=strlen(result); i<40; i++) {
        strcat(buffer, "0");
    }
    
    strcat(buffer, result);

	RETURN_STRING(buffer);
}
/* }}} */


/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(widiuid)
{
#if defined(ZTS) && defined(COMPILE_DL_WIDIUID)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(widiuid)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "widiuid support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_uid, 0)
ZEND_END_ARG_INFO()

/* }}} */

/* {{{ widiuid_functions[]
 */
const zend_function_entry widiuid_functions[] = {
	PHP_FE(uid,		arginfo_uid)
	PHP_FE_END
};
/* }}} */

/* {{{ widiuid_module_entry
 */
zend_module_entry widiuid_module_entry = {
	STANDARD_MODULE_HEADER,
	"widiuid",					/* Extension name */
	widiuid_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(widiuid),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(widiuid),			/* PHP_MINFO - Module info */
	PHP_WIDIUID_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_WIDIUID
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(widiuid)
#endif
