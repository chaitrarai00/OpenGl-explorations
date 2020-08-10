#!/usr/bin/perl
#5a.cgi
use CGI':standard'
print "content-type:text/html\n\n";
print "server name:$ENV{'SERVER_NAME'}<br/>";
print "server port:$ENV{'SERVER_PORT'}<br/>";
print "server software:$ENV{'SERVER_SOFTWARE'}<br/>";
print "server protocol:$ENV{'SERVER_PROTOCOL'}<br/>";
print "CGI version:$ENV{'GATEWAY_INTERFACE'}<br/>";
#end of file#