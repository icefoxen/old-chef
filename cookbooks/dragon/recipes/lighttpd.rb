package 'lighttpd'

cookbook_file '/etc/lighttpd/lighttpd.conf'
cookbook_file '/etc/lighttpd/alopex.li.inc'
cookbook_file '/etc/lighttpd/nm.alopex.li.inc'

service 'lighttpd' do
   action :restart
end
