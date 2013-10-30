# Install packages
package 'ntp'
package 'openssh-server'



# Set hostname and such
hostname = 'draconoid'

file '/etc/hostname' do
   content "#{hostname}\n"
end

# There's no /etc/init.d/hostname 
# service script, so this is invalid...?
#service 'hostname' do
#   action :restart
#end

file '/etc/hosts' do
   content "127.0.0.1 localhost #{hostname}
::1      localhost ip6-localhost ip6-loopback #{hostname}
ff02::1  ip6-allnodes
ff02::2  ip6-allrouters
"
end


