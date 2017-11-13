# PHP Extension widiuid
This extension provides a function that generates a unique id. The id is related to the process id, the current time and an call incrementor to prevent any id collision. 
## Usage
Since the extension is loaded there is a new global function called "uid()". It does not need any arguments. It will return a string with the length of 40. Here a small sample:
	
	<?php
	$uid = uid();
	
	echo sprintf('The uid is %s.', $uid)
	
## Installation
To use this extension you may follow this few steps:

+ clone the source
+ enter source directory
+ run phpize
+ run ./configure
+ run make
+ copy the widiuid.so from modules directory to the php extension directory (e.g. "/var/lib/php/????????")
+ load the extension over your php configuration ("extension=widiuid.so")