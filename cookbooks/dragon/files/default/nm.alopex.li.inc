
$HTTP["host"] == "nm.alopex.li" {
  # Redirect root page to the wiki
  #url.redirect = (
  #  "^/index\..*" => "/wiki/",
  #  "^/$" => "/wiki/", 
  #  "^/.*" => "/index.html", 
  #)

  server.document-root = "/srv/www/nice-mullet/htdocs/"

  alias.url += ("/cgi-bin/" => "/srv/www/nice-mullet/cgi-bin/") 
  $HTTP["url"] =~ "^/cgi-bin/" {
    cgi.assign = ( "" => "" )
    server.dir-listing = "disable"
  }


  # Moinmoin stuffs
  alias.url += ("/moin_static194/" => "/usr/share/moin/htdocs/")
  #alias.url += ("/wiki" => "/usr/share/moin/server/moin.cgi")
  #$HTTP["url"] =~ "^/wiki" {
  #  cgi.assign = ( "" => "" )
  #  server.dir-listing = "disable"
  #}

  # Moinmoin fastcgi
  $HTTP["url"] =~ "^/wiki" {
     fastcgi.server =  ("/wiki" => ( "localhost" =>
      ( "socket" => "/var/run/lighttpd/moin2.socket",
        "check-local" => "disable",
        "broken-scriptfilename" => "enable",
        "min-procs" => 1,
        "max-procs" => 2,
        "bin-path" => "/usr/share/moin/server/moin.fcgi",
        "docroot" => "/wiki"
      )
      ))
  }

  # PHP fastcgi
#  $HTTP["url"] =~ "^/gallery/" {
#   fastcgi.server = (".php" => ((
#      "bin-path" => "/usr/bin/php5-cgi",
#      "socket" => "/tmp/php.socket",
#        "check-local" => "disable",
#        "broken-scriptfilename" => "enable",
#      "min-procs" => 1,
#      "max-procs" => 2,
#      "bin-environment" => (
#         "PHP_FCGI_CHILDREN" => "2",
#         "PHP_FCGI_REQUESTS" => "10000"
#      ),
#      "bin-copy-environment" => ( "PATH", "SHELL", "USER", "SCRIPT_FILENAME" )
#   )))
#   }


  # Admin tools
  auth.backend = "htdigest"
  auth.backend.htdigest.userfile = "/etc/lighttpd/users.htdigest" 



   # Disallow access to include
   #$HTTP["url"] =~ "^/gallery/web/include" { 
   #    url.access-deny = ( "" ) 
   #}

  # ikiwiki test
  alias.url += ("/ikiwiki/" => "/srv/www/nice-mullet/ikiwiki/public_html/wiki/")
  cgi.assign = ( "ikiwiki.cgi" => "" )
}

