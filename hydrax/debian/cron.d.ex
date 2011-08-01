#
# Regular cron jobs for the ssshydrax package
#
0 4	* * *	root	[ -x /usr/bin/libssshydrax_maintenance ] && /usr/bin/libssshydrax_maintenance
