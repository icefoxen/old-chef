
$HTTP["host"] == "www.alopex.li" {
   url.redirect = ( "^/(.*)" => "http://alopex.li/$1" )
}


#$HTTP["host"] == "cast.alopex.li" {
#   proxy.server = (
#      "" => ( "" => ( "host" => "127.0.0.1", "port" => 8888 ) )
#   )
#}



$HTTP["host"] == "alopex.li" {

  # Redirect root page to the wiki
  url.redirect = (
    "^/index\..*" => "/wiki/",
    "^/$" => "/wiki/", 
  #  "^/.*" => "/index.html", 
  )

  server.document-root = "/srv/www/alopex.li/htdocs/"

  alias.url += ("/cgi-bin/" => "/srv/www/alopex.li/cgi-bin/") 
  $HTTP["url"] =~ "^/cgi-bin/" {
    cgi.assign = ( "" => "" )
    server.dir-listing = "disable"
  }

  # User home directories
  alias.url += ("/~talhydras/" => "/home/talhydras/htdocs/")
  alias.url += ("/~dgibson/" => "/home/dgibson/htdocs/")

  # AeroFS integration test
  alias.url += ("/aero/" => "/home/icefox/AeroFS/web/")

  # ikiwiki test
  alias.url += ("/ikiwiki/" => "/srv/www/alopex.li/ikiwiki/public_html/wiki/")
  cgi.assign = ( "ikiwiki.cgi" => "" )

  # Moinmoin stuffs
  alias.url += ("/moin_static197/" => "/usr/share/moin/htdocs/")
  #alias.url += ("/wiki" => "/usr/share/moin/server/moin.cgi")
  #$HTTP["url"] =~ "^/wiki" {
  #  cgi.assign = ( "" => "" )
  #  server.dir-listing = "disable"
  #}

  # Moinmoin fastcgi
  $HTTP["url"] =~ "^/wiki" {
     fastcgi.server =  ("/wiki" => ( "localhost" =>
      ( "socket" => "/var/run/lighttpd/moin.socket",
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
  alias.url += ("/munin/" => "/var/cache/munin/www/")
  auth.backend = "htdigest"
  auth.backend.htdigest.userfile = "/etc/lighttpd/users.htdigest" 
  auth.require = (
    "/munin/" => (
      "method" => "digest",
      "realm" => "Admin site",
      "require" => "user=icefox"
    ),
    "/cgi-bin/awstats.pl" => (
      "method" => "digest",
      "realm" => "Admin site",
      "require" => "user=icefox"
    )
  )



   # Disallow access to include
   #$HTTP["url"] =~ "^/gallery/web/include" { 
   #    url.access-deny = ( "" ) 
   #}

}


$HTTP["host"] == "dragon" {

  # Redirect root page to the wiki
  url.redirect = (
    "^/index\..*" => "/wiki/",
    "^/$" => "/wiki/", 
  #  "^/.*" => "/index.html", 
  )

  server.document-root = "/srv/www/alopex.li/htdocs/"

  alias.url += ("/cgi-bin/" => "/srv/www/alopex.li/cgi-bin/") 
  $HTTP["url"] =~ "^/cgi-bin/" {
    cgi.assign = ( "" => "" )
    server.dir-listing = "disable"
  }

  # User home directories
  alias.url += ("/~talhydras/" => "/home/talhydras/htdocs/")
  alias.url += ("/~dgibson/" => "/home/dgibson/htdocs/")

  # AeroFS integration test
  alias.url += ("/aero/" => "/home/icefox/AeroFS/web/")

  # ikiwiki test
  alias.url += ("/ikiwiki/" => "/srv/www/alopex.li/ikiwiki/public_html/wiki/")
  cgi.assign = ( "ikiwiki.cgi" => "" )

  # Moinmoin stuffs
  alias.url += ("/moin_static197/" => "/usr/share/moin/htdocs/")
  #alias.url += ("/wiki" => "/usr/share/moin/server/moin.cgi")
  #$HTTP["url"] =~ "^/wiki" {
  #  cgi.assign = ( "" => "" )
  #  server.dir-listing = "disable"
  #}

  # Moinmoin fastcgi
  $HTTP["url"] =~ "^/wiki" {
     fastcgi.server =  ("/wiki" => ( "localhost" =>
      ( "socket" => "/var/run/lighttpd/moin.socket",
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
  alias.url += ("/munin/" => "/var/cache/munin/www/")
  auth.backend = "htdigest"
  auth.backend.htdigest.userfile = "/etc/lighttpd/users.htdigest" 
  auth.require = (
    "/munin/" => (
      "method" => "digest",
      "realm" => "Admin site",
      "require" => "user=icefox"
    ),
    "/cgi-bin/awstats.pl" => (
      "method" => "digest",
      "realm" => "Admin site",
      "require" => "user=icefox"
    )
  )



   # Disallow access to include
   #$HTTP["url"] =~ "^/gallery/web/include" { 
   #    url.access-deny = ( "" ) 
   #}

}

